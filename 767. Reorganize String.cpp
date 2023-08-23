class Solution
{
public:
    string reorganizeString(string s)
    {
        const int length = s.length();
        vector<int> frequency(26, 0);
        for (const char c : s)
            ++frequency[c - 'a'];
        const int maxIndex = max_element(frequency.begin(), frequency.end()) - frequency.begin();
        if (((length + 1) >> 1) < frequency[maxIndex])
            return "";
        int index = 0;
        for (; frequency[maxIndex]; index += 2, --frequency[maxIndex])
            s[index] = 'a' + maxIndex;
        for (int i = 0; i < 26; ++i)
            while (frequency[i]--)
            {
                if (length <= index)
                    index = 1;
                s[index] = 'a' + i;
                index += 2;
            }
        return s;
    }
};
