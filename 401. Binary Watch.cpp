class Solution
{
private:
    void findNums(int cur, const int limit, int remainLength, int remainBits, vector<int> &nums)
    {
        if (remainBits > remainLength)
            return;
        if (!remainLength)
        {
            if (cur < limit)
                nums.emplace_back(cur);
            return;
        }
        cur <<= 1;
        --remainLength;
        findNums(cur, limit, remainLength, remainBits, nums);
        if (remainBits)
            findNums(cur + 1, limit, remainLength, remainBits - 1, nums);
    }

public:
    vector<string> readBinaryWatch(int turnedOn)
    {
        vector<string> result;
        for (int hourBits = 0; hourBits <= turnedOn && hourBits <= 4; ++hourBits)
        {
            const int minuteBits = turnedOn - hourBits;
            if (minuteBits > 6)
                continue;
            vector<int> hours, minutes;
            findNums(0, 12, 4, hourBits, hours);
            findNums(0, 60, 6, minuteBits, minutes);
            const size_t hourSize = hours.size(), minuteSize = minutes.size();
            for (size_t i = 0; i < hourSize; ++i)
                for (size_t j = 0; j < minuteSize; ++j)
                {
                    string tmp(to_string(hours[i]) + ':');
                    if (minutes[j] < 10)
                        tmp.push_back('0');
                    tmp += to_string(minutes[j]);
                    result.emplace_back(tmp);
                }
        }
        return result;
    }
};
