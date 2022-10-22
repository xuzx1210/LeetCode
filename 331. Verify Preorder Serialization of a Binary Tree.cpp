class Solution
{
public:
    bool isValidSerialization(string preorder)
    {
        preorder.push_back(',');
        int length = preorder.length(), left = 0, stack = 1;
        for (int right = 0; right < length; ++right)
            if (preorder[right] == ',')
            {
                if (!stack)
                    return false;
                stack += preorder[left] == '#' ? -1 : 1;
                left = right + 1;
            }
        return !stack;
    }
};
