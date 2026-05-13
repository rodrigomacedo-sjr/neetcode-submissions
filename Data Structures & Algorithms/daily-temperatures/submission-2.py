class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        SIZE = len(temperatures)
        output = [0] * SIZE
        s = []
        for idx, n in enumerate(temperatures):
            while s:
                i = s[-1]
                if n > temperatures[i]:
                    output[i] = idx - i
                    s.pop()
                else:
                    break
            s.append(idx)
        return output
