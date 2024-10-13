/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


//BFS (breadth first search) solution for trees.

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        ios::sync_with_stdio(false); //ignore this
        queue<TreeNode*> q;
        vector<vector<int>> ans;

        if(root == nullptr) return ans;
        q.push(root);

        while(!q.empty()) {
            vector<int> level;
            int size = q.size();

            for(int i=0; i<size ; i++) {
                TreeNode* ele = q.front();
                q.pop();
                if(ele->left != nullptr) q.push(ele->left);
                if(ele->right != nullptr) q.push(ele->right);
                level.push_back(ele->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
};