class Solution
{
private:
    string dfs(string &s, int &index)
    { // decode encoded_string between '[' and ']'
        string result;
        while (index < s.length())
            if (isdigit(s[index])) // find a number
            {
                int k = 0; // count k
                while (isdigit(s[index]))
                    k = k * 10 + (s[index++] - '0');
                string encoded_string(dfs(s, ++index)); // skip '[' and find encoded_string
                for (int i = 0; i < k; ++i)             // add encoded_string k times
                    result += encoded_string;
            }
            else if (islower(s[index])) // find a char
                result.push_back(s[index++]);
            else // find a ']'
                break;
        ++index; // skip ']'
        return result;
    }

public:
    string decodeString(string s)
    {
        int index = 0;
        return dfs(s, index);
    }
};
