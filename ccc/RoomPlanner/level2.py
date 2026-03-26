def room_length_to_matrix(x_length: int, y_length: int) -> str:
    out = ""
    current_desk = 0
    for i in range(y_length):
        for j in range(x_length):
            if j % 3 == 0:
                current_desk += 1
            out += str(current_desk) + " "
        out = out.rstrip()
        out += "\n"
    return out




with open("level2(1)/level2_5.in") as f:
    input = f.read()
f.close()

out = ""
#dividor = int(input.split("\n")[0])
for line in input.splitlines()[1:]:
    x_num = int(line.split(" ")[0])
    y_num = int(line.split(" ")[1])
    out += room_length_to_matrix(x_num, y_num)
    out += "\n"



out = out.strip()

with open("out", "w") as o:
    o.write(str(out))


print(out)


