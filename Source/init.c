#include "../Header/init.h"

bool InitGame(struct Game *game)
{
	if(!SDL_Init(SDL_INIT_VIDEO)){SDL_Log("Could not initialize SDL %s: ", SDL_GetError()); return APP_FAILURE;}
	if(!TTF_Init()){SDL_Log("Could not initialize SDL_TTF %s: ", SDL_GetError()); return APP_FAILURE;}
    
	game->window = SDL_CreateWindow("My Poland",SCREEN_WIDTH,SCREEN_HEIGHT, 0);
	if (!game->window){SDL_Log("Could not create window %s: ", SDL_GetError()); return APP_FAILURE;}

	game->renderer = SDL_CreateRenderer(game->window, NULL);
	if (!game->renderer) {SDL_Log("Could not initialize renderer %s: ", SDL_GetError()); return APP_FAILURE;}

    return APP_CONTINUE;
}

bool InitGrid(Vector2 *coor)
{
    for(int i = 0; i < 5; i = i + 1)
	{
		for (int l = 0; l < 3; l++)
		{
		    coor[3 * i + l].x = 75 + (175 * (l % 3));
			coor[3 * i + l].y = 260 + 120 * i + 1;
		}
	}
}

bool InitAssets(struct Game *game)
{
    Vector2 starting = {.x = 0 , .y = 0};
	Vector2 header = {.x = 75, .y = 60};
    
	if(!InitApply(&game->bkg, "Assets/bkg.bmp", game->surface, game->renderer, starting)){return APP_FAILURE;}
    
	if(!InitApplyText(&game->text, "Assets/Helvetica.ttf", game->surface, game->renderer, header, ""));

	char buf[256];
	for (int i = 0; i < 15; i = i + 1)
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
	if(!surface){SDL_Log("Could not find bmp image of %s - %s: ",imageAdress ,SDL_GetError()); return APP_FAILURE;}
    entity->rect.w = surface->w; entity->rect.h = surface->h;
	entity->rect.x = pos.x; entity->rect.y = pos.y;
	
	entity->texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!entity->texture) {SDL_Log("Could not apply %s image to texture - %s: ",imageAdress , SDL_GetError()); return APP_FAILURE;}

	return APP_CONTINUE;
}

bool InitApplyText(Text *text, char* fontAdress, SDL_Surface *surface, SDL_Renderer *renderer, Vector2 pos, char* string)
{
    SDL_Color COLOUR_WHITE = {190, 190, 190, 255};
	text->fontSize = 50;
	text->string = string;
    text->font = TTF_OpenFont(fontAdress, text->fontSize);
    if(!text->font) {SDL_Log("Could not find font file %s: ", SDL_GetError()); return APP_FAILURE;}

	surface = TTF_RenderText_Blended(text->font, string, 0, COLOUR_WHITE);
	if(!surface){SDL_Log("Could not find font in %s - %s: ",fontAdress ,SDL_GetError()); return APP_FAILURE;}
    text->rect.w = surface->w; text->rect.h = surface->h;
	text->rect.x = pos.x; text->rect.y = pos.y;
	
	text->texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!text->texture) {SDL_Log("Could not apply %s image to texture - %s: ",fontAdress , SDL_GetError()); return APP_FAILURE;}

	return APP_CONTINUE;
}
