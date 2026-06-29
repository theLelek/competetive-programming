import math

def input_to_2d_list(input: list[str]):
    out = []
    for line in input:
        splitted = line.split(",")
        out.append(Position(int(splitted[0]), int(splitted[1]), int(splitted[2])))
    return out

class Position:
    def __init__(self, x: int, y: int, z: int):
        self.x = x
        self.y = y
        self.z = z

    def distance(self, other):
        return math.sqrt((self.x - other.x) ** 2 + (self.y - other.y) ** 2 + (self.z - other.z) ** 2)

    def __str__(self):
        return f"{self.x}, {self.y}, {self.z}\n"

def get_sorted_coordinate_pairs(list_2d):
    pairs = []
    for i in range(len(list_2d)):
        for j in range(i + 1, len(list_2d)):
            p1 = list_2d[i]
            p2 = list_2d[j]
            d = p1.distance(p2)
            pairs.append((d, p1, p2))

    pairs.sort(key=lambda x: x[0])
    return pairs


def union_find(sorted_coordinate_pairs, list_2d):
    groups = []
    for i in list_2d:
        groups.append({i})

    def find(x):
        for i in range(len(groups)):
            if x in groups[i]:
                return i
        return None

    def union(x, y):
        x_find = find(x)
        y_find = find(y)
        if x_find != y_find:
            groups[x_find].update(groups[y_find])
            groups[y_find] = set()


    # TODO maybe length isnt right
    x_coordinates = []
    for i in sorted_coordinate_pairs:
        if get_number_of_groups(groups) == 1:
            break
        distance1 = i[1]
        distance2 = i[2]
        x_coordinates.append(distance1.x)
        x_coordinates.append(distance2.x)
        union(distance1, distance2)
    return x_coordinates[-1] * x_coordinates[-2]

def get_number_of_groups(groups):
    count = 0
    for group in groups:
        if group != set():
            count += 1
    return count

def multiply_3_largest_groups(groups):
    lengths = list()
    for group in groups:
        lengths.append(len(group))
    lengths.sort(reverse=True)
    out = lengths[0]
    for i in lengths[1:3]:
        out *= i
    return out

def main(input):
    list_2d = input_to_2d_list(input)
    sorted_coordinate_pairs = get_sorted_coordinate_pairs(list_2d)
    count = union_find(sorted_coordinate_pairs, list_2d)
    return count

if __name__ == '__main__':
    path = "large_input.txt"
    with open(path, "r") as file:
        input = file.read().strip().split("\n")
    print(main(input))

