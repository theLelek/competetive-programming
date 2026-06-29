# 1 line = 1 bank of batteries
#


def main(input: str):
    sum = 0
    for line in input.split("\n"):
        max_number = -1
        index_i = 0
        for i in line:
            number_i = int(i)
            index_i += 1
            for j in line[index_i:]:
                number_j = int(j)
                current_number = int(i + j)
                max_number = max(max_number, current_number)
        sum += max_number
        print(max_number)
    return sum

if __name__ == '__main__':
    path = "input.txt"
    with open(path, "r") as file:
        input = file.read().strip()
    print(main(input))
