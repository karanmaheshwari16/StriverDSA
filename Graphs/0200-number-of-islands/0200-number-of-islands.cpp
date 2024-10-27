class Solution {
private:
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || visited[row][col] || grid[row][col] == '0') 
            return;

        visited[row][col] = 1;

        dfs(row - 1, col, grid, visited);
        dfs(row + 1, col, grid, visited);
        dfs(row, col - 1, grid, visited);
        dfs(row, col + 1, grid, visited);
    }

public:
    // similar problem to find the number of provinces
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool> (m,0));
        int count = 0;

        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                if(grid[i][j] == '1' and !visited[i][j]) {
                    count++;
                    dfs(i, j, grid, visited);
                }   
            }
        }
        return count;
    }
};