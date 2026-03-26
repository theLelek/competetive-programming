class UnionFind:
    def __init__(self, size):
        self.parent = list(range(size))
        self.rank = [0] * size

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])  # Path compression
        return self.parent[x]

    def union(self, x, y):
        root_x = self.find(x)
        root_y = self.find(y)

        if root_x != root_y:
            if self.rank[root_x] < self.rank[root_y]:
                self.parent[root_x] = root_y
            elif self.rank[root_x] > self.rank[root_y]:
                self.parent[root_y] = root_x
            else:
                self.parent[root_y] = root_x
                self.rank[root_x] += 1

    def connected(self, x, y):
        return self.find(x) == self.find(y)


def get_matrix(input: str, height: int) -> list:
    splitted = input.split("\n")
    out = []
    for i in range(1, height + 1):
        current = []
        for j in range(len(splitted[i])):
            current.append(splitted[i][j])
        out.append(current)
    return out


def get_coordinate_pairs(input: str, height: int) -> list:
    out = []
    splitted = input.splitlines()
    for line in splitted[height + 2:]:
        if line.strip():  # Skip empty lines
            parts = line.split()
            coord1 = parts[0].split(',')
            coord2 = parts[1].split(',')
            x1, y1 = int(coord1[0]), int(coord1[1])
            x2, y2 = int(coord2[0]), int(coord2[1])
            out.append(((x1, y1), (x2, y2)))
    return out


def main(input: str):
    splitted = input.split("\n")
    height = int(splitted[0])
    matrix = get_matrix(input, height)
    width = len(matrix[0])

    uf = UnionFind(height * width)

    def coord_to_index(x, y):
        return y * width + x

    for y in range(height):
        for x in range(width):
            if matrix[y][x] == 'L':
                current_idx = coord_to_index(x, y)

                # Check right neighbor
                if x + 1 < width and matrix[y][x + 1] == 'L':
                    neighbor_idx = coord_to_index(x + 1, y)
                    uf.union(current_idx, neighbor_idx)

                # Check bottom neighbor
                if y + 1 < height and matrix[y + 1][x] == 'L':
                    neighbor_idx = coord_to_index(x, y + 1)
                    uf.union(current_idx, neighbor_idx)

    coordinate_pairs = get_coordinate_pairs(input, height)

    out = ""
    for (x1, y1), (x2, y2) in coordinate_pairs:
        idx1 = coord_to_index(x1, y1)
        idx2 = coord_to_index(x2, y2)

        if uf.connected(idx1, idx2):
            out += "SAME\n"
        else:
            out += "DIFFERENT\n"

    return out


if __name__ == '__main__':
    with open("level2(4)/level2_5.in") as f:
        input = f.read()
    out = main(input)
    print(out)
    with open("out.txt", "w") as f:
        f.write(out)