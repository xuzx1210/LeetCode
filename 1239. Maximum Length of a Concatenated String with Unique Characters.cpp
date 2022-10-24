class Solution
{
public:
    int maxLength(vector<string> &arr)
    {
        vector<bitset<26>> possible{bitset<26>()};
        int result = 0;
        for (string &s : arr)
        {
            bitset<26> cur;
            for (char c : s)
                cur.set(c - 'a');
            if (cur.count() == s.length())
                for (int i = possible.size() - 1; i >= 0; --i)
                    if ((cur & possible[i]).none())
                    {
                        possible.emplace_back(cur | possible[i]);
                        result = max(result, (int)(cur.count() + possible[i].count()));
                    }
        }
        return result;
    }
};
