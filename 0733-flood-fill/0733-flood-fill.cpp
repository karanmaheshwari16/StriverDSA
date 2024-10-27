class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& image, vector<vector<bool>>& visited, int color, int orignalcolor) {
        if(row < 0 || col < 0 || row >= image.size() || col >= image[0].size() || visited[row][col] == 1 || image[row][col] != orignalcolor) {
            return;
        }

        visited[row][col] = 1;
        image[row][col] = color;

        dfs(row - 1, col, image, visited, color, orignalcolor);
        dfs(row + 1, col, image, visited, color, orignalcolor);
        dfs(row, col - 1, image, visited, color, orignalcolor);
        dfs(row, col + 1, image, visited, color, orignalcolor);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<bool>> visited(n, vector<bool> (m,0));
        int orignalcolor = image[sr][sc];

        //not required to traverse through all the nodes, just the ones connected with the give node at sr and sc

        // for(int i=0 ; i<n ; i++) {
        //     for(int j=0 ; j<m ; j++) {
        //         if(!visited[i][j]) {
        //             dfs(i, j, image, visited, color);
        //         }
        //     }
        // }

        dfs(sr, sc, image, visited, color, orignalcolor);
        return image;
    }
};