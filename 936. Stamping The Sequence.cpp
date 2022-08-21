class Solution
{
private:
    bool match(string &stamp, string &target)
    {
        const int length = stamp.length();
        for (int i = 0; i < length; ++i)
            if (stamp[i] != target[i] && target[i] != '?')
                return false;
        return true;
    }

public:
    vector<int> movesToStamp(string stamp, string target)
    {
        const int stampLength = stamp.length(), targetLength = target.length();
        const int turns = 10 * targetLength;
        const string question(stampLength, '?');
        vector<int> result = {};
        int turn = 0;
        bool change = true;
        vector<bool> visited(targetLength - stampLength + 1, false);
        while (change)
        {
            change = false;
            for (int i = 0; i <= targetLength - stampLength; ++i)
            {
                if (visited[i])
                    continue;
                string substring(target, i, stampLength);
                if (substring == string(stampLength, '?'))
                {
                    visited[i] = true;
                    continue;
                }
                if (!match(stamp, substring))
                    continue;
                if (turn == turns)
                    return {};
                target.replace(i, stampLength, question);
                result.push_back(i);
                visited[i] = true;
                change = true;
                ++turn;
            }
        }
        if (target != string(targetLength, '?'))
            return {};
        reverse(result.begin(), result.end());
        return result;
    }
};
