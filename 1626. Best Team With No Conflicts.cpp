class Solution
{
public:
    int bestTeamScore(vector<int> &scores, vector<int> &ages)
    {
        const int length = scores.size();
        vector<pair<int, int>> players(length);
        for (int i = 0; i < length; ++i)
            players[i] = {ages[i], scores[i]};
        sort(players.begin(), players.end());
        int result = 0;
        vector<int> dp(length);
        for (int i = 0; i < length; ++i)
        {
            dp[i] = players[i].second;
            for (int j = 0; j < i; ++j)
                if (players[j].first == players[i].first || players[j].second <= players[i].second)
                    dp[i] = max(dp[i], dp[j] + players[i].second);
            result = max(result, dp[i]);
        }
        return result;
    }
};
