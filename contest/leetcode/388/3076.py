import math
from filecmp import cmp
from typing import List


class Solution:
    def shortestSubstrings(self, arr: List[str]) -> List[str]:
        n = len(arr)

        ans = [""] * n
        set_ = [set() for _ in range(n)]

        for i in range(0, n):
            s = list(arr[i])
            m = len(s)
            for j in range(0, m):
                for o in range(0, m):
                    ss = ''.join(s[j:o + 1])
                    set_[i].add(ss)

        for i in range(0, n):
            s = list(arr[i])
            m = len(s)
            for j in range(0, m):
                for o in range(0, m):
                    ss = ''.join(s[j:o + 1])
                    if ss == '':
                        continue

                    is_in = False
                    for k in range(0, n):
                        if k == i:
                            continue

                        if ss in set_[k]:
                            is_in = True
                            break

                    if not is_in:
                        if ans[i] == "":
                            ans[i] = ss
                        else:
                            if len(ss) < len(ans[i]):
                                ans[i] = ss
                            elif len(ss) == len(ans[i]):
                                ans[i] = ss if ss < ans[i] else ans[i]

        return ans


if __name__ == '__main__':
    solution = Solution()
    print(solution.shortestSubstrings(["nasmh"]))
