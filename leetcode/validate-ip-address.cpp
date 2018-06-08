/*
Write a function to check whether an input string is a valid IPv4 address or IPv6 address or neither.

IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging from 0
to 255, separated by dots ("."), e.g.,172.16.254.1;

Besides, leading zeros in the IPv4 is invalid. For example, the address 172.16.254.01 is invalid.

IPv6 addresses are represented as eight groups of four hexadecimal digits, each group representing 16 bits. The groups are
separated by colons (":"). For example, the address 2001:0db8:85a3:0000:0000:8a2e:0370:7334 is a valid one. Also, we could omit
some leading zeros among four hexadecimal digits and some low-case characters in the address to upper-case ones, so
2001:db8:85a3:0:0:8A2E:0370:7334 is also a valid IPv6 address(Omit leading zeros and using upper cases).

However, we don't replace a consecutive group of zero value with a single empty group using two consecutive colons (::) to
pursue simplicity. For example, 2001:0db8:85a3::8A2E:0370:7334 is an invalid IPv6 address.

Besides, extra leading zeros in the IPv6 is also invalid. For example, the address 02001:0db8:85a3:0000:0000:8a2e:0370:7334 is
invalid.

Note: You may assume there is no extra space or special characters in the input string.

Example 1:
Input: "172.16.254.1"

Output: "IPv4"

Explanation: This is a valid IPv4 address, return "IPv4".
Example 2:
Input: "2001:0db8:85a3:0:0:8A2E:0370:7334"

Output: "IPv6"

Explanation: This is a valid IPv6 address, return "IPv6".
Example 3:
Input: "256.256.256.256"

Output: "Neither"

Explanation: This is neither a IPv4 address nor a IPv6 address.
*/

class Solution {
public:
    string validIPAddress(string IP) {
        int n = IP.size();
        if(n < 7 || n > 39 || IP.back() == '.' || IP.back() == ':') return "Neither";
        vector<string> nums;
        int type = -1; // -1 neither, 0 IPv4, 1 IPv6
        for(int i = 0; i < n; ){
            int j = i;
            while(j < n){
                if(IP[j] == '.'){
                    type = 0;
                    break;
                }else if(IP[j] == ':'){
                    type = 1;
                    break;
                }
                ++j;
            }
            nums.push_back(IP.substr(i, j - i));
            i = j + 1;
        }
        if(type == 0 && isValidIPv4(nums)) return "IPv4";
        if(type == 1 && isValidIPv6(nums)) return "IPv6";
        return "Neither";
    }
    
    bool isValidIPv4(vector<string> &nums){
        if(nums.size() != 4) return false;
        for(auto &num : nums){
            int n = num.size();
            if(n == 0 || n > 3) return false;
            // check leading zeros
            if(n > 1 && num[0] == '0') return false;
            // check range
            int sum = 0;
            for(int i = 0; i < n; ++i){
                if(num[i] < '0' || num[i] > '9') return false;
                sum = sum * 10 + num[i] - '0';
            }
            /*
            for(int i = n - 1; i >= 0; --i){
                if(num[i] < '0' || num[i] > '9') return false;
                sum += (num[i] - '0') * pow(10, n - 1 - i);
            }
            */
            if(sum > 255) return false;
        }
        return true;
    }
    
    bool isValidIPv6(vector<string> &nums){
        if(nums.size() != 8) return false;
        for(auto &num : nums){
            int n = num.size();
            if(n == 0 || n > 4) return false;
            for(auto c : num){
                if(c >= '0' && c <= '9' ||
                   c >= 'a' && c <= 'f' ||
                   c >= 'A' && c <= 'F') continue;
                else return false;
            }
        }
        return true;
    }
};

// places to improve
// 1. no need to split IP to a vector, check block by block
// 2. can determine the protocol version by scanning at most 5 characters.
// 3. use stringstream to find blocks
// ref: https://leetcode.com/problems/validate-ip-address/discuss/95565/C++-solution-straightforward-string-processing
class Solution {
public:
    string validIPAddress(string IP) {
        // determine protocol version
        if(IP.substr(0, 4).find('.') != string::npos){
            if(isValidIPAddress(IP, 4, '.', isValidIPv4Block))
                return "IPv4";
        }else if(IP.substr(0, 5).find(':') != string::npos){
            if(isValidIPAddress(IP, 8, ':', isValidIPv6Block))
                return "IPv6";
        }
        return "Neither";
    }
    
    bool isValidIPAddress(string &IP, int n, char delimiter, function<bool(string &)> isValidBlock){
        istringstream iss(IP);
        string block;
        for(int i = 0; i < n; ++i){
            if(!getline(iss, block, delimiter) || !isValidBlock(block)) return false;
        }
        return iss.eof();
    }

    static bool isValidIPv4Block(string &block){
        int n = block.size();
        if(n == 0 || n > 3) return false;
        if(n > 1 && block[0] == '0') return false;
        int num = 0;
        for(auto c : block){
            if(c < '0' || c > '9') return false;
            num = num * 10 + c - '0';
        }
        return num < 256;
    }
    
    static bool isValidIPv6Block(string &block){
        int n = block.size();
        if(n == 0 || n > 4) return false;
        for(auto c : block){
            if(c >= '0' && c <= '9' || c >= 'a' && c <= 'f' || c >= 'A' && c <= 'F') continue;
            return false;
        }
        return true;
    }
};
