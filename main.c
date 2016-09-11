#include <stdio.h>
#include <mem.h>
#include "twitch.h"
#include "values.h" // username/oath token
#include "nr_func.h"
#include "nr_socket.h"

void message_handler(nr_twitch_ctx_t *, char*);

int main() {
    nr_twitch_ctx_t twitch_ctx;
    puts("INIT");
    nr_twitch_init(&twitch_ctx);
    puts("LOGIN");
    nr_twitch_login(&twitch_ctx, USERNAME, OATH_TOKEN);
    puts("READ");
    nr_twitch_read(&twitch_ctx, message_handler);
    //fgetc(stdin);
    puts("END");
    return 0;
}

void message_handler(nr_twitch_ctx_t *ctx, char* data) {
    printf("\n-Data: %sLength: %d-\n", data, strlen(data));
    // twitch send ping every 5 minutes to ensure active connection
    char* output;
    if (startswith(data, "PING")) {
        output = "PONG :tmi.twitch.tv";
        nr_twitch_send(ctx, output);
        puts("Pinged");
    }
    // For now, this determines successful login
    if (contains(data, "Welcome")) {
        puts("Logged in");
        //nr_twitch_send(ctx, "CAP REQ :twitch.tv/tags");
        nr_twitch_send(ctx, "JOIN #nullruto");
    }
    if (contains(data, "PRIVMSG")) {
        char *basemsg = substr(data, indexof(data, '#'), strlen(data));
        char *channel = substr(basemsg, 0, indexof(basemsg, ' '));
        char *msg = substr(basemsg, indexof(basemsg, ':')+1, strlen(basemsg));
        char *nick = substr(data, 1, indexof(data,'!'));
        printf("%s: %s => %s\n", channel, nick, msg);
    }
}