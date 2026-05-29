class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        res = []
        children = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz",
        }

        def dfs(idx, curr):
            return res.append(curr) if idx == len(digits) else [dfs(idx + 1, curr + c) for c in children[digits[idx]]]

        return res if digits and (dfs(0, "") or 1) else []
