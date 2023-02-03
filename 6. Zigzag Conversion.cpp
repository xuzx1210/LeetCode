class Solution
{
private:
    string result;
    void addChar(const int index, string &s)
    {
        if (index < s.length())
            result.push_back(s[index]);
    }

public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        const int size = (numRows - 1) << 1;
        const int groups = s.length() / size;
        result = "";
        for (int i = 0; i <= groups; ++i)
            addChar(i * size, s);
        for (int j = 1; j < numRows - 1; ++j)
            for (int i = 0; i <= groups; ++i)
            {
                addChar(i * size + j, s);
                addChar((i + 1) * size - j, s);
            }
        for (int i = 0; i <= groups; ++i)
            addChar(i * size + numRows - 1, s);
        return result;
    }
};
