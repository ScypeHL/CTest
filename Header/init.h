#ifndef INIT_H
#define INIT_H

#include "../Header/game.h"

bool InitGame(struct Game *game);
bool InitAssets(struct Game *game);
bool InitApply(Entity entity, char* imageAdress ,SDL_Surface *surface, SDL_Renderer *renderer);

#endif
