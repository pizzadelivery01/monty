#!/usr/bin/python3
if __name__ == "__main":
    from sys import argv
    sum = 0
    for i in range(1, len(argv)):
       sum = sum + int(argv[i])
    print("{:d}".format(sum))
