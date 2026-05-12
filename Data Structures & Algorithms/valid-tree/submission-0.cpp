class Solution {
private:
    bool dfs(int curr, vector<vector<int>>& adjList, vector<bool>& visited, int prev) {
        if (visited[curr]) return false;

        visited[curr] = true;

        for (auto adj : adjList[curr]) {
            if (adj == prev) continue;
        
            if (!dfs(adj, adjList, visited, curr))
                return false;
        }

        return true;
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);

        for (auto e : edges) {
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);

        if (!dfs(0, adjList, visited, -1))
            return false;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) return false;
        }

        return true;
    }
};
