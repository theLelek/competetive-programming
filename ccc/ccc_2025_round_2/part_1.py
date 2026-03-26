# format: x y

def get_integer_pairs(input: str, height) -> list:
    out = []
    splitted = input.splitlines()
    for line in splitted[height + 2:]:
        current = line.split(",")
        a = int(current[0])
        b = int(current[1])
        current = [a, b]
        out.append(current)
    return out

def get_matrix(input: str, height: int) -> list:
    splitted = input.split("\n")
    out = []
    for i in range(1, height + 1):
        current = []
        for j in range(len(splitted[i])):
            current.append(splitted[i][j])
        out.append(current)
    return out


def main(input: str):
    splitted = input.split("\n")
    height = int(splitted[0])
    matrix = get_matrix(input, height)
    int_pairs = get_integer_pairs(input, height)

    out = ""
    for pair in int_pairs:
        out += matrix[pair[1]][pair[0]] + "\n"
    return out

if __name__ == '__main__':
    with open("level1(4)/level1_5.in") as f:
        input = f.read()
    out = main(input)
    print(out)
    with open("out.txt", "w") as f:
        f.write(out)