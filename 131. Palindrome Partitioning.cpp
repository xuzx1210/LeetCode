class Solution
{
public:
    string str;
    vector<string> cur;
    vector<vector<string>> result;
    vector<vector<bool>> palindrome;
    bool isPalindrome(int start, int end)
    {
        int half = (end - start + 1) >> 1;
        for (int i = 0; i < half; ++i)
            if (str[start + i] != str[end - i])
                return false;
        return true;
    }
    void dfs(const int start)
    {
        if (start == str.length())
        {
            result.push_back(cur);
            return;
        }
        for (int i = start; i < str.length(); ++i)
            if (palindrome[start][i])
            {
                cur.push_back(string(str, start, i - start + 1));
                dfs(i + 1);
                cur.pop_back();
            }
    }
    vector<vector<string>> partition(string s)
    {
        str = s;
        cur = {};
        result = {};
        int length = s.length();
        palindrome = vector<vector<bool>>(length, vector<bool>(length, false));
        for (int i = 0; i < length; ++i)
            for (int j = i; j < length; ++j)
                palindrome[i][j] = isPalindrome(i, j);
        dfs(0);
        return result;
    }
};
