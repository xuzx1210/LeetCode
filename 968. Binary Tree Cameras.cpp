class Solution
{
private:
    int result;
    /*
     * 0: leaf
     * 1: parent of leaf with a camera
     * 2: covered but no camera
     */
    int dfs(TreeNode *node)
    {
        if (!node)
            return 2;
        int left = dfs(node->left), right = dfs(node->right);
        if (left == 0 || right == 0)
        {
            ++result;
            return 1;
        }
        return left == 1 || right == 1 ? 2 : 0;
    }

public:
    int minCameraCover(TreeNode *root)
    {
        result = 0;
        return dfs(root) == 0 ? result + 1 : result;
    }
};
