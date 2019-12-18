Learn more or give us feedback
#!/usr/bin/python3
def divisible_by_2(my_list=[]):
     new = [len(my_list)]
     for a in my_list:
         if a % 2 == 0:
             new[a] = True
         else:
             new[a] = False
    return new
