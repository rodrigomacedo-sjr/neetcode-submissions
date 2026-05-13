class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        SIZE = len(temperatures)
        output = [0] * SIZE
        s = []
        for idx, n in enumerate(temperatures):
            while s:
                i, x = s[-1]
                if n > x:
                    output[i] = idx - i
                    s.pop()
                else:
                    break
            s.append((idx, n))
            continue
        return output
