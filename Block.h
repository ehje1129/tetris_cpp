// #include <iostream>
// #include <conio.h>
// #include <windows.h>
#ifndef BLOCK_H_
#define BLOCK_H_

const int block_list[7][4][4][2] ={ // i,j offset
    {
        {{-1, 0}, {-1, 1}, {0, 0}, {0, 1}},
        {{-1, 0}, {-1, 1}, {0, 0}, {0, 1}},
        {{-1, 0}, {-1, 1}, {0, 0}, {0, 1}},
        {{-1, 0}, {-1, 1}, {0, 0}, {0, 1}}
    },
    {
        {{-1, -1}, {0, -1}, {0, 0}, {0, 1}},
        {{-1, 1}, {-1, 0}, {0, 0}, {1, 0}},
        {{1, 1}, {0, -1}, {0, 0}, {0, 1}},
        {{1, -1}, {-1, 0}, {0, 0}, {1, 0}}
    },
    {
        {{-1, 1}, {0, -1}, {0, 0}, {0, 1}},
        {{1, 1}, {-1, 0}, {0, 0}, {1, 0}},
        {{1, -1}, {0, -1}, {0, 0}, {0, 1}},
        {{-1, -1}, {-1, 0}, {0, 0}, {1, 0}}
    },
    {
        {{0, -1}, {0, 0}, {0, 1}, {0, 2}},
        {{-1, 1}, {0, 1}, {1, 1}, {2, 1}},
        {{1, -1}, {1, 0}, {1, 1}, {1, 2}},
        {{-1, 0}, {0, 0}, {1, 0}, {2, 0}},
    },
    {
        {{-1, -1}, {-1, 0}, {0, 0}, {0, 1}},
        {{-1, 1}, {0, 1}, {0, 0}, {1, 0}},
        {{0, -1}, {0, 0}, {1, 0}, {1, 1}},
        {{-1, 0}, {0, 0}, {0, -1}, {1, -1}},
    },
    {
        {{-1, 1}, {-1, 0}, {0, 0}, {0, -1}},
        {{1, 1}, {0, 1}, {0, 0}, {-1, 0}},
        {{1, -1}, {1, 0}, {0, 0}, {0, 1}},
        {{-1, -1}, {0, -1}, {0, 0}, {1, 0}},
    },
    {
        {{-1, 0}, {0, -1}, {0, 0}, {0, 1}},
        {{-1, 0}, {0, 0}, {0, 1}, {1, 0}},
        {{0, -1}, {0, 0}, {0, 1}, {1, 0}},
        {{-1, 0}, {0, -1}, {0, 0}, {1, 0}},
    },
};


class Block {
    public:
        enum Btype {O=0, J=1, L=2, I=3, Z=4, S=5, T=6};
    private:
        int rotation = 0;
        Btype type;
    public:
        Block(Btype t) : type(t) {}
        void newBlock(Btype t) {type=t; rotation = 0;}
        Btype getType() {return type;}
        // int getRatation() {return rotation;}
        void rotateCW() {if (rotation == 3) rotation=0; else rotation+=1;}
        void rotateCCW() {if (rotation == 0) rotation=3; else rotation-=1;}
        const int (* state())[2] {return block_list[type][rotation];}
};

#endif
 



// test code
// using namespace std;
 
// void gotoxy(int x, int y)
// {
//     COORD Cur;
//     Cur.X = x;
//     Cur.Y = y;
//     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
// }

// void draw_block(int x, int y, Block &b){
//     const int (* shape)[4] = b.state();
//     for (int i=0; i<4; i++){
//         gotoxy(x, y+i);
//         for (int j=0; j<4; j++){
//             if (shape[i][j] == 0) cout << "  ";
//             else cout << "■";
//         }
//     }
    

// }
 
// int main()
// {
//     int temp;
//     int x = 0, y = 0;
//     Block b = Block(Block::O);
 
//     system("mode con: cols=50 lines=50");
 
//     while (true) { 
//         system("cls");
//         draw_block(x, y, b);
//         // gotoxy(x, y);
//         // cout << "*";
        
//         temp = _getch();
//         if (temp == 27) return 0;
//         else if (temp == 'z') b.rotateCCW();
//         else if (temp == 'x') b.rotateCW();
//         else if (temp == 'c') b.newBlock( Block::Btype((b.getType()+1)%7) );
//         else if (temp == 224) {
//             temp = _getch();
//             if (temp == 77) { //오른쪽
//                 if (x == 49) x = 0;
//                 else x++;
//             }
//             else if (temp == 72) { //위
//                 if (y == 0) y = 49;
//                 else y--;
//             }
//             else if (temp == 75) { //왼쪽
//                 if (x == 0) x = 49;
//                 else x--;
//             }
//             else if (temp == 80) { //아래
//                 if (y == 49) y = 0;
//                 else y++;
//             }
//         }
//     }
// }
