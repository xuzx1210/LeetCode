class Solution
{
public:
    string reverseVowels(string s)
    {
        unordered_map<char, bool> vowel{{'a', true}, {'e', true}, {'i', true}, {'o', true}, {'u', true}, {'A', true}, {'E', true}, {'I', true}, {'O', true}, {'U', true}};
        vector<int> index;
        int length = s.length();
        for (int i = 0; i < length; ++i)
            if (vowel[s[i]])
                index.emplace_back(i);
        int size = index.size();
        int half = size >> 1;
        for (int i = 0; i < half; ++i)
            swap(s[index[i]], s[index[size - i - 1]]);
        return s;
    }
};
