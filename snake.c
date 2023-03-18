#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define WIDTH 20
#define HEIGHT 20

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point points[WIDTH * HEIGHT];
    int length;
} Snake;

typedef struct {
    Point point;
    int eaten;
} Food;

void init_snake(Snake *snake) {
    snake->length = 3;
    snake->points[0].x = WIDTH / 2;
    snake->points[0].y = HEIGHT / 2;
    snake->points[1].x = WIDTH / 2 - 1;
    snake->points[1].y = HEIGHT / 2;
    snake->points[2].x = WIDTH / 2 - 2;
    snake->points[2].y = HEIGHT / 2;
}

void init_food(Food *food) {
    food->eaten = 0;
    food->point.x = rand() % WIDTH;
    food->point.y = rand() % HEIGHT;
}

void move_snake(Snake *snake, int direction) {
    int i;
    for (i = snake->length - 1; i > 0; i--) {
        snake->points[i].x = snake->points[i - 1].x;
        snake->points[i].y = snake->points[i - 1].y;
    }
    switch (direction) {
        case 0:
            snake->points[0].y--;
            break;
        case 1:
            snake->points[0].x++;
            break;
        case 2:
            snake->points[0].y++;
            break;
        case 3:
            snake->points[0].x--;
            break;
    }
}

int check_collision(Snake *snake) {
    int i;
    for (i = 1; i < snake->length; i++) {
        if (snake->points[0].x == snake->points[i].x && snake->points[0].y == snake->points[i].y) {
            return 1;
        }
    }
    if (snake->points[0].x < 0 || snake->points[0].x >= WIDTH || snake->points[0].y < 0 || snake->points[0].y >= HEIGHT) {
        return 1;
    }
    return 0;
}

int check_food(Snake *snake, Food *food) {
    if (snake->points[0].x == food->point.x && snake->points[0].y == food->point.y) {
        food->eaten = 1;
        snake->length++;
        return 1;
    }
    return 0;
}

void draw(Snake *snake, Food *food) {
    int i, j;
    for (i = 0; i < WIDTH + 2; i++) {
        printf("#");
    }
    printf("\n");
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH + 2; j++) {
            if (j == 0 || j == WIDTH + 1) {
                printf("#");
            } else {
                int k;
                int draw = 0;
                for (k = 0; k < snake->length; k++) {
                    if (snake->points[k].x == j - 1 && snake->points[k].y == i) {
                        draw = 1;
                        break;
                    }
                }
                if (draw) {
                    printf("*");
                } else if (food->point.x == j - 1 && food->point.y == i) {
                    printf("F");
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    for (i = 0; i < WIDTH + 2; i++) {
        printf("#");
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    Snake snake;
    Food food;
    int direction = 0;
    int running = 1;
    init_snake(&snake);
    init_food(&food);
    while (running) {
        draw(&snake, &food);
        move_snake(&snake, direction);
        if (check_collision(&snake)) {
            running = 0;
        }
        if (check_food(&snake, &food)) {
            init_food(&food);
        }
        int c = getchar();
        switch (c) {
            case 'w':
                direction = 0;
                break;
            case 'd':
                direction = 1;
                break;
            case 's':
                direction = 2;
                break;
            case 'a':
                direction = 3;
                break;
            case 'q':
                running = 0;
                break;
        }
            system("cls");
    }
    return 0;
}