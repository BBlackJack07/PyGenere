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

#include <Python.h>
#include <stdlib.h>
#include "vigenere.h"

#define MAX_MSG_SIZE 200000

static PyObject*
pygenere_encrypt(PyObject* self, PyObject* args) {
    const char* msg_to_encrypt;
    const char* encryption_key;

    if(!PyArg_ParseTuple(args, "ss", &msg_to_encrypt, &encryption_key)) {
        return NULL;
    }
    char encrypted_msg[MAX_MSG_SIZE]="";
    vencrypt(msg_to_encrypt, encryption_key, encrypted_msg);
    return Py_BuildValue("s", encrypted_msg);
}

static PyObject*
pygenere_decrypt(PyObject* self, PyObject* args) {
    const char* msg_to_decrypt;
    const char* encryption_key;

    if(!PyArg_ParseTuple(args, "ss", &msg_to_decrypt, &encryption_key)) {
        return NULL;
    }
    char msg[MAX_MSG_SIZE]="";
    vdecrypt(msg_to_decrypt, encryption_key, msg);
    return Py_BuildValue("s", msg);
}

static PyMethodDef pygenereMethods[] = {
    {"encrypt", pygenere_encrypt, METH_VARARGS, "Encrypt string using vigenere cipher" },
    {"decrypt", pygenere_decrypt, METH_VARARGS, "Decrypt string using vigenere cipher" },
    {NULL,NULL,0,NULL}
};

static struct PyModuleDef pygeneremodule = {
    PyModuleDef_HEAD_INIT,
    "pygenere",
    NULL,
    -1,
    pygenereMethods
};

PyObject* PyInit_pygenere(void) {
    return PyModule_Create(&pygeneremodule); 
}

