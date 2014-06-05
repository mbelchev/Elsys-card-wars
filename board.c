#include <stdio.h>
#include "board.h"

void init_board(board_t *board){
    int i, k;
    for (i = 1; i <= 5; i++){
        for (k = 1; k <= 2; k++){
            board->lanes[k][i].card_name = NULL;
            board->lanes[k][i].card_dmg = 0;
            board->lanes[k][i].card_hp = 0;
            board->lanes[k][i].card_mana = 0;
        }
    }
}

void play_card(board_t *board, player_t *player, card_t card, int num_lane, int player_id){
    if (can_put_card(card, player->player_manapool) == 1){
        board->lanes[player_id][num_lane].card_name  = card.card_name;
        board->lanes[player_id][num_lane].card_dmg   = card.card_dmg;
        board->lanes[player_id][num_lane].card_hp    = card.card_hp;
        board->lanes[player_id][num_lane].card_mana  = card.card_mana;
        
        remove_mana(&player->player_manapool, card.card_mana);     
    } else {
        printf("You are out of mana!\n");
    }
}
void delete_from_hand(player_t *player, int a){
    int i;
    for (i = a - 1 ; i < 5 - 1 ; i++)
        player->player_hand[i] = player->player_hand[i+1];
    
}

void print_board(board_t *board1, player_t player1, board_t *board2, player_t player2){
    printf("%s(HP: %d), Mana: %d \n", player1.player_name, player1.player_health, player1.player_manapool.current_mana);
    printf("_________________________________________________________________________________ \n| ");
    int i;
    print_hand(player1);
    printf("\n¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");
        for (i = 1; i <= 5; i++){
            if (check_card(board1->lanes[1][i]) == 0){
                printf("#\t%d|%d\t", board1->lanes[1][i].card_dmg, board1->lanes[1][i].card_hp);
            } else {
                printf("#\tEmpty\t");
            }
        }
    printf("#\n");
            for (i = 1; i <= 5; i++){
            if (check_card(board2->lanes[2][i]) == 0){
                printf("#\t%d|%d\t", board2->lanes[2][i].card_dmg, board2->lanes[2][i].card_hp);
            } else {
                printf("#\tEmpty\t");
            }
        }
    printf("#\n_________________________________________________________________________________ \n| ");
    print_hand(player2);
    printf("\n¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");
    printf("%s(HP: %d), Mana: %d \n", player2.player_name, player2.player_health, player2.player_manapool.current_mana);
}