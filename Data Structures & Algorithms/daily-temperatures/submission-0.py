class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        SIZE = len(temperatures)
        output = [0] * SIZE
        for i in range(SIZE):
            cur = temperatures[i]
            for j in range(i + 1, SIZE):
                if temperatures[j] > cur:
                    output[i] = j - i
                    break
        return output
