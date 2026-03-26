from typing import List

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counts = {}
        for x in nums:
            counts[x] = counts.get(x, 0) + 1

        freq_to_vals = {}
        for val, freq in counts.items():
            freq_to_vals.setdefault(freq, []).append(val)

        result = []
        for freq in sorted(freq_to_vals.keys(), reverse=True):
            for val in freq_to_vals[freq]:
                result.append(val)
                if len(result) == k:
                    return result
        return result

obj = Solution()
print(obj.topKFrequent([1,1,2,100], 2))





ls = [3,1,3,1,0]