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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        vector<int>row;
        if(!root)
            return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int cnt=q.size();
            for(int i=0;i<cnt;i++)
            {
                root=q.front();
                q.pop();
                row.push_back(root->val);
                if(root->left!=NULL)
                    q.push(root->left);
                if(root->right!=NULL)
                q.push(root->right);
                
            }
            ans.push_back(row);
            row.clear();
        }
        return ans;
    }
};