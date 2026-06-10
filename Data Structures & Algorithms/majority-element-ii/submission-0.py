class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        m = {}
        ans = set()
        for n in nums:
            m[n] = 1 + m.get(n, 0)
            if m[n] > len(nums) // 3:
                ans.add(n)
        return list(ans)