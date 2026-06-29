def to_map(input: str):
    a_map = dict()
    for line in input.splitlines():
        key = line[:line.find(":")]
        values = line[line.find(":") + 2:].split(" ")
        a_map[key] = values
    return a_map

def get_number_of_paths(a_map, current_key):
    branches = 0
    if a_map[current_key] == ["out"]:
        return 1

    for value in a_map[current_key]:
        foo = get_number_of_paths(a_map, value)
        branches += foo
    return branches


def main(input: str):
    a_map = to_map(input)
    return get_number_of_paths(a_map, "you")


if __name__ == '__main__':
    path = "large_input.txt"
    with open(path, "r") as file:
        input = file.read().strip()
    print(main(input))
