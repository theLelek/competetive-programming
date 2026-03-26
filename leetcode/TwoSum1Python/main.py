class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for i, element1 in enumerate(nums):
            for j, element2 in enumerate(nums):

                if element1 + element2 == target and i != j:
                    return [i, j]


obj = Solution()
print(obj.twoSum(nums=[3,2,4], target=6))