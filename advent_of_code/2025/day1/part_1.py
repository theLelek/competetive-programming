# 0 - 1 = 99
# starts at 50

def turn(line: str, point: int):
    if line[0] == "R":
        return point + int(line[1:])
    else:
        l = line[1:]
        return point - int(l)


def main():
    path = "input.txt"
    password = 0
    point = 50
    with open(path, "r") as file:
        input = file.read().strip()

    for line in input.split("\n"):
        point = turn(line, point)
        if point > 99:
            point = point % 100
        while point < 0:
            point += 100

        if point == 0:
            password += 1

    return password


if __name__ == '__main__':
    print(main())
