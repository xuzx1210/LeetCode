class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        vector<vector<int>> answer(2, vector<int>{});
        map<int, int> loses{};
        for (const vector<int> &match : matches)
        {
            const int winner = match[0], loser = match[1];
            loses[winner] = loses[winner];
            ++loses[loser];
        }
        for (const auto &[player, lost] : loses)
            if (lost < 2)
                answer[lost].emplace_back(player);
        return answer;
    }
};
