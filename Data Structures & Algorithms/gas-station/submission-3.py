class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        SIZE = len(gas)
        end, start = 0, SIZE - 1
        tank = gas[start] - cost[start]

        while start > end:
            if tank >= 0:
                tank += gas[end] - cost[end]
                end += 1
            else:
                start -= 1
                tank += gas[start] - cost[start]

        return start if tank >= 0 else -1
