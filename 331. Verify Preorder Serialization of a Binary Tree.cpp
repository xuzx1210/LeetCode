class Solution
{
public:
    bool isValidSerialization(string preorder)
    {
        vector<bool> sharp;
        int length = preorder.length();
        int left = 0;
        for (int right = 0; right < length; ++right)
            if (preorder[right] == ',')
            {
                sharp.emplace_back(preorder[left] == '#');
                left = right + 1;
            }
        sharp.emplace_back(preorder[left] == '#');
        int stack = 1;
        for (bool s : sharp)
        {
            if (!stack)
                return false;
            stack += s ? -1 : 1;
        }
        return !stack;
    }
};
