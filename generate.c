#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){
	time_t t;
	int i, dmg, hp, mana, hp_max, mana_max;
	FILE *fp;
	fp = fopen("cards.csv", "w");
	srand((unsigned) time(&t));
	for (i = 1; i <= 30; ++i)
	{
		dmg = rand() % 9 +1;
		
		hp_max = dmg * 2 -1;
		if(hp_max > 12){
			hp_max = 11;
		}
		hp = rand() & hp_max + 1;

		mana_max = dmg + hp -1;
		if(mana_max > 10){
			mana_max = 9;
		}
		mana = rand() % mana_max +1;

		fprintf(fp, "NAME%d,%d,%d,%d\n", i, dmg, hp, mana);
	}
   


   fclose(fp);
	return 0;
}
