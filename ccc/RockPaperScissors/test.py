from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        answer = []
        sum_value = sum(nums)
        for i in range(len(nums)):
            answer.append(sum_value - nums[i])
        return answer



solution = Solution()
print(solution.productExceptSelf([1,2,3]))

