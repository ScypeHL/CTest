#include "../Header/game.h"

int main(void)
{
	struct Game *game = NULL;
	if(GameCreate(&game)) 
	{
		printf("App Succed!\n");
		game->isRunning = true;
		GameFlow(game);
	}
	else {printf("App Failed!\n");}
	GameCleanup(game);
	return 0;
}
