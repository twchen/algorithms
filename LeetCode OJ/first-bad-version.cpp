/*
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.
*/

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1, end = n;
        while(true){
            if(isBadVersion(start) == isBadVersion(end)){
                return isBadVersion(start) ? start : end + 1;
            }
            int mid = ((double)start + end) / 2; // addition overflow
            if(isBadVersion(mid)){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
    }
};

// simple and concise solution
// credit: https://leetcode.com/discuss/66788/binary-search-in-c
class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1, end = n;
        while(start < end){
            int mid = start + (end - start) / 2;
            if(isBadVersion(mid)){
                end = mid;
            }else{
                start = mid + 1;
            }
        }
        return end;
    }
};
