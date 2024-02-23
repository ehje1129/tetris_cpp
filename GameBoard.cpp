#include "GameBoard.h"

GameBoard::GameBoard(){
    for (int i=0; i<height; i++){
        for (int j=0; j<width; j++){
            if (i<2 || j<2 || i>(height-3) || j>(width-3)) board[i][j] = dummy; 
            else if (j==2) board[i][j] = left_wall; // �޺�
            else if (j==(width-3)) board[i][j] = right_wall; // ������
            else if (i==(height-3)) board[i][j] = bottom; // �ٴ�
            else if (i==2) board[i][j] = top; // õ��
            else if (i==3 && j==5) board[i][j] = dead_zone; // ���ӿ�����
            else board[i][j] = empty_space; // ��ĭ
        }
    }
    board[1][2] = -2;
    board[1][width-3] = -3;
}

int GameBoard::get_board_ij(int i, int j) const{
    return board[i][j];
}

void GameBoard::set_board_ij(int i, int j, int val){
    board[i][j] = val;
}