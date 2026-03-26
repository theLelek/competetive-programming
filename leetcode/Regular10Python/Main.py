class Solution:

    def __init__(self):
        self.letters = []
        self.patterns = []

    def isMatch(self, s: str, p: str) -> bool:
        self.assign_letters(s)
        self.assign_patterns(p)

        for index, value in enumerate(self.letters):
            current_letter = self.letters[index]
            current_pattern = self.patterns[index]

            if current_pattern[len(current_pattern) - 1] == '*':
                pass



        return None


    def assign_letters(self, s : str):
        current_letters_index = 0
        current_letter = s[0]
        self.letters.append("")
        for value in s:
            if value != current_letter:
                current_letters_index +=1
                self.letters.append("")
                current_letter = value
            self.letters[current_letters_index] += value

    def assign_patterns(self, s : str):
        add_index = 0
        for index, value in enumerate(s):
            if value == "*":
                self.patterns.append(s[add_index : index + 1])
                add_index = index + 1

        if add_index != len(s):
            self.patterns.append(s[add_index : len(s)])

obj = Solution()
obj.assign_letters("abbcccdddd")
print(obj.letters)

obj.assign_patterns("asdfasdf*asdf* *asdf")
print(obj.patterns)

obj.isMatch("aaa*", "asdf")