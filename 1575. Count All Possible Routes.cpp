// recursive
class Solution
{
private:
    int mod, size, target;
    vector<vector<int>> dp;
    int dfs(const int curr, const int fuel, const vector<int> &locations)
    {
        if (fuel < 0)
            return 0;
        if (dp[curr][fuel] != -1)
            return dp[curr][fuel];
        dp[curr][fuel] = curr == target ? 1 : 0;
        for (int next = 0; next < size; ++next)
            if (next != curr)
                dp[curr][fuel] = (dp[curr][fuel] + dfs(next, fuel - abs(locations[curr] - locations[next]), locations)) % mod;
        return dp[curr][fuel];
    }

public:
    int countRoutes(vector<int> &locations, int start, int finish, int fuel)
    {
        mod = 1000000007;
        size = locations.size();
        target = finish;
        dp.resize(size, vector<int>(fuel + 1, -1));
        return dfs(start, fuel, locations);
    }
};

//iterative
class Solution
{
public:
    int countRoutes(vector<int> &locations, int start, int finish, int fuel)
    {
        const int mod = 1000000007;
        const int size = locations.size();
        vector<vector<int>> dp(size, vector<int>(fuel + 1, 0));
        dp[start][fuel] = 1;
        for (int remainFuel = fuel; remainFuel >= 0; --remainFuel)
            for (int src = 0; src < size; ++src)
                for (int dst = 0; dst < size; ++dst)
                {
                    if (dst == src)
                        continue;
                    const int cost = abs(locations[src] - locations[dst]);
                    if (cost > remainFuel)
                        continue;
                    int &cur = dp[dst][remainFuel - cost];
                    cur += dp[src][remainFuel];
                    cur %= mod;
                }
        int result = 0;
        for (int remainFuel = 0; remainFuel <= fuel; ++remainFuel)
            result = (result + dp[finish][remainFuel]) % mod;
        return result;
    }
};
