from typing import List

class Solution:
    def maxArea(self, heights: List[int]) -> int:
        out = 0
        left = 0
        right = len(heights) - 1
        while left < right:
            area = min(heights[left], heights[right]) * (right - left)
            if area > out:
                out = area

            if heights[left] <= heights[right]:
                left += 1
            elif heights[left] > heights[right]:
                right -= 1

        return out


obj = Solution()
print(obj.maxArea([1,7,2,5,4,7,3,6]))
