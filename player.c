#include <stdio.h>
#include "player.h"


//----------------------- START: Tova trqbva da izchezne ->
/*

Ne se include-vat drugite failove, zatova trqbva pak da se pishat funkciite:

ERROR MSG:
player.c:(.text+0x9d): undefined reference to `can_put_card'
player.c:(.text+0xc0): undefined reference to `draw_card'
collect2: ld returned 1 exit status

*/



int can_put_card(card_t card_to_put, manapool_t pool){
	if(card_to_put.card_mana > pool.current_mana){
		return 0;
	} else {
		return 1;
	}
}

void draw_card(deck_t *player_deck, card_t *card) {
	printf("Name: %s\n", 	player_deck->deck[player_deck->top].card_name);
	printf("DMG: %d\n", 	player_deck->deck[player_deck->top].card_dmg);
	printf("HP: %d\n", 		player_deck->deck[player_deck->top].card_hp);
	printf("Mana: %d\n", 	player_deck->deck[player_deck->top].card_mana);
	--player_deck->top;
}

//-------------------------- END.

int change_hp(player_t *player, int hp, int set_or_get){
	if (set_or_get = 0) player->player_health -= hp;
	if (set_or_get = 1) player->player_health += hp;

	//printf("%d\n", player->player_health);
}

card_t play_card_from_hand(player_t *player, card_t card){
	int errors[2] = {0, 0};

	if (can_put_card(card, player->player_manapool) != 1) 	errors[0] = 1;
	//if (can_put_card(card, player->player_manapool) != 1) errors[1] = 1;  TODO: Add check_card_existing, check_card_if_it_is_played

	if (errors[0] == 0 /*&& errors[1] == 0*/){
		draw_card(&player->player_deck, &card);
	} else {
		printf("No mana or other problem occurs\n");
	}
}

void turn_begin(player_t *player){

}

int main(){
	//player_t example_player = {{HERE_DECK_T_PAR}, {HERE_CARD_T_PAR}, {MAX_MANA,CURRENT_MANA}, HEALTH};
	card_t example_card = {"Almighty", 10, 10, 10};
	player_t example_player = {{example_card, 0}, example_card, {0, 30}, 30};
	//change_hp(&example_player, 10, 0);
	play_card_from_hand(&example_player, example_card);
}