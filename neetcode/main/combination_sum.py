from typing import List

class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        used_combinations = set()

        def get_amount_combinations(current_sum: int, current_combination: List[int]):
            if current_sum > target:
                return

            if current_sum == target:
                used_combinations.add(tuple(sorted(current_combination)))
                return

            for i in nums:
                get_amount_combinations(current_sum + i, current_combination + [i])

        get_amount_combinations(0, [])
        return list(map(list, used_combinations))






obj = Solution()
nums = [2, 5, 6, 9]
target = 9
out = obj.combinationSum(nums, target)
print(out)