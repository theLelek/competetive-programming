def get_tiles(input :str):
    splitted = input.split("\n")
    tiles = []
    for line in splitted:
        current = []
        current_splitted = line.split(",")
        current.append(int(current_splitted[0]))
        current.append(int(current_splitted[1]))
        tiles.append(current)
    return tiles

def calclulate_area(a, b):
    # x, y format
    x = abs(a[0] - b[0]) + 1
    y = abs(a[1] - b[1]) + 1
    return x * y


def get_largest_rectangle(tiles):
    largest_area = -1
    for i in range(len(tiles)):
        for j in range(i + 1, len(tiles)):
            largest_area = max(largest_area, calclulate_area(tiles[i], tiles[j]))
    return largest_area


def main(input: str):
    tiles = get_tiles(input)
    print(tiles)
    largest_area = get_largest_rectangle(tiles)
    return largest_area



if __name__ == '__main__':
    path = "small_input.txt"
    with open(path, "r") as file:
        input = file.read().strip()
    print(main(input))
