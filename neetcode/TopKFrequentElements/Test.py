from typing import List

class Solution:
    def encode(self, strs: List[str]) -> str:
        encoded = ""
        for i in strs:
            encoded += str(len(i)) + "#" + i
        return encoded

    def decode(self, s: str) -> List[str]:
        if s == "":
            return []
        decoded = []
        first_index_number = 0
        last_index_number = Solution._index_of_first_non_numeric(s) - 1
        current_word_length = int(s[first_index_number:last_index_number + 1])

        while last_index_number + current_word_length + 1 <= len(s):
            current_word = s[last_index_number + 2:last_index_number + 2 + current_word_length]
            decoded.append(current_word)
            first_index_number += current_word_length + 2
            last_index_number = Solution._index_of_first_non_numeric(s, first_index_number) - 1

            if last_index_number + 1 >= len(s) or first_index_number + 1 >= len(s):
                break
            current_word_length = int(s[first_index_number:last_index_number + 1])


        return decoded


    @staticmethod
    def _index_of_first_non_numeric(s: str, start_index=0):
        for index, value in enumerate(s[start_index:]):
            if value.isnumeric() == False:
                return index + start_index
        return -1




Test = Solution()
ls = ["we","say",":","yes","!@#$%^&*()"]
encoded = Test.encode([])
print(encoded)
print(Test.decode(encoded))