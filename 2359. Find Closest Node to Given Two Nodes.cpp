class Solution
{
private:
    void findDistance(int node, vector<bool> &visited, vector<int> &distances, vector<int> &edges)
    {
        for (int cur = node, distance = 0; cur != -1; cur = edges[cur])
        {
            if (visited[cur])
                return;
            visited[cur] = true;
            distances[cur] = distance++;
        }
    }

public:
    int closestMeetingNode(vector<int> &edges, int node1, int node2)
    {
        const int n = edges.size();
        vector<bool> visited1(n, false), visited2(n, false);
        vector<int> distances1(n, INT_MAX), distances2(n, INT_MAX);
        findDistance(node1, visited1, distances1, edges);
        findDistance(node2, visited2, distances2, edges);
        int result = -1, minDistance = INT_MAX;
        for (int i = 0; i < n; ++i)
        {
            int tmp = max(distances1[i], distances2[i]);
            if (tmp < minDistance)
            {
                minDistance = tmp;
                result = i;
            }
        }
        return result;
    }
};
