#ifndef GAME_H
#define GAME_H

#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define BUTTON_COUNT 15
#define APP_FAILURE 0
#define APP_SUCCESS 1
#define APP_CONTINUE 1
#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 900

typedef struct 
{
    int x;
	int y;
} Vector2;

typedef struct
{
    float x;
	float y;
	int pressedButton;
}Mouse;

typedef struct
{
    char* name;
    SDL_Texture *texture;
	SDL_FRect rect;
}Entity;

struct Game
{
    Mouse mouse;
	bool isRunning;
	
	SDL_Window *window;
	SDL_Renderer *renderer;	
	SDL_Event event;
	SDL_Surface *surface;
	
	Entity bkg;
	Entity buttons[BUTTON_COUNT];
    Vector2 coor[BUTTON_COUNT];

	Entity button1;
	Entity button2;
	Entity button3;
    Entity button4;
    Entity button5;
    Entity button6;
    Entity button7;
    Entity button8;
    Entity button9;
    Entity button0;
    Entity buttond;
	Entity buttont;
	Entity buttonp;
	Entity buttonm;
	Entity buttone;
};

bool GameCreate(struct Game **game);
void GameRender(struct Game *game);
void GameEvent(struct Game *game);
void GameFlow(struct Game *game);
void GameCleanup(struct Game *game);
void GameRT(SDL_Renderer *renderer, Entity *entity);

#endif
