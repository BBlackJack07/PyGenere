/*
        PyGenere is a python extension module written in C wich allow you to encrypt/decrypt using Vigenere Cipher
        Copyright (C) 2019 Bastien Brunel

        This program is free software: you can redistribute it and/or modify
        it under the terms of the GNU General Public License as published by
        the Free Software Foundation, either version 3 of the License, or
        (at your option) any later version.

        This program is distributed in the hope that it will be useful,
        but WITHOUT ANY WARRANTY; without even the implied warranty of
        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
        GNU General Public License for more details.

        You should have received a copy of the GNU General Public License
        along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "vigenere.h"

static const char* AVALAIBLE_CHARS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ";
static const int   LENGHT = 63;
static char** vigenere_square;

static void set_vigenere_square()
{
    vigenere_square = malloc(sizeof(char*) * (LENGHT+1));
    for (int i = 0; i < LENGHT; i++) {
        vigenere_square[i] = malloc(LENGHT+1);
        for (int j = 0; j < LENGHT; j++) {
            vigenere_square[i][j] = AVALAIBLE_CHARS[(j+i) % LENGHT];
        } 
    }
}

static void free_vigenere_square()
{
    for (int i = 0; i < LENGHT; i++) {
        free(vigenere_square[i]);
    }
    free(vigenere_square);
    vigenere_square = NULL;
}

static int findIndex(const char c) 
{
    for (unsigned int i = 0; i < (unsigned int)LENGHT; i++) {
        if (c == AVALAIBLE_CHARS[i]) return (int)i; 
    }
    return -1; 
}

static bool isavalaible(const char c) { return (isalnum(c) || c == ' '); }

static char get_vigenere_encrypt_char(const char c, const int position, const char* key, const int key_size)
{
    char c_to_return = 0x00;
    int row = findIndex(key[position % key_size]);
    int column = findIndex(c);
    if ((0 <= row) && (row < LENGHT) && (0 <= column) && (column < LENGHT)) {
        c_to_return = vigenere_square[row][column];
    }
    return c_to_return;
}

static char get_vigenere_decrypt_char(const char c, const int position, const char* key, const int key_size)
{
    char c_to_return = c;
    int column = findIndex(key[position % key_size]);
    for (int i = 0; i < LENGHT; i++) {
        if (vigenere_square[i][column] == c) {
            c_to_return = AVALAIBLE_CHARS[i];
            break;
        }
    }
    return c_to_return;
}


void vencrypt(const char* msg, const char* key, char* encrypted_msg)
{
    set_vigenere_square();
    const size_t msg_size = strlen(msg);
    const size_t key_size = strlen(key); 
    
    for (unsigned int i = 0; i < (unsigned int)msg_size; i++)
    {
        if (isavalaible(msg[i]))
        {
            encrypted_msg[i] = get_vigenere_encrypt_char(msg[i], i, key, (int)key_size);
        }
        else
            encrypted_msg[i] = msg[i];
    }
    free_vigenere_square();
}

void vdecrypt(const char* encrypted_msg, const char* key, char* msg)
{
    set_vigenere_square();
    const size_t msg_size = strlen(encrypted_msg);
    const size_t key_size = strlen(key);

    for (unsigned int i = 0; i < (unsigned int)msg_size; i++)
    {
        if (isavalaible(encrypted_msg[i]))
        {
            msg[i] = get_vigenere_decrypt_char(encrypted_msg[i], i, key, (int)key_size);
        }
        else
            msg[i] = encrypted_msg[i];
    }
    free_vigenere_square();
}

