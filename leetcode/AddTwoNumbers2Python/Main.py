from typing import Optional
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    reversed = None
    def addTwoNumbers(self, l1: Optional['ListNode'], l2: Optional['ListNode']): # -> Optional[ListNode]:
        solution1 = Solution()
        solution2 = Solution()
        solution1.linked_list_to_reversed_int(l1)
        solution2.linked_list_to_reversed_int(l2)

        num1 = solution1.reversed
        num2 = solution2.reversed
        #print(num1, num2)

        #Solution.number_to_linked_list(num1)
        #print(num1 + num2)
        #print(Solution.reverse_number(num1 + num2))
        x = Solution.reverse_number(int(num1) + int(num2))
        #print(x)
        return Solution.number_to_linked_list(x)



    @staticmethod
    def reverse_number(number):
        number = str(number)
        return number[::-1]




    @staticmethod
    def number_to_linked_list(values: str) -> 'ListNode':
        head = ListNode(int(values[0]))
        current = head

        for val in values[1:]:
            current.next = ListNode(int(val))
            current = current.next

        return head

    def linked_list_to_reversed_int(self, l):
        self.reversed = Solution.prepend_number(self.reversed, l.val)
        if l.next is not None:
            self.linked_list_to_reversed_int(l.next)


    @staticmethod
    def prepend_number(num, prepend):
        if num is None:
            return prepend
        result = str(prepend) + str(num)
        return result

class ListNode:



    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


linked_list1 = ListNode(1, ListNode(0, ListNode(9)))
linked_list2 = ListNode(5, ListNode(7, ListNode(8)))


obj = Solution()
ls = obj.addTwoNumbers(linked_list1, linked_list2)
print(ls)