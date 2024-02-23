#include "GameBoardController.h"

GameBoardController::GameBoardController():
    current_block(Block::O), holding_block(Block::O),
    next_list{Block::O, Block::J, Block::L, Block::I, Block::Z, Block::S, Block::T},
    block_cordinate_i(start_block_cordinate_i), block_cordinate_j(start_block_cordinate_j),
    block_used_count(0), hold_empty(true), hold_unused(true) {
        std::random_shuffle(&next_list[0], &next_list[7]);
        current_block.newBlock(next_list[block_used_count++]);
}

bool GameBoardController::collison_test(int i, int j){
    const int (* shape)[2] = current_block.state();
    for (int t=0; t<4; t++){
        if (gb.get_board_ij(i+shape[t][0], j+shape[t][1]) < 0) return false;
    }
    return true;
}

void GameBoardController::move_block_left(){
    if (collison_test(block_cordinate_i, block_cordinate_j-1)) block_cordinate_j-=1;
}
void GameBoardController::move_block_right() {
    if (collison_test(block_cordinate_i, block_cordinate_j+1)) block_cordinate_j+=1;
}
void GameBoardController::move_block_down() {
    if (collison_test(block_cordinate_i+1, block_cordinate_j)) block_cordinate_i+=1;
    else {
        const int (* shape)[2] = current_block.state();
        for (int t=0; t<4; t++){
            gb.set_board_ij(block_cordinate_i+shape[t][0], block_cordinate_j+shape[t][1], isblock);
        }

        remove_line();

        current_block.newBlock(next_list[block_used_count++]);
        if (block_used_count == 7) {
            block_used_count = 0;
            std::random_shuffle(&next_list[0], &next_list[7]);
        }
        block_cordinate_i = start_block_cordinate_i;
        block_cordinate_j = start_block_cordinate_j;
        hold_unused = true;
    }
}
void GameBoardController::rotate_block_CW() {
    current_block.rotateCW();
    if (!collison_test(block_cordinate_i, block_cordinate_j)) current_block.rotateCCW();
}
void GameBoardController::rotate_block_CCW() {
    current_block.rotateCCW();
    if (!collison_test(block_cordinate_i, block_cordinate_j)) current_block.rotateCW();
}
void GameBoardController::hold_block() {
    if (hold_unused) {
        if (hold_empty) {
            holding_block.newBlock(current_block.getType());
            current_block.newBlock(next_list[block_used_count++]);
            if (block_used_count == 7) {
                block_used_count = 0;
                std::random_shuffle(&next_list[0], &next_list[7]);
            }
            block_cordinate_i = start_block_cordinate_i;
            block_cordinate_j = start_block_cordinate_j;
            hold_empty = false;
        }
        else {
            Block::Btype t = holding_block.getType();
            holding_block.newBlock(current_block.getType());
            current_block.newBlock(t);
            block_cordinate_i = start_block_cordinate_i;
            block_cordinate_j = start_block_cordinate_j;
            hold_unused = false;
        }
    }
}
void GameBoardController::remove_line(){
    bool line_full;
    for (int i=height-4; i>2; i--){
        line_full = true;
        for (int j=3; j<width-3; j++){
            if (gb.get_board_ij(i, j) != -5) 
            {
                line_full = false;
                break;
            }
        }
        if (line_full){
            for (int k=i; k>2; k--){
                for (int j=3; j<width-3; j++){
                    gb.set_board_ij(k,j, gb.get_board_ij(k-1,j));
                }
            }
        }
    }
}
void GameBoardController::draw_all(int x, int y){
    using namespace std;
    for (int i=0; i<height; i++){
        gotoxy(x, y+i);
        for (int j=0; j<width; j++) {
            if (gb.get_board_ij(i, j) < 0) cout << "бс";
            else cout << "  ";
        }
    }
    const int (* shape)[2] = current_block.state();
    for (int t=0; t<4; t++){
        gotoxy(x + 2*(block_cordinate_j+shape[t][1]),
                y + (block_cordinate_i + shape[t][0]));
        cout << "бс";
    }
}