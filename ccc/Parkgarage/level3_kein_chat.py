
def solve(input: str):
    splitted = input.split(" ")
    amount_parkplaetze = int(splitted[0])
    amount_cars = int(splitted[0])

    prices = []
    for i in input.split("\n")[1].split(" "):
        prices.append(int(i))
    print(prices)



def main():
    with open("level4/input.1", "r", encoding="UTF-8") as input_file:
        string_input = input_file.read().strip()

    output = solve(string_input)

    with open("output.txt", "w", encoding="UTF-8") as output_file:
        output_file.write(output)



if __name__ == '__main__':
    main()