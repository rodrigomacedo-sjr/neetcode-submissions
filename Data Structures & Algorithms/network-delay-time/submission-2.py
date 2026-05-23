from heapq import heappush, heappop


class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        adj = [[] for _ in range(n + 1)]
        for a, b, c in times:
            adj[a].append((c, b))

        max_time = 0
        visited = set()

        h = [(0, k)]
        while h:
            cost, curr = heappop(h)

            if curr in visited:
                continue

            max_time = max(max_time, cost)
            visited.add(curr)

            for weight, neighbour in adj[curr]:
                heappush(h, (cost + weight, neighbour))

        return max_time if len(visited) == n else -1
