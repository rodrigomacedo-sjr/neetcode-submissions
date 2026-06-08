class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        def s(a):
            return a[1]

        tickets.sort(key=s)

        def dfs(path, t):
            if not t:
                return path
      
            for i in range(len(t)):
                if not (t[i][0] == path[-1]):
                    continue
                used = t.pop(i)
                path.append(used[1])
                ans = dfs(path, t)
                if ans:
                    return ans
                t.insert(i, used)
                path.pop()

            return []
        
        return dfs(["JFK"], tickets)
                
