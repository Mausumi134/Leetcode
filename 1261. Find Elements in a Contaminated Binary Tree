class FindElements {
public:
    FindElements(TreeNode* root) { dfs(root, 0); }

    bool find(int target) { return seen.count(target) > 0; }

private:
    unordered_set<int> seen;

    void dfs(TreeNode* currentNode, int currentValue) {
        if (!currentNode) return;
        // visit current node by adding its value to seen
        seen.insert(currentValue);
        dfs(currentNode->left, currentValue * 2 + 1);
        dfs(currentNode->right, currentValue * 2 + 2);
    }
};