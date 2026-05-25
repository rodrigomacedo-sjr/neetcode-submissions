class Solution:
    def partition(self, s: str) -> List[List[str]]:
        SIZE = len(s)

        def dfs(i):
            if i == SIZE:
                return [[]]
            ans = []
            for j in range(i, SIZE):
                sub = s[i : j + 1]
                bus = sub[::-1]
                if sub == bus:
                    ways = dfs(j + 1)
                    for way in ways:
                        way.insert(0, sub)
                        ans.append(way)
            return ans
                    

        return dfs(0)
