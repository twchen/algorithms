/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/

class Solution {
public:
    string countAndSay(int n) {
        static vector<string> table(1, "1");
        if(n <= table.size())
            return table[n-1];
        for(int i=table.size(); i<n; ++i){
            string &last = table[i-1];
            string next = "";
            for(int j=0; j<last.size();){
                char c = last[j++];
                int counter = 1;
                while(j < last.size() && c == last[j]){
                    counter++;
                    j++;
                }
                next += to_string(counter) += c;
            }
            table.push_back(next);
        }
        return table[n-1];
    }
};
