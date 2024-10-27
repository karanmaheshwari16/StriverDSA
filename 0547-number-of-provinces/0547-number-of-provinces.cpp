class Solution {
private:
    void dfs(int node, vector<vector<int>> &isConnected, vector<int> &visited) {
        visited[node] = 1;
        for(int i=0 ; i<isConnected.size() ; i++) {
            if(isConnected[node][i] == 1 and !visited[i])
                dfs(i, isConnected, visited);
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0);

        int cnt = 0;

        for(int i=0 ; i<n ; i++) {
            if(visited[i] == 0) {
                cnt++;
                dfs(i, isConnected, visited);
            }
        }

        return cnt;
    }
};