class Solution
{
public:
    vector<string> readBinaryWatch(int turnedOn)
    {
        vector<string> result;
        for (int hour = 0; hour < 12; ++hour)
            for (int minute = 0; minute < 60; ++minute)
                if (bitset<10>(hour << 6 | minute).count() == turnedOn)
                    result.push_back(to_string(hour) + ":" + (minute < 10 ? "0" : "") + to_string(minute));
        return result;
    }
};
