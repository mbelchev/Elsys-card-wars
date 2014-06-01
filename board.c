#include <stdio.h>
#include "board.h"

void init_board(board_t *board){
    int i, k;
    for (i = 1; i <= 5; i++){
        for (k = 1; k <= 2; k++){
            board->lanes[k][i].card_name = "";
            board->lanes[k][i].card_dmg = 0;
            board->lanes[k][i].card_hp = 0;
            board->lanes[k][i].card_mana = 0;
        }
    }
}

void play_card(board_t *board, player_t player, card_t card, int num_lane, int turn){
    if (can_put_card(card, player.player_manapool) == 1){
        board->lanes[turn][num_lane].card_name = card.card_name;
        board->lanes[turn][num_lane].card_dmg = card.card_dmg;
        board->lanes[turn][num_lane].card_hp = card.card_hp;
        board->lanes[turn][num_lane].card_mana = card.card_mana;
        
        //delete_card_from_hand(player, card);
       // remove_mana(&player.player_manapool, card.card_mana);
        player.player_manapool.current_mana -= card.card_mana;
        printf("%d \n", player.player_manapool.current_mana);
        print_board(board, player, turn);
    }
}

void print_board(board_t *board, player_t player, int turn){
    printf("\t Player: %s, Health: %d, Mana: %d \n", player.player_name, player.player_health, player.player_manapool.current_mana);
    printf("------------------------------------------------------ \n");
    printf("\t -> №# Name(DMG | HP | MANA) <- \n");
    int i;
        for (i = 1; i <= 5; i++){
            if (check_card(board->lanes[turn][i]) == 0){
                printf("%d# %s", i, board->lanes[turn][i].card_name);
                printf("(%d | ", board->lanes[turn][i].card_dmg);
                printf("%d | ", board->lanes[turn][i].card_hp);
                printf("%d)", board->lanes[turn][i].card_mana);
                printf("\n");
            } else {
                printf("%d# This lane is empty", i);
                printf("\n");
            }
        }
    printf("###################################################### \n\n");
}

