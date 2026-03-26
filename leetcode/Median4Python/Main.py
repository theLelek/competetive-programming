from typing import List
from bisect import bisect_left

class Solution:
    @staticmethod
    def findMedianSortedArrays(nums1: List[int], nums2: List[int]) -> float:
        if(len(nums1) < len(nums2)):
            temp = nums1
            nums1 = nums2
            nums2 = temp

        Solution.append_sorted_list(nums1, nums2)
        return Solution.get_median(nums1)

        
    @staticmethod
    def append_sorted_list(nums1, nums2):
        for idx_nums, value in enumerate(nums2):
            idx_added = bisect_left(nums1, value)
            nums1.insert(idx_added, value)

            if(idx_added == len(nums1)):
                    nums1.extend(nums2[idx_nums + 1:]) # unsure if correct



    @staticmethod
    def get_median(ls: List[int]) -> float:
        if(len(ls) % 2 == 0):
            value1 =  ls[(len(ls) // 2) - 1]
            value2 = ls[(len(ls) // 2)]
            return (value1 + value2) / 2.0
        return float(ls[len(ls) // 2])








ls1 = [1, 2]
ls2 = [3,4]

print(Solution.findMedianSortedArrays(ls1, ls2))