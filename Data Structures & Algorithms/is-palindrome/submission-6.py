class Solution:
    def isPalindrome(self, s: str) -> bool:
        ns = ""
        for c in s:
            if c >= 'a' and c <= 'z':
                ns += c
            elif c >= 'A' and c <= 'Z':
                ns += c.lower()
            elif c >= '0' and c <= '9':
                ns += c
        print(ns)
        return ns == ns[::-1]