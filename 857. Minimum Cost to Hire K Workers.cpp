class Solution
{
public:
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k)
    {
        const int n = quality.size();
        vector<pair<double, int>> ratio(n);
        for (int i = 0; i < n; ++i)
            ratio[i] = {(double)wage[i] / quality[i], i};
        sort(ratio.begin(), ratio.end());
        priority_queue<int> qualitiesOfHiredWorkers{};
        int qualitySum = 0;
        for (int i = 0; i < k; ++i)
        {
            const int currWorkerQuality = quality[ratio[i].second];
            qualitySum += currWorkerQuality;
            qualitiesOfHiredWorkers.emplace(currWorkerQuality);
        }
        double result = qualitySum * ratio[k - 1].first;
        for (int i = k; i < n; ++i)
        {
            qualitySum -= qualitiesOfHiredWorkers.top();
            qualitiesOfHiredWorkers.pop();
            const int currWorkerQuality = quality[ratio[i].second];
            qualitySum += currWorkerQuality;
            qualitiesOfHiredWorkers.emplace(currWorkerQuality);
            result = min(result, qualitySum * ratio[i].first);
        }
        return result;
    }
};
