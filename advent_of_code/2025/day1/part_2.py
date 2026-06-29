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
        direction = line[0]
        distance = int(line[1:])

        step = 1 if direction == "R" else -1

        for j in range(distance):
            point = (point + step) % 100
            if point == 0:
                password += 1


    return password


if __name__ == '__main__':
    print(main())
