#include <stdio.h>
#include "sort.h"

void swap(card_t *card1, card_t *card2){
    card_t temp = *card1;
    *card1 = *card2;
    *card2 = temp;
}

void sort(player_t *player, int sort_by){
    printf("asd\n");
    printf("%d\n", player->player_deck.top);
    
    int i, k, top = player->player_deck.top + 1;
    card_t sort_array[top];
    
    for (i = 0; i < top; i++){
        sort_array[i].card_name = player->player_deck.deck[i].card_name;
        sort_array[i].card_dmg = player->player_deck.deck[i].card_dmg;
        sort_array[i].card_hp = player->player_deck.deck[i].card_hp;
        sort_array[i].card_mana = player->player_deck.deck[i].card_mana;
    }
    switch(sort_by){
        //sorting by dmg
        case 1: 
            for (i = 0; i < top - 1; i++){
                for ( k = 0; k < top - 1 - i; k++){
                    if (sort_array[k].card_dmg > sort_array[k+1].card_dmg){
                        swap(&sort_array[k], &sort_array[k+1]);
                    }
                }
            }
            break;
        //sorting by hp
        case 2: 
            for (i = 0; i < top - 1; i++){
                for ( k = 0; k < top - 1 - i; k++){
                    if (sort_array[k].card_hp > sort_array[k+1].card_hp){
                        swap(&sort_array[k], &sort_array[k+1]);
                    }
                }
            }
            break;
        //sorting by mana;
        case 3:
            for (i = 0; i < top - 1; i++){
                for ( k = 0; k < top - 1 - i; k++){
                    if (sort_array[k].card_mana > sort_array[k+1].card_mana){
                        swap(&sort_array[k], &sort_array[k+1]);
                    }
                }
            }
            break;
        default: printf("Please choose correct option\n"); break;
    }
    FILE *fp = fopen("cards.csv", "w+");
    for (i = 0; i < top; i ++){
        fprintf(fp, "%s,%d,%d,%d\n", sort_array[i].card_name, 
                                     sort_array[i].card_dmg, 
                                     sort_array[i].card_hp,
                                     sort_array[i].card_mana);
    }
    fclose(fp);
}
