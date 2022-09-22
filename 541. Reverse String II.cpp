class Solution
{
public:
    string reverseStr(string s, int k)
    {
        int K = k << 1, length = s.length(), start = 0;
        for (start = 0; start + K <= length; start += K)
            reverse(s.begin() + start, s.begin() + start + k);
        reverse(s.begin() + start, s.begin() + min(start + k, length));
        return s;
    }
};
