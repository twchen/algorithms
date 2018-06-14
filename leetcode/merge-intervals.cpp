/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considerred overlapping.
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

// note a special case [[1, 4], [2, 3]]
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans;
        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b){
           return a.start < b.start;
        });
        int n = intervals.size();
        for(int i = 0; i < n; ){
            Interval in = intervals[i];
            int j = i + 1;
            while(j < n && intervals[j].start <= in.end){
                in.end = max(in.end, intervals[j].end);
                ++j;
            }
            ans.push_back(in);
            i = j;
        }
        return ans;
    }
};
