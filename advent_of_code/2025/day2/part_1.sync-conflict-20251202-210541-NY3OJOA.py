# ranges seperated by ,
#
def _id_valid_with(id: str, sub: str) -> bool:
    s = id[:sub]
    for i in range(0, len(id), len(sub)):
        foo = id[i:i + len(sub)]
        if foo != sub:
            return False
    return True

def is_invalid_id(n: int) -> bool:
    sub = ""
    for i in range(len(n)):
        if len(str(n)) % i + 1 != 0:
            continue
        


def get_sum_of_invalid_ids(input: str):
    splitted = input.split("-")
    count = 0
    for i in range(int(splitted[0]), int(splitted[1])+1):
        if is_invalid_id(str(i)):
            print(i)

            count += int(i)
    return count

def main(input: str):
    splitted = input.split(",")
    invalid_sum = 0
    for item in splitted:
        invalid_sum += get_sum_of_invalid_ids(item)
    return invalid_sum


if __name__ == '__main__':
    path = "input.txt"
    with open(path, "r") as file:
        input = file.read().strip()
    print(main(input))
