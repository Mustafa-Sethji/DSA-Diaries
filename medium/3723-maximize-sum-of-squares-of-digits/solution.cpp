class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) return "";

        int nines = sum / 9;
        int rem = sum % 9;

        string res(num, '0');
        for (int i = 0; i < nines; i++) res[i] = '9';
        if (rem > 0) res[nines] = '0' + rem;

        return res;
    }
};