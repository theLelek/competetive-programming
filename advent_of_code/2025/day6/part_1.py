def string_list_to_int_list(string_list: list):
    int_list = []
    for string in string_list:
        if string.strip() == "":
            continue
        if string == "*" or string == "+":
            break
        int_list.append(int(string))
    return int_list


def to_2d_list(input: str) -> list:
    list_2d = []
    splitted = input.split("\n")
    for line in splitted:
        if line[0] == "*" or line[0] == "+":
            break
        line_splitted = line.split(" ")
        list_2d.append(string_list_to_int_list(line_splitted))
    return list_2d

def get_operations(input: str) -> list:
    operations = []
    splitted = input.split("\n")
    for i in splitted[-1]:
        if i == "*" or i == "+":
            operations.append(i)
    return operations

def main(input):
    numbers = to_2d_list(input)
    operations = get_operations(input)
    print(operations)
    out = 0
    for j in range(len(numbers[0])):
        column_sum = numbers[0][j]
        for i in range(1, len(numbers), 1):
            current_number = numbers[i][j]
            if operations[j] == "+":
                column_sum += current_number
            elif operations[j] == "*":
                column_sum = column_sum * current_number
        out += column_sum
    return out

if __name__ == '__main__':
    path = "large_input.txt"
    with open(path, "r") as file:
        input = file.read().strip()
    print(main(input))
