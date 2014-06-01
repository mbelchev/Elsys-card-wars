#include <stdio.h>

#include "player.h"
#include "board.h"

int main() {
    player_t player1, player2;
    player1.player_name = "Gosho1";
    player1.player_manapool.current_mana = 9;
    player1.player_health = 30;
    
    player2.player_name = "Pesho2";
    player2.player_manapool.current_mana = 1;
    player2.player_health = 30;
    
    //CARDS:
    card_t pl1_1 = {"Pl1_card 1", 1, 10, 1};
    card_t pl1_2 = {"Pl1_card 2", 2, 10, 2};
    card_t pl1_3 = {"Pl1_card 3", 3, 10, 3};
    card_t pl1_4 = {"Pl1_card 4", 4, 10, 4};
    card_t pl1_5 = {"Pl1_card 5", 5, 10, 5};
    
    card_t pl2_1 = {"Pl2_card 1", 1, 10, 1};
    card_t pl2_2 = {"Pl2_card 2", 2, 10, 2};
    card_t pl2_3 = {"Pl2_card 3", 3, 10, 3};
    card_t pl2_4 = {"Pl2_card 4", 4, 10, 4};
    card_t pl2_5 = {"Pl2_card 5", 5, 10, 5};
    
    //PUSHING CARDS:
    init_deck(&player1.player_deck);
    push_card(pl1_1, &player1.player_deck);
    push_card(pl1_2, &player1.player_deck);
    push_card(pl1_3, &player1.player_deck);
    push_card(pl1_4, &player1.player_deck);
    push_card(pl1_5, &player1.player_deck);
    
    
    init_deck(&player2.player_deck);
    push_card(pl2_1, &player2.player_deck);
    push_card(pl2_2, &player2.player_deck);
    push_card(pl2_3, &player2.player_deck);
    push_card(pl2_4, &player2.player_deck);
    push_card(pl2_5, &player2.player_deck);
    
    //For testing deck:
    //print_deck(&player2.player_deck);
    
    
    board_t player1_board, player2_board;
    //BOARD
    init_board(&player1_board);
    init_board(&player2_board);
    
    play_card(&player1_board, player1, pl1_1, 5, 1);
    //play_card(&player1_board, player1, pl1_2, 4, 1);
    //play_card(&player1_board, player1, pl1_3, 3, 1);
    play_card(&player1_board, player1, pl1_4, 2, 1);
    //play_card(&player1_board, player1, pl1_5, 1, 1);
    
    
    
    //print_board(&player2_board, player2, 2);
    return 0;
}

