class Solution
{
private:
    vector<int> result;
    int cur, curCount, maxCount;
    void inorder(TreeNode *node, bool getResult)
    {
        if (node == nullptr)
            return;
        inorder(node->left, getResult);
        if (node->val != cur)
        {
            cur = node->val;
            curCount = 0;
        }
        ++curCount;
        if (getResult && curCount == maxCount)
            result.emplace_back(cur);
        maxCount = max(maxCount, curCount);
        inorder(node->right, getResult);
    }

public:
    vector<int> findMode(TreeNode *root)
    {
        result.clear();
        cur = -100001;
        curCount = 0;
        maxCount = 0;
        inorder(root, false);
        cur = -100001;
        curCount = 0;
        inorder(root, true);
        return result;
    }
};
