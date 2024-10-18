#include <iostream>
using namespace std;

void displayBoard(char arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "          ";
        }
        for (int z = 0; z < 6; z++) {
            if (i == 2) {
                continue;
            }
            cout << endl;
        }
    }
    
    cout << endl;
    cout << endl;
}

bool checkWin(char arr[3][3], char player) {
    if ((arr[0][0] == player && arr[0][1] == player && arr[0][2] == player) ||
        (arr[1][0] == player && arr[1][1] == player && arr[1][2] == player) ||
        (arr[2][0] == player && arr[2][1] == player && arr[2][2] == player) ||
        (arr[0][0] == player && arr[1][0] == player && arr[2][0] == player) ||
        (arr[0][1] == player && arr[1][1] == player && arr[2][1] == player) ||
        (arr[0][2] == player && arr[1][2] == player && arr[2][2] == player) ||
        (arr[0][0] == player && arr[1][1] == player && arr[2][2] == player) ||
        (arr[2][0] == player && arr[1][1] == player && arr[0][2] == player)) {
        return true;
    }
    return false;
}

void computerMove(char arr[3][3], bool checkArr[3][3], char compChar, char playerChar) {
    // Check for winning possibilities
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (!checkArr[i][j]) {
                arr[i][j] = compChar;
                if (checkWin(arr, compChar)) {
                    checkArr[i][j] = true;
                    return;
                }
                arr[i][j] = '?'; // Backtracking
            }
        }
    }

    // If player is about to win --> block
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (!checkArr[i][j]) {
                arr[i][j] = playerChar;
                if (checkWin(arr, playerChar)) {
                    arr[i][j] = compChar;
                    checkArr[i][j] = true;
                    return;
                }
                arr[i][j] = '?'; // Undo move
            }
        }
    }

    // Optimal moves - 1) Pick centre --> 2) pick corners --> 3) pick sides

    //1) Pick centre
    if (!checkArr[1][1]) {
        arr[1][1] = compChar;
        checkArr[1][1] = true;
        cout << "Computer placed " << compChar << " at position 2 2" << endl;
        return;
    }

    //2) Pick corners
    int corners[4][2] = {{0, 0}, {0, 2}, {2, 0}, {2, 2}};
    for (int i = 0; i < 4; i++) {
        int x = corners[i][0];
        int y = corners[i][1];
        if (!checkArr[x][y]) {
            arr[x][y] = compChar;
            checkArr[x][y] = true;
            cout << "Computer placed " << compChar << " at position " << x + 1 << " " << y + 1 << endl;
            return;
        }
    }

    // 3) Pick sides
    int sides[4][2] = {{0, 1}, {1, 0}, {1, 2}, {2, 1}};
    for (int i = 0; i < 4; i++) {
        int x = sides[i][0];
        int y = sides[i][1];
        if (!checkArr[x][y]) {
            arr[x][y] = compChar;
            checkArr[x][y] = true;
            cout << "Computer placed " << compChar << " at position " << x + 1 << " " << y + 1 << endl;
            return;
        }
    }
}

int main() {
    cout << endl;
    cout << "----------------------->Welcome to Tic Tac Toe!" << endl;
    cout << "Which game-mode would you like to play? "<<endl;
    cout<<endl;
    cout<< "1. Multiplayer(2 people required)"<<endl;
    cout<< "2. Multiplayer(Against the computer)"<<endl;

    cout<< "Enter the number corresponsing to what you want to play: ";

    int gameMode;
    cin >> gameMode;

    string namep1, namep2;
    char charp1, charp2;
    cout << "Hi, Player 1, Please enter your name: ";
    cin >> namep1;
    cout << "Hey, " << namep1 << " please choose (X/O): ";
    cin >> charp1;
    if (charp1 == 'X') {
        charp2 = 'O';
    } else {
        charp2 = 'X';
    }

    bool isVsComputer = (gameMode == 2);

    if (!isVsComputer) {
        cout << "Hi, Player 2, Please enter your name: ";
        cin >> namep2;
    } else {
        namep2 = "Computer";
    }

    char arr[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr[i][j] = '?';
        }
    }

    displayBoard(arr);

    bool checkArr[3][3] = {false};
    int x1, y1, x2, y2;
    bool isWin = false;
    char Winner = '?';
    int moveCount = 0;

    while (true) {
        cout << namep1 << ", please enter the x and y coordinates to place " << charp1 << ": ";
        cin >> x1 >> y1;
        while (checkArr[x1 - 1][y1 - 1]) {
            cout << "-->That place is already taken. Please try again: ";
            cin >> x1 >> y1;
        }
        checkArr[x1 - 1][y1 - 1] = true;
        arr[x1 - 1][y1 - 1] = charp1;

        displayBoard(arr);
        moveCount++;

        if (checkWin(arr, charp1)) {
            isWin = true;
            Winner = charp1;
            break;
        }

        if (moveCount == 9) {
            break;
        }

        if (isVsComputer) {
            //Computer move
            computerMove(arr, checkArr, charp2, charp1);
        } else {
            cout << namep2 << ", please enter the x and y coordinates to place " << charp2 << ": ";
            cin >> x2 >> y2;
            while (checkArr[x2 - 1][y2 - 1]) {
                cout << "-->That place is already taken. Please try again: ";
                cin >> x2 >> y2;
            }
            checkArr[x2 - 1][y2 - 1] = true;
            arr[x2 - 1][y2 - 1] = charp2;
        }

        displayBoard(arr);
        moveCount++;

        if (checkWin(arr, charp2)) {
            isWin = true;
            Winner = charp2;
            break;
        }

        if (moveCount == 9) {
            break;
        }
    }

    cout << endl;
    cout << "//// FINAL GRID ////" << endl;
    displayBoard(arr);

    if (isWin) {
        cout << "-->>> The winner is: ";
        if (Winner == charp1) {
            cout << namep1 << endl;
        } else {
            cout << namep2 << endl;
        }
    } else {
        cout << "It's a tie!" << endl;
    }

    return 0;
}
