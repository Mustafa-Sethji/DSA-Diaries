class Solution {
public:

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    int maxLength(vector<int>& nums) {

        int n = nums.size();
        int maxLen = 0;

        // gcd <= 10 and lcm <= lcm(1..10) = 2520, so gcd * lcm <= 25200.
        const int LIMIT = 25200;

        for (int i = 0; i < n; i++) {

            int l = 1;
            int g = 0;
            int prd = 1;

            for (int j = i; j < n; j++) {

                int num = nums[j];

                prd *= num;

                // The product only grows, so it can never come back down to g * l.
                if (prd > LIMIT) {
                    break;
                }

                g = gcd(g, num);
                l = (l * num) / gcd(l, num);

                if (prd == g * l) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }
};