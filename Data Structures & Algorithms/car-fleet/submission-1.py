class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        pairs = sorted(zip(position, speed), reverse=True)

        fleets = []
        for p, s in pairs:
            time = (target - p) / s
            if fleets and fleets[-1] >= time:
                time = fleets[-1]
                fleets.pop()
            fleets.append(time)
    
        return len(fleets)