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
            if idx == len(digits):
                res.append(curr)
                return

            for c in children[digits[idx]]:
                dfs(idx + 1, curr + c)

        dfs(0, "")
        return res if digits else []
