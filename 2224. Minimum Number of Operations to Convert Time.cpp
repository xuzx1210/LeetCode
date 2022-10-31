class Solution
{
public:
    int convertTime(string current, string correct)
    {
        int currentTime = stoi(current.substr(0, 2)) * 60 + stoi(current.substr(3, 2)), correctTime = stoi(correct.substr(0, 2)) * 60 + stoi(correct.substr(3, 2));
        int diff = correctTime - currentTime, result = 0;
        vector<int> deltaTime{60, 15, 5, 1};
        for (int &delta : deltaTime)
        {
            result += diff / delta;
            diff %= delta;
        }
        return result;
    }
};
