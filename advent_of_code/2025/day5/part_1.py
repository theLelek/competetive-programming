def get_id_ranges(input):
    id_ranges = []
    for line in input:
        if line.strip() == "":
            break

        splitted = line.split("-")
        a = int(splitted[0])
        b = int(splitted[1])
        ls = []
        ls.append(a)
        ls.append(b)
        id_ranges.append(ls)
    return id_ranges

def get_ingredient_ids(input: list[str]):
    ingredient_ids = []
    for i in range(len(input)):
        if input[i].strip() == "":
            break
    for i in range(i + 1, len(input)):
        ingredient_ids.append(int(input[i].strip()))
    return ingredient_ids

def is_ingredient_valid(id_ranges, ingredient):
    for id_range in id_ranges:
        if ingredient >= id_range[0] and ingredient <= id_range[1]:
            return True
    return False


def main(input):
    count = 0
    splitted = input.split("\n")
    id_ranges = get_id_ranges(splitted)
    ingredient_ids = get_ingredient_ids(splitted)
    count = 0
    for ingredient in ingredient_ids:
        if is_ingredient_valid(id_ranges, ingredient):
            count += 1
    return count


if __name__ == '__main__':
    path = "large_input.txt"
    with open(path, "r") as file:
        input = file.read().strip()
    print(main(input))
