from typing import List

class Solution:
    def trap(self, height: List[int]) -> int:

        reftrindex = 0
        left_value = height[0]
        right_index = 0
        right_value = height[0]
        highest_value = -1
        highest_index = -1

        sum_highest_to_right = 0
        maximum_area = 0

        for index, value in enumerate(height):
            if value == 0:
                continue

            sum_highest_to_right += value

            reft_index = right_index
            left_value = right_value
            right_index = index
            right_value = value

            if left_value == 0 or right_value == 0:
                continue

            if value > highest_value:
                highest_value = value
                highest_index = index
                sum_highest_to_right = 0

            if left_index != highest_index and right_index != highest_index:
                sum_highest_to_right += left_value

            if left_index == highest_index or right_index == highest_index:
                area = Solution.calculate_area(height, left_index, right_index)
                maximum_area += area
                sum_highest_to_right += area
            else:
                maximum_area += Solution.calculate_area(height, highest_index, right_index)
                maximum_area -= sum_highest_to_right


            print(left_index, right_index, highest_index)


        return maximum_area

    @staticmethod
    def calculate_area(height: List[int], left_index: int, right_index: int) -> int:
        length = right_index - left_index - 1
        return length * min(height[left_index], height[right_index])


def main():
    obj = Solution()
    height = [0,2,0,3,1,0,1,3,2,1]
    print(obj.trap(height))

if __name__ == '__main__':
    main()