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
    int maxdepth=INT_MIN;
    int solve(TreeNode* root){
        if(root==NULL)return 0;
        int left=max(0,solve(root->left));
        int right=max(0,solve(root->right));

        maxdepth=max(maxdepth,root->val+left+right);

        return root->val+max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxdepth;
    }
};