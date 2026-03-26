class Solution:

    def __init__(self):
        self.solution = 0
        self.first_number_index = -1
        self.last_number_index = -1
        self.operator = 1
        self.was_operator_assigned = False

    def myAtoi(self, s: str) -> int:
        if s == "":
            return 0
        self.solution = self.get_number(s)
        if self.solution < -2 ** 31:
            return -2 ** 31
        if self.solution > 2 ** 31 - 1:
            return 2 ** 31 - 1

        return self.solution

    def get_number(self, s: str) -> int:
        for index, value in enumerate(s):
            if value.isdigit():
                self.first_number_index = index
                break

            elif value == '-' and not self.was_operator_assigned:
                self.operator = -1
                self.was_operator_assigned = True

            elif value == '+' and not self.was_operator_assigned:
                self.operator = 1
                self.was_operator_assigned = True

            elif value == " " and self.was_operator_assigned:
                return 0

            elif value != ' ':
                return 0

        if self.first_number_index == -1:
            return 0
        self.last_number_index = self.first_number_index

        for index, value in enumerate(s[self.first_number_index:]):
            if value.isdigit():
                self.last_number_index = index + self.first_number_index
            else:
                break

        return int(s[self.first_number_index: self.last_number_index + 1]) * self.operator


obj = Solution()
print(obj.myAtoi("  +  413"))