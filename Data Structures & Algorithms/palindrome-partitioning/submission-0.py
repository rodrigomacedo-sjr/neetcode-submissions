class Solution:
    def partition(self, s: str) -> List[List[str]]:
        SIZE = len(s)
        res = []

        def dfs(i, curr):
            if i >= SIZE:
                res.append(curr)
                return
            for j in range(i, SIZE):
                sub = s[i : j + 1]
                bus = sub[::-1]
                if sub == bus:
                    dfs(j + 1, curr + [sub])

        dfs(0, [])

        return res
