class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        size_s = len(s)
        size_p = len(p)

        def dfs(i, j):
            if i == size_s:
                if j == size_p:
                    return True
                # check if p is empty forever
                for k in range(j + 1, size_p, 2):
                    if p[k] != "*":
                        return False
                return (size_p - j) % 2 == 0
            elif j == size_p:
                return False

            # can we go bonkers
            bonkers = False
            if j + 1 < size_p and p[j + 1] == "*":
                bonkers = True

            # valid
            valid = p[j] == "." or s[i] == p[j]

            if not bonkers and not valid:
                return False
            
            if valid and not bonkers:
                if dfs(i + 1, j + 1):
                    return True
            if valid and bonkers:
                if p[j] == "." or s[i] == p[j]:
                    if dfs(i + 1, j):
                        return True
                if dfs(i, j + 2):
                    return True
            if not valid and bonkers:
                if dfs(i, j + 2):
                    return True
            return False
        return dfs(0, 0)
            

     