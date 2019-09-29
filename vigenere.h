#ifndef VIGENERE_CIPHER
#define VIGENERE_CIPHER

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define bool char
#define true 1
#define false 0

void vencrypt(const char* msg, const char* key, char* encrypted_msg);

void vdecrypt(const char* encrypted_msg, const char* key, char* msg);

#endif //VIGENERE_CIPHER
