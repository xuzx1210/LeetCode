class BSTIterator
{
public:
    queue<int> nodes;
    void getNodes(TreeNode *node, queue<int> &nodes)
    {
        if (!node)
            return;
        getNodes(node->left, nodes);
        nodes.push(node->val);
        getNodes(node->right, nodes);
    }
    BSTIterator(TreeNode *root)
    {
        while (!nodes.empty())
            nodes.pop();
        getNodes(root, nodes);
    }
    int next()
    {
        int result = nodes.front();
        nodes.pop();
        return result;
    }
    bool hasNext()
    {
        return !nodes.empty();
    }
};
