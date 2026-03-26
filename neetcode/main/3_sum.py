from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()
        for index1, value1 in enumerate(nums):
            if index1 > 0 and value1 == nums[index1 - 1]:
                continue

            left_pointer = index1 + 1
            right_pointer = len(nums) - 1
            while left_pointer < right_pointer:
                three_sum = nums[left_pointer] + nums[right_pointer]
                if three_sum > 0:
                    right_pointer -= 1
                elif three_sum < 0:
                    left_pointer += 1
                else:
                    res.append([left_pointer, right_pointer])
                    left_pointer += 1
                    while nums[left_pointer] == nums[left_pointer - 1] and left_pointer < right_pointer:
                        left_pointer += 1
        return res