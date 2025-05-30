#include "./sound.h"

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
