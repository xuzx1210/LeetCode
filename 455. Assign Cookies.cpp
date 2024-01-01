class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        int result = 0;
        const int gSize = g.size(), sSize = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        for (int index = 0; result < gSize && index < sSize; ++index)
            if (g[result] <= s[index])
                ++result;
        return result;
    }
};
