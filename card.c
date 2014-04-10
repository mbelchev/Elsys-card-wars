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
	/*  	Copyright © 2014 Patka Inc. All Rights Reserved. Permission to use, copy, modify, and 
 	 *	distribute this software and its documentation for educational, research, and not-for-profit 
	 *	purposes, without fee and without a signed licensing agreement, is hereby granted, provided 
	 *	that the above copyright notice, this paragraph and the following two paragraphs appear in all 
	 *	copies, modifications, and distributions. Contact Patka Inc., BGR Sofia, Koepenicker Str. 55, 
	 *	BG (359) 878-93-2517, for commercial licensing opportunities.
	 *
	 *	Created by Marian Belchev and Hristo Dachev, ELSYS, Sofia.
	 *
	 *	IN NO EVENT SHALL REGENTS BE LIABLE TO ANY PARTY FOR DIRECT, INDIRECT, SPECIAL, INCIDENTAL,
	 *	OR CONSEQUENTIAL DAMAGES, INCLUDING LOST PROFITS, ARISING OUT OF THE USE OF THIS SOFTWARE AND 
	 *	ITS DOCUMENTATION, EVEN IF REGENTS HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
	 *
	 *	REGENTS SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
	 *	WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. THE SOFTWARE AND ACCOMPANYING 
	 *	DOCUMENTATION, IF ANY, PROVIDED HEREUNDER IS PROVIDED "AS IS". REGENTS HAS NO OBLIGATION TO 
	 *	PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.
	 */
