with open(r"level3/level3_example.in", encoding="UTF-8") as f:
    lines = f.readlines()

class currencies:
    def __init__(self, coins: list):
        self.currency_list = coins


    def find_amounts(self, number: int):
        result = ""
        for i in range(len(self.currency_list) - 1, 0, -1):
            fit_in_number = number // self.currency_list[i]
            number -= fit_in_number * self.currency_list[i]
            if fit_in_number != 0:
                result += str(fit_in_number) + "x" + str(self.currency_list[i]) + " "
            return result

output = ""
for i in range(2, len(lines) - 1):
    coins = lines[i].strip().split(" ")
    coins = list(map(int, coins))

    currency = currencies(coins)

    for i in range(1, 100):
        result = currency.find_amounts(i)

#    for i in result:
 #       output += str(i[0]) + " "
  #      output += str(i[1]) + "\n"


print(output)

with open("out/out_1.out", "w") as f:
    f.write(output)



