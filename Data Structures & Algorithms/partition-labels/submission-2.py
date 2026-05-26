class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        ans = []
        lasts = {}

        for i, n in enumerate(s):
            lasts[n] = i
        
        curr = 0
        while curr < len(s):
            i = curr
            last = curr
            while i <= last:
                last = max(last, lasts[s[i]])
                i += 1
            ans.append(i - curr)
            curr = i

        return ans
