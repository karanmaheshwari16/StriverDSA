class Solution {
private:
    int m, n;

    void dfs(int row, int col, vector<vector<int>>& grid,
             vector<vector<int>>& visited) {
        if (row < 0 || col < 0 || row >= m || col >= n || grid[row][col] == 0 || visited[row][col] == 1) {
            return;
        }

        visited[row][col] = 1;

        dfs(row - 1, col, grid, visited);
        dfs(row + 1, col, grid, visited);
        dfs(row, col - 1, grid, visited);
        dfs(row, col + 1, grid, visited);
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1)
                dfs(i, 0, grid, visited);

            if (grid[i][n - 1] == 1)
                dfs(i, n - 1, grid, visited);
        }

        for (int i = 0; i < n; i++) {
            if (grid[0][i] == 1)
                dfs(0, i, grid, visited);

            if (grid[m - 1][i] == 1)
                dfs(m - 1, i, grid, visited);
        }

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && visited[i][j] == 0) {
                    count++;
                }
            }
        }

        return count;
    }
};