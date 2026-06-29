def count_splits(grid, col, row, seen_splitters, visited_beams):
    height = len(grid)
    width = len(grid[0])

    if col < 0 or col >= width or row >= height:
        return 0

    state = (col, row)
    if state in visited_beams:
        return 0
    visited_beams.add(state)

    while row < height:
        cell = grid[row][col]

        if cell in ('.', 'S'):
            row += 1
            continue

        pos = (col, row)
        total = 0
        if pos not in seen_splitters:
            seen_splitters.add(pos)
            total += 1

        total += count_splits(grid, col - 1, row + 1, seen_splitters, visited_beams)
        total += count_splits(grid, col + 1, row + 1, seen_splitters, visited_beams)
        return total

    return 0


def main(grid):
    start_col = grid[0].index('S')
    return count_splits(grid, start_col, 1, set(), set())

if __name__ == '__main__':
    path = "large_input.txt"
    with open(path, "r") as file:
        input = file.read().strip()
    print(main(input.split("\n")))
