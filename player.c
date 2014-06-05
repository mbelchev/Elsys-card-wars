#include <stdio.h>
#include "player.h"

void change_hp(player_t *player, int hp){
	player->player_health -= hp;
}


void push_to_hand(player_t *player, int k){
    int i;
    for (i = 0; i < k; i++){
        
        if (player->player_deck.top < 0) {
            printf("No more cards in your deck!\n");
        } else {
           player->player_hand[i] = player->player_deck.deck[i];
        }
    }
}