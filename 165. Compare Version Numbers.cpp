class Solution
{
public:
    vector<int> split(string version)
    {
        vector<int> result({});
        for (int i = 0; i < version.length(); ++i)
            if (version[i] == '.')
            {
                result.push_back(stoi(string(version, 0, i)));
                version.erase(0, i + 1);
                i = -1;
            }
        result.push_back(stoi(version));
        return result;
    }
    int compareVersion(string version1, string version2)
    {
        vector<int> v1(split(version1)), v2(split(version2));
        int minSize = min(v1.size(), v2.size());
        for (int i = 0; i < minSize; ++i)
        {
            if (v1[i] < v2[i])
                return -1;
            if (v1[i] > v2[i])
                return 1;
        }
        if (v1.size() < v2.size())
        {
            for (int i = minSize; i < v2.size(); ++i)
                if (v2[i])
                    return -1;
        }
        else
            for (int i = minSize; i < v1.size(); ++i)
                if (v1[i])
                    return 1;
        return 0;
    }
};
