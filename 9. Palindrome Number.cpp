class Solution
{
public:
    bool isPalindrome(int x)
    {
        string num = to_string(x);
        string tmp = num;
        reverse(tmp.begin(), tmp.end());
        return num == tmp;
    }
};
