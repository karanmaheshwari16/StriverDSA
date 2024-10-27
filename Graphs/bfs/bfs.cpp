class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        // Code here
        int n = adj.size();
        vector<int> v(n+1,0);
        v[0] = 1;
        queue<int> q;
        q.push(0);
        
        vector<int> bfs;
        
        while(!q.empty()) {
            int ele = q.front();
            q.pop();
            bfs.push_back(ele);
            
            for(auto i : adj[ele]) {
                if(v[i] == 0) {
                    v[i] = 1;
                    q.push(i);
                }
            }
        }
        return bfs;
    }
};