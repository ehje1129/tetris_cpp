#ifndef GAMEBOARDCONTROLLER_H_
#define GAMEBOARDCONTROLLER_H_

#include "Block.h"
#include "GameBoard.h"
#include "utils.h"
#include <iostream>
#include <algorithm>

const int start_block_cordinate_i = 2;
const int start_block_cordinate_j = 7;

class GameBoardController {
    private:
        GameBoard gb;
        Block current_block, holding_block;
        Block::Btype next_list[7];
        int block_cordinate_i, block_cordinate_j;
        int block_used_count;
        bool hold_empty, hold_unused;
    public:
        GameBoardController();
        bool collison_test(int i, int j);
        void move_block_left();
        void move_block_right();
        void move_block_down();
        void rotate_block_CW();
        void rotate_block_CCW();
        void hold_block();
        void remove_line();
        void draw_all(int x, int y);
};

#endif