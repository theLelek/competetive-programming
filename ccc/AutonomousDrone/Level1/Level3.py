from typing import List

class Drone:
    def __init__(self, min_height_goal: List[int], max_ticks: int):
        self.min_height_goal = min_height_goal
        self.max_tick = max_ticks





    @staticmethod
    def accelerations_to_height(accelerations: List[int]) -> float:
        height = 0
        current_speed = 0
        prior_speed = 0
        for i in accelerations:
            current_speed += i
            height += (prior_speed + current_speed) / 2
            prior_speed = current_speed
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

        #obj = Drone(int_list)
        #i.write(str(obj.end_height) + "\n")




print(Drone.accelerations_to_height([20,20,0,0,1,9,10,10,19]))