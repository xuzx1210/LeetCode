class Solution
{
private:
    long long sum;
    int findSum(TreeNode *root)
    {
        if (!root)
            return 0;
        return root->val += findSum(root->left) + findSum(root->right);
    }
    long long findMaxProduct(TreeNode *root)
    {
        if (!root)
            return 0;
        return max(root->val * (sum - root->val), max(findMaxProduct(root->left), findMaxProduct(root->right)));
    }

public:
    int maxProduct(TreeNode *root)
    {
        sum = findSum(root);
        return findMaxProduct(root) % 1000000007;
    }
};
