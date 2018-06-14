/*
Given a non-empty string containing an out-of-order English representation of digits 0-9,
output the digits in ascending order.

Note:
Input contains only lowercase English letters.
Input is guaranteed to be valid and can be transformed to its original digits.
That means invalid inputs such as "abc" or "zerone" are not permitted.
Input length is less than 50,000.
Example 1:
Input: "owoztneoer"

Output: "012"
Example 2:
Input: "fviefuro"

Output: "45"
*/

/*
unique character for each number in English
zero: z
two: w
four: u
six: x
eight: g

after removing the above numbers, unique character for each remaining number in English
one: o
three: t
five: f
seven: s
nine: i

Idea: use the unique character to find the count of each number in s
the elimination order is 0, 2, 4, 6, 8, 1, 3, 5, 7, 9
*/
class Solution {
public:
    string originalDigits(string s) {
        static const string ids("zowtufxsgi");
        static const vector<string> english {
            "zero", "one", "two", "three", "four",
            "five", "six", "seven", "eight", "nine"
        };
        vector<int> freqs(26, 0);
        for(auto c : s)
            ++freqs[c - 'a'];
        vector<int> counts(10, 0);
        for(int i = 0; i < 10; ++i){
            // elimination order: 0, 2, 4, 6, 8, 1, 3, 5, 7, 9
            int num = (i * 2 + (i * 2) / 10) % 10;
            char id = ids[num];
            int count = freqs[id - 'a'];
            counts[num] = count;
            for(char c : english[num]){
                freqs[c - 'a'] -= count;
            }
        }
        string digits;
        for(int i = 0; i < 10; ++i){
            digits += string(counts[i], '0' + i);
        }
        return digits;
    }
};

class Solution {
public:
    string originalDigits(string s) {
        vector<int> counts(10, 0);
        for(auto c : s){
            switch(c){
                case 'z': ++counts[0]; // 0
                break;
                case 'w': ++counts[2]; // 2
                break;
                case 'u': ++counts[4]; // 4
                break;
                case 'x': ++counts[6]; // 6
                break;
                case 'g': ++counts[8]; // 8
                break;
                case 'o': ++counts[1]; // 0, 2, 4, 1
                break;
                case 't': ++counts[3]; // 2, 8, 3
                break;
                case 'f': ++counts[5]; // 4, 5
                break;
                case 's': ++counts[7]; // 6, 7
                break;
                case 'i': ++counts[9]; // 6, 8, 5, 9
            }
        }
        counts[1] -= (counts[0] + counts[2] + counts[4]);
        counts[3] -= (counts[2] + counts[8]);
        counts[5] -= counts[4];
        counts[7] -= counts[6];
        counts[9] -= (counts[6] + counts[8] + counts[5]);
        string digits;
        for(int i = 0; i < 10; ++i){
            digits += string(counts[i], '0' + i);
        }
        return digits;
    }
};

// the above code is not very fast because a lot of branch statements
// improvement: count frequencies of all characters, then compute the counts from the frequencies
class Solution {
public:
    string originalDigits(string s) {
        vector<int> freqs(26, 0);
        for(auto c : s)
            ++freqs[c - 'a'];
        vector<int> counts(10);
        counts[0] = freqs['z' - 'a'];
        counts[2] = freqs['w' - 'a'];
        counts[4] = freqs['u' - 'a'];
        counts[6] = freqs['x' - 'a'];
        counts[8] = freqs['g' - 'a'];
        counts[1] = freqs['o' - 'a'] - counts[0] - counts[2] - counts[4];
        counts[3] = freqs['t' - 'a'] - counts[2] - counts[8];
        counts[5] = freqs['f' - 'a'] - counts[4];
        counts[7] = freqs['s' - 'a'] - counts[6];
        counts[9] = freqs['i' - 'a'] - counts[5] - counts[6] - counts[8];
        string digits;
        for(int i = 0; i < 10; ++i){
            digits += string(counts[i], '0' + i);
        }
        return digits;
    }
};
