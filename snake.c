#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int width = 20, height = 10;
    int x = width / 2, y = height / 2;

    int foodX, foodY;
    int score = 0;

    int dir = 0;
    int gameOver = 0;

    srand(time(0));

    // initial food
    do {
        foodX = rand() % (width - 2) + 1;
        foodY = rand() % (height - 2) + 1;
    } while(foodX == x && foodY == y);

    while(!gameOver) {

        Sleep(200); //For speed

        // Movement input
        if(_kbhit()) {
            char ch = _getch();

            if(ch == 'a') dir = 1;
            else if(ch == 'd') dir = 2;
            else if(ch == 'w') dir = 3;
            else if(ch == 's') dir = 4;
            else if(ch == 'x') gameOver = 1;
        }

        // Movement
        if(dir == 1) x--;
        else if(dir == 2) x++;
        else if(dir == 3) y--;
        else if(dir == 4) y++;

        // WALL 
        if(x <= 0 || x >= width - 1 || y <= 0 || y >= height - 1)
            gameOver = 1;

        // FOOD 
        if(x == foodX && y == foodY) {
            score += 10;

            // new food (safe spawn)
            do {
                foodX = rand() % (width - 2) + 1;
                foodY = rand() % (height - 2) + 1;
            } while(foodX == x && foodY == y);
        }

        // DRAW
        system("cls");

        for(int i = 0; i < height; i++) {
            for(int j = 0; j < width; j++) {

                if(i == 0 || i == height - 1 || j == 0 || j == width - 1)
                    printf("#");
                else if(i == y && j == x)
                    printf("O");
                else if(i == foodY && j == foodX)
                    printf("F");
                else
                    printf(" ");
            }
            printf("\n");
        }

        printf("Score: %d\n", score);
    }

    printf("\nGame Over! Final Score: %d\n", score);

    return 0;
} 

//Want more challenge? Reduce the sleep time and watch the game speed go crazy.
//insta:- @krzznh
