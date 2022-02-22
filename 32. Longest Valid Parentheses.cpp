class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int result = 0;
        vector<int> starts({});
        for (int start = 0; start < s.length() - result; ++start)
        {
            if (find(starts.begin(), starts.end(), start) != starts.end())
                continue;
            int count = 0;
            for (int end = start; end < s.length(); ++end)
            {
                if (s[end] == ')')
                {
                    if (count)
                        --count;
                    else
                        break;
                }
                else
                    ++count;
                if (!count)
                {
                    result = max(result, end - start + 1);
                    starts.push_back(end + 1);
                }
            }
        }
        return result;
    }
};
