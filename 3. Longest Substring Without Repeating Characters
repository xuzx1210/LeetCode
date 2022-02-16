class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int M = 0, length = s.length();
        for (int start = 0; start < length - M; ++start)
        {
            vector<bool> record(127, false);
            bool repeat = false;
            for (int end = start; end < length; ++end)
            {
                if (record[s[end]])
                {
                    M = max(M, end - start);
                    repeat = true;
                    break;
                }
                else
                    record[s[end]] = true;
            }
            if (!repeat)
                M = max(M, length - start);
        }
        return M;
    }
};
