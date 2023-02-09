class Solution
{
public:
    long long distinctNames(vector<string> &ideas)
    {
        long long result = 0;
        array<unordered_set<string>, 26> groupByInitial;
        for (const string &idea : ideas)
            groupByInitial[idea[0] - 'a'].emplace(idea, 1);
        for (int i = 0; i < 25; ++i)
            for (int j = i + 1; j < 26; ++j)
            {
                int validI = 0, validJ = 0;
                for (const string &str : groupByInitial[i])
                    if (groupByInitial[j].find(str) == groupByInitial[j].end())
                        ++validI;
                for (const string &str : groupByInitial[j])
                    if (groupByInitial[i].find(str) == groupByInitial[i].end())
                        ++validJ;
                result += validI * validJ;
            }
        return result << 1;
    }
};
