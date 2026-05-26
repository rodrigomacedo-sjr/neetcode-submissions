class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        def stoi(s: str) -> int:
            num = 0
            for i in range(len(s)):
                num += (ord(s[i]) - ord('0')) * 10**(len(s) - i - 1)
            return num
        
        def itos(n: int) -> str:
            num = ""
            r = n
            while r > 0:
                l = r % 10
                r = r // 10
                num = chr(ord('0') + l) + num
            return num if num else "0"

        return itos(stoi(num1) * stoi(num2))