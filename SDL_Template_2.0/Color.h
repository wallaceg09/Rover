#ifndef COLOR_H
#define COLOR_H

#include <SDL.h>

struct Color
{
	Uint8 Red;
	Uint8 Green;
	Uint8 Blue;
	Uint8 Alpha;
};

static const Color BLACK = Color{ 0x00, 0x00, 0x00, 0xFF };
static const Color WHITE = Color{ 0xFF, 0xFF, 0xFF, 0xFF };

#endif