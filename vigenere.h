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
