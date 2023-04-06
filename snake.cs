using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SnakeGame
{
    //Structure for the snake
    struct Snake
    {
        public int x, y; //Position of the snake
    }

    //Class for the game
    class SnakeGame
    {
        private int width, height; //Size of the game
        private int score; //Score of the player
        private int foodX, foodY; //Position of the food
        private List<Snake> snake; //List of snakes
        private enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN }; //Direction of the snake
        private eDirection direction; //Current direction of the snake

        //Constructor
        public SnakeGame(int _width, int _height)
        {
            //Initializing the game
            width = _width;
            height = _height;
            score = 0;
            direction = eDirection.STOP;
            foodX = foodY = 9;
            snake = new List<Snake>();
            snake.Add(new Snake { x = 0, y = 0 });
        }

        //Function to get the current score
        public int GetScore() { return score; }

        //Function to start the game
        public void StartGame()
        {
            //Game logic
        }

        //Function to move the snake
        public void MoveSnake()
        {
            //Check for wasd keys
            if (Console.KeyAvailable)
            {
                ConsoleKeyInfo key = Console.ReadKey(true);
                switch (key.Key)
                {
                    case ConsoleKey.W:
                        if (direction != eDirection.DOWN)
                        {
                            direction = eDirection.UP;
                        }
                        break;
                    case ConsoleKey.S:
                        if (direction != eDirection.UP)
                        {
                            direction = eDirection.DOWN;
                        }
                        break;
                    case ConsoleKey.A:
                        if (direction != eDirection.RIGHT)
                        {
                            direction = eDirection.LEFT;
                        }
                        break;
                    case ConsoleKey.D:
                        if (direction != eDirection.LEFT)
                        {
                            direction = eDirection.RIGHT;
                        }
                        break;
                }
            }
            //Game logic for the movement of the snake
        }

        // Function to set the color of the snake
        public void SetColor(ConsoleColor foodColor = ConsoleColor.Black, ConsoleColor snakeColor = ConsoleColor.White)
        {
            // Setting the color of the food 
            Console.ForegroundColor = foodColor;
            Console.Write("■");  // Food symbol

            // Setting the color of the snake
            Console.ForegroundColor = snakeColor;
            foreach (Snake snakeParts in snake)
            {
                Console.Write("■");  // Snake symbol
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            int width = 20;
            int height = 20;
            SnakeGame snakeGame = new SnakeGame(width, height);
            snakeGame.StartGame();
        }
    }
}