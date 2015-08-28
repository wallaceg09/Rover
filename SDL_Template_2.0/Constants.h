#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <SDL.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_POSITION_X = SDL_WINDOWPOS_UNDEFINED;
const int SCREEN_POSITION_Y = SDL_WINDOWPOS_UNDEFINED;
const Uint32 SCREEN_WINDOW_FLAGS = SDL_WINDOW_SHOWN;
const Uint32 SDL_INIT_FLAGS = SDL_INIT_VIDEO;

#pragma region  Game Constants
const float ROOM_SIZE_INCREMENT = 32.0;
#pragma endregion

#endif