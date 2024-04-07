import math
from typing import List


class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        n = len(s)
        stack = []
        for i in range(0, n):
            if len(stack) > 0 and i == n - 1 and stack[-1] == 0 and stack[-1] == '(' and s[i] == ')':
                stack.append(i)
                continue

            if len(stack) > 0 and s[stack[-1]] == '(' and s[i] == ')':
                stack.pop()
            elif s[i] in ['(', ')']:
                stack.append(i)

        res = []
        set_ = set(stack)
        for i in range(0, n):
            if i in set_:
                continue
            res.append(s[i])

        return "".join(res)


if __name__ == '__main__':
    s = Solution()
    print(s.minRemoveToMakeValid("(z))(()f))))s()(xy(al(cb(u)((("))
