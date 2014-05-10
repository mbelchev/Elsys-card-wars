#ifndef DECK_H

	#define DECK_H
	#define DECK_SIZE 30
	#include "card.h"

	typedef struct {
		card_t deck[DECK_SIZE];
		int top;
	} deck_t;


	int push_card(card_t card_to_push, deck_t *player_deck);
	void draw_card(deck_t *player_deck, card_t *card);
	void look_card(deck_t *player_deck, card_t *card);

#endif
