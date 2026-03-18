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
    int sum=0;
    void compute(TreeNode* root,int curr){
        if(root==NULL)return;
        curr=curr*2+root->val;
        if(root->left==NULL && root->right==NULL){
           sum+=curr;
           return;
        }

        compute(root->left,curr);
        compute(root->right,curr);
    }
    int sumRootToLeaf(TreeNode* root) {
        compute(root,0);
        return sum;
    }
};