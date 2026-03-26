def main(input: str):
    return "hello world"

if __name__ == '__main__':
    with open("") as f:
        input = f.read()
    out = main(input)
    with open("out.txt", "w") as f:
        f.write(out)