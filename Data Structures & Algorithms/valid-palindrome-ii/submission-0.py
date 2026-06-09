class Solution:
    def validPalindrome(self, s: str) -> bool:
        l, r = 0, len(s) - 1

        while l < r:
            if s[l] != s[r]:
                a = s[:l] + s[l + 1:]
                b = s[:r] + s[r + 1:]
                print(a)
                print(b)
                return a == a[::-1] or b == b[::-1]
            l += 1
            r -= 1
        return True



