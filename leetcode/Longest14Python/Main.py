from typing import List


class Solution:

    def __init__(self):
        self.longest_common_prefix = None

    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 0:
            return ""

        self.longest_common_prefix = strs[0]

        for s in strs:
            current_common_prefix = Solution.find_common_prefix(strs[0], s)
            if len(self.longest_common_prefix) > len(current_common_prefix):
                self.longest_common_prefix = current_common_prefix

        return self.longest_common_prefix

    @staticmethod
    def find_common_prefix(str1: str, str2: str) -> str:
        common_prefix = ""
        if len(str2) > len(str1):
            foo = str1
            str1 = str2
            str2 = foo

        for i in range(len(str2)):
            if str1[i] == str2[i]:
                common_prefix += str1[i]
            else:
                break
        return common_prefix


obj = Solution()
print(obj.longestCommonPrefix(["aaaaa", "b"]))