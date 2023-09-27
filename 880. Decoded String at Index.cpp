class Solution
{
public:
    string decodeAtIndex(string s, int k)
    {
        long length = 0;
        int index = 0;
        for (; length < k; ++index)
            if (isdigit(s[index]))
                length *= s[index] - '0';
            else
                ++length;
        while (index--)
            if (isdigit(s[index]))
            {
                length /= s[index] - '0';
                k %= length;
            }
            else if (k % length-- == 0)
                break;
        return string(1, s[index]);
    }
};
