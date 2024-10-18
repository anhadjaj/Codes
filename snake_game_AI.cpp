#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <cstdlib>

using namespace std;

bool gameOver;
const int width = 20;
const int height = 17;
int x, y, fruitX, fruitY, score;
int aiX, aiY, aiScore;
int tailX[100], tailY[100], aiTailX[100], aiTailY[100];
int nTail, aiTail;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir, aiDir;
bool walls_on;  // New variable to determine if walls are on or off

void Setup() {
    gameOver = false;
    dir = STOP;
    aiDir = STOP;
    x = width / 2;
    y = height / 2;
    aiX = width / 4;
    aiY = height / 4;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
    aiScore = 0;
}

int _kbhit() {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

void single_setup(int score_to_win, bool *is_win) {
    system("clear");
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)
                cout << "#";
            if (i == y && j == x)
                cout << "O";
            else if (i == fruitY && j == fruitX)
                cout << "F";
            else {
                bool print = false;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print)
                    cout << " ";
            }

            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;
    cout << "Score: " << score / 10 << endl;
    if (score == score_to_win) {
        gameOver = true;
        *is_win = true;
    }
}

void AI_setup(int score_to_win, bool *is_win) {
    system("clear");
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)
                cout << "#";
            if (i == y && j == x)
                cout << "O"; // Player
            else if (i == aiY && j == aiX)
                cout << "A"; // AI
            else if (i == fruitY && j == fruitX)
                cout << "F";
            else {
                bool print = false;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        cout << "o";
                        print = true;
                    }
                }
                for (int k = 0; k < aiTail; k++) {
                    if (aiTailX[k] == j && aiTailY[k] == i) {
                        cout << "x";
                        print = true;
                    }
                }
                if (!print)
                    cout << " ";
            }

            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;
    cout << "Player Score: " << score / 10 << " | AI Score: " << aiScore / 10 << endl;

    if (score == score_to_win || aiScore == score_to_win) {
        gameOver = true;
        *is_win = true;
    }
}



void Input() {
    if (_kbhit()) {
        switch (getchar()) {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}

void AI() {
    if (aiX < fruitX)
        aiDir = RIGHT;
    else if (aiX > fruitX)
        aiDir = LEFT;
    else if (aiY < fruitY)
        aiDir = DOWN;
    else if (aiY > fruitY)
        aiDir = UP;
}

void Logic(bool is_multiplayer) {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir) {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

    // Wall collision logic
    if (walls_on) {
        // If walls are on, hitting the boundary ends the game
        if (x >= width || x < 0 || y >= height || y < 0)
            gameOver = true;
    } else {
        // If walls are off, wrap around the screen
        if (x >= width) x = 0;
        else if (x < 0) x = width - 1;
        if (y >= height) y = 0;
        else if (y < 0) y = height - 1;
    }

    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;
    }

    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }

    if (is_multiplayer) {
        AI();

        int aiPrevX = aiTailX[0];
        int aiPrevY = aiTailY[0];
        int aiPrev2X, aiPrev2Y;
        aiTailX[0] = aiX;
        aiTailY[0] = aiY;
        for (int i = 1; i < aiTail; i++) {
            aiPrev2X = aiTailX[i];
            aiPrev2Y = aiTailY[i];
            aiTailX[i] = aiPrevX;
            aiTailY[i] = aiPrevY;
            aiPrevX = aiPrev2X;
            aiPrevY = aiPrev2Y;
        }

        switch (aiDir) {
        case LEFT:
            aiX--;
            break;
        case RIGHT:
            aiX++;
            break;
        case UP:
            aiY--;
            break;
        case DOWN:
            aiY++;
            break;
        default:
            break;
        }

        if (walls_on) {
            if (aiX >= width || aiX < 0 || aiY >= height || aiY < 0)
                gameOver = true;
        } else {
            if (aiX >= width) aiX = 0;
            else if (aiX < 0) aiX = width - 1;
            if (aiY >= height) aiY = 0;
            else if (aiY < 0) aiY = height - 1;
        }

        for (int i = 0; i < aiTail; i++) {
            if (aiTailX[i] == aiX && aiTailY[i] == aiY)
                gameOver = true;
        }

        if (aiX == fruitX && aiY == fruitY) {
            aiScore += 10;
            fruitX = rand() % width;
            fruitY = rand() % height;
            aiTail++;
        }
    }
}

void Sleep(int ms) {
    usleep(ms * 1000);
}

int main() {
    int game_mode;
    cout << "-----> Choose from the following modes: " << endl;
    cout << "1. Single Player." << endl;
    cout << "2. Multiplayer (Against the computer)." << endl;

    cout << "Enter the number corresponding to the game mode you want to play: ";
    cin >> game_mode;

    cout << endl;
    int winning_score;
    cout << "The difficulty levels are below: " << endl;
    cout << "1. Easy (Winning score = 40, speed = slow)" << endl;
    cout << "2. Medium (Winning score = 80, speed = medium)" << endl;
    cout << "3. Hard (Winning score = 100, speed = fast)" << endl;
    int dif;
    cout << "-----> Enter the number corresponding to the difficulty of the game you want to play: ";
    cin >> dif;
    
    cout << "Would you like to turn walls on or off? (1 for On, 0 for Off): ";
    cin >> walls_on;

    if (dif == 1) {
        winning_score = 400;
    } else if (dif == 2) {
        winning_score = 800;
    } else if (dif == 3) {
        winning_score = 1000;
    }
    bool is_win = false;
    Setup();
    
    if(game_mode ==1)
    {
        while (!gameOver) {
            single_setup(winning_score, &is_win);
            Input();
            Logic(false);
            Sleep((4 - dif) * 50);
        }
    }
    else if(game_mode == 2)
    {
        while (!gameOver) {
            AI_setup(winning_score, &is_win);
            Input();
            Logic(true);
            Sleep((4 - dif) * 50);
        }
    }

    if (is_win) {
        cout << endl;
        cout << endl;
        cout << "#1 VICTORY ROYALE." << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "---> Thanks for playing, that was an amazing win!" << endl;
    } else {
        cout << endl;
        cout << "Well tried, better luck next time." << endl;
    }

    return 0;
}
