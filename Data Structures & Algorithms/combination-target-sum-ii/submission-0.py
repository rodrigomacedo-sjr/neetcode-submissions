class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        res = []

        def dfs(idx, curr, curr_sum):    
            if curr_sum == target:
                res.append(curr[:])
                return
            if curr_sum > target:
                return
            
            for i in range(idx, len(candidates)):
                if i > idx and candidates[i] == candidates[i - 1]:
                    continue

                curr.append(candidates[i])
                dfs(i + 1, curr, curr_sum + candidates[i])
                curr.pop()
        
        dfs(0, [], 0)

        return res