#ifndef INIT_H
#define INIT_H

#include "../Header/game.h"

bool InitGame(struct Game *game);
bool InitAssets(struct Game *game);
bool InitGrid(Vector2 *coor);
bool InitApply(Entity *entity, char* imageAdress ,SDL_Surface *surface, SDL_Renderer *renderer, Vector2 pos);
bool InitApplyText(Text *entity, char* fontAdress ,SDL_Surface *surface, SDL_Renderer *renderer, Vector2 pos, char* string);
#endif
