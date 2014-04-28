#ifndef MANAPOOL_H

	#define MANAPOOL_H
	#include "card.h"
	
	typedef struct {
		int max_mana;
		int current_mana;
	} manapool_t;

	int can_put_card(card_t card_to_put, manapool_t pool);

#endif