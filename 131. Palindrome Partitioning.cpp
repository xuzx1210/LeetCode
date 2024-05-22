class Solution
{
private:
    vector<vector<string>> result;
    int length;
    vector<vector<bool>> isPalindrome;
    vector<string> substrings;
    void dfs(const int begin, const int end, const string &s)
    {
        if (begin == length)
            result.emplace_back(substrings);
        if (length < end)
            return;
        if (isPalindrome[begin][end])
        {
            substrings.emplace_back(s, begin, end - begin);
            dfs(end, end + 1, s);
            substrings.pop_back();
        }
        dfs(begin, end + 1, s);
    }

public:
    vector<vector<string>> partition(string s)
    {
        result.clear();
        substrings.clear();
        length = s.length();
        isPalindrome.resize(length, vector<bool>(length + 1, true));
        for (int len = 2; len <= length; ++len)
            for (int begin = 0, end = begin + len; end <= length; ++begin, ++end)
                isPalindrome[begin][end] = isPalindrome[begin + 1][end - 1] && s[begin] == s[end - 1];
        dfs(0, 1, s);
        return result;
    }
};
