class Solution
{
public:
    bool isPalindrome(string s)
    {
        vector<char> result({});
        for (auto c : s)
            if (isalnum(c))
                result.push_back(tolower(c));
        int size = result.size();
        int half = size >> 1;
        for (int i = 0; i < half; ++i)
            if (result[i] != result[size - i - 1])
                return false;
        return true;
    }
};
