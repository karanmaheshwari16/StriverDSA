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
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;

        if(root == nullptr) return ans;
        q.push(root);

        while(!q.empty()) {
            vector<int> level;
            int size = q.size();

            for(int i=0 ; i<size ; i++) {
                TreeNode* element = q.front();
                q.pop();
                level.push_back(element->val);
                
                if(element->left) q.push(element->left);
                if(element->right) q.push(element->right);
            }
            ans.push_back(level);
        }

        for(int i=1 ; i<ans.size() ; i+=2)
            reverse(ans[i].begin() , ans[i].end());
    
        return ans;
    }
};