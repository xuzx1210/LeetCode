class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        const int n = spells.size(), m = potions.size();
        sort(potions.rbegin(), potions.rend());
        vector<int> result(n);
        for (int i = 0; i < n; ++i)
        {
            lldiv_t lld = lldiv(success, spells[i]);
            long long target = lld.quot;
            if (lld.rem)
                ++target;
            int left = 0, right = m;
            while (left < right)
            {
                const int middle = (left + right) >> 1;
                const long long cur = potions[middle];
                if (cur < target)
                    right = middle;
                else
                    left = middle + 1;
            }
            result[i] = left;
        }
        return result;
    }
};
