from typing import List
class Solution:
    def __init__(self):
        self.longest_palindrome = ""

    def longestPalindrome(self, s: str) -> str:
        for idx_left in range(len(s)):
            for idx_right in range(len(s) - 1, -1, -1):  # iterates s backwards
                current_string = s[idx_left:idx_right + 1]

                if(len(current_string) <= len(self.longest_palindrome)):
                    continue
                self._replace_palindrome(current_string)
        return self.longest_palindrome

    def _replace_palindrome(self, s: str) -> bool:
        if Solution.is_palindrome(s):
            if len(s) > len(self.longest_palindrome):
                self.longest_palindrome = s
                return True
        return False

    @staticmethod
    def is_palindrome(s: str) -> bool:
        if s == s[::-1]:
            return True
        return False



obj = Solution()
print(obj.longestPalindrome("cbbd"))

