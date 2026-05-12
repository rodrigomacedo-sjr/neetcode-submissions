class Solution {
private:
    void dfs(int vertice, vector<vector<int>>& adjList, vector<int>& colors, int color) {
        if (colors[vertice]) return;

        colors[vertice] = color;

        for (auto adj : adjList[vertice])
            dfs(adj, adjList, colors, color);
    }

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);

        for (auto e : edges) {
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }

        vector<int> colors(n);
        int color = 0;

        for (int vertice = 0; vertice < n; ++vertice)
            if (!colors[vertice])
                dfs(vertice, adjList, colors, ++color);

        return color;
    }
};
