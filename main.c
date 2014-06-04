#include <stdio.h>

#include "player.h"
#include "board.h"

int main() {
    board_t player1_board, player2_board;
    player_t player1, player2;
    
    player1.player_name = "Gosho1";
    player1.player_manapool.current_mana = 9;
    player1.player_health = 12;
    
    player2.player_name = "Shopska salata";
    player2.player_manapool.current_mana = 15;
    player2.player_health = 40;
    
    //CARDS:
    card_t pl1_1 = {"kufte", 1, 10, 1};
    card_t pl1_2 = {"kebabche", 2, 10, 2};
    card_t pl1_3 = {"nadenica", 3, 10, 3};
    card_t pl1_4 = {"purjola", 4, 10, 4};
    card_t pl1_5 = {"skara", 5, 10, 5};
    
    card_t pl2_1 = {"luk", 1, 10, 1};
    card_t pl2_2 = {"sirene", 2, 10, 2};
    card_t pl2_3 = {"chushka", 3, 10, 3};
    card_t pl2_4 = {"krastavica", 4, 10, 4};
    card_t pl2_5 = {"domati", 5, 10, 5};
 
    
    init_deck(&player2.player_deck);
    init_deck(&player1.player_deck);
    init_board(&player1_board);
    init_board(&player2_board);
    
    //PUSHING CARDS:
    push_card(pl1_1, &player1.player_deck);
    push_card(pl1_2, &player1.player_deck);
    push_card(pl1_3, &player1.player_deck);
    push_card(pl1_4, &player1.player_deck);
    push_card(pl1_5, &player1.player_deck);
    push_card(pl2_1, &player2.player_deck);
    push_card(pl2_2, &player2.player_deck);
    push_card(pl2_3, &player2.player_deck);
    push_card(pl2_4, &player2.player_deck);
    push_card(pl2_5, &player2.player_deck);
    
        push_to_hand(&player1, 5);
        push_to_hand(&player2, 5);    
        print_board(&player1_board, player1, &player2_board, player2);
    return 0;
}

