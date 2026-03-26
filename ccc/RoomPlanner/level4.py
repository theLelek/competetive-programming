from typing import List
class room:


    def __init__(self, x_length: int, y_length: int, max_desks: int):
        self.x_length = x_length
        self.y_length = y_length
        self.max_desks = max_desks
        self.room = room.initializeRoom(x_length, y_length)
        
        
    @staticmethod
    def initializeRoom(x_length: int, y_length: int):
        room = []
        for i in range(y_length):
            room.append(["."] * x_length)
        return room

    def assign_rom_desk(self):
        for i in range(0, self.y_length, 2):
            for j in range(0, self.x_length - 2, 4):
                self.room[i][j] = "x"
                self.room[i][j + 1] = "x"
                self.room[i][j + 2] = "x"

        if not j + 4 < self.x_length:
            return

        for i in range(0, self.y_length - 2, 4):
            self.room[i][self.x_length - 1] = "x"
            self.room[i + 1][self.x_length - 1] = "x"
            self.room[i + 2][self.x_length - 1] = "x"

    @staticmethod
    def list_to_string(room: List[List[str]]) -> str:
        out = ""
        for i in range(0, len(room)):
            for j in range(0, len(room[i])):
                out += room[i][j]
            out += "\n"
        return out


with open("level4/level4_5.in") as f:
    input = f.read()
f.close()

out = ""
#dividor = int(input.split("\n")[0])
for line in input.splitlines()[1:]:
    splitted = line.split(" ")
    x_num = int(splitted[0])
    y_num = int(splitted[1])
    max_desk = int(splitted[2])
    obj = room(x_num, y_num, max_desk)
    obj.assign_rom_desk()
    out += room.list_to_string(obj.room) + "\n"




out = out.strip()
with open("out", "w") as o:
    o.write(out)


print(out)


