class Codec
{
private:
    void serialize(TreeNode *cur, string &result)
    {
        if (!cur)
        {
            result += "1001 ";
            return;
        }
        result += (to_string(cur->val) + ' ');
        serialize(cur->left, result);
        serialize(cur->right, result);
    }
    TreeNode *deserialize(istringstream &iss)
    {
        int cur;
        iss >> cur;
        if (cur == 1001)
            return nullptr;
        TreeNode *result = new TreeNode(cur);
        result->left = deserialize(iss);
        result->right = deserialize(iss);
        return result;
    }

public:
    string serialize(TreeNode *root)
    {
        string result = "";
        serialize(root, result);
        return result;
    }
    TreeNode *deserialize(string data)
    {
        istringstream iss(data);
        return deserialize(iss);
    }
};
