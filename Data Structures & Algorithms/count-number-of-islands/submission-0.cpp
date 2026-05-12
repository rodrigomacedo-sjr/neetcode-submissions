class Solution {
private:
    int dirs[4][2] {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void gridDfs(vector<vector<char>>& grid, int r, int c) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] != '1') return;

        cout << "im in\n";
        cout << "i: " << r << "\n";
        cout << "j: " << c << "\n\n";
        grid[r][c] = '#';

        for (auto d : dirs)
            gridDfs(grid, r + d[0], c + d[1]);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;

        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
                if (grid[i][j] == '1') {
                    gridDfs(grid, i, j);
                    count++;
                }

        return count;
    }
};
