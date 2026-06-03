class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        pair = []
        for i in range(len(position)):
            pair.append((position[i], speed[i]))
        pair.sort(reverse=True)

        fleets = []
        for p, s in pair:
            time = (target - p) / s
            if fleets and fleets[-1] >= time:
                time = fleets[-1]
                fleets.pop()
            fleets.append(time)
        
        return len(fleets)