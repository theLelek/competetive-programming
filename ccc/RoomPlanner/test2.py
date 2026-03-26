ls = [1,2,3,4,5]

for index1, value1 in enumerate(ls):
    for index2, value2 in enumerate(ls[index1:], start=index1):

        print(index1, index2)

