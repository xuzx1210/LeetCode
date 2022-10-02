class Solution
{
public:
    int maxProduct(vector<string> &words)
    {
        int size = words.size();
        vector<vector<bool>> alphabet(size, vector<bool>(26));
        for (int i = 0; i < size; ++i)
            for (char &c : words[i])
                alphabet[i][c - 'a'] = true;
        int result = 0;
        for (int i = 0; i < size - 1; ++i)
            for (int j = i + 1; j < size; ++j)
            {
                bool overlap = false;
                for (int k = 0; k < 26; ++k)
                    if (alphabet[i][k] && alphabet[j][k])
                    {
                        overlap = true;
                        break;
                    }
                if (!overlap)
                    result = max(result, (int)(words[i].length() * words[j].length()));
            }
        return result;
    }
};
