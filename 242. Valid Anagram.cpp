class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> letters = {};
        for (char &c : s)
            ++letters[c];
        for (char &c : t)
            --letters[c];
        bool result = true;
        for (auto &p : letters)
            result = result && !p.second;
        return result;
    }
};
