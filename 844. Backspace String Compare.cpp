class Solution
{
private:
    int typing(string &str)
    {
        int result = 0;
        for (char c : str)
            if (c == '#')
                result = max(0, result - 1);
            else
                str[result++] = c;
        return result;
    }

public:
    bool backspaceCompare(string s, string t)
    {
        const int sLength = typing(s), tLength = typing(t);
        if (sLength != tLength)
            return false;
        return equal(s.begin(), s.begin() + sLength, t.begin());
    }
};
