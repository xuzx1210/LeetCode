class Solution
{
private:
    int skillCount, peopleCount;
    vector<int> result, team, peopleSkills;
    vector<vector<int>> dp;
    void dfs(const int index, const int skills)
    {
        if (result.size() <= team.size()) // worse than result
            return;
        if (skills + 1 == (1 << skillCount)) // save smallest team
            result = team;
        if (index == peopleCount || dp[index][skills] <= team.size()) // out of range or worse than before
            return;
        dp[index][skills] = team.size(); // save smalleest team
        dfs(index + 1, skills);          // no hire
        team.emplace_back(index);
        dfs(index + 1, skills | peopleSkills[index]); // hire
        team.pop_back();
    }

public:
    vector<int> smallestSufficientTeam(vector<string> &req_skills, vector<vector<string>> &people)
    {
        skillCount = req_skills.size(), peopleCount = people.size();
        result.resize(peopleCount);
        iota(result.begin(), result.end(), 0);
        team.clear();
        peopleSkills.resize(peopleCount, 0);
        dp.resize(peopleCount, vector<int>((1 << skillCount), peopleCount));
        unordered_map<string, int> skills{};
        for (int i = 0; i < skillCount; ++i)
            skills[req_skills[i]] = (1 << i);
        for (int i = 0; i < peopleCount; ++i)
            for (const string &skill : people[i])
                peopleSkills[i] |= skills[skill];
        dfs(0, 0);
        return result;
    }
};
