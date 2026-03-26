from typing import List

class Drone:
    def __init__(self, accelerations: List[int]):
        self.accelerations = accelerations
        self.end_height = Drone.return_height(accelerations)

    @staticmethod
    def return_height(accelerations: List[int]) -> int:
        height = 0
        velocity = 0
        for i in accelerations:
            velocity += i - 10
            height += velocity
        return height





def string_list_to_int_list(str :list[str]) -> List[int]:
    return list(map(int, str))



with open("level1Inputs/level1_1.in") as i:
    content = i.read()

content = content.strip()

splitted = content.split("\n")

with open("level1Inputs/level1_1.out", "w") as i:
    for numbers in splitted[1:]:
        string_list = numbers.split(" ")
        int_list = string_list_to_int_list(string_list)

        obj = Drone(int_list)
        i.write(str(obj.end_height) + "\n")




