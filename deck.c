#include<stdio.h>
#include "deck.h"

int push_card(card_t card_to_push, struct deck_t *player_deck) {
	player_deck->array[++player_deck->top] = card_to_push;
}


void draw_card(struct deck_t *player_deck) {
	printf("name: %s\n", player_deck.array[player_deck.top].card_name);
	printf("HP: %d\n", player_deck.array[player_deck.top].card_hp);
	printf("DMG: %d\n", player_deck.array[player_deck.top].card_dmg);
	printf("mana: %d\n", player_deck.array[player_deck.top].card_mana);
	--player_deck->top;
}

void look_card(struct deck_t player_deck) {
	printf("name: %s\n", player_deck.array[player_deck.top].card_name);
	printf("HP: %d\n", player_deck.array[player_deck.top].card_hp);
	printf("DMG: %d\n", player_deck.array[player_deck.top].card_dmg);
	printf("mana: %d\n", player_deck.array[player_deck.top].card_mana);
}
