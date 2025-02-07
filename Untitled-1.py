def func(list):
    list2 = []
    flag = True
    for i in range(len(list)-1):
        if list[i] > list[i+1] and flag: # getting smaller
            list2.append(list[i])
            flag = False
        elif list[i] < list[i+1] and not flag: # getting bigger
            list2.append(list[i])
            flag = True
    return list2


list = [1, 2, 3, 2, 1, 5, 7, 8, 7, 5, 3, 2, 1]
print(func(list))

#-__----------------------------#



