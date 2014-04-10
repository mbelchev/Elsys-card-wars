#include <stdio.h>
#include "card.h"

int attack (card_t *attacker, card_t *defender){
	attacker -> card_hp -= defender -> card_dmg;
	defender -> card_hp -= attacker -> card_dmg;
	
	if (defender -> card_hp < 0 && attacker -> card_hp < 0)
		return 0;
	if (defender -> card_hp < 0 && attacker -> card_hp > 0)
		return 1;
	if (defender -> card_hp > 0 && attacker -> card_hp < 0)
		return 2;
	if (defender -> card_hp > 0 && attacker -> card_hp > 0) /* БУнТАР  >>>> */ return 3;
}

int main(){
	card_t attacker = {"Almighty PATKA", 4123, 12, 0};
	card_t defender = {"Weak PATKA", 1, 12, 10};
	
	printf ("%d\n", attack(&attacker, &defender));    
	
	if (attack(&attacker, &defender) == 0) printf("Both cards die (happy) \n");
	if (attack(&attacker, &defender) == 1) printf("Card: %s WON! GG WP \n", attacker.card_name);
	if (attack(&attacker, &defender) == 2) printf("Card: %s WON! GG WP \n", defender.card_name);
	if (attack(&attacker, &defender) == 3) printf("Both cards are still alive :( \n");
	
	return 0;
}
// Copyright © 2014 by МАРКО И АЗ. All Rights Reserved.
