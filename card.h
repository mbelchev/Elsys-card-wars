#ifndef CARD_H

	#define CARD_H

	typedef struct {
		char *card_name;
		int card_dmg;
		int card_hp;
		int card_mana;
	} card_t;

	void attack (card_t *card1, card_t *card2);
        

#endif