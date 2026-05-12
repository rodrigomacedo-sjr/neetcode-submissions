class Solution {
private:
    void dfs(int& edge, vector<vector<int>>& adjList, vector<int>& colors, int& color, int previous) {
        if (colors[edge]) return;

        colors[edge] = color;

        for (auto adj : adjList[edge]) {
            if (adj == previous) continue;

            dfs(adj, adjList, colors, color, edge);
        }
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

        for (int edge = 0; edge < n; ++edge)
            if (!colors[edge])
                dfs(edge, adjList, colors, ++color, -1);

        return color;
    }
};
