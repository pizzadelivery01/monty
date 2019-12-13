#!/usr/bin/python3
import sys

if __name__ == "__main__":
    num = 1
    if len(sys.argv) == 2:
        for args in sys.argv[1:]:
            print('{:d} argument:'.format(len(sys.argv) - 1))
            print('{:d}: {:s}'.format(num, args))
    elif len(sys.argv) == 1:
        print('{:d} arguments.'.format(len(sys.argv) - 1))
    else:
        print('{:d} arguments:'.format(len(sys.argv) - 1))
        for args in sys.argv[1:]:
            print('{:d}: {:s}'.format(num, args))
            num = num + 1
