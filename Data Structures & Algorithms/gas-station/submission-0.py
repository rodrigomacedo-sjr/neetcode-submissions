class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        SIZE = len(gas)
        for i in range(SIZE):
            tank = 0
            good = True
            for j in range(i, SIZE + i):
                tank += gas[j % SIZE]
                tank -= cost[j % SIZE]
                if tank < 0:
                    good = False
                    break
            if good:
                return i

        return -1