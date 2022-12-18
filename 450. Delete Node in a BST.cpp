class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
            return nullptr;
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
        // root has two children, delete successor or predecessor node
        TreeNode *successor = root->left; // successor
        while (successor->right)
            successor = successor->right;
        root->val = successor->val;                          // root->val = successor
        root->left = deleteNode(root->left, successor->val); // delete successor node
        /*
        TreeNode *predecessor = root->right; // predecessor
        while (predecessor->left)
            predecessor = predecessor->left;
        root->val = predecessor->val;                            // root->val = predecessor
        root->right = deleteNode(root->right, predecessor->val); // delete predecessor node
        */
        return root;
    }
};
