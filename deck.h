#ifndef DECK_H
#define DECK_H
#include "card.h"

struct deck_t
{
	card_t array[30];
	int top;
};


int push_card(card_t card_to_push, struct deck_t *player_deck);
void draw_card(struct deck_t *player_deck);
void look_card(struct deck_t player_deck);


#endif
