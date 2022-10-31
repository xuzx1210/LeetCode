class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> coinUsed(amount + 1, amount + 1);
        coinUsed[0] = 0;
        for (int i = 1; i <= amount; ++i)
            for (int &coin : coins)
                if (coin <= i)
                    coinUsed[i] = min(coinUsed[i], coinUsed[i - coin] + 1);
        return coinUsed[amount] > amount ? -1 : coinUsed[amount];
    }
};
