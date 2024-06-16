class Solution
{

public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        const int n = profits.size();
        vector<pair<int, int>> projects{};
        for (int i = 0; i < n; ++i)
            projects.emplace_back(capital[i], i);
        sort(projects.begin(), projects.end());
        priority_queue<int> toIPO{};
        int availableProjects = 0;
        while (k--)
        {
            for (; availableProjects < n && projects[availableProjects].first <= w; ++availableProjects)
                toIPO.emplace(profits[projects[availableProjects].second]);
            if (toIPO.empty())
                break;
            w += toIPO.top();
            toIPO.pop();
        }
        return w;
    }
};
