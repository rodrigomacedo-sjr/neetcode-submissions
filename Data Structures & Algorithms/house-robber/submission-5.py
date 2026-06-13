class Solution:
    def rob(self, nums: List[int]) -> int:
        nn, nnn = 0, 0
        nums.append(0)
        for n in nums[::-1]:
            n = max(n + nnn, nn)
            nnn = nn
            nn = n
        return nn
