class Solution
{
private:
    int binarySearch(vector<int> &row)
    {
        int left = 0, right = row.size();
        while (left < right)
        {
            const int middle = (left + right) >> 1;
            if (row[middle])
                left = middle + 1;
            else
                right = middle;
        }
        return left;
    }

public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        vector<int> result(k);
        const int m = mat.size(), n = mat.front().size();
        priority_queue<pair<int, int>> pq{};
        for (int i = 0; i < k; ++i)
            pq.emplace(binarySearch(mat[i]), i);
        for (int i = k; i < m; ++i)
        {
            pq.emplace(binarySearch(mat[i]), i);
            pq.pop();
        }
        for (int i = k - 1; i >= 0; --i)
        {
            result[i] = pq.top().second;
            pq.pop();
        }
        return result;
    }
};
