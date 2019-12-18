#!/usr/bin/python3
def divisible_by_2(my_list=[]):
    new = [len(my_list)]
    for i in my_list:
        if i % 2 == 0:
            new[i] = True
        else:
            new[i] = False
    return new
