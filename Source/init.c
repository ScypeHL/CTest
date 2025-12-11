#include "../Header/init.h"

bool InitGame(struct Game *game)
{
	if(!SDL_Init(SDL_INIT_VIDEO)){SDL_Log("Could not initialize SDL %s: ", SDL_GetError()); return APP_FAILURE;}
    
	game->window = SDL_CreateWindow("My Poland",SCREEN_WIDTH,SCREEN_HEIGHT, 0);
	if (!game->window){SDL_Log("Could not create window %s: ", SDL_GetError()); return APP_FAILURE;}

	game->renderer = SDL_CreateRenderer(game->window, NULL);
	if (!game->renderer) {SDL_Log("Could not initialize renderer %s: ", SDL_GetError()); return APP_FAILURE;}

    return APP_CONTINUE;
}

bool InitGrid(Vector2 *coor)
{
    int level = 0;
    for(int i = 0; i < 15; i = i + 3)
	{
		for (int l = 0; l < 3; l++)
		{
		    coor[i + l % 3].x = 75 + 175 * l % 3;
		}
		coor[i - 2].y = 60 + 60 * level * 3;
		coor[i - 1].y = 60 + 60 * level * 3;
		coor[i].y = 60 + 60 * level;
		level++;
	}
}

bool InitAssets(struct Game *game)
{
    Vector2 starting = {.x = 0 ,.y = 0};
    if(!InitApply(&game->bkg, "Assets/bkg.bmp", game->surface, game->renderer, starting)){return APP_FAILURE;}
	
	char buf[256];
	for (int i = 0; i <= 9; i = i + 1)
	{
		snprintf(buf, sizeof(buf),"Assets/%dbutton.bmp", i);
	    char* sampleAdress = buf; 
		if(!InitApply(&game->buttons[i], sampleAdress, game->surface, game->renderer, game->coor[i])){return APP_FAILURE;}
	}
    SDL_DestroySurface(game->surface);
	return APP_CONTINUE;
}

bool InitApply(Entity *entity, char* imageAdress, SDL_Surface *surface, SDL_Renderer *renderer, Vector2 pos)
{
    surface = SDL_LoadBMP(imageAdress);
	if(!surface){SDL_Log("Could not find bmp image of %s - %s: ",entity->name ,SDL_GetError()); return APP_FAILURE;}
    entity->rect.w = surface->w; entity->rect.h = surface->h;
	entity->rect.x = pos.x; entity->rect.y = pos.y;
	
	entity->texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!entity->texture) {SDL_Log("Could not apply %s image to texture - %s: ",entity->name, SDL_GetError()); return APP_FAILURE;}

	return APP_CONTINUE;
}
