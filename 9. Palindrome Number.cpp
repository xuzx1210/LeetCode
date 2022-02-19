class Solution
{
public:
    bool isPalindrome(int x)
    {
        stringstream ss;
        ss.clear();
        ss << x;
        string num;
        ss >> num;
        for (int i = 0; i < (num.length() >> 1); ++i)
            if (num[i] != num[num.length() - i - 1])
                return false;
        return true;
    }
};
