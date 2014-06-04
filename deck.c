#include <stdio.h>
#include "deck.h"
#include "player.h"

int init_deck(deck_t *player_deck){
    player_deck->top = -1;
}

int push_card(card_t card_to_push, deck_t *player_deck) {
	player_deck->deck[++player_deck->top] = card_to_push;
}


void draw_card(deck_t *player_deck) {
        printf("%s(%d,%d,%d) | ",   player_deck->deck[player_deck->top].card_name, 
                                      player_deck->deck[player_deck->top].card_dmg,
                                      player_deck->deck[player_deck->top].card_hp,
                                      player_deck->deck[player_deck->top].card_mana);
        --player_deck->top;
}

void look_card(deck_t *player_deck, card_t *card) {
	printf("Name: %s\n", 	player_deck->deck[player_deck->top].card_name);
	printf("DMG: %d\n", 	player_deck->deck[player_deck->top].card_dmg);
	printf("HP: %d\n", 	player_deck->deck[player_deck->top].card_hp);
	printf("Mana: %d\n", 	player_deck->deck[player_deck->top].card_mana);
}

void print_deck(deck_t *player_deck){
    int i;
    for (i = 0; i < 5; i++){
        printf("%s (%d | %d | %d)\n", player_deck->deck[i].card_name, 
                                      player_deck->deck[i].card_dmg,
                                      player_deck->deck[i].card_hp,
                                      player_deck->deck[i].card_mana);
    }
}

void print_hand(player_t player){
    int i;
    for (i = 0; i <= 4; i++){
        printf("%s(%d,%d,%d) |", player.player_hand[i].card_name, 
                                 player.player_hand[i].card_dmg,
                                 player.player_hand[i].card_hp,
                                 player.player_hand[i].card_mana);
    }
}
