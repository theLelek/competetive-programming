with open("level1(1)/level1_5.in") as f:
    input = f.read()
f.close()

out = ""
#dividor = int(input.split("\n")[0])
for line in input.splitlines()[1:]:
    x_num = int(line.split(" ")[0])
    y_num = int(line.split(" ")[1])

    out += str(int(x_num * y_num // 3)) + "\n"

out = out.strip()

with open("out", "w") as o:
    o.write(str(out))






