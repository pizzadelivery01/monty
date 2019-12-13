#!/usr/bin/python3
if __name__ == "__main":
    import sys
    sum = 0
    for i in range(len(sys.argv)):
        if i == 0:
            continue
        sum = sum + int(sys.argv[i])
    print('{:d}'.format(sum))
