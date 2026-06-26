class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        has = {}
        for n in nums:
            if has.get(n):
                return True
            has[n] = True
        return False