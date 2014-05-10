#ifndef PLAYER_H
	
	#define PLAYER_H
	#include "manapool.h"

	typedef struct {
		deck_t player_deck;
		card_t player_card;
		manapool_t player_manapool;
		int player_health;
	} player_t;

	int change_hp(player_t *player, int hp, int set_or_get); // set_or_get = 0, when taking hp | set_or_get = 1, when giving hp
	card_t play_card_from_hand(player_t *player, card_t card);
	void turn_begin(player_t *player);

#endif