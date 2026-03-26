class Solution:
    letter_to_number = {
        "a": 0, "b": 1, "c": 2, "d": 3, "e": 4, "f": 5,
        "g": 6, "h": 7, "i": 8, "j": 9, "k": 10, "l": 11,
        "m": 12, "n": 13, "o": 14, "p": 15, "q": 16, "r": 17,
        "s": 18, "t": 19, "u": 20, "v": 21, "w": 22, "x": 23,
        "y": 24, "z": 25,
    }

    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:

        solution = []
        anagram_groups = {}

        for i in strs:
            current_tuple = self.string_to_tuple(i)

            foo = anagram_groups.get(current_tuple)
            if foo is None:
                anagram_groups[current_tuple] = len(solution)
                solution.append([])

            solution[anagram_groups[current_tuple]].append(i)

        return solution

    def string_to_tuple(self, s: str) -> tuple:
        letters = [0] * 24
        for i in s:
            letters[self.letter_to_number[i]] += 1

        return tuple(letters)



obj = Solution()
ls = strs=["cab","tin","pew","duh","may","ill","buy","bar","max","doc"]
print(obj.groupAnagrams([ls]))