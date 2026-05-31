class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        SIZE1, SIZE2 = len(s1), len(s2)

        if SIZE1 > SIZE2:
            return False

        d1, d2 = {}, {}

        for i in range(SIZE2):
            if i < SIZE1:
                d1[s1[i]] = d1.get(s1[i], 0) + 1
                d2[s2[i]] = d2.get(s2[i], 0) + 1
                continue
            if d1 == d2:
                return True

            d2[s2[i]] = d2.get(s2[i], 0) + 1

            remove = s2[i - SIZE1]
            d2[remove] = d2.get(remove, 0) - 1
            if d2[remove] <= 0:
                d2.pop(remove, None)

        return d1 == d2
