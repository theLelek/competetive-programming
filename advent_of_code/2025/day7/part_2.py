def count_splits(grid, col, row, dp):
    height = len(grid)
    width = len(grid[0])

    if col < 0 or col >= width or row >= height:
        return 1

    timelines = 0
    if (col, row) in dp:
        return dp[(col, row)]

    current_letter = grid[row][col]
    if current_letter == ".":
        timelines += count_splits(grid, col, row + 1, dp)
    elif current_letter == "^":
        timelines += count_splits(grid, col - 1, row + 1, dp)
        timelines += count_splits(grid, col + 1, row + 1, dp)

    dp[(col, row)] = timelines
    return timelines

def main(grid):
    start_col = grid[0].index('S')
    return count_splits(grid, start_col, 1, {})

if __name__ == '__main__':
    path = "large_input.txt"
    with open(path, "r") as file:
        input = file.read().strip()
    print(main(input.split("\n")))