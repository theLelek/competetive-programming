class Solution:
    def reverse(self, x: int) -> int:
        reversed = Solution.reverse_int(x)
        if(Solution.is_32_bit_integer(reversed)):
            return reversed
        return 0

    @staticmethod
    def is_32_bit_integer(number):
        if number <= 2**31 - 1 and number >= -2**31:
            return True
        return False

    @staticmethod
    def reverse_int(n: int) -> int:
        sign = -1 if n < 0 else 1
        rev = str(abs(n))[::-1]
        return sign * int(rev)


obj = Solution()
print(obj.reverse(-1299999999999999999999993))