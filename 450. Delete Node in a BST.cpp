class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
            return root;
        if (key < root->val) // go left
        {
            root->left = deleteNode(root->left, key);
            return root;
        }
        if (root->val < key) // go right
        {
            root->right = deleteNode(root->right, key);
            return root;
        }
        // key == root->val
        if (!root->left && !root->right) // root is leaf
            return nullptr;
        if (!root->left || !root->right) // root has one child
            return root->left ? root->left : root->right;
        // root has two children
        TreeNode *cur = root->left;
        while (cur->right)
            cur = cur->right;
        root->val = cur->val;                          // root->val = successor
        root->left = deleteNode(root->left, cur->val); // delete successor
        return root;
    }
};
