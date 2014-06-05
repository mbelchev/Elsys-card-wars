#include <stdio.h>
#include "game.h"

int main() {
    board_t player1_board, player2_board;
    player_t player1, player2;
    
    char name1[30], name2[30], pa[1];
    int option1, option2, option3, option4, finished = 0;
    int card_no, card_pos;
    int n;
    
    player1.player_manapool.current_mana = 10;
    player1.player_health = 30;
    
    player2.player_manapool.current_mana = 10;
    player2.player_health = 30;
    
    //CARDS:
    card_t pl1_1 = {"kufte", 1, 10, 1};
    card_t pl1_2 = {"kebabche", 2, 10, 2};
    card_t pl1_3 = {"nadenica", 3, 10, 3};
    card_t pl1_4 = {"purjola", 4, 10, 4};
    card_t pl1_5 = {"skara", 5, 10, 5};
    card_t pl1_6 = {"krenwirsh", 6, 10, 5};
    card_t pl1_7 = {"sudjuk", 7, 10, 5};
    card_t pl1_8 = {"lukanka", 8, 10, 5};
    card_t pl1_9 = {"salam", 9, 10, 5};
    card_t pl1_10 = {"bira", 100, 100, 1};
    
    card_t pl2_1 = {"luk", 1, 10, 1};
    card_t pl2_2 = {"sirene", 2, 10, 2};
    card_t pl2_3 = {"chushka", 3, 10, 3};
    card_t pl2_4 = {"krastavica", 4, 10, 4};
    card_t pl2_5 = {"domati", 5, 10, 5};
    card_t pl2_6 = {"maslini", 6, 10, 5};
    card_t pl2_7 = {"marula", 7, 10, 5};
    card_t pl2_8 = {"morkowi", 8, 10, 5};
    card_t pl2_9 = {"kartofi", 9, 10, 5};
    card_t pl2_10 = {"kambi", 10, 10, 5};
 
    //INIT:
    init_deck(&player1.player_deck);
    init_deck(&player2.player_deck);
    
    init_board(&player1_board);
    init_board(&player2_board);
    
    //PUSHING CARDS:
    push_card(pl1_1, &player1.player_deck);
    push_card(pl1_2, &player1.player_deck);
    push_card(pl1_3, &player1.player_deck);
    push_card(pl1_4, &player1.player_deck);
    push_card(pl1_5, &player1.player_deck);
    push_card(pl1_6, &player1.player_deck);
    push_card(pl1_7, &player1.player_deck);
    push_card(pl1_8, &player1.player_deck);
    push_card(pl1_9, &player1.player_deck);
    push_card(pl1_10, &player1.player_deck);
    push_card(pl2_1, &player2.player_deck);
    push_card(pl2_2, &player2.player_deck);
    push_card(pl2_3, &player2.player_deck);
    push_card(pl2_4, &player2.player_deck);
    push_card(pl2_5, &player2.player_deck);
    push_card(pl2_6, &player2.player_deck);
    push_card(pl2_7, &player2.player_deck);
    push_card(pl2_8, &player2.player_deck);
    push_card(pl2_9, &player2.player_deck);
    push_card(pl2_10, &player2.player_deck);
    

    //MAIN MENU:
    printf("\x1b[32m ELSYS CARD WARS v2.0 beta by Marian Belchev and Hristo Dachev \x1b[0m \n\n");
    main_menu:
    printf("Choose option:\n");
    printf(" 1. Start game\n 2. Generate deck\n 3. Sort deck\n 4. Exit\n");
    scanf("%d", &option1);
    switch (option1) {
        //START GAME:
        case 1 :
            //NAMES:
            new_game:
            clrscr();
            printf("Player 1 name:");
            scanf("%s", name1);
            player1.player_name = name1;
            printf("Player 2 name:");
            scanf("%s", name2);
            player2.player_name = name2;
            
            //HAND:
            push_to_hand(&player1, 5);
            push_to_hand(&player2, 5);
            
            while(finished == 0){
                clrscr();
                option2:
                print_board(&player1_board, player1, &player2_board, player2);
                printf("\n Player 1 options: \n");
                printf(" 1. Play card\n 2. End turn\n");
                scanf("%d", &option2);
                
                while (option2 == 1){
                        printf ("Chose a card to play: ");
                        scanf ("%d", &card_no);
                        printf ("Chose a position on the board: ");
                        scanf ("%d", &card_pos);
                        play_card(&player1_board, &player1, player1.player_hand[card_no], card_pos, 1);
                        delete_from_hand(&player1, card_no);
                        clrscr();
                        print_board(&player1_board, player1, &player2_board, player2);
                        printf("\n Player 1 options: \n");
                        printf(" 1. Play card\n 2. End turn\n");
                        scanf("%d", &option2);
                }    
                if (option2 == 2){
                    clrscr(); option3:  
                    print_board(&player1_board, player1, &player2_board, player2);
                    printf("\n Player 2 options: \n");
                    printf(" 1. Play card\n 2. End turn\n");
                    scanf("%d", &option3);
                    while(option3 == 1){
                        printf ("Chose a card to play: ");
                        scanf ("%d", &card_no);
                        printf ("Chose a position on the board: ");
                        scanf ("%d", &card_pos);
                        play_card(&player2_board, &player2, player2.player_hand[card_no], card_pos, 2);
                        delete_from_hand(&player2, card_no);
                        clrscr();
                        print_board(&player1_board, player1, &player2_board, player2);
                        printf("\n Player 2 options: \n");
                        printf(" 1. Play card\n 2. End turn\n");
                        scanf("%d", &option3);
                    }
                    if (option3 == 2){
                        //kartite da se biqt
                        fight(&player1_board, &player2_board, &player1, &player2);
                        push_to_hand(&player1, 1);
                        push_to_hand(&player2, 1);
                        if (player1.player_health <= 0 || player2.player_health <= 0) finished = 1; 
                    }else{
                        clrscr();
                        printf("\t \x1b[31m Please choose correct OPTION! \x1b[0m \n\n");
                        goto option3;
                    }
                }else{        
                    clrscr();
                    printf("\t \x1b[31m Please choose correct OPTION! \x1b[0m \n\n");
                    goto option2;
                }
            }
            clrscr();
            if (player1.player_health <= 0) printf("\x1b[36m %s \x1b[32m WON THE GAME!\x1b[0m \n\n", name2);
            if (player2.player_health <= 0) printf("\x1b[36m %s \x1b[32m WON THE GAME!\x1b[0m \n\n", name1); 
            goto main_menu;
            break;
            
        //GENERATE:
        case 2 :
            printf("How many cards to generate: ");
            scanf("%d", &n);
            generate(n);
            clrscr();
            printf("\x1b[31m Generate complete! \x1b[0m\n \n\n");
            goto main_menu;
        //SORT:
        case 3 :   
            printf("Sort by:\n");
            printf(" 1. DMG\n 2. HP\n 3. Mana\n");
            scanf("%d", &option4);
            switch(option4){
                case 1: sort(&player1, 1); break; //sort by dmg
                case 2: sort(&player1, 2); break; //sort by hp
                case 3: sort(&player1, 3); break; //sort by mana
            }
            clrscr();
            printf("\x1b[31m Sort complete! \x1b[0m\n \n\n");
            goto main_menu;
            
        //EXIT:    
        case 4 :
            clrscr();
            break;   
        
        default: 
            clrscr();
            printf("\t \x1b[31m Please choose correct OPTION!!!\x1b[0m\n\n");
            goto main_menu;
            break;
    }
    return 0;
}