class Solution
{
public:
    int numberOfWeakCharacters(vector<vector<int>> &properties)
    {
        map<int, vector<int>> table = {};
        for (vector<int> &property : properties)
            table[property[0]].emplace_back(property[1]);
        int maxDefense = 0, result = 0;
        for (auto it = table.rbegin(); it != table.rend(); ++it)
        {
            int defense = 0;
            for (int &num : it->second)
            {
                if (num < maxDefense)
                    ++result;
                defense = max(defense, num);
            }
            maxDefense = max(maxDefense, defense);
        }
        return result;
    }
};
