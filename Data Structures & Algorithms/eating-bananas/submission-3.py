class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        small = 1
        big = max(piles)

        while big > small:
            curr = (big + small) // 2

            s = sum(math.ceil(p / curr) for p in piles)

            if s <= h:
                big = curr
            else:
                small = curr + 1

        return big