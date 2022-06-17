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
    
    //DP on trees
    //define 3 states
    //need a camera -1
    //have a camera 0
    // u r covered 1
    // we start from bottom , leaf nodes always need a camera
    //and maybe for this reason we have to do postorder traversal(left,right,root)
    //so that we initially check for both the leaf nodes and get information from both left and right part and derive conclusion based on that for the parent
    
    
    int cameras=0;
    int helper(TreeNode* root)
    {
        if(root==NULL)
            return 1;
        int lchild=helper(root->left);
        int rchild=helper(root->right);
        if(lchild==-1 or rchild==-1){ //case when even 1 of my children need a camera
            cameras++;
            return 0;
        }
        if(lchild==0 or rchild==0)    //case when my children have camera , so i am covered
            return 1;
        return -1;          //case when my children r covered but then i need a camera from my parent
    }
    int minCameraCover(TreeNode* root) {
        if(helper(root)==-1)
            cameras++;
        return cameras;
    }
};