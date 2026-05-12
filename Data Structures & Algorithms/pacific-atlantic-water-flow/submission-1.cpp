class Solution {
private:
    vector<vector<int>> ans;

    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void dfs(vector<vector<int>>& grid, int row, int col, const string& ocean, vector<vector<bool>>& visitedP, vector<vector<bool>>& visitedA) {
        if (ocean == "pacific") {
            visitedP[row][col] = true;
        }

        if (ocean == "atlantic" && !visitedA[row][col]) {
            visitedA[row][col] = true;
            if (visitedP[row][col])
                ans.push_back({row, col});
        }

        for (auto d : dirs) {
            int rowN = row + d[0];
            int colN = col + d[1];

            if (rowN < 0 || rowN >= grid.size() || colN < 0 || colN >= grid[0].size()) 
                continue;
            if (ocean == "pacific" && visitedP[rowN][colN])
                continue;
            if (ocean == "atlantic" && visitedA[rowN][colN])
                continue;
            if (grid[row][col] > grid[rowN][colN])
                continue;
            
            dfs(grid, rowN, colN, ocean, visitedP, visitedA);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>> visitedP(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool>> visitedA(heights.size(), vector<bool>(heights[0].size(), false));

        const string pacific = "pacific", atlantic = "atlantic";
        for (int i = 0; i < heights.size(); ++i)
            for (int j = 0; j < heights[0].size(); ++j)
                if (i == 0 || j == 0)
                    dfs(heights, i, j, pacific, visitedP, visitedA);

        for (int i = 0; i < heights.size(); ++i)
            for (int j = 0; j < heights[0].size(); ++j)
                if (i == heights.size() - 1 || j == heights[0].size() - 1)
                    dfs(heights, i, j, atlantic, visitedP, visitedA);
        return ans;
    }
};
