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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        int maxsum=INT_MIN;

        q.push(root);
        int lvl=1;
        int ans=0;
        while(!q.empty()){
            int n=q.size();
            int sum=0;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                sum+=node->val;
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            
            if(sum>maxsum){
               maxsum=sum;
               ans=lvl;
            }
            lvl++;
        }
        return ans;
    }
};