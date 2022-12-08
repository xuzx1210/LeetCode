class Solution
{
private:
    int dfs(TreeNode *root, const long long remain)
    { // return how many path sum to remain from root to leaves
        if (!root)
            return 0;
        const long long cur = remain - root->val;
        return !cur + dfs(root->left, cur) + dfs(root->right, cur);
    }

public:
    int pathSum(TreeNode *root, int targetSum)
    { // sum of dfs for all nodes
        if (!root)
            return 0;
        return dfs(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
};
