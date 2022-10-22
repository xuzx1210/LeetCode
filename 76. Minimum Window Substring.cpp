class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> targetCount, counter;
        for (char &c : t)
            ++targetCount[c];
        int targetRemain = targetCount.size(), length = s.length();
        pair<int, int> range = {0, length - 1};
        for (int left = 0, right = 0; right < length; ++right)
        {
            char end = s[right];
            if (targetCount[end])
                if (++counter[end] == targetCount[end])
                    --targetRemain;
            for (; left <= right; ++left)
            {
                char start = s[left];
                if (!targetCount[start])
                    continue;
                if (counter[start] > targetCount[start])
                    --counter[start];
                else
                    break;
            }
            if (!targetRemain && right - left < range.second - range.first)
                range = {left, right};
        }
        return targetRemain ? "" : s.substr(range.first, range.second - range.first + 1);
    }
};
