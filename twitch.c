//
// Created by Ruto on 9/11/2016.
//

#include "twitch.h"
#include "nr_socket.h"
#include "nr_func.h"

#define BUFFER_SIZE 512

#define TWITCH_IRC "irc.chat.twitch.tv"
#define TWITCH_PORT 6667

void nr_twitch_init(nr_twitch_ctx_t* ctx) {
    ctx->sock = nr_socket_create();
    nr_socket_connect(ctx->sock, TWITCH_IRC, TWITCH_PORT);
}

// Twitch IRC protocol @ https://github.com/justintv/Twitch-API/blob/master/IRC.md
void nr_twitch_login(nr_twitch_ctx_t* ctx, char* username, char* oath) {
    // Send Pass
    char *pass = concat("PASS ", oath);
    char *nick = concat("NICK ", username);
    nr_twitch_send(ctx, pass);
    nr_twitch_send(ctx, nick);
}

void nr_twitch_read(nr_twitch_ctx_t *ctx, void (*message_handler)(nr_twitch_ctx_t *, char*)) {
    char buffer[BUFFER_SIZE];
    int size = 1;
    while (size > 0) {
        size = nr_socket_read(ctx->sock, buffer, BUFFER_SIZE);
        buffer[size] = '\0';
        message_handler(ctx, buffer);
    }
}

void nr_twitch_send(nr_twitch_ctx_t *ctx, char* data) {
    nr_socket_send(ctx->sock, concat(data, "\n"), strlen(data)+1);
}