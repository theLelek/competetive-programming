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

def reformat_id_ranges(id_ranges):
    reformatted = [id_ranges[0]]
    for i in range(1, len(id_ranges), 1):

        a_cur = id_ranges[i][0]
        b_cur = id_ranges[i][1]
        a_bef = id_ranges[i - 1][0]
        b_bef = id_ranges[i - 1][1]

        a_mod = a_cur
        b_mod = b_cur
        if a_cur <= b_bef:
            a_mod = b_bef + 1
        if not a_mod > b_mod:
            reformatted.append((a_mod, b_mod))



    return reformatted


def sum_id_ranges(id_ranges):
    sorted_id_ranges = sorted(id_ranges)
    reformatted = reformat_id_ranges(sorted_id_ranges)
    sum = 0
    for i in reformatted:
        sum += i[1] - i[0] + 1
    return sum

def sort_id_ranges(unsorted):
    sorted_list = sorted(unsorted, key=lambda x: x[0])
    return sorted_list


def main(input):
    count = 0
    splitted = input.split("\n")
    id_ranges = get_id_ranges(splitted)


    return sum_id_ranges(id_ranges)


if __name__ == '__main__':
    path = "large_input.txt"
    with open(path, "r") as file:
        input = file.read().strip()
    print(main(input))
