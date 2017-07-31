/*
Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are
such that A[i] + B[j] + C[k] + D[l] is zero.

To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500.
All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.

Example:

Input:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

Output:
2

Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
 */

// similar idea from 4sum
// time complexity: O(n^3)
// space complexity: O(1)
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        sort(C.begin(), C.end());
        sort(D.begin(), D.end());
        int count = 0;
        int n = A.size();
        for(int i = 0; i < n; ){
            int prev_i = i;
            while(i < n && A[i] == A[prev_i]) ++i;
            if(A[prev_i] + B[0] + C[0] + D[0] > 0) break;
            if(A[prev_i] + B[n-1] + C[n-1] + D[n-1] < 0) continue;
            for(int j = 0; j < n; ){
                int prev_j = j;
                while(j < n && B[j] == B[prev_j]) ++j;
                if(A[prev_i] + B[prev_j] + C[0] + D[0] > 0) break;
                if(A[prev_i] + B[prev_j] + C[n-1] + D[n-1] < 0) continue;
                int target = -A[prev_i] - B[prev_j];
                int k = 0, l = n - 1;
                while(k < n && l >= 0){
                    int sum = C[k] + D[l];
                    if(sum < target){
                        ++k;
                        if(C[n-1] + D[l] < target) break;
                    }
                    else if(sum > target){
                        --l;
                        if(C[k] + D[0] > target) break;
                    }
                    else{
                        int prev_k = k;
                        int prev_l = l;
                        while(k < n && C[k] == C[prev_k]) ++k;
                        while(l >= 0 && D[l] == D[prev_l]) --l;
                        count += (i - prev_i) * (j - prev_j) * (k - prev_k) * (prev_l - l);
                    }
                }
            }
        }
        return count;
    }
};

// similar idea from two-sum
// O(n^2) time and space complexity
class Solution2 {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> h1, h2;
        for(int a : A)
            for(int b : B)
                ++h1[a + b];
        
        for(int c : C)
            for(int d : D)
                ++h2[c + d];
        
        int count = 0;
        for(auto const& kv : h1){
            auto it = h2.find(-kv.first);
            if(it != h2.end())
                count += kv.second * it->second;
        }
        return count;
    }
};
