def number_of_adjacencies(grid, x: int, y: int):
    count = 0
    if  x + 1 < len(grid[0]) and grid[y][x + 1] == '@':
        count += 1
    if x - 1 >= 0 and grid[y][x - 1] == '@':
        count += 1
    if y + 1 < len(grid) and grid[y + 1][x] == '@':
        count += 1
    if y - 1 >= 0 and grid[y - 1][x] == '@':
        count += 1
    if x + 1 < len(grid[0]) and y + 1 < len(grid) and grid[y + 1][x + 1] == '@':
        count += 1
    if x - 1 >= 0 and y - 1 >= 0 and grid[y - 1][x - 1] == '@':
        count += 1
    if x - 1 >= 0 and y + 1 < len(grid) and grid[y + 1][x - 1] == '@':
        count += 1
    if x + 1 < len(grid) and y - 1 >= 0 and grid[y - 1][x + 1] == '@':
        count += 1
    return count


def main(input):
    count = 0
    for index1 in range(len(input)):
        for index2 in range(len(input[index1])):
            if input[index1][index2] == '@':
                if number_of_adjacencies(input, index2, index1) < 4:
                    count += 1
    return count

if __name__ == '__main__':
    path = "large_input.txt"
    with open(path, "r") as file:
        input = file.read().strip()
    print(main(input.split("\n")))
