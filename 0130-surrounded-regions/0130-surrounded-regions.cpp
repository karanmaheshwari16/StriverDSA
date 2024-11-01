class Solution {
private:
    int m, n;

    void dfs(int row, int col, vector<vector<char>>& board,
             vector<vector<int>>& visited) {
        if (row < 0 || col < 0 || row >= m || col >= n || visited[row][col] || board[row][col] != 'O') {
            return;
        }

        visited[row][col] = 1;

        dfs(row - 1, col, board, visited);
        dfs(row + 1, col, board, visited);
        dfs(row, col - 1, board, visited);
        dfs(row, col + 1, board, visited);
    }

public:
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        vector<vector<int>> visited(m, vector<int> (n, 0));

        // traverse the edge rows first (first and last)
        for(int i=0 ; i<m ; i++) {
            if(board[i][0] == 'O')
                dfs(i, 0, board, visited);

            if(board[i][n-1] == 'O')
                dfs(i, n-1, board, visited);
        }

        // traverse the edge cols then (first and last)
        for(int i=0 ; i<n ; i++) {
            if(board[0][i] == 'O')
                dfs(0, i, board, visited);

            if(board[m-1][i] == 'O')
                dfs(m-1, i, board, visited);
        }

        // convert all the 'O' to 'X' that are not visited
        for(int i=0 ; i<m ; i++) {
            for(int j=0 ; j<n ; j++) {
                if(!visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};