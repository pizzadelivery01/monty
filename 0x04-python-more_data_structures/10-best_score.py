#!/usr/bin/python3
def best_score(my_dict):
    if my_dict == {}:
        return (None)
    if isinstance(my_dict, dict) is False:
        return (None)
    return(max(my_dict, key=my_dict.get))
