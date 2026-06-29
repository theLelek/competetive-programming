import numbers
from operator import length_hint

from pip._internal import operations


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


def reformat_numbers(numbers: list[list], x_idx: int):
    column = []
    for i in range(len(numbers)):
        column.append(numbers[i][x_idx])

    reformatted_numbers = []

    length_of_largest = len(str(max(column)))
    count = -1
    while True:
        contains_letters = False
        current_number = ""
        for i in column:
            str_number = str(i)
            if len(str_number) - count >= 0:
                contains_letters = True
                current_number += str_number[count]

        if not contains_letters:
            break
        reformatted_numbers.append(int(current_number))
        count -= 1


    return reformatted_numbers

def get_numbers(input: str):
    splitted = input.split("\n")
    numbers = []
    for j in range(len(splitted[0]) + 100):
        column = []
        for i in range(len(splitted)):
            if j >= len(splitted[i]):
                continue

            if splitted[i][0] == "*" or splitted[i][0] == "+":
                break
            char = splitted[i][j]

            if char.isdigit():
                column.append(char)
        numbers.append(column)

    return numbers


def calculate(numbers: list, operations: list):
    reformatted_numbers = []
    current_numbers = []
    numbers.append([])
    for i in numbers:
        if i == []:
            if current_numbers != []:
                reformatted_numbers.append(current_numbers)
            current_numbers = []
            continue

        current_number = string_list_to_int(i)
        current_numbers.append(current_number)

    sum = 0
    for i in range(len(reformatted_numbers)):
        foo = calculate_list(reformatted_numbers[i], operations[i])
        sum += foo
        print(foo)


    return sum

def string_list_to_int(ls: list):
    out = ""
    for i in ls:
        out += i
    return int(out)


def main(input):
    operations = get_operations(input)
    numbers = get_numbers(input)
    result = calculate(numbers, operations)
    return result

def calculate_list(numbers: list, operation: str) -> int:
    sum = numbers[0]
    for i in range(1, len(numbers), 1):
        if operation == "+":
            sum += numbers[i]
        elif operation == "*":
            sum = sum * numbers[i]
    return sum

if __name__ == '__main__':
    path = "large_input.txt"
    with open(path, "r") as file:
        input = file.read().strip()
    print(main(input))
