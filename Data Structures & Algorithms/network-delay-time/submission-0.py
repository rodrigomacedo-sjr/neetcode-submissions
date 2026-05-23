from heapq import heappush, heappop


class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        h = []
        heappush(h, (0, k))

        adj = [[] for _ in range(n + 1)]
        for time in times:
            adj[time[0]].append((time[2], time[1]))

        visited = {}

        big = -1
        while h:
            cost, curr = heappop(h)

            if visited.get(curr, False):
                continue

            big = max(big, cost)
            visited[curr] = True

            for v in adj[curr]:
                heappush(h, (cost + v[0], v[1]))

        if len(visited) < n:
            return -1

        return big
