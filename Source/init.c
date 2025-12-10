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

bool InitAssets(struct Game *game)
{
    game->surface = SDL_LoadBMP("Assets/bkg.bmp");
	if(!game->surface){SDL_Log("Could not find background image - %s: ", SDL_GetError()); return APP_FAILURE;}
    game->bkg.rect.w = game->surface->w; game->bkg.rect.h = game->surface->h;

	game->bkg.texture = SDL_CreateTextureFromSurface(game->renderer, game->surface);
	if (!game->bkg.texture) {SDL_Log("Could not apply background image to texture - %s: ", SDL_GetError()); return APP_FAILURE;}

	if(!InitApply(game->button4, "Assets/4button.bmp", game->surface, game->renderer)){return APP_FAILURE;}
    game->button4.rect.x=100; game->button4.rect.y=300;
	
	return APP_CONTINUE;
}

bool InitApply(Entity entity, char* imageAdress, SDL_Surface *surface, SDL_Renderer *renderer)
{
    surface = SDL_LoadBMP(imageAdress);
	if(!surface){SDL_Log("Could not find bmp image of %s - %s: ",entity.name ,SDL_GetError()); return APP_FAILURE;}
    entity.rect.w = surface->w; entity.rect.h = surface->h;
	
	entity.texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!entity.texture) {SDL_Log("Could not apply %s image to texture - %s: ",entity.name, SDL_GetError()); return APP_FAILURE;}

	return APP_CONTINUE;
}


