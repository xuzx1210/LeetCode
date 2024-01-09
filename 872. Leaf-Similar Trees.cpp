class Solution
{
private:
    int getNext(stack<TreeNode *> &tree)
    {
        int result = -1;
        while (!tree.empty())
        {
            TreeNode *curr = tree.top();
            tree.pop();
            if (curr == nullptr)
                continue;
            result = curr->val;
            tree.emplace(curr->left);
            tree.emplace(curr->right);
            if (curr->left == nullptr && curr->right == nullptr)
                break;
        }
        return result;
    }

public:
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        stack<TreeNode *> tree1({root1}), tree2({root2});
        while (!tree1.empty() && !tree2.empty())
            if (getNext(tree1) != getNext(tree2))
                return false;
        return tree1.empty() && tree2.empty();
    }
};
