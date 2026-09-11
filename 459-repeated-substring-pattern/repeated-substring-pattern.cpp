class Solution {
public:
     bool repeatedSubstringPattern(string s) {
        int n = s.size();
        
        // Iterate over all possible lengths of the substring (up to half of the string length)
        for (int len = 1; len <= n / 2; ++len) {
            // If the current length can divide the string evenly
            if (n % len == 0) {
                string sub = s.substr(0, len);
                string repeated = "";
                
                // Rebuild the string by repeating the substring
                for (int i = 0; i < n / len; ++i) {
                    repeated += sub;
                }
                
                // Check if the rebuilt string matches the original
                if (repeated == s) {
                    return true;
                }
            }
        }
        return false;
    }
};