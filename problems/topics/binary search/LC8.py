import collections
import heapq
import math
from typing import List


class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        def lower_bound(k, arr):
            l, r = -1, len(arr)
            while r - l > 1:
                mid = l + (r - l) // 2
                if arr[mid] <= k:
                    l = mid
                else:
                    r = mid
            return l

        def ith_elements(i, a, b):
            n, m = len(a), len(b)
            l, r = min(a[0], b[0]) - 1, max(a[n - 1], b[m - 1]) + 1
            while r - l > 1:
                mid = l + (r - l) // 2
                bound_a = lower_bound(mid, a) + 1
                bound_b = lower_bound(mid, b) + 1
                if bound_a + bound_b <= i:
                    l = mid
                else:
                    r = mid
            return r

        N, M = len(nums1), len(nums2)
        x = (N + M) // 2
        if N == 0:
            return nums2[x] if M % 2 == 1 else (nums2[x - 1] + nums2[x]) / 2

        if M == 0:
            return nums1[x] if N % 2 == 1 else (nums1[x - 1] + nums1[x]) / 2

        if (N + M) % 2 == 0:
            return (ith_elements(x, nums1, nums2) + ith_elements(x - 1, nums1, nums2)) / 2
        return ith_elements(x, nums1, nums2)


if __name__ == '__main__':
    s = Solution()
    print(s.findMedianSortedArrays(
        [], [3, 4]))
