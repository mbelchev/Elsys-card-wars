#ifndef PLAYER_H
	
	#define PLAYER_H
	#include "manapool.h"

	typedef struct {
                char *player_name;
		deck_t player_deck;
		card_t player_hand[30];
		manapool_t player_manapool;
		int player_health;
	} player_t;

	void change_hp(player_t *player, int hp);
        void push_to_hand(player_t *player, int k);
        void print_hand(player_t player);
#endif