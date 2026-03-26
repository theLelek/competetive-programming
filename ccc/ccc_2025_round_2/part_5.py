from collections import deque

DIRS_8 = [
    (-1, -1), (0, -1), (1, -1),
    (-1,  0),          (1,  0),
    (-1,  1), (0,  1), (1,  1),
]

# Directions in clockwise order
DIRS = [
    (0, -1),   # N
    (1, -1),   # NE
    (1, 0),    # E
    (1, 1),    # SE
    (0, 1),    # S
    (-1, 1),   # SW
    (-1, 0),   # W
    (-1, -1),  # NW
]


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

def get_island(matrix, start_x, start_y):
    h = len(matrix)
    w = len(matrix[0])

    island = set()
    q = deque()
    q.append((start_x, start_y))
    island.add((start_x, start_y))

    while q:
        x, y = q.popleft()
        for dx, dy in DIRS_8:
            nx, ny = x + dx, y + dy
            if 0 <= nx < w and 0 <= ny < h:
                if matrix[ny][nx] == 'L' and (nx, ny) not in island:
                    island.add((nx, ny))
                    q.append((nx, ny))
    return island


def get_matrix(input: str, height: int) -> list:
    splitted = input.split("\n")
    out = []
    for i in range(1, height + 1):
        current = []
        for j in range(len(splitted[i])):
            current.append(splitted[i][j])
        out.append(current)
    return out

def find_start_water(matrix, island):
    h = len(matrix)
    w = len(matrix[0])

    for x, y in island:
        for dx, dy in DIRS_8:
            nx, ny = x + dx, y + dy
            if 0 <= nx < w and 0 <= ny < h:
                if matrix[ny][nx] == 'W':
                    return (nx, ny)

    raise RuntimeError("No water next to island (should never happen)")

def add(p, d):
    return (p[0] + d[0], p[1] + d[1])


def follow_border(matrix, island, start):
    h = len(matrix)
    w = len(matrix[0])

    # Find initial direction - move along the island's edge
    cur = start
    dir_idx = None

    # Find first valid direction from start
    for i in range(8):
        dx, dy = DIRS[i]
        nxt = (cur[0] + dx, cur[1] + dy)
        if not (0 <= nxt[0] < w and 0 <= nxt[1] < h):
            continue
        if matrix[nxt[1]][nxt[0]] != 'W':
            continue

        # Check if touches island
        touches = any((nxt[0] + ddx, nxt[1] + ddy) in island
                      for ddx, ddy in DIRS_8)
        if touches:
            dir_idx = i
            cur = nxt
            break

    if dir_idx is None:
        return [start]

    path = [start, cur]

    max_steps = 2 * w

    for _ in range(max_steps):
        # Check if we're adjacent to start (valid endpoint)
        dx_to_start = start[0] - cur[0]
        dy_to_start = start[1] - cur[1]
        if len(path) > 2 and abs(dx_to_start) <= 1 and abs(dy_to_start) <= 1:
            return path

        found = False
        # Try turning left first, then straight, then right (wall-following)
        for turn in [-2, -1, 0, 1, 2, 3, 4]:
            test_dir = (dir_idx + turn) % 8
            dx, dy = DIRS[test_dir]
            nxt = (cur[0] + dx, cur[1] + dy)

            if not (0 <= nxt[0] < w and 0 <= nxt[1] < h):
                continue
            if matrix[nxt[1]][nxt[0]] != 'W':
                continue
            if nxt in path[:-1]:  # Allow returning near start
                continue

            # Must touch island
            touches = any((nxt[0] + ddx, nxt[1] + ddy) in island
                          for ddx, ddy in DIRS_8)
            if not touches:
                continue

            path.append(nxt)
            cur = nxt
            dir_idx = test_dir
            found = True
            break

        if not found:
            break

    return path


def main(input: str):
    splitted = input.split("\n")
    height = int(splitted[0])
    matrix = get_matrix(input, height)
    int_pairs = get_integer_pairs(input, height)

    out = ""

    for pair in int_pairs:
        x = pair[0]
        y = pair[1]
        island = get_island(matrix, x, y)
        starting_water = find_start_water(matrix, island)
        path = follow_border(matrix, island, starting_water)
        for element in path:
            out += str(element[0]) + "," + str(element[1]) + " "
        out += "\n"




    return out


if __name__ == '__main__':
    with open("level5(1)/level5_3.in") as f:
        input = f.read()
    out = main(input)
    print(out)
    with open("out.txt", "w") as f:
        f.write(out)