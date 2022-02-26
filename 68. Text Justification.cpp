class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> result({});
        while (words.size())
        {
            int charLength = 0;
            vector<string> tmp({});
            for (int i = 0; i < words.size(); ++i)
            {
                if (charLength + tmp.size() + words[i].length() > maxWidth)
                    break;
                tmp.push_back(words[i]);
                charLength += words[i].length();
            }
            words.erase(words.begin(), words.begin() + tmp.size());
            int spaceLength = maxWidth - charLength;
            if (tmp.size() == 1)
            {
                result.push_back(tmp[0] + string(spaceLength, ' '));
                continue;
            }
            if (!words.size())
            {
                string cur("");
                for (int i = 0; i < tmp.size() - 1; ++i)
                    cur += (tmp[i] + " ");
                cur += tmp.back();
                cur += string(maxWidth - cur.length(), ' ');
                result.push_back(cur);
                continue;
            }
            int quotient = spaceLength / (tmp.size() - 1), remainder = spaceLength % (tmp.size() - 1);
            string space(quotient, ' '), cur("");
            for (int i = 0; i < tmp.size() - 1; ++i)
            {
                cur += (tmp[i] + space);
                if (i < remainder)
                    cur.push_back(' ');
            }
            cur += tmp.back();
            result.push_back(cur);
        }
        return result;
    }
};
