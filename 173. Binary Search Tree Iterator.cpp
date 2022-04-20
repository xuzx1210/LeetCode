class BSTIterator
{
public:
    vector<TreeNode *> nodes;
    int index, size;
    void getNodes(TreeNode *node, vector<TreeNode *> &nodes)
    {
        if (!node)
            return;
        getNodes(node->left, nodes);
        nodes.push_back(node);
        getNodes(node->right, nodes);
    }
    BSTIterator(TreeNode *root)
    {
        nodes.clear();
        getNodes(root, nodes);
        size = nodes.size();
        nodes.insert(nodes.begin(), nullptr);
        index = 0;
    }
    int next()
    {
        return nodes[++index]->val;
    }
    bool hasNext()
    {
        return index < size;
    }
};
