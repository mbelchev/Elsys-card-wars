#include <stdio.h>

#include "player.h"
#include "board.h"

int main() {
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
    
    card_t test = {"test", 100, 100, 100};
    
    card_t pl2_1 = {"luk", 1, 10, 1};
    card_t pl2_2 = {"sirene", 2, 10, 2};
    card_t pl2_3 = {"chushka", 3, 10, 3};
    card_t pl2_4 = {"krastavica", 4, 10, 4};
    card_t pl2_5 = {"domati", 5, 10, 5};
    
    //PUSHING CARDS:
    init_deck(&player2.player_deck);
    init_deck(&player1.player_deck);
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
    
  
    //For testing deck:
    //print_deck(&player2.player_deck);
  
    
    //HAND
    
        //tegli ot deck v hand 5 karti
//    int i;
//    for(i=1; i<=5; i++){
//        draw_card(&player2.player_deck);
//    }
    
    
    board_t player1_board, player2_board;
    init_board(&player1_board);
    init_board(&player2_board);
    
    
    
    play_card(&player1_board, &player1, player1.player_deck.deck[1], 5, 1);
    play_card(&player1_board, &player1, player1.player_deck.deck[3], 2, 1);

    play_card(&player2_board, &player2, player2.player_deck.deck[1], 1, 2);
    
    print_board(&player1_board, player1, &player2_board, player2);
    return 0;
}

