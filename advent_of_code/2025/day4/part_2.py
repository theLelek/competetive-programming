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
    number_of_removed = 0
    remove = []
    while(True):
        for i in range(0, len(remove), 2):
            input = change_string_list(input, remove[i], remove[i + 1], "x")
        remove = []

        count = 0
        for index1 in range(len(input)):
            for index2 in range(len(input[index1])):
                if input[index1][index2] == '@':
                    if number_of_adjacencies(input, index2, index1) < 4:
                        count += 1
                        remove.append(index1)
                        remove.append(index2)



        number_of_removed += count
        if count == 0:
            break
    return number_of_removed

def change_string_list(matrix, y, x, value: str):
    new_string = []
    for i in range(len(matrix)):
        new_string.append("")
        for j in range(len(matrix[i])):
            if i == y and j == x:
                new_string[i] += value
                continue
            new_string[i] += matrix[i][j]
    return new_string

def has_changed(changed, index1, index2):
    for i in range(0, len(changed), 2):
        if changed[i] == index1 and changed[i + 1] == index2:
            return True
    return False


if __name__ == '__main__':
    path = "large_input.txt"
    with open(path, "r") as file:
        input = file.read().strip()
    print(main(input.split("\n")))
