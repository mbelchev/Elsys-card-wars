#include <stdio.h>
#include "card.h"

int attack (card_t *attacker, card_t *defender){
	attacker -> card_hp -= defender -> card_dmg;
	defender -> card_hp -= attacker -> card_dmg;

	if (defender -> card_hp <= 0 && attacker -> card_hp <= 0)
		return 0;
	if (defender -> card_hp <= 0 && attacker -> card_hp > 0)
		return 1;
	if (defender -> card_hp > 0 && attacker -> card_hp <= 0)
		return 2;
	if (defender -> card_hp > 0 && attacker -> card_hp > 0) 
                return 3;
}

int check_card(card_t *card){
    if (card->card_name == NULL || 
        card->card_dmg  == 0 ||
        card->card_hp   == 0 ||
        card->card_mana == 0
    ) return 1;
    else return 0;
}
