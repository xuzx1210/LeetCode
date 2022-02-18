class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int m = 200;
        for (auto str : strs)
            m = min(m, (int)str.length());
        string result;
        result.clear();
        bool different = false;
        for (int i = 0; i < m; ++i)
        {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); ++j)
                if (c != strs[j][i])
                {
                    different = true;
                    break;
                }
            if (!different)
                result.push_back(c);
            else
                break;
        }
        return result;
    }
};
