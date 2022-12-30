class Solution
{
public:
    vector<int> getOrder(vector<vector<int>> &tasks)
    {
        const size_t size = tasks.size();
        for (size_t i = 0; i < size; ++i)
            tasks[i].emplace_back(i);     // enqueueTime, processTime, index
        sort(tasks.begin(), tasks.end()); // sort by enqueueTime
        vector<int> result(size);
        priority_queue<pair<size_t, size_t>, vector<pair<size_t, size_t>>, greater<>> pq{}; // sort by 1. processIndex, 2. index
        for (size_t timer = 0, enqueueIndex = 0, processIndex = 0; processIndex < size; ++processIndex)
        {
            if (pq.empty()) // if pq is empty, get next enqueueTime
                timer = max(timer, (size_t)tasks[enqueueIndex][0]);
            for (; enqueueIndex < size && tasks[enqueueIndex][0] <= timer; ++enqueueIndex)
                pq.emplace(tasks[enqueueIndex][1], tasks[enqueueIndex][2]); // push processTime and index while enqueueTime <= timer
            timer += pq.top().first;                                        // update timer
            result[processIndex] = pq.top().second;
            pq.pop();
        }
        return result;
    }
};
