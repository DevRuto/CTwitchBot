//
// Created by Ruto on 9/11/2016.
//

#ifndef CTWITCHBOT_NR_FUNC_H
#define CTWITCHBOT_NR_FUNC_H

#include <stdbool.h>

bool startswith(const char *str, const char *pre);

char* concat(char *str1, char *str2);

bool contains(char*, char*);

int indexof(char*, char);

char* substr(char*, int, int);

#endif //CTWITCHBOT_NR_FUNC_H
