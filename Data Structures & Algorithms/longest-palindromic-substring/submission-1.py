class Solution:
    def longestPalindrome(self, s: str) -> str:
        best = ""
        for i in range(len(s)):
            for j in range(i, len(s)):
                normal = s[i: j + 1]
                if normal == normal[::-1] and len(normal) > len(best):
                    best = normal
        return best