class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        vector<int> hash(128, -1);
        int length = s.length();
        for (int i = 0; i < length; ++i)
            if (hash[s[i]] == -1)
                hash[s[i]] = t[i];
            else if (hash[s[i]] != t[i])
                return false;
        vector<int> remain({});
        for (int c : hash)
            if (c != -1)
                remain.push_back(c);
        int size = remain.size();
        for (int i = 0; i < size - 1; ++i)
            for (int j = i + 1; j < size; ++j)
                if (remain[i] == remain[j])
                    return false;
        return true;
    }
};
