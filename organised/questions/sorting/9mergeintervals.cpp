#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct interval
{
    int start;
    int end;
    interval(int x, int y) : start(x), end(y)
    {
    }
    interval()
    {
        start = -1;
        end = -1;
    }
};
bool mycmp(interval a, interval b)
{
    if (a.start == b.start)
        return a.end > b.end;

    return a.start < b.start;
}

bool overlap(interval a, interval b)
{
    return b.start <= a.end;
}
void mergeIntervals(vector<interval> &intervals)
{
    sort(intervals.begin(), intervals.end(), mycmp);
    for (auto i : intervals)
        cout << i.start << " " << i.end << endl;
    cout << endl;
    // int i = 0;
    // auto curr = intervals[i];
    // while (i < intervals.size())
    // {
    //     if (overlap(curr, intervals[i]))
    //     {
    //         curr = {curr.start, max(curr.end, intervals[i].end)};
    //     }
    //     else
    //     {
    //         cout << curr.start << "," << curr.end << endl;
    //         curr = intervals[i];
    //     }
    //     ++i;
    // }
    // cout << curr.start << "," << curr.end << endl;

    int res = 0;
    for (auto i : intervals)
    {
        if (intervals[res].end >= i.start)
        {
            intervals[res].start = min(intervals[res].start, i.start);
            intervals[res].end = max(intervals[res].end, i.end);
        }
        else
        {
            ++res;
            intervals[res] = i;
        }
    }

    for (int i = 0; i <= res; ++i)
    {
        cout << intervals[i].start << "," << intervals[i].end << endl;
    }
}

int main()
{
    vector<interval> intervals = {{7, 9}, {6, 10}, {4, 5}, {1, 3}, {2, 4}};
    mergeIntervals(intervals);
    return 0;
}