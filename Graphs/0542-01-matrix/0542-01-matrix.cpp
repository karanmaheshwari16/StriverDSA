class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int step = 0;
        queue<pair<pair<int, int>, int>> q;

        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<vector<int>> ans(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({{i, j}, step});
                    visited[i][j] = 1;
                }
            }
        }

        int row_dir[] = {-1, 0, 1, 0};
        int col_dir[] = {0, -1, 0, 1};

        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int moves = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int new_row = row + row_dir[i];
                int new_col = col + col_dir[i];

                if (new_row >= 0 && new_row < m && new_col >= 0 &&
                    new_col < n && !visited[new_row][new_col]) {
                    visited[new_row][new_col] = 1;
                    ans[new_row][new_col] = moves + 1;

                    q.push({{new_row, new_col}, moves + 1});
                }
            }
        }

        return ans;
    }
};
