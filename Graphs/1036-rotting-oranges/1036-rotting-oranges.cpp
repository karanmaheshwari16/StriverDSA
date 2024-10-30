class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair< pair<int, int>, int>> q;
        int visited[m][n];

        for(int i=0 ; i<m ; i++) {
            for(int j=0 ; j<n ; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});    //co-ordinates and time
                    visited[i][j] = 2;
                }
                else {
                    visited[i][j] = 0;
                }
            }
        }

        int time_max = 0;
        int row_dir[] = {-1, 0, 1, 0};
        int col_dir[] = {0, 1, 0, -1};

        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            time_max = max(time_max, time);
            q.pop();


            for(int i=0 ; i<4 ; i++) {
                int new_row = row + row_dir[i];
                int new_col = col + col_dir[i];

                if(new_row>=0 && new_row<m && new_col>=0 && new_col<n && grid[new_row][new_col]==1 && visited[new_row][new_col]==0) {
                    q.push({{new_row, new_col}, time+1});
                    visited[new_row][new_col] = 2;
                }
            }
        }

        for(int i=0 ; i<m ; i++) {
            for(int j=0 ; j<n ; j++) {
                if(visited[i][j] != 2 && grid[i][j] == 1) return -1; 
            }
        }

        return time_max;
    }
};