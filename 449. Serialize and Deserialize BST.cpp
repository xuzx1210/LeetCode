class Codec
{
private:
    void serializeDFS(TreeNode *cur, string &result)
    {
        if (!cur)
        {
            result.push_back('/');
            return;
        }
        result += to_string(cur->val);
        result.push_back('/');
        serializeDFS(cur->left, result);
        serializeDFS(cur->right, result);
    }
    TreeNode *deserializeDFS(vector<string> &splitted, size_t &index)
    {
        if (splitted[index] == "")
        {
            ++index;
            return nullptr;
        }
        TreeNode *result = new TreeNode(stoi(splitted[index++]));
        result->left = deserializeDFS(splitted, index);
        result->right = deserializeDFS(splitted, index);
        return result;
    }

public:
    string serialize(TreeNode *root)
    {
        string result{};
        serializeDFS(root, result);
        return result;
    }
    TreeNode *deserialize(string data)
    {
        vector<string> splitted{};
        const size_t length = data.length();
        for (size_t start = 0, end = 0; end < length; ++end)
            if (data[end] == '/')
            {
                splitted.emplace_back(data.begin() + start, data.begin() + end);
                start = end + 1;
            }
        size_t index = 0;
        return deserializeDFS(splitted, index);
    }
};
