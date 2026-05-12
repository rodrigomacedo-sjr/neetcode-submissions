class Solution {
private:
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void dfs(vector<vector<int>>& grid, int row, int col, vector<vector<bool>>& visited) {
        if (visited[row][col]) return;

        visited[row][col] = true;

        for (auto d: dirs) {
            int rowN = row + d[0];
            int colN = col + d[1];
            if (rowN < 0|| rowN >= grid.size() || colN < 0 || colN >= grid[0].size())
                continue;
            if (grid[row][col] <= grid[rowN][colN])
                dfs(grid, rowN, colN, visited);
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>> visitedP(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool>> visitedA(heights.size(), vector<bool>(heights[0].size(), false));

        for (int i = 0; i < heights.size(); ++i) {
            dfs(heights, i, 0, visitedP);
            dfs(heights, i, heights[0].size() - 1, visitedA);
        }

        for (int j = 0; j < heights[0].size(); ++j) {
            dfs(heights, 0, j, visitedP);
            dfs(heights, heights.size() - 1, j, visitedA);
        }
        
        vector<vector<int>> ans;
        for (int i = 0; i < heights.size(); ++i)
            for (int j = 0; j < heights[0].size(); ++j)
                if (visitedA[i][j] && visitedP[i][j])
                    ans.push_back({i, j});

        return ans;
    }
};
