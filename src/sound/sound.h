#include <SDL2/SDL.h>
#include <math.h>
#include <stdio.h>

#define SAMPLE_RATE 44100
#define FREQUENCY 800.0
#define DOT_DURATION_MS 50
#define DASH_DURATION_MS 150

void play_tone(int ms);
