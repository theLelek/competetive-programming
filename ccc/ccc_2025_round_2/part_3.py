# format: x y

def get_integer_pairs(input: str, height) -> list:
    out = []
    splitted = input.splitlines()
    for line in splitted[height + 2:]:
        if line.strip():
            pairs = line.split()
            current = []
            for pair in pairs:
                coords = pair.split(",")
                a = int(coords[0])
                b = int(coords[1])
                current.append((a, b))
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


def get_positions_between(pair1, pair2):
    x1, y1 = pair1
    x2, y2 = pair2

    positions = set()

    dx = 0 if x1 == x2 else (1 if x2 > x1 else -1)
    dy = 0 if y1 == y2 else (1 if y2 > y1 else -1)

    x, y = x1 + dx, y1 + dy
    while (x, y) != (x2, y2):
        positions.add((x, y))
        x += dx
        y += dy
    return positions


def diagonal_segments_cross(p1, p2, p3, p4):
    """Check if diagonal segments (p1->p2) and (p3->p4) cross each other"""
    x1, y1 = p1
    x2, y2 = p2
    x3, y3 = p3
    x4, y4 = p4

    # Only check diagonal moves
    if abs(x2 - x1) != abs(y2 - y1) or abs(x4 - x3) != abs(y4 - y3):
        return False

    # Check if the segments intersect (excluding endpoints)
    # For diagonals on a grid, they cross if they go in opposite diagonal directions
    # and their bounding boxes overlap

    dx1 = 1 if x2 > x1 else -1
    dy1 = 1 if y2 > y1 else -1
    dx2 = 1 if x4 > x3 else -1
    dy2 = 1 if y4 > y3 else -1

    # Same direction diagonals don't cross
    if dx1 * dx2 == dy1 * dy2:
        return False

    # Check for actual intersection point
    # Solve: p1 + t*(p2-p1) = p3 + s*(p4-p3)
    denom = (x2 - x1) * (y4 - y3) - (y2 - y1) * (x4 - x3)
    if denom == 0:
        return False

    t = ((x3 - x1) * (y4 - y3) - (y3 - y1) * (x4 - x3)) / denom
    s = ((x3 - x1) * (y2 - y1) - (y3 - y1) * (x2 - x1)) / denom

    # Check if intersection is strictly between the endpoints (0 < t < 1, 0 < s < 1)
    return 0 < t < 1 and 0 < s < 1

def is_intersection(matrix, int_pairs):
    # Check for revisiting positions
    visited = set()
    visited.add(int_pairs[0])

    segments = []  # Store all segments

    for i in range(1, len(int_pairs)):
        current = int_pairs[i]
        previous = int_pairs[i - 1]
        current_set = get_positions_between(previous, current)

        if current in visited or visited.intersection(current_set):
            return True

        # Check if this segment crosses any previous diagonal segment
        for prev_seg in segments:
            if diagonal_segments_cross(prev_seg[0], prev_seg[1], previous, current):
                return True

        segments.append((previous, current))
        visited.update(current_set)
        visited.add(current)

    return False


def main(input: str):
    splitted = input.split("\n")
    height = int(splitted[0])
    matrix = get_matrix(input, height)
    int_pairs = get_integer_pairs(input, height)

    out = ""
    for pair in int_pairs:
        b = is_intersection(matrix, pair)
        if b:
            out += "INVALID\n"
        else:
            out += "VALID\n"
    return out


if __name__ == '__main__':
    with open("level3(7)/level3_5.in") as f:
        input = f.read()
    out = main(input)
    print(out)
    with open("out.txt", "w") as f:
        f.write(out)