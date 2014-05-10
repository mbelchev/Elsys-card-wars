#include <stdio.h>
#include "deck.h"

int push_card(card_t card_to_push, deck_t *player_deck) {
	player_deck->deck[++player_deck->top] = card_to_push;
}


void draw_card(deck_t *player_deck, card_t *card) {
	printf("Name: %s\n", 	player_deck->deck[player_deck->top].card_name);
	printf("DMG: %d\n", 	player_deck->deck[player_deck->top].card_dmg);
	printf("HP: %d\n", 		player_deck->deck[player_deck->top].card_hp);
	printf("Mana: %d\n", 	player_deck->deck[player_deck->top].card_mana);
	--player_deck->top;
}

void look_card(deck_t *player_deck, card_t *card) {
	printf("Name: %s\n", 	player_deck->deck[player_deck->top].card_name);
	printf("DMG: %d\n", 	player_deck->deck[player_deck->top].card_dmg);
	printf("HP: %d\n", 		player_deck->deck[player_deck->top].card_hp);
	printf("Mana: %d\n", 	player_deck->deck[player_deck->top].card_mana);
}
