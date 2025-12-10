#include "../Header/game.h"
#include "../Header/init.h"
#include "../Header/button.h"

bool GameCreate(struct Game **game)
{
	*game = calloc(1, sizeof(struct Game));
	if (*game == NULL) {SDL_Log("Could not allocate game %s: ", SDL_GetError()); return APP_FAILURE;}
   
    if (!InitGame(*game)) {SDL_Log("Could not initialize game %s: ", SDL_GetError()); return APP_FAILURE;}
	if (!InitAssets(*game)) {SDL_Log("Could not initialize assets %s: ", SDL_GetError()); return APP_FAILURE;}

	return APP_CONTINUE;
}

void GameRender(struct Game *game)
{
    SDL_RenderClear(game->renderer);
    SDL_RenderTexture(game->renderer, game->bkg.texture, NULL, &game->bkg.rect);

	SDL_RenderTexture(game->renderer, game->button1.texture, NULL, &game->button1.rect);
    SDL_RenderTexture(game->renderer, game->button2.texture, NULL, &game->button2.rect);
    SDL_RenderTexture(game->renderer, game->button3.texture, NULL, &game->button3.rect);
	SDL_RenderTexture(game->renderer, game->button4.texture, NULL, &game->button4.rect);
	printf("Button 4 rect: %f, %f\n", game->button4.rect.x, game->button4.rect.w);
    SDL_RenderPresent(game->renderer);	
}

void GameEvent(struct Game *game)
{
	while (SDL_PollEvent(&game->event))
	{
		switch (game->event.type)
		{
			case SDL_EVENT_KEY_DOWN:
				switch (game->event.key.scancode)
				{
					case SDL_SCANCODE_ESCAPE:
						game->isRunning = false;
						break;
				    case SDL_SCANCODE_W:
						break;
					default:
						break;
				}
		    case SDL_EVENT_MOUSE_BUTTON_DOWN:
				game->mouse.pressedButton = game->event.button.button;
				game->mouse.x = game->event.button.x;
				game->mouse.y = game->event.button.y;
				break;
			default:
				break;
		}

	}
    switch(game->mouse.pressedButton)
    {
		case 1:
		    if(IsColliding(game->mouse, game->button2)) {printf("This is left click on button 2\n");}
			if(IsColliding(game->mouse, game->button1)) {printf("This is left click on button 1\n");}
		    if(IsColliding(game->mouse, game->button3)) {printf("This is left click on button 3\n");}
	    break;			    
		case 4:
		    printf("This is right click\n");
		    break;
		default:
		    break;
	}
}

void GameFlow(struct Game *game)
{
	while (game->isRunning)
	{
		//printf("Mouse Coor: %f - %f\n", game->mouse.x, game->mouse.y);
		GameRender(game);
		GameEvent(game);
		SDL_Delay(100);
	}
}

void GameCleanup(struct Game *game)
{
	if (game->renderer) {SDL_DestroyRenderer(game->renderer);	game->renderer = NULL;}
	if (game->window) {SDL_DestroyWindow(game->window); 		game->window = NULL;}
	free(game);
	SDL_Quit();	
}
