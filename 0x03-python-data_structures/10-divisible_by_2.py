Learn more or give us feedback
#!/usr/bin/python3
def divisible_by_2(my_list=[]):
     for a in my_list:
         if a % 2 == 0:
             my_list[a] = True
         else:
             my_list[a] = False
    return my_list
