class Solution
{
private:
    unordered_map<string, vector<TreeNode *>> serializedSubtree;
    string dfs(TreeNode *node)
    {
        if (!node)
            return "";
        string result = "(" + dfs(node->left) + "," + to_string(node->val) + "," + dfs(node->right) + ")";
        serializedSubtree[result].emplace_back(node);
        return result;
    }

public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        serializedSubtree.clear();
        dfs(root);
        vector<TreeNode *> result{};
        for (const auto &[str, nodes] : serializedSubtree)
            if (nodes.size() > 1)
                result.push_back(nodes.front());
        return result;
    }
};
