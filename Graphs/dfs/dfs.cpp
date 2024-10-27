class Solution {
  private:
    void dfs(int node, vector<vector<int>>& adj, vector<int> &visited, vector<int> &list) {
        visited[node] = 1;
        
        list.push_back(node);
        
        for(auto it : adj[node]) {
            if(!visited[it]) {
                dfs(it, adj, visited, list);
            }
        }
    }
    
    
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int> visited(n+1, 0);
        // v[0] = 1;
        
        vector<int> list;
        dfs(0, adj, visited, list);
        return list;
    }
};