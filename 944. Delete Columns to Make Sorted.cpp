class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        const size_t n = strs.size(), length = strs.front().length();
        int result = 0;
        for (size_t i = 0; i < length; ++i)
            for (size_t j = 1; j < n; ++j)
                if (strs[j][i] < strs[j - 1][i])
                {
                    ++result;
                    break;
                }
        return result;
    }
};
