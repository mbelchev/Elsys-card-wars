#include <stdio.h>
#include "manapool.h"

int can_put_card(card_t card_to_put, manapool_t pool){
	if(card_to_put.card_mana > pool.current_mana){
		printf("0\n");
		return 0;
	} else {
		return 1;
	}
}

int main(){
	card_t attacker = {"Almighty PATKA", 4123, 12, 12};
	manapool_t pool = {1, 1};
	can_put_card(attacker, pool);
	return 0;
}