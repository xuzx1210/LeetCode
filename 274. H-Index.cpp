class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int maxCitation = 1000;
        vector<int> atLeast(maxCitation + 1, 0);
        for (int &citation : citations)
            ++atLeast[citation];
        for (int i = maxCitation; i > 0; --i)
        {
            if (atLeast[i] >= i)
                return i;
            atLeast[i - 1] += atLeast[i];
        }
        return 0;
    }
};
