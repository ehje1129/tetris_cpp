#include "GameBoardController.h"
#include "utils.h"
#include <iostream>

const int tic_per_sec = 60;

using namespace std;

int main() {
    int temp;
    int x=10, y=5;
    GameBoardController gbc;
    int tic_counter = 0;
    int speed = 0;
    system("mode con: cols=50 lines=50");

    while (true) {
        if(tic_counter == (60-speed)) {
            gbc.move_block_down();
            tic_counter = 0;
        } else tic_counter++;

        system("cls");
        cout << tic_counter << "  " << speed;
        gbc.draw_all(x, y);
        if (_kbhit()){
            temp = _getch();
            if (temp == 27) return 0;
            else if (temp == 'a') speed = speed>0 ? speed-1 : speed;
            else if (temp == 's') speed = speed<59 ? speed+1 : speed;
            else if (temp == 'z') gbc.rotate_block_CCW();
            else if (temp == 'x') gbc.rotate_block_CW();
            else if (temp == 'c') gbc.hold_block();
            else if (temp == 224) {
                temp = _getch();
                if (temp == 77) { //오른쪽
                    gbc.move_block_right();
                }
                else if (temp == 72) { //위
                    // if (y != 0 && collision_test(x, y-1, b, gb)) y--;
                }
                else if (temp == 75) { //왼쪽
                    gbc.move_block_left();
                    }
                else if (temp == 80) { //아래
                    gbc.move_block_down();
                }
            }
        }
        Sleep(1000/60);
    }
}