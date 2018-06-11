/*
We partition a row of numbers A into at most K adjacent (non-empty) groups, then our score is the sum of the average of each
group. What is the largest score we can achieve?

Note that our partition must use every number in A, and that scores are not necessarily integers.

Example:
Input: 
A = [9,1,2,3,9]
K = 3
Output: 20
Explanation: 
The best choice is to partition A into [9], [1, 2, 3], [9]. The answer is 9 + (1 + 2 + 3) / 3 + 9 = 20.
We could have also partitioned A into [9, 1], [2], [3, 9], for example.
That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.
 

Note:

1 <= A.length <= 100.
1 <= A[i] <= 10000.
1 <= K <= A.length.
Answers within 10^-6 of the correct answer will be accepted as correct.
*/

class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int n = A.size();
        vector<int> sums(n); // sums[i] = sum of A[0..i]
        int sum = 0;
        for(int i = 0; i < n; ++i){
            sum += A[i];
            sums[i] = sum;
        }
        // dp[k][i]: maximum sum of averages of at most (k+1) groups for A[0..i]
        vector<vector<double>> dp(K, vector<double>(n));
        for(int i = 0; i < n; ++i){
            dp[0][i] = sums[i] / (i + 1.0);
            for(int k = 1; k < K; ++k){
                double max_sum = dp[k - 1][i]; // at most k groups
                for(int j = k - 1; j < i; ++j){ // exactly k+1 groups
                    double sum = dp[k - 1][j] + static_cast<double>(sums[i] - sums[j]) / (i - j);
                    if(sum > max_sum) max_sum = sum;
                }
                dp[k][i] = max_sum;
            }
        }
        return dp[K - 1][n - 1];
    }
};
