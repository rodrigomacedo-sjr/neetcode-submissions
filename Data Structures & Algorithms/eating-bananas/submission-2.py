class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        small = 1
        big = -1
        for pile in piles:
            big = max(big, pile)

        while big > small:
            curr = (big + small) // 2

            s = 0
            for p in piles:
                s += math.ceil(p / curr)

            if s <= h:
                big = curr
            else:
                small = curr + 1

        return big
