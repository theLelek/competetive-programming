from typing import List

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        unique_combinations = []

        def dfs(current_elements: List, current_sum, previous_index):
            if current_sum == target:
                unique_combinations.append(current_elements.copy())
                return True
            if current_sum > target:
                return
            for i in range(previous_index, len(candidates)):
                current_elements.append(candidates[i])
                b = dfs(current_elements, current_sum + candidates[i], i)
                current_elements.pop()
                if b:
                    break

        dfs([], 0, 0)
        return unique_combinations


candidates_1 = [2, 3, 6, 7]
target_1 = 7

candidates_2 = [2, 3, 5]
target_2 = 8

candidates_3 = [2]
target_3 = 1

print(Solution().combinationSum(candidates_1, target_1))
print(Solution().combinationSum(candidates_2, target_2))
print(Solution().combinationSum(candidates_3, target_3))

