class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        m = {}
        ans = set()
        treshold = len(nums) // 3
        for n in nums:
            m[n] = 1 + m.get(n, 0)
            if m[n] > treshold:
                ans.add(n)
        return list(ans)