class Solution
{
private:
    int skillCount, peopleCount;
    vector<int> result, team, peopleSkills;
    vector<vector<int>> dp;
    void dfs(const int index, const int skills)
    {
        if (skills + 1 == (1 << skillCount) && team.size() < result.size())
        {
            result = team;
            return;
        }
        if (index == peopleCount || dp[index][skills] <= team.size())
            return;
        dp[index][skills] = team.size();
        dfs(index + 1, skills);
        team.emplace_back(index);
        dfs(index + 1, skills | peopleSkills[index]);
        team.pop_back();
    }

public:
    vector<int> smallestSufficientTeam(vector<string> &req_skills, vector<vector<string>> &people)
    {
        skillCount = req_skills.size(), peopleCount = people.size();
        result.resize(peopleCount);
        iota(result.begin(), result.end(), 0);
        team.clear();
        peopleSkills.clear();
        dp.resize(peopleCount, vector<int>((1 << skillCount), peopleCount + 1));
        unordered_map<string, int> skills{};
        for (int i = 0; i < skillCount; ++i)
            skills[req_skills[i]] = (1 << i);
        for (const vector<string> &person : people)
        {
            int skillBitMask = 0;
            for (const string &skill : person)
                skillBitMask |= skills[skill];
            peopleSkills.emplace_back(skillBitMask);
        }
        dfs(0, 0);
        return result;
    }
};
