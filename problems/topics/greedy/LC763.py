import math
from typing import List


class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        n = len(s)
        f = {}
        for i in range(0, n):
            f[s[i]] = i

        p = []
        e = 0
        for i in range(0, n):
            e = max(e, f[s[i]])
            if i == e:
                p.append(i)

        ans = [p[0] + 1]
        for i in range(1, len(p)):
            ans.append(p[i] - p[i - 1])

        return ans


if __name__ == '__main__':
    s = Solution()
    print(s.partitionLabels("ababcbacadefegdehijhklij"))
