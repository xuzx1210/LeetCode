class Solution
{
public:
    string getSmallestString(int n, int k)
    {
        k -= n;
        auto d = div(k, 25);
        string result(d.quot, 'z');
        n -= d.quot;
        if (d.rem)
        {
            result.push_back('a' + d.rem);
            --n;
        }
        result += string(n, 'a');
        reverse(result.begin(), result.end());
        return result;
    }
};
