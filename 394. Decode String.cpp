class Solution
{
private:
    string dfs(string &s, int &index)
    {
        string result;
        while (index < s.length())
            if (isdigit(s[index]))
            {
                int k = 0;
                while (isdigit(s[index]))
                    k = k * 10 + (s[index++] - '0');
                ++index;
                string encoded_string(dfs(s, index));
                for (int i = 0; i < k; ++i)
                    result += encoded_string;
            }
            else if (islower(s[index]))
                result.push_back(s[index++]);
            else
                break;
        ++index;
        return result;
    }

public:
    string decodeString(string s)
    {
        int index = 0;
        return dfs(s, index);
    }
};
