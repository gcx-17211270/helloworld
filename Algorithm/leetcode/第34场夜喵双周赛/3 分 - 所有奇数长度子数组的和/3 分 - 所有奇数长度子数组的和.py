'''
简单前缀和模拟
'''
from typing import List
class Solution:
    def sumOddLengthSubarrays(self, arr: List[int]) -> int :

        ans = 0 
        S = []
        for i, val in enumerate(arr):
            if i == 0:
                S.append(val)
            else:
                S.append(S[-1] + val)

            if len(S) % 2 == 1:
                ans += S[-1]

                for j in range(1, len(S), 2):
                    ans += S[-1] - S[j]

            else:
                for j in range(0, len(S), 2):
                    ans += S[-1] - S[j]

        return ans