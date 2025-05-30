#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <SDL2/SDL.h>
#include <math.h>
#include "./translator.h"

#define SAMPLE_RATE 44100
#define FREQUENCY 800.0
#define DOT_DURATION_MS 50
#define DASH_DURATION_MS 150

void play_tone(int ms) {
    SDL_AudioSpec want, have;
    SDL_AudioDeviceID dev;
    int samples = SAMPLE_RATE * ms / 1000;
    float *buffer = malloc(sizeof(float) * samples);
    
    // Fill buffer with sine wave
    for (int i =0; i < samples; i++) {
        buffer[i] = 0.3f * sinf(2.0f * M_PI * FREQUENCY * i / SAMPLE_RATE);
    }

    SDL_memset(&want, 0, sizeof(want));
    want.freq = SAMPLE_RATE;
    want.format = AUDIO_F32SYS;
    want.channels = 1;
    want.samples = 1024;
    want.callback = NULL;

    dev = SDL_OpenAudioDevice(NULL, 0, &want, &have, 0);
    if (dev == 0) {
        fprintf(stderr, "Failed to open audio: %s\n", SDL_GetError());
        free(buffer);
        return;
    }

    SDL_PauseAudioDevice(dev, 0);
    SDL_QueueAudio(dev, buffer, samples * sizeof(float));
    SDL_Delay(ms);
    SDL_CloseAudioDevice(dev);
    free(buffer);
}

int get_input(char input[256]) {
    int c, counter = 0;
    while ((c = getchar()) != 'e') {
        if (c == 'j') {
            printf(".");
            input[counter] = '.';
            play_tone(DOT_DURATION_MS);
            counter++;
        }
        if (c == 'k') {
            printf("-");
            input[counter] = '-';
            play_tone(DASH_DURATION_MS);
            counter++;
        }
        if (c == 'f' || c == ' ') {
            printf(" ");
            input[counter] = ' ';
            SDL_Delay(DOT_DURATION_MS); // pause between letters
            counter++;
        }
    }
    return counter;
}

int main(void) {
    static struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    SDL_Init(SDL_INIT_AUDIO);

    char buffer[256];
    int counter = get_input(buffer);
    walk(buffer,counter);

    SDL_Quit();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return 0;
}

