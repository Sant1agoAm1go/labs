#ifndef LAB4_GRAF_TICTACTOE_H
#define LAB4_GRAF_TICTACTOE_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Graph/NonDiGraph.h"
#include "ISortedSequence.h"

using namespace sf;
using namespace std;

const int WINDOW_SIZE = 600;
const int GRID_SIZE = 3;
const int CELL_SIZE = WINDOW_SIZE / GRID_SIZE;

class Cross {
public:
    Cross(float size, sf::Color color = sf::Color::Red, float thickness = 5.0f) {
        // Отцентрируем крестик внутри клетки
        line1.setSize(sf::Vector2f(size, thickness));
        line1.setFillColor(color);
        line1.setOrigin(size / 2, thickness / 2);
        line1.rotate(45);

        // Добавим вторую линию
        line2.setSize(sf::Vector2f(size, thickness));
        line2.setFillColor(color);
        line2.setOrigin(size / 2, thickness / 2);
        line2.rotate(-45);
    }

    void draw(sf::RenderWindow& window, float x, float y) {
        // Используем две линии для отрисовки крестика
        line1.setPosition(x, y);
        line2.setPosition(x, y);
        window.draw(line1);
        window.draw(line2);
    }

private:
    sf::RectangleShape line1;
    sf::RectangleShape line2;
};

class Circle {
public:
    Circle(float radius, sf::Color color = sf::Color::Blue, float thickness = 5.0f) {
        circleShape.setRadius(radius);
        circleShape.setFillColor(sf::Color::Transparent);
        circleShape.setOutlineColor(color);
        circleShape.setOutlineThickness(thickness);
        circleShape.setOrigin(radius, radius);
    }

    void draw(sf::RenderWindow& window, float x, float y) {
        circleShape.setPosition(x, y);
        window.draw(circleShape);
    }

private:
    sf::CircleShape circleShape;
};

struct MoveScore {
    sf::Vector2i move;
    int score;

    // Оператор сравнения для сортировки
    bool operator<(const MoveScore& other) const {
        return score < other.score;
    }
};
enum class Player { Cross, Circle, Empty };
sf::Vector2i findBestMove(Player board[GRID_SIZE][GRID_SIZE], ISortedSequence<MoveScore>& moveSequence);



int minimax(Player board[GRID_SIZE][GRID_SIZE], int depth, bool isMaximizing, ISortedSequence<MoveScore>& moveSequence);
int evaluate(Player board[GRID_SIZE][GRID_SIZE]);

////Проверка победы
bool checkWin(const Player board[GRID_SIZE][GRID_SIZE], Player player) {
    for (int i = 0; i < GRID_SIZE; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}


////Минимакс
sf::Vector2i findBestMove(Player board[GRID_SIZE][GRID_SIZE], ISortedSequence<MoveScore>& moveSequence) {
    int bestVal = INT_MIN;
    sf::Vector2i bestMove = { -1, -1 };

    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            if (board[i][j] == Player::Empty) {
                board[i][j] = Player::Circle;

                int moveVal = minimax(board, 0, false, moveSequence);

                board[i][j] = Player::Empty;

                if (moveVal > bestVal) {
                    bestMove = { j, i };
                    bestVal = moveVal;
                }
            }
        }
    }

    return bestMove;
}

int minimax(Player board[GRID_SIZE][GRID_SIZE], int depth, bool isMaximizing, ISortedSequence<MoveScore>& moveSequence) {
    int score = evaluate(board);

    if (score != -2) {
        return score;
    }

    if (isMaximizing) {
        int best = INT_MIN;

        for (int i = 0; i < GRID_SIZE; ++i) {
            for (int j = 0; j < GRID_SIZE; ++j) {
                if (board[i][j] == Player::Empty) {
                    board[i][j] = Player::Circle;
                    int moveVal = minimax(board, depth + 1, !isMaximizing, moveSequence);
                    board[i][j] = Player::Empty;

                    MoveScore moveScore;
                    moveScore.move = { j, i };
                    moveScore.score = moveVal;
                    moveSequence.Add(moveScore);

                    best = std::max(best, moveVal);
                }
            }
        }

        return best;
    } else {
        int best = INT_MAX;

        for (int i = 0; i < GRID_SIZE; ++i) {
            for (int j = 0; j < GRID_SIZE; ++j) {
                if (board[i][j] == Player::Empty) {
                    board[i][j] = Player::Cross;
                    int moveVal = minimax(board, depth + 1, !isMaximizing, moveSequence);
                    board[i][j] = Player::Empty;

                    MoveScore moveScore;
                    moveScore.move = { j, i };
                    moveScore.score = moveVal;
                    moveSequence.Add(moveScore);

                    best = std::min(best, moveVal);
                }
            }
        }

        return best;
    }
}
int evaluate(Player board[GRID_SIZE][GRID_SIZE]) {
    // Проверяем выигрышные комбинации для крестиков и ноликов
    if (checkWin(board, Player::Cross)) {
        return -1; // Крестики проиграли
    } else if (checkWin(board, Player::Circle)) {
        return 1;  // Нолики выиграли
    }

    // Проверяем, завершена ли игра в ничью
    bool isBoardFull = true;
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            if (board[i][j] == Player::Empty) {
                isBoardFull = false;
                break;
            }
        }
    }

    if (isBoardFull) {
        return 0;  // Ничья
    }

    // Если игра не завершена, возвращаем нейтральное значение
    return -2; // Продолжаем играть
}



int start_game() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "Tic Tac Toe");

    sf::RectangleShape gridLines[GRID_SIZE - 1][2];
    for (int i = 0; i < GRID_SIZE - 1; ++i) {
        for (int j = 0; j < 2; ++j) {
            gridLines[i][j].setSize(sf::Vector2f(WINDOW_SIZE, 5));
            gridLines[i][j].setFillColor(sf::Color::Black);
            if (j == 0) {
                gridLines[i][j].setPosition(0, (i + 1) * CELL_SIZE - 2.5);
            } else {
                gridLines[i][j].setPosition((i + 1) * CELL_SIZE - 2.5, 0);
                gridLines[i][j].rotate(90);
            }
        }
    }

    Player board[GRID_SIZE][GRID_SIZE] = {{Player::Empty, Player::Empty, Player::Empty},
                                          {Player::Empty, Player::Empty, Player::Empty},
                                          {Player::Empty, Player::Empty, Player::Empty}};

    Player currentPlayer = Player::Cross;

    int previousNodeIndex = -1;  // Добавляем переменную для отслеживания предыдущего хода

    NonDiGraph gameGraph(GRID_SIZE * GRID_SIZE);  // Используем граф для отслеживания ходов

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("C:/Mephi/3 sem/lab3_with_graphic/Pictures/fon.jpg")) {
        std::cerr << "Failed to load background texture\n";
        return EXIT_FAILURE;
    }

    sf::Sprite backgroundSprite(backgroundTexture);

    Cross cross(CELL_SIZE - 10);  // Размер крестика
    Circle circle((CELL_SIZE - 30) / 2);  // Уменьшенный размер нолика
    Circle transparentCircle((CELL_SIZE - 30) / 2, sf::Color(0, 0, 0, 128), 5.0f);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    int x = event.mouseButton.x / CELL_SIZE;
                    int y = event.mouseButton.y / CELL_SIZE;

                    if (x < GRID_SIZE && y < GRID_SIZE && board[y][x] == Player::Empty) {
                        board[y][x] = currentPlayer;

                        // Обновляем граф после каждого хода
                        int nodeIndex = y * GRID_SIZE + x;
                        gameGraph.addEdge(previousNodeIndex, nodeIndex, 1);  // Просто добавим ребро, вес несущественен
                        previousNodeIndex = nodeIndex;

                        if (currentPlayer == Player::Cross) {
                            cross.draw(window, x * CELL_SIZE + CELL_SIZE / 2, y * CELL_SIZE + CELL_SIZE / 2);
                        } else if (currentPlayer == Player::Circle) {
                            circle.draw(window, x * CELL_SIZE + CELL_SIZE / 2, y * CELL_SIZE + CELL_SIZE / 2);
                        }

                        if (checkWin(board, currentPlayer)) {
                            std::cout << "Player " << (currentPlayer == Player::Cross ? "Cross" : "Toe") << " win!\n";
                            window.close();
                        } else {
                            bool isBoardFull = true;
                            for (int i = 0; i < GRID_SIZE; ++i) {
                                for (int j = 0; j < GRID_SIZE; ++j) {
                                    if (board[i][j] == Player::Empty) {
                                        isBoardFull = false;
                                        break;
                                    }
                                }
                            }

                            if (isBoardFull) {
                                std::cout << "Game Draw!\n";
                                window.close();
                            } else {
                                currentPlayer = (currentPlayer == Player::Cross) ? Player::Circle : Player::Cross;
                            }
                        }
                    }
                }
            }
        }

        window.clear();

        window.draw(backgroundSprite);

        for (int i = 0; i < GRID_SIZE - 1; ++i) {
            for (int j = 0; j < 2; ++j) {
                window.draw(gridLines[i][j]);
            }
        }

        // Отрисовка крестиков и ноликов
        for (int i = 0; i < GRID_SIZE; ++i) {
            for (int j = 0; j < GRID_SIZE; ++j) {
                if (board[i][j] == Player::Cross) {
                    cross.draw(window, j * CELL_SIZE + CELL_SIZE / 2, i * CELL_SIZE + CELL_SIZE / 2);
                } else if (board[i][j] == Player::Circle) {
                    circle.draw(window, j * CELL_SIZE + CELL_SIZE / 2, i * CELL_SIZE + CELL_SIZE / 2);
                }
            }
        }

        // Если текущий игрок - нолик, отрисовать черный полупрозрачный нолик в лучшей клетке
        if (currentPlayer == Player::Circle) {
            ISortedSequence<struct MoveScore> moveQueue;
            sf::Vector2i bestMove = findBestMove(board, moveQueue);
            // Проверим, что клетка свободна
            if (board[bestMove.y][bestMove.x] == Player::Empty) {
                transparentCircle.draw(window, bestMove.x * CELL_SIZE + CELL_SIZE / 2, bestMove.y * CELL_SIZE + CELL_SIZE / 2);
            }
        }

        window.display();
    }
    return 0;
}

#endif //LAB4_GRAF_TICTACTOE_H