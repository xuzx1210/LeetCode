class Solution
{
public:
    int maxValueOfCoins(vector<vector<int>> &piles, int k)
    {
        const int n = piles.size();
        for (vector<int> &pile : piles) // prefix sum for every pile
            for (int i = 1; i < pile.size(); ++i)
                pile[i] += pile[i - 1];
        vector<int> dp0(k + 1, 0), dp1(k + 1, 0);            // dp0: piles[0 : pileCount - 1], dp1: piles[0 : pileCount]
        for (int pileCount = 1; pileCount <= n; ++pileCount) // current pile is piles[pileCount - 1], considering piles[0 : pileCount]
        {
            for (int coinCount = 1; coinCount <= k; ++coinCount)                                         // coinCount: how many coins will be taken from piles[0 : pileCount]
                for (int coins = 1; coins <= coinCount && coins <= piles[pileCount - 1].size(); ++coins) // coins: how many coins will be taken from piles[pileCount - 1]
                    dp1[coinCount] = max(dp1[coinCount], dp0[coinCount - coins] + piles[pileCount - 1][coins - 1]);
            dp0 = dp1;
        }
        return dp0[k];
    }
};
