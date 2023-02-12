class Solution
{
private:
    long long result, seats;
    vector<vector<int>> graph;
    long long dfs(int city, int prev) // how many representatives go to capital from this city
    {
        long long representatives = 1; // one representative start from this city
        for (const int &next : graph[city])
        {
            if (next == prev) // avoid go from capital
                continue;
            representatives += dfs(next, city); // add all representatives who go pass this city
        }
        if (city == 0) // skip capital
            return 0;
        lldiv_t d = div(representatives, seats);
        result += d.quot; // how many car need to go to prev from this city
        if (d.rem != 0)
            ++result;
        return representatives;
    }

public:
    long long minimumFuelCost(vector<vector<int>> &roads, int seats)
    {
        const int n = roads.size() + 1;
        result = 0;
        this->seats = seats;
        graph.resize(n, vector<int>{});
        for (const vector<int> &road : roads)
        {
            graph[road[0]].emplace_back(road[1]);
            graph[road[1]].emplace_back(road[0]);
        }
        dfs(0, -1);
        return result;
    }
};
