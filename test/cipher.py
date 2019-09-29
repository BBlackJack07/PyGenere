#!/usr/bin/env python3
import vigenere as vig


if __name__=="__main__":
    with open("hamlet") as f:
        msg=f.read()
        cmsg=vig.encrypt(msg, "veryLoNgKEY")
        print(cmsg)
        print(vig.decrypt(cmsg, "veryLoNgKEY"))
        f.close()
