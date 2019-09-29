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

