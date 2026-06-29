# ranges seperated by ,
#
def contains_string_only(s: str, sequence: str):
    for i in range(0, len(s), len(sequence)):
        if s[i:i+len(sequence)] != sequence:
            return False
    return True


def is_invalid(inp: int):
    converted = str(inp)
    s = ""

    for i in converted[:len(converted)//2]:
        s += i
        if contains_string_only(converted, s):
            return True
    return False


def get_sum_of_invalid_ids(input: str):
    splitted = input.split("-")
    count = 0
    for i in range(int(splitted[0]), int(splitted[1]) + 1, 1):
        if is_invalid(int(i)):
            print(i)
            count += int(i)
    return count

def main(input: str):
    splitted = input.split(",")
    invalid_sum = 0
    for item in splitted:
        invalid_sum += get_sum_of_invalid_ids(item)
#        print("sum=" , invalid_sum)
    return invalid_sum


if __name__ == '__main__':
    path = "input.txt"
    with open(path, "r") as file:
        input = file.read().strip()
    print(main(input))
