
class Solution {
public:
    int minInsertions(string s) {
        int open = 0;
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                open++;
            } 
            else {
                // If next character is also ')',
                // we have a pair of closing brackets
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    i++;
                } 
                else {
                    // Insert one ')' to complete the pair
                    ans++;
                }

                // Match the closing pair with an opening bracket
                if (open > 0) {
                    open--;
                } 
                else {
                    // Insert one '(' because no opening exists
                    ans++;
                }
            }
        }

        // Each remaining '(' needs two ')'
        ans += open * 2;

        return ans;
    }
};
