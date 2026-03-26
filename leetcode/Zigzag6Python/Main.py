class Solution:

    def __init__(self):
        rows = []

    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        self.rows = [""] * numRows
        index_status = "down"
        index = 0
        for i in s:
            self.rows[index] += i
            if index_status == "up":
                index -= 1
                if index < 0:
                    index_status = "down"
                    index = 1

            elif index_status == "down":
                index += 1
                if index >= numRows:
                    index_status = "up"
                    index = numRows - 2
        #print(self.rows)
        return "".join(self.rows)

obj = Solution()
print(obj.convert("PAYPALISHIRING", 1))