#include <stdio.h>
#include "player.h"

int change_hp(player_t *player, int hp, int set_or_get){
	if (set_or_get = 0) player->player_health -= hp;
	if (set_or_get = 1) player->player_health += hp;

	//printf("%d\n", player->player_health);
}

card_t play_card_from_hand(player_t *player, card_t card){
	int errors[2] = {0, 0};

	if (can_put_card(card, player->player_manapool) != 1) 	errors[0] = 1;
	//if (can_put_card(card, player->player_manapool) != 1) errors[1] = 1;  TODO: Add check_card_existing, check_card_if_it_is_played

	if (errors[0] == 0 /*&& errors[1] == 0*/){
		draw_card(&player->player_deck);
	} else {
		printf("No mana or other problem occurs\n");
	}
}

void delete_card_from_hand(player_t *player, card_t card){
    
}

void turn_begin(player_t *player){

}