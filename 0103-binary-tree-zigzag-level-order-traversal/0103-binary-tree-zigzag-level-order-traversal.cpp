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
        
        queue<TreeNode*>q;
        q.push(root);
        bool flag=false;
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        while(!q.empty()){
           int n=q.size();
           deque<int>v;

           for(int i=0;i<n;i++){
            TreeNode* node=q.front();
            q.pop();

            if(flag){
                v.push_front(node->val);
            }
            else{
                v.push_back(node->val);
            }
           if(node->left)q.push(node->left);
           if(node->right)q.push(node->right);

           }
           flag=!flag;
           ans.push_back(vector<int>(v.begin(),v.end()));

        }
        return ans;
    }
};