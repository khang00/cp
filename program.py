from collections import deque, defaultdict, Counter
from dataclasses import dataclass, field
from functools import cache, lru_cache
from heapq import heappop, heappush, heapify, merge
from math import log10, floor, sqrt, floor, ceil, lcm, trunc
from typing import List, Deque, Tuple, Dict


class Solution:
    def checkPrimeFrequency(self, a: List[int]) -> bool:
        n = len(a)
        f = defaultdict(int)

        for c in a:
            f[c] += 1

        def isPrime(n: int) -> bool:
            if n < 2:
                return False

            for i in range(2, ceil(sqrt(n))):
                if n % i == 0:
                    return False
            return True

        for k in f.keys:
            if not isPrime(f[k]):
                return False
        return True

if __name__ == '__main__':
    sol = Solution()
    print(sol.checkPrimeFrequency([[0, 1], [1, 2], [2, 3]], 3, [-5644, -6018, 1188, -8502]))
