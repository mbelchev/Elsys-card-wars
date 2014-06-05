#include <stdio.h>
#include "card.h"
#include "board.h"

void attack (card_t *card1, card_t *card2){
    card1->card_hp -= card2->card_dmg;
    card2->card_hp -= card1->card_dmg;
}

void fight(board_t *board1, board_t *board2, player_t *player1,  player_t *player2){
    int i;
    for (i = 1; i <= 5; i++){
        if(&board1->lanes[1][i].card_name != NULL && &board2->lanes[2][i].card_name != NULL){
            attack (&board1->lanes[1][i], &board2->lanes[2][i]);            
        }
        
        if(board1->lanes[1][i].card_name != NULL && board2->lanes[2][i].card_name == NULL){
            change_hp(player2, board1->lanes[1][i].card_dmg);
        }
        
        if(board1->lanes[1][i].card_name == NULL && board2->lanes[2][i].card_name != NULL){
            change_hp(player1, board2->lanes[2][i].card_dmg);
        }
    }
}

int check_card(card_t *card){
    if (card->card_name == NULL || 
        card->card_dmg  == 0 ||
        card->card_hp   == 0 ||
        card->card_mana == 0
    ) return 1;
    else return 0;
}
