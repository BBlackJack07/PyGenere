from distutils.core import setup, Extension

module1 = Extension('pygenere', sources= ['pygeneremodule.c', 'vigenere.c'])
setup (name = "pygenere", version = "1.0", description = "Encryption/Decryption using Vigenere Cipher", ext_modules = [module1])
