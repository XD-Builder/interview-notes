# Given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add two numbers and return it as a linked list
# Ex.
# Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
# Output 7 -> 0 -> 8
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    # @param A : head node of linked list
    # @param B : head node of linked list
    # @return the head node in the linked list
    def addTwoNumbers(self, A, B):
        carry = 0
        result = ListNode(None)
        nextResult = result
        while A != None:
            if B == None:
                break
                
            sumAB = A.val + B.val + carry
            if sumAB >= 10:
                sumAB -= 10
                carry = 1
            else:
                carry = 0 
            
            nextResult.next = ListNode(sumAB)
            nextResult = nextResult.next
            A = A.next
            B = B.next
        
        while A != None:
            sumA = carry + A.val
            if sumA >= 10:
                sumA -= 10
                carry = 1
            else:
                carry = 0
            nextResult.next = ListNode(sumA)
            nextResult = nextResult.next
            A = A.next
            
        while B != None:
            sumB = carry + B.val
            if sumB >= 10:
                sumB -= 10
                carry = 1
            else:
                carry = 0
            nextResult.next = ListNode(sumB)
            nextResult = nextResult.next
            B = B.next

        if carry != 0:
            nextResult.next=ListNode(carry)
        return result.next


a = ListNode(9)
b = ListNode(9)
a.next = b

Solution().addTwoNumbers(a, a)