#ifndef GAMEBOARD_H_
#define GAMEBOARD_H_

const int width = 10+2+4;
const int height = 20+2+4;
const int dummy = 10;
const int top = 2;
const int bottom = -1;
const int left_wall = -2;
const int right_wall = -3;
const int dead_zone = 1;
const int empty_space = 0;
const int isblock = -5;

class GameBoard{
    private:
        int board[height][width];
    public:
        GameBoard();
        int get_board_ij(int i, int j) const;
        void set_board_ij(int i, int j, int val);
};

#endif