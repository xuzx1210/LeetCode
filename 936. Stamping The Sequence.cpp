class Solution
{
private:
    bool match(string &stamp, string &target)
    {
        const int length = stamp.length();
        if (target == string(length, '?'))
            return false;
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
        string question(stampLength, '?');
        vector<int> result = {};
        int turn = 0;
        bool change = true;
        while (change)
        {
            change = false;
            for (int i = 0; i <= targetLength - stampLength; ++i)
            {
                string substring(target, i, stampLength);
                if (!match(stamp, substring))
                    continue;
                if (turn == turns)
                    return {};
                target.replace(i, stampLength, question);
                result.push_back(i);
                change = true;
                ++turn;
                i = i + stampLength - 1;
            }
        }
        if (target != string(targetLength, '?'))
            return {};
        reverse(result.begin(), result.end());
        return result;
    }
};
