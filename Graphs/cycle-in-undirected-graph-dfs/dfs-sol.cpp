class Solution {
  private:
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& visited) {
        visited[node] = 1;
        
        for(auto it : adj[node]) {
            if(!visited[it]) {
                if(dfs(it, node, adj, visited)) return true;
            }
            
            else if(it != parent) return true;
        }
        return false;
    }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>> adj) {
        int n = adj.size();
        vector<int> visited(n, 0);
        
        for(int i=0 ; i<n ; i++) {
            if(!visited[i]) {
                if(dfs(i, -1, adj, visited)) return true;
            }
        }
        return false;
    }
};