#ifndef BOARD_H

    #define BOARD_H
    #include "player.h"
    typedef struct{
        card_t lanes[2][5];
    } board_t;
    
    void init_board(board_t *board);
    void play_card(board_t *board, player_t *player, card_t card, int num_lane, int turn);
    void print_board(board_t *board1, player_t player1, board_t *board2, player_t player2);
#endif

