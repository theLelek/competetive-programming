from collections import deque


def get_integer_pairs(input: str, height: int) -> list:
    splitted = input.split("\n")
    out = []
    for i in range(height + 2, len(splitted)):
        line = splitted[i].strip()
        if not line:
            continue

        current_splitted = line.split(" ")
        current = []

        for coord_pair in current_splitted:
            if coord_pair:
                parts = coord_pair.split(",")
                if len(parts) == 2:
                    x = int(parts[0])
                    y = int(parts[1])
                    current.append((x, y))

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


def find_path(matrix, start, end, max_length):
    height = len(matrix)
    width = len(matrix[0])

    directions = [
        (-1, -1), (-1, 0), (-1, 1),
        (0, -1), (0, 1),
        (1, -1), (1, 0), (1, 1)
    ]

    queue = deque([(start, [start])])
    visited = {start}

    while queue:
        (x, y), path = queue.popleft()

        if (x, y) == end:
            return path

        if len(path) >= max_length:
            continue

        for dx, dy in directions:
            nx, ny = x + dx, y + dy

            # Check bounds
            if 0 <= nx < width and 0 <= ny < height:
                # Check if water and not visited
                if matrix[ny][nx] == 'W' and (nx, ny) not in visited:
                    visited.add((nx, ny))
                    queue.append(((nx, ny), path + [(nx, ny)]))

    return None  # No path found


def main(input: str):
    splitted = input.split("\n")
    height = int(splitted[0])
    matrix = get_matrix(input, height)
    int_pairs = get_integer_pairs(input, height)

    out = ""
    max_length = 2 * len(matrix[0])  # twice the width

    for pair in int_pairs:
        start = pair[0]
        end = pair[1]

        path = find_path(matrix, start, end, max_length)

        if path:
            path_str = " ".join([f"{x},{y}" for x, y in path])
            out += path_str + "\n"
        else:
            out += "NO PATH FOUND\n"

    return out


if __name__ == '__main__':
    with open("level4(2)/level4_5.in") as f:
        input = f.read()
    out = main(input)
    print(out)
    with open("out.txt", "w") as f:
        f.write(out)