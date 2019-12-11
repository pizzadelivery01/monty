#!/usr/bin/python3
import random
import math
number = random.randint(-10000, 10000)
ld = math.floor(math.fabs(number)) % 10
if ld > 5:
    str = "and is greater than 5"
elif ld == 0:
    str = "and is 0"
else:
    str = "and is less than 6 and not 0"
print('Last digit of {} is {} {}'.format(number, ld, str))
