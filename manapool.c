#include <stdio.h>
#include "manapool.h"

int can_put_card(card_t card_to_put, manapool_t pool){
	if(card_to_put.card_mana > pool.current_mana){
		return 0;
	} else {
		return 1;
	}
}

void add_mana (manapool_t *pool, int mana_to_add){
	pool->current_mana += mana_to_add;
}

void remove_mana (manapool_t *pool, int mana_to_remove){
	pool->current_mana -= mana_to_remove;
}

int main(){
	card_t attacker = {"Almighty PATKA", 4123, 12, 12};
	manapool_t pool = {1, 1};

	can_put_card(attacker, pool);

	/*
		TESTING add & remove mana

		add_mana(&pool, 5);
		remove_mana(&pool, 2);

		printf("%d\n", pool.current_mana);

	*/
	return 0;
}