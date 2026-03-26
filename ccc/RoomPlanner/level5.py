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

    def assign_rom_desks(self):
        i = 0
        current_iteration = 0
        direction = 0
        while i < len(self.room):
            if current_iteration % 4 == 0:
                direction += 1

            if direction % 2 != 0:
                current_iteration +=1
                continue

            # down:
            if direction % 2 == 0:


            current_iteration +=1

    @staticmethod
    def list_to_string(room: list[list[str]]) -> str:
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
# dividor = int(input.split("\n")[0])
for line in input.splitlines()[1:]:
    splitted = line.split(" ")
    x_num = int(splitted[0])
    y_num = int(splitted[1])
    max_desk = int(splitted[2])
    obj = room(x_num, y_num, max_desk)
    obj.assign_rom_desks()
    out += room.list_to_string(obj.room) + "\n"

out = out.strip()
with open("out", "w") as o:
    o.write(out)

print(out)


