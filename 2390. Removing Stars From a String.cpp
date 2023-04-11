class Solution
{
public:
    string removeStars(string s)
    {
        int index = 0;
        for (char c : s)
            if (c == '*')
                --index;
            else
                s[index++] = c;
        return s.substr(0, index);
    }
};
