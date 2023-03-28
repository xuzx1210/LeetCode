class Solution
{
public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        queue<pair<int, int>> last7{}, last30{}; // day, cost
        int result = 0;
        for (int day : days)
        {
            while (!last7.empty())
                if (last7.front().first + 7 <= day)
                    last7.pop();
                else
                    break;
            last7.emplace(day, result + costs[1]);
            while (!last30.empty())
                if (last30.front().first + 30 <= day)
                    last30.pop();
                else
                    break;
            last30.emplace(day, result + costs[2]);
            result = min({result + costs[0], last7.front().second, last30.front().second});
        }
        return result;
    }
};
