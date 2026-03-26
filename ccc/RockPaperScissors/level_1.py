def get_winner(a, b):
    # a wins
    if a == "S" and (b == "S" or b == "P"):
        return "S"
    elif a == "P" and (b == "P" or b == "R"):
        return "P"
    elif a == "R" and (b == "R" or b == "S"):
        return "R"

    elif a == "S" and b == "R":
        return "R"
    elif a == "R" and b == "P":
        return "P"
    elif a == "P" and b == "S":
        return "S"


def main(input: str):
    splitted = input.split("\n")
    out = ""
    for line in splitted[1:]:
        a = line[0]
        b = line[1]
        out += get_winner(a, b) + "\n"
    return out


    return input

if __name__ == '__main__':
    with open("input.txt") as f:
        input = f.read().strip()

    output = main(input)
    with open("output.txt", "w") as f:
        f.write(output)
