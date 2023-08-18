class Solution
{
public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads)
    {
        vector<vector<bool>> graph(n, vector<bool>(n, false));
        vector<int> degrees(n, 0);
        for (const vector<int> &road : roads)
        {
            const int a = road[0], b = road[1];
            graph[a][b] = true;
            graph[b][a] = true;
            ++degrees[a];
            ++degrees[b];
        }
        const int firstDegree = *max_element(degrees.begin(), degrees.end());
        vector<int> firstDegreeCites{};
        for (int city = 0; city < n; ++city)
            if (degrees[city] == firstDegree)
                firstDegreeCites.emplace_back(city);
        const int firstDegreeCitesSize = firstDegreeCites.size();
        if (2 <= firstDegreeCitesSize)
        {
            for (int i = 0; i < firstDegreeCitesSize; ++i)
                for (int j = i + 1; j < firstDegreeCitesSize; ++j)
                    if (!graph[firstDegreeCites[i]][firstDegreeCites[j]])
                        return firstDegree << 1;
            return (firstDegree << 1) - 1;
        }
        int secondDegree = 0;
        for (const int degree : degrees)
            if (degree < firstDegree)
                secondDegree = max(secondDegree, degree);
        vector<int> secondDegreeCites{};
        for (int city = 0; city < n; ++city)
            if (degrees[city] == secondDegree)
                secondDegreeCites.emplace_back(city);
        for (const int firstCity : firstDegreeCites)
            for (const int secondCity : secondDegreeCites)
                if (!graph[firstCity][secondCity])
                    return firstDegree + secondDegree;
        return firstDegree + secondDegree - 1;
    }
};
