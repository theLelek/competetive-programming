from typing import List

class Solution:
    def trap(self, height: List[int]) -> int:

        left_index = 0
        left_value = -1
        right_index = 0
        right_value = -1
        highest_value = -1
        highest_index = -1

        sum_highest_to_right = 0
        maximum_water_area = 0



        for index, value in enumerate(height):
            if value == 0:
                continue



            left_index = right_index
            left_value = right_value
            right_index = index
            right_value = value

            if left_value == -1 or right_value == -1:
                highest_index = index
                highest_value = value
                sum_highest_to_right = 0
                continue


            solution_from_calculating = Solution.calculate_area(height, highest_index, right_index)
            solution_from_calculating -= sum_highest_to_right
            if solution_from_calculating > 0:
                maximum_water_area += solution_from_calculating
                sum_highest_to_right += solution_from_calculating




            if value >= highest_value:
                highest_value = value
                highest_index = index
                sum_highest_to_right = 0
            else:
                sum_highest_to_right += value

            print(left_index, right_index, highest_index)



        return maximum_water_area

    @staticmethod
    def calculate_area(height: List[int], left_index: int, right_index: int) -> int:
        length = right_index - left_index - 1
        return length * min(height[left_index], height[right_index])


def main():
    obj = Solution()
    height = [0,2,0,3,1,0,1,3,2,0,0,1]
    print(obj.trap(height))

if __name__ == '__main__':
    main()