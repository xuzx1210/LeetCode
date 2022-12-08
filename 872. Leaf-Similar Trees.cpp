class Solution
{
private:
    void dfs(TreeNode *root, vector<int> &sequence)
    {
        if (!root)
            return;
        if (!root->left && !root->right)
        {
            sequence.emplace_back(root->val);
            return;
        }
        dfs(root->left, sequence);
        dfs(root->right, sequence);
    }

public:
    bool
    leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> sequence1{}, sequence2{};
        dfs(root1, sequence1);
        dfs(root2, sequence2);
        return sequence1 == sequence2;
    }
};
