class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> block(numCourses, vector<int>({}));
        vector<int> blocked(numCourses, 0);
        for (auto prerequisite : prerequisites)
        {
            block[prerequisite[1]].push_back(prerequisite[0]);
            ++blocked[prerequisite[0]];
        }
        vector<int> bfs({});
        for (int i = 0; i < numCourses; ++i)
            if (!blocked[i])
                bfs.push_back(i);
        for (int i = 0; i < bfs.size(); ++i)
            for (int next : block[bfs[i]])
                if (!(--blocked[next]))
                    bfs.push_back(next);
        return bfs.size() == numCourses;
    }
};
