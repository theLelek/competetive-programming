with open(r"level2/level2_5.in", encoding="UTF-8") as f:
    lines = f.readlines()

class currencies:
    def __init__(self, coins: list, amounts: list):
        self.coins_list = coins
        self.coins_set = set(coins[1:])
        self.amounts = amounts
        self.possible_amounts = self.createMap()


    def get_solution(self):


output = ""
for i in range(3, len(lines) -1, 2):
    coins = lines[i].strip().split(" ")
    coins = list(map(int, coins))

    amounts = lines[i + 1].strip().split(" ")
    amounts = list(map(int, amounts))



    obj = currencies(coins, amounts)

    result = obj.find_amounts()

    for i in result:
        output += str(i[0]) + " "
        output += str(i[1]) + "\n"


print(output)

with open("out/out_1.out", "w") as f:
    f.write(output)



