from typing import List
class room:


    def room_length_to_matrix(x_length: int, y_length: int) -> List:
        global current_desk
        current_desk = 0
        out = []
        for i in range(y_length):
            row = ["0"] * x_length
            for j in range(x_length):
                if j % 3 == 0:
                    if j >= x_length -2:
                        break
                    current_desk += 1

                row[j] = str(current_desk) + " ".strip()

            out.append(row)

        if out[0][len(out[0]) - 1] == "0":
            room.add_missing_desks(out, len(out[0]) - 1)

        if out[0][len(out[0]) - 2] == "0":
            room.add_missing_desks(out, len(out[0]) - 2)

        return out

    def list_to_string(lst: List) -> str:
        s = ""
        for i in range(len(lst)):
            for j in range(len(lst[i])):
                s += str(lst[i][j]) + " "
            s = s.strip()
            s += "\n"
        return s

    def add_missing_desks(out: list, x_index: int):
        global current_desk
        y_length = len(out)

        for i in range(y_length - y_length % 3):
            if i % 3 == 0:
                current_desk +=1
            out[i][x_index] = current_desk





with open("level3(2)/level3_5.in") as f:
    input = f.read()
f.close()

out = ""
#dividor = int(input.split("\n")[0])
for line in input.splitlines()[1:]:
    x_num = int(line.split(" ")[0])
    y_num = int(line.split(" ")[1])
    out += room.list_to_string(room.room_length_to_matrix(x_num, y_num)) + "\n"



out = out.strip()
with open("out", "w") as o:
    o.write(out)


print(out)


