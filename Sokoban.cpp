#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
using namespace std;
bool endgame,win_or_lose=false;
enum movement { STOP = 0, LEFT, RIGHT, UP, DOWN, UNDO, REDO, EXIT,LMAP,RMAP,UMAP,DMAP };
int x, y; 
movement dir;
char cell[22][11];
int x_con, y_con;
int score;
struct undo { //structure which contains coordinates of deleted move
    int done_x;
    int done_y;
};
undo undomove[11]; //list of deleted moves
undo redomove[11];
int undoclick, redoclick;
void beginning() {
    endgame = false;
    dir = STOP;
    x = 12;
    y = 8;
    cell[x][y] = 'X'; //position of a player
    
    cell[5][2] = cell[5][4] = cell[5][7] = cell[2][7] = cell[7][3] = cell[8][4] = '$';
    //coordinates of containers
    x_con = 5;
    y_con = 7;
    //victory cells
    cell[19][6] = cell[20][6] = cell[19][7] = cell[20][7] = cell[19][8] = cell[20][8] = '0'; 
    undoclick = -1;
    redoclick = -1; 
    score = 300; //number of available moves
}

void map1() {
    system("cls");
	// '#' is used as a wall
    //row0
    for (int i = 0; i <= 21; i++) {
        if (i >= 4 && i <= 8) {
            cell[i][0] = '#';
            cout << '#';
        }
        else if (cell[i][0] == 'X') {
            cout << 'X';
        }
        else if (cell[i][0] == '$') {
            cout << '$';
        }
        else {
            cell[i][0] = ' ';
            cout << ' ';
        }

    }
    cout << endl;
    //row1
    for (int i = 0; i <= 21; i++) {
        if (i == 4 || i == 8) {
            cell[i][1] = '#';
            cout << '#';
        }
        else if (cell[i][1] == 'X') {
            cout << 'X';
        }
        else if (cell[i][1] == '$') {
            cout << '$';
        }
        else {
            cell[i][1] = ' ';
            cout << ' ';
        }

    }
    cout << endl;
    //row2
    for (int i = 0; i <= 21; i++) {
        if (i == 4 || i == 8) {
            cell[i][2] = '#';
            cout << '#';
        }
        else if (cell[i][2] == 'X') {
            cout << 'X';
        }
        else if (cell[i][2] == '$') {
            cout << '$';
        }
        else {
            cell[i][2] = ' ';
            cout << ' ';
        }
    }
    cout << endl;

    //row3
    for (int i = 0; i <= 21; i++) {
        if ((i >= 2 && i <= 4) || (i >= 8 && i <= 10)) {
            cell[i][3] = '#';
            cout << '#';
        }
        else if (cell[i][3] == 'X') {
            cout << 'X';
        }
        else if (cell[i][3] == '$') {
            cout << '$';
        }
        else {
            cell[i][3] = ' ';
            cout << ' ';
        }
    }
    cout << endl;

    //row4
    for (int i = 0; i <= 21; i++) {
        if (i == 2 || i == 10) {
            cell[i][4] = '#';
            cout << '#';
        }
        else if (cell[i][4] == 'X') {
            cout << 'X';
        }
        else if (cell[i][4] == '$') {
            cout << '$';
        }
        else {
            cell[i][4] = ' ';
            cout << ' ';
        }
    }
    cout << endl;

    //row5
    for (int i = 0; i <= 21; i++) {
        if ((i >= 0 && i <= 2) || (i == 4) || (i >= 6 && i <= 8) || (i == 10) || (i >= 16 && i <= 21)) {
            cell[i][5] = '#';
            cout << '#';
        }
        else if (cell[i][5] == 'X') {
            cout << 'X';
        }
        else if (cell[i][5] == '$') {
            cout << '$';
        }
        else {
            cell[i][5] = ' ';
            cout << ' ';
        }
    }
    cout << endl;

    //row6
    for (int i = 0; i <= 21; i++) {
        if ((i == 0 || i == 4) || (i >= 6 && i <= 8) || (i >= 10 && i <= 16) || (i == 21)) {
            cell[i][6] = '#';
            cout << '#';
        }
        else if (cell[i][6] == 'X') {
            cout << 'X';
        }
        else if (cell[i][6] == '$') {
            cout << '$';
        }
        else if (cell[i][6] == '0') {
            cout << '0';
        }
        else if (cell[i][6] == '%') {
            cout << '%';
        }
        else {
            cell[i][6] = ' ';
            cout << ' ';
        }
    }
    cout << endl;

    //row7
    for (int i = 0; i <= 21; i++) {
        if ((i == 0 || i == 21)) {
            cell[i][7] = '#';
            cout << '#';
        }
        else if (cell[i][7] == 'X') {
            cout << 'X';
        }
        else if (cell[i][7] == '$') {
            cout << '$';
        }
        else if (cell[i][7] == '0') {
            cout << '0';
        }
        else if (cell[i][7] == '%') {
            cout << '%';
        }
        else {
            cell[i][7] = ' ';
            cout << ' ';
        }
    }
    cout << endl;

    //row8
    for (int i = 0; i <= 21; i++) {
        if ((i >= 0 && i <= 4) || (i >= 6 && i <= 9) || (i == 11) || (i >= 13 && i <= 16) || (i == 21)) {
            cell[i][8] = '#';
            cout << '#';
        }
        else if (cell[i][8] == 'X') {
            cout << 'X';
        }
        else if (cell[i][8] == '$') {
            cout << '$';
        }
        else if (cell[i][8] == '0') {
            cout << '0';
        }
        else if (cell[i][8] == '%') {
            cout << '%';
        }
        else {
            cell[i][8] = ' ';
            cout << ' ';
        }
    }
    cout << endl;

    //row9
    for (int i = 0; i <= 21; i++) {
        if ((i == 4) || (i >= 11 && i <= 13) || (i >= 16 && i <= 21)) {
            cell[i][9] = '#';
            cout << '#';
        }
        else if (cell[i][9] == 'X') {
            cout << 'X';
        }
        else if (cell[i][9] == '$') {
            cout << '$';
        }
        else {
            cell[i][9] = ' ';
            cout << ' ';
        }
    }
    cout << endl;

    //row10
    for (int i = 0; i <= 21; i++) {
        if (i >= 4 && i <= 11) {
            cell[i][10] = '#';
            cout << '#';
        }
        else if (cell[i][10] == 'X') {
            cout << 'X';
        }
        else if (cell[i][10] == '$') {
            cout << '$';
        }
        else {
            cell[i][10] = ' ';
            cout << ' ';
        }
    }
    cout << endl;

    cout << "Number of moves: " << score << endl;
    cout << "Deleted moves: " << undoclick+1 << endl;
    cout << "Redo moves: " << redoclick+1 << endl;
}

void input() {
    char p;
    cin >> p;
    p = tolower(p);

    switch (p) {
    case 'w':
        dir = UP;
        break;
    case 'd':
        dir = RIGHT;
        break;
    case 's':
        dir = DOWN;
        break;
    case 'a':
        dir = LEFT;
        break;
    case 'u':
        dir = UNDO;
        break;
    case 'r':
        dir = REDO;
        break;
    case 'q':
        dir = EXIT;
    }
}

void logic() {
    int x_pre = x, y_pre = y; //previous position of a player
    int x_con_pre = x_con, y_con_pre = y_con; //previous container's position
    switch (dir) {
    case UP:
        undoclick++;
        undomove[undoclick].done_x = x; //for every made move, a previous position is saved
        undomove[undoclick].done_y = y;

        y--;
        if (cell[x][y] == '$') {
            x_con_pre = x;
            y_con_pre = y;
            if (cell[x_con_pre][y_con_pre - 1] == '$') {
                y += 1;
                cell[x][y] = 'X';
                x_pre = 0;
                y_pre = 0;
                score++;
                undoclick--;
            }
            else {
                cell[x][y] = 'X';
                x_con = x;
                y_con = y - 1;
            }
        }
        else if (cell[x][y] == '%') {
            x_con_pre = x;
            y_con_pre = y;
            if (cell[x_con_pre][y_con_pre - 1] == '%') {
                y += 1;
                cell[x][y] = 'X';
                x_pre = 0;
                y_pre = 0;
                score++;
                undoclick--;
            }
            else {
                cell[x][y] = 'X';
                x_con = x;
                y_con = y - 1;
            }
        }
        break;
    case RIGHT:
        undoclick++;
        undomove[undoclick].done_x = x;
        undomove[undoclick].done_y = y;

        x++;
        if (cell[x][y] == '$') {
            x_con_pre = x;
            y_con_pre = y;
            if (cell[x_con_pre + 1][y_con_pre] == '$') {
                x -= 1;
                cell[x][y] = 'X';
                x_pre = 0;
                y_pre = 0;
                score++;
                undoclick--;
            }
            else {
                cell[x][y] = 'X';
                x_con = x + 1;
                y_con = y;

            }
        }
        else if (cell[x][y] == '%') {
            x_con_pre = x;
            y_con_pre = y;
            if (cell[x_con_pre + 1][y_con_pre] == '%') {
                x -= 1;
                cell[x][y] = 'X';
                x_pre = 0;
                y_pre = 0;
                score++;
                undoclick--;
            }
            else {
                cell[x][y] = 'X';
                x_con = x + 1;
                y_con = y;
            }
        }
        break;
    case DOWN:
        undoclick++;
        undomove[undoclick].done_x = x;
        undomove[undoclick].done_y = y;

        y++;
        if (cell[x][y] == '$') {
            x_con_pre = x;
            y_con_pre = y;
            if (cell[x_con_pre][y_con_pre + 1] == '$') {
                y -= 1;
                cell[x][y] = 'X';
                x_pre = 0;
                y_pre = 0;
                score++;
                undoclick--;
            }
            else {
                cell[x][y] = 'X';
                x_con = x;
                y_con = y + 1;

            }
        }
        else if (cell[x][y] == '%') {
            x_con_pre = x;
            y_con_pre = y;
            if (cell[x_con_pre][y_con_pre + 1] == '%') {
                y -= 1;
                cell[x][y] = 'X';
                x_pre = 0;
                y_pre = 0;
                score++;
                undoclick--;
            }
            else {
                cell[x][y] = 'X';
                x_con = x;
                y_con = y + 1;

            }
        }
        break;
    case LEFT:
        undoclick++;
        undomove[undoclick].done_x = x;
        undomove[undoclick].done_y = y;

        x--;
        if (cell[x][y] == '$') {
            x_con_pre = x;
            y_con_pre = y;
            if (cell[x_con_pre - 1][y_con_pre] == '$') {
                x += 1;
                cell[x][y] = 'X';
                x_pre = 0;
                y_pre = 0;
                score++;
                undoclick--;
            }
            else {
                cell[x][y] = 'X';
                x_con = x - 1;
                y_con = y;

            }
        }
        else if (cell[x][y] == '%') {
            x_con_pre = x;
            y_con_pre = y;
            if (cell[x_con_pre - 1][y_con_pre] == '%') {
                x += 1;
                cell[x][y] = 'X';
                x_pre = 0;
                y_pre = 0;
                score++;
                undoclick--;
            }
            else {
                cell[x][y] = 'X';
                x_con = x - 1;
                y_con = y;

            }
        }
        break;
    case UNDO:
        if (undoclick > -1 && undoclick < 10) {
            redoclick++;
            redomove[redoclick].done_x = x;
            redomove[redoclick].done_y = y;


            x = undomove[undoclick].done_x;
            y = undomove[undoclick].done_y;
            undoclick--;




            score += 2;

        }
        else if (undoclick == -1) {
            score++;
        }
        break;
    case REDO: //case UNDO i REDO are symmetrical
        if (redoclick < 11 && redoclick >-1) {
            undoclick++;
            undomove[undoclick].done_x = x;
            undomove[undoclick].done_y = y;
            

            x = redomove[redoclick].done_x;
            y = redomove[redoclick].done_y;
            redoclick--;
       
        }
        else if (redoclick == -1) {
            score++;
        }  
    }


    if (undoclick > 9) { 
        undoclick = -1;
    }
    if (redoclick > 9) {
        redoclick = -1;
    }

    if (cell[x][y] == '#') {
        x = x_pre;
        y = y_pre;
        x_pre = 0;
        y_pre = 0;
        undoclick--;
        score++;
    }


    if (cell[x_con][y_con] == '#' && cell[x][y] == cell[x_con_pre][y_con_pre]) {
        x_con = x_con_pre;
        y_con = y_con_pre;
        x = x_pre;
        y = y_pre;
        x_pre = 0;
        y_pre = 0;
        x_con_pre = 0;
        y_con_pre = 0;
        score++;
        undoclick--;
    }


    cell[x][y] = 'X';
    cell[x_con][y_con] = '$';
    cell[x_pre][y_pre] = ' ';

    for (int i = 19; i <= 20; i++) {
        for (int j = 6; j <= 8; j++) {
            if (cell[i][j] != '$' && cell[i][j] != '%' && cell[i][j] != 'X') {
                cell[i][j] = '0';
            }
            else if (cell[i][j] == 'X') {
                cell[i][j] = 'X';
            }
            else if (cell[i][j] == '$') {
                cell[i][j] = '%';
            }
        }
    }
    score--;
}

void win() {
    char a;
    if (cell[19][6] == '%' && cell[19][7] == '%' && cell[19][8] == '%' && cell[20][6] == '%' && cell[20][7] == '%' && cell[20][8] == '%') {
        endgame = true;
        win_or_lose = true;
        cout <<"\n" << "Congratulations! You won";
        cout << "Press any button to return to the main menu: ";
        cin >> a;
    }
    else if (score == 0) {
        endgame = true;
        win_or_lose = false;
        cout << "\n" << "HAHA, you lost!"<<endl;
        cout << "Press any button to return to the main menu: ";
        cin >> a;
    }
    
}

void level1() {
    beginning();
    while (!endgame) {
        map1();
        input();
        logic();
        win();
        if (dir == EXIT) {
            for (int i = 0; i < 22; i++) {
                for (int j = 0; j < 11; j++) {
                    cell[i][j] =' ';
                }
            }
            break;
        }
    }
}

void menu() {
    bool openmenu = true;
    while (openmenu) {
        system("cls");
        char start_game;
        // string logo which was generated using http://www.patorjk.com/software/taag/
        string logo[] = { "                                                                       @@@                                      @@@.                                                      ","                             #@@@@@@@@@@@@                             @@@                                      @@@.                                                      ","                           .@@@                                        @@@                                      @@@.                                                      ","                           @@@(                                        @@@                                      @@@.                                                      ","                            @@@@                  %@@@@@@@@@@@@        @@@      (@@@/       @@@@@@@@@@@@,       @@@..@@@@@@@@@@.       @@@@@@@@@@@@       @@@.*@@@@@@@@@/ ","                             .@@@@@&            @@@@         @@@@      @@@    @@@@        @@@,        ,@@@      @@@@@        &@@@      &         @@@      @@@@%       @@@@","                                 .@@@@@@       &@@%           &@@&     @@@  @@@%         @@@            @@@     @@@#          #@@@               &@@*     @@@*         @@@","                                      @@@@(    @@@             @@@     @@@@@@           *@@@            @@@.    @@@.           @@@      @@@@@@@@@@@@*     @@@          @@@","                                        @@@.   @@@.           ,@@@     @@@ #@@@*        ,@@@            @@@     @@@.          (@@@    @@@        %@@*     @@@          @@@","                                        @@@     @@@           @@@      @@@   .@@@@       @@@@          @@@(     @@@@         .@@@    @@@/        @@@*     @@@.         @@@","                           @@@@@#   (@@@@@       @@@@@     @@@@(       @@@      @@@@       @@@@#    /@@@@       @@@#@@#    @@@@&      @@@@    &@@%@@*     @@@.         @@@","                             ,@@@@@@@@               @@@@@@&           @@@        @@@@#       #@@@@@@,          @@@.  %@@@@@.           (@@@@@   %@@*     @@@          @@@" };
        for (int i = 0; i < 12; i++) {
            cout << logo[i] << endl;
        }
        cout << endl;
        //It is better to run in it in full screen mode
        cout << "Serhii Pyskovatskyi 196662" << endl;
        cout << "\n";

        cout << "Hi, this is a Sokoban " << "\n";
        cout << "Q: exit" << endl;
        cout << "X: choose level" << endl;
        cout << "Y: HELPME" << endl;
        cin >> start_game;
        start_game = tolower(start_game);

        if (start_game == 'x') {
            while (true) {
                system("cls");
                char level;
                bool next_level = false;
                cout << "Available levels:" << "\n" << "1" << "\n" << "2" << endl;
                cout << "Type a level number:" << endl;
                cout << "Return to menu: Q" << endl;
                cin >> level;
                level = tolower(level);
                if (level == '1') {
                    system("cls");
                    level1();
                    if (win_or_lose == true) {
                        next_level = true;
                    }
                }
                if (level == '2') {
                    if (next_level == true) {
                        cout << "Loading level"; //if there was second level, it would be "map2();"
                    }
                    else {
                        while (level != '1') {
                            cout << "This level is blocked, you must complete the first one!" << endl;
                            cin >> level;
                            if (level == '1') {
                                level1();
                            }
                            else if (level == 'q') {
                                break;
                            }
                        }
                    }
                }
                if (level == 'q') {
                    break;
                }
            }
        }
         else if (start_game == 'q') {
                openmenu = false;
            }
         else if (start_game == 'y') {
                while (true){
                system("cls");
                char button;
                cout << "Use buttons W,A,S,D for movements across the map" << endl;
                cout << "Press U to undo move. You can undo up to 10 moves. Every 11-th move deletes the list of undo moves";
                cout << "Put containers in right places to win the game" << endl;
                cout << "Return to menu: Q" << endl;
                cin >> button; 
                button = tolower(button);
                if (button == 'q') {
                    break;
                }
              }
            }
        }
}

int main()
{
    menu();
    return 0;
}