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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]]=i;
        TreeNode* root=helper(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root;
    }
    TreeNode* helper(vector<int>& preorder,int prest,int preend,vector<int>& inorder,int inst,int inend,map<int,int>&mp)
    {
        if(prest>preend or inst>inend)
            return NULL;
        
        TreeNode* root=new TreeNode(preorder[prest]);
        
        int locroot=mp[root->val];
        int numsleft=locroot-inst;
        root->left=helper(preorder,prest+1,prest+numsleft,inorder,inst,locroot-1,mp);
        root->right=helper(preorder,prest+numsleft+1,preend,inorder,locroot+1,inend,mp);
        return root;
    }
};