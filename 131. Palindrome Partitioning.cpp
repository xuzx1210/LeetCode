class Solution
{
private:
    string s;
    size_t length;
    vector<vector<size_t>> palindrome;
    vector<string> path;
    vector<vector<string>> result;
    bool isPalindrome(size_t start, size_t end)
    {
        for (; start < end; ++start, --end)
            if (s[start] != s[end])
                return false;
        return true;
    }
    void dfs(const size_t index)
    {
        if (index == length)
        {
            result.emplace_back(path);
            return;
        }
        for (const size_t next : palindrome[index])
        {
            path.emplace_back(s, index, next - index);
            dfs(next);
            path.pop_back();
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        this->s = s;
        length = s.length();
        palindrome.resize(length, vector<size_t>{});
        for (size_t start = 0; start < length; ++start)
            for (size_t end = start; end < length; ++end)
                if (isPalindrome(start, end))
                    palindrome[start].emplace_back(end + 1);
        path.clear();
        result.clear();
        dfs(0);
        return result;
    }
};
