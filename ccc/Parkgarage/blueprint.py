
def solve(input: str):
    pass


def main():
    with open("input.txt", "r", encoding="UTF-8") as input_file:
        string_input = input_file.read().strip()

    output = solve(string_input)

    with open("output.txt", "w", encoding="UTF-8") as output_file:
        output_file.write(output)



if __name__ == '__main__':
    main()