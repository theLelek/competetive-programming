def plus_one(number: int):
    def add_one(i: int):
        return i + 1

    return add_one(number)


f = plus_one
print(f(2))



