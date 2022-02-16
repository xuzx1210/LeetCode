class Solution
{
public:
    int myAtoi(string s)
    {
        while (s.length())
            if (s[0] == ' ')
                s.erase(s.begin());
            else
                break;
        bool negative = false;
        if (s.length())
            if (s[0] == '-')
            {
                negative = true;
                s.erase(s.begin());
            }
            else if (s[0] == '+')
                s.erase(s.begin());
        long long tmp = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if (isdigit(s[i]))
                tmp = tmp * 10 + s[i] - '0';
            else
                break;
            if (tmp > INT_MAX && !negative)
                return INT_MAX;
            if (-tmp < INT_MIN && negative)
                return INT_MIN;
        }
        int result = negative ? -tmp : tmp;
        return result;
    }
};
