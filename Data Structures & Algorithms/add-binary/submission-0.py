class Solution:
    def addBinary(self, a: str, b: str) -> str:
        res = ""
        i, j = len(a) - 1, len(b) - 1
        carry = 0

        while i >= 0 or j >= 0:
            v1 = 1 if not i < 0 and a[i] == "1" else 0
            v2 = 1 if not j < 0 and b[j] == "1" else 0
            res = str((v1 + v2 + carry) % 2) + res
            carry = 1 if v1 + v2 + carry > 1 else 0

            i -= 1
            j -= 1

        return str(carry) + res if carry else res
