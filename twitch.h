//
// Created by Ruto on 9/11/2016.
//

#ifndef CTWITCHBOT_TWITCH_H
#define CTWITCHBOT_TWITCH_H

#include <stdlib.h>

typedef struct nr_twitch_channel {
    char* name;
    int flags;
} nr_twitch_channel_t;

typedef struct nr_twitch_ctx {
    int sock;
    nr_twitch_channel_t *channels;
} nr_twitch_ctx_t;

void nr_twitch_init(nr_twitch_ctx_t *);

void nr_twitch_login(nr_twitch_ctx_t *, char*, char*);

void nr_twitch_read(nr_twitch_ctx_t *, void (*)(nr_twitch_ctx_t *,char*));

void nr_twitch_send(nr_twitch_ctx_t *, char*);

#endif //CTWITCHBOT_TWITCH_H
