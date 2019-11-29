# Implement a wildcard pattern matching with support fort '?' and '*'
class Solution:
    # @param A : string
    # @param B : string
    # @return an integer
    def isMatch(self, A, B):
        matchIndexes = ["-1"]
        for pattern in B:
            matchIndexInner = []
            for index in matchIndexes:
                if index.startswith("*"):
                    start = int(index[1:])
                    if pattern == "*":
                        matchIndexInner.append(index)
                    elif pattern == "?":
                        matchIndexInner.append("*" + str(start + 1))
                    else:
                        for st in enumerate(A[start:]):
                            if st[1] == pattern:
                                matchIndexInner.append(str(start +st[0]))
                        break
                elif pattern == "*":    
                    matchIndexInner.append("*" + str(int(index)+1))
                elif int(index)+1 == len(A):
                    continue
                elif pattern == "?" or pattern == A[int(index)+1]:
                    matchIndexInner.append(str(int(index)+1))
            matchIndexes = matchIndexInner
        
        for i in matchIndexInner:
            if i.startswith("*") or int(i) == len(A)-1:
                return 1
        return 0
        
    def isMatch2(self, A, B):
        n1 = len(A)
        n2 = len(B)
        # Edge cases
        if not n1 and not n2:
            return 1
        if not n2:
            return 0

        i = 0
        j = 0
        star = None
        curr_i = None
        #print('HERE1')
        # n1 is the length of the all character
        while i < n1:
            if j < n2 and (A[i] == B[j] or B[j] == '?'):
                i += 1
                j += 1
            elif j < n2 and B[j] == '*':
                #print('HERE2')
                star = j
                j += 1
                curr_i = i
            elif star is not None:
                #print('HERE3')
                curr_i += 1
                i = curr_i
                j = star + 1
            else:
                #print('HERE4')
                return 0
        while j < n2 and B[j] == '*':
            j += 1
        #print('HERE5')
        return 1 if j == n2 else 0
solution = Solution()
# print(solution.isMatch("acccaba", "*??ba*a"))
# print(solution.isMatch("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","a**************************************************************************************"))
# print(solution.isMatch("bbbcbcb","**b"))

# print(solution.isMatch("a","?"))
print(solution.isMatch("aabbaaabbbaa", "a*bbb*aaa"))
print(solution.isMatch2("aabbaaabbbaa", "a*bbb*aaa"))
print(solution.isMatch("aab", "a*a*b"))

print(solution.isMatch("aa","a"))
print(solution.isMatch("aa","aa"))
print(solution.isMatch("aaa","aa"))
# print(isMatch("aa","*"))
# print(isMatch("aa", "a*"))
# print(isMatch("ab", "?*"))
# print(isMatch("aab", "c*a*b"))

# print(isMatch("aa", "b*"))