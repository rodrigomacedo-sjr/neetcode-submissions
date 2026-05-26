class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        lasts = {char: i for i, char in enumerate(s)}
        ans = []
        start = 0
        end = 0
        for i, n in enumerate(s):
            end = max(end, lasts[n])
            if i == end:
                ans.append(i - start + 1)
                start = i + 1
        return ans
