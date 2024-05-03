class Solution
{
private:
    int getRevision(int &position, const string &version)
    {
        int revision = 0;
        while (position < version.length() && version[position] != '.')
            revision = revision * 10 + (version[position++] - '0');
        ++position;
        return revision;
    }

public:
    int compareVersion(string version1, string version2)
    {
        const int length1 = version1.length(), length2 = version2.length();
        int position1 = 0, position2 = 0;
        while (position1 < length1 || position2 < length2)
        {
            const int revision1 = getRevision(position1, version1), revision2 = getRevision(position2, version2);
            if (revision1 < revision2)
                return -1;
            if (revision1 > revision2)
                return 1;
        }
        return 0;
    }
};
