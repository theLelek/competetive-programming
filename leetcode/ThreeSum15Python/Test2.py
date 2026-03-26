from typing import List

class Solution:

    def __init__(self):
        self.keys = []
        self.values = []
        self.keys_to_values = {}
        self.values_to_keys = {}

    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        for i in nums:
            if i not in self.keys_to_values:
                self.keys_to_values[i] = 0
            self.keys_to_values[i] += 1

        self.values = list(self.keys_to_values.values())
        self.keys = list(self.keys_to_values.keys())

        self.values.sort()

        for key, value in self.keys_to_values.items():
           if self.values_to_keys.get(value) == None:
               self.values_to_keys[value] = []
           self.values_to_keys[value].append(key)

        solution = []
        for i in self.values[k - 1:]:
            solution.extend(self.values_to_keys[i])

        return solution


obj = Solution()
nums = [1,2,2,3,3,3, 4]
k = 3
print(obj.topKFrequent(nums, k))



