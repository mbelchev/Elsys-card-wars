#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate (int n){
	time_t t;
	int i, dmg, hp, mana, hp_max, mana_max;
	char name[10];
	FILE *wf;
	FILE *rf;
	wf = fopen("generated_cards.csv", "w");
	rf = fopen("names.txt", "r");
	srand((unsigned) time(&t));
	for (i = 1; i <= n; ++i) {
		dmg = rand() % 9 +1;

		hp_max = dmg * 2;
		if(hp_max >= 12){
			hp_max = 11;
		}
		hp = rand() & hp_max;
		hp+=1;

		mana_max = (dmg + hp)/2;
		mana_max+=1;
		if(mana_max >= 10){
			mana_max = 9;
		}
		mana = rand() % mana_max;
		mana+=1;
		fscanf(rf, "%s\n", name);
		fprintf(wf, "%s,%d,%d,%d\n", name, dmg, hp, mana);
	}
   

	fclose(rf);
   	fclose(wf);
}
