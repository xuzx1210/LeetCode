class Solution
{
public:
    bool buddyStrings(string s, string goal)
    {
        const int length = s.length();
        if (length != goal.length())
            return false;
        unordered_map<char, int> count{};
        vector<int> indices{};
        for (int index = 0; index < length; ++index)
        {
            if (s[index] != goal[index])
                indices.emplace_back(index);
            ++count[s[index]];
        }
        if (indices.empty() && count.size() < length)
            return true;
        return indices.size() == 2 && s[indices[0]] == goal[indices[1]] && s[indices[1]] == goal[indices[0]];
    }
};
