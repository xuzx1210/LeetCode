class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        const int arrLength = arr.size();
        const int target = arrLength - 1;
        unordered_map<int, vector<int>> indicesOfValue{};
        for (int i = 0; i < arrLength; ++i)
            indicesOfValue[arr[i]].emplace_back(i);
        vector<bool> visited(arrLength, false);
        visited[0] = true;
        queue<int> bfs({0});
        int steps = 0;
        while (!bfs.empty())
        {
            for (int size = bfs.size(); size; --size)
            {
                const int i = bfs.front();
                if (i == target)
                    return steps;
                bfs.pop();
                vector<int> &next = indicesOfValue[arr[i]];
                if (i)
                    next.emplace_back(i - 1);
                next.emplace_back(i + 1);
                for (int j : next)
                    if (!visited[j])
                    {
                        visited[j] = true;
                        bfs.emplace(j);
                    }
                next.clear();
            }
            ++steps;
        }
        return target;
    }
};
