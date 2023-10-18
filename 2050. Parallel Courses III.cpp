class Solution
{
private:
    class Course
    {
    public:
        int startTime;
        int prevCount;
        vector<int> nextCourses;
        Course()
        {
            startTime = 0;
            prevCount = 0;
            nextCourses.clear();
        }
    };

public:
    int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time)
    {
        int result = 0;
        vector<Course> courses(n);
        for (const vector<int> &relation : relations)
        {
            const int prevCourse = relation[0] - 1, nextCourse = relation[1] - 1;
            courses[prevCourse].nextCourses.emplace_back(nextCourse);
            ++courses[nextCourse].prevCount;
        }
        queue<int> bfs{};
        for (int i = 0; i < n; ++i)
            if (courses[i].prevCount == 0)
                bfs.emplace(i);
        while (!bfs.empty())
        {
            const int course = bfs.front(), endTime = courses[course].startTime + time[course];
            bfs.pop();
            result = max(result, endTime);
            for (const int nextCourse : courses[course].nextCourses)
            {
                courses[nextCourse].startTime = max(courses[nextCourse].startTime, endTime);
                if (--courses[nextCourse].prevCount == 0)
                    bfs.emplace(nextCourse);
            }
        }
        return result;
    }
};
