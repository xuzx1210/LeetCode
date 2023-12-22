class Solution
{
public:
    int maxScore(string s)
    {
        int result = count(s.begin(), s.end() - 1, '0') + (s.back() == '1');
        for (int i = s.length() - 2, score = result; i; --i)
        {
            const int ds = (s[i] == '1') - (s[i] == '0');
            score += ds;
            result = max(result, score);
        }
        return result;
    }
};
