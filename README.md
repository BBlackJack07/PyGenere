PyGenere module
===============

Python extension module written in C, it allows you to encrypt and decrypt using the Vigener Cipher.

## Installation
To install it just clone this repository and build this module with the following commands:
```sh
git clone https://github.com/BBlackJack07/PyGenere.git
cd PyGenere
python3 setup.py build
sudo python3 setup.py install
```

## Usage
For now, this module provides you two functions, `encrypt` and `decrypt` wich both expect two arguments: a string for the message to encrypt\decrypt and another string for the encryption key.

### Import
To use this module import it with the following line:
```python
import pygenere
# or
from pygenere import *
```

### Exemple
```python
import pygenere as pyg

print (pyg.encrypt("Hello", "world")
```
`==> 4sCwr`
```python
print (pyg.decrypt("4sCwr", "world")
```
`==> Hello`
