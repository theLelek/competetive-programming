class Solution:

    roman_values = [1000, 500, 100, 50, 10, 5, 1]
    values_to_letter = {
        1:"I",

        5:"V",
        10:"X",

        50:"L",
        100:"C",

        500:"D",
        1000:"M"
    }
    @staticmethod
    def intToRoman(num: int) -> str:
        roman_number = ""
        for index, value in enumerate(Solution.roman_values):
            roman_number += Solution.values_to_letter[value] * (num // value)
            num = num % value
        return roman_number




print(Solution.intToRoman(3749))



