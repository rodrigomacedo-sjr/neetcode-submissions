class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        sc = [0 for _ in range(26)]
        tc = [0 for _ in range(26)]

        for i in range(len(s)):
            sc[ord(s[i]) - ord('a')] += 1
            tc[ord(t[i]) - ord('a')] += 1
        
        for i in range(26):
            if sc[i] != tc[i]:
                return False

        return True