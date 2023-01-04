class Solution
{
public:
    int minimumRounds(vector<int> &tasks)
    {
        unordered_map<int, int> difficultyCounter{};
        for (int &difficulty : tasks)
            ++difficultyCounter[difficulty];
        int result = 0;
        for (auto &[difficulty, count] : difficultyCounter)
        {
            if (count == 1)
                return -1;
            result += (count + 2) / 3;
        }
        return result;
    }
};
