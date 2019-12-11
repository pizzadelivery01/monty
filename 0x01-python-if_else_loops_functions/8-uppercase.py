#!/usr/bin/python3
def uppercase(str):
    for letter in str:
        if letter >= 'a' and letter <= 'z':
            letter = chr(ord(letter - 32))
        print("{}".format(letter), end="")
    print('{}'.format(letter), end="\n")
