class Solution
{
private:
    void dfs(TreeNode *node, vector<int> &sequence)
    {
        if (node == nullptr)
            return;
        dfs(node->left, sequence);
        dfs(node->right, sequence);
        if (node->left == nullptr && node->right == nullptr)
            sequence.emplace_back(node->val);
    }

public:
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> sequence1{}, sequence2{};
        dfs(root1, sequence1);
        dfs(root2, sequence2);
        return sequence1 == sequence2;
    }
};
