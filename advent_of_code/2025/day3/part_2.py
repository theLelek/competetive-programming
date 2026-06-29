# 1 line = 1 bank of batteries
#
def list_to_number(ls):
    number = ""
    for item in ls:
        number += str(item)
    return int(number)

def get_biggest_number_of_line(line: str):
    max_number = -1
    index_i = 0
    stack = []

    remaining_elements = len(line)

    for i in line:
        number_i = int(i)
        index_i += 1

        while len(stack) != 0 and stack[-1] < number_i and len(stack) - 1 + remaining_elements >= 12:
            stack.pop()

        if len(stack) < 12:
            stack.append(number_i)
        remaining_elements -= 1

    return list_to_number(stack)

def main(input: str):
    sum = 0
    for line in input.split("\n"):
        max_number = get_biggest_number_of_line(line)
        sum += max_number
        print(max_number)
    return sum

if __name__ == '__main__':
    path = "small_input.txt"
    with open(path, "r") as file:
        input = file.read().strip()
        print(main(input))
