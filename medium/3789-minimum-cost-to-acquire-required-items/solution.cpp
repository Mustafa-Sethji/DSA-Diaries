class Solution {
public:
    typedef long long ll;

    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {

        // If buying both separately is cheaper or equal
        if (cost1 + cost2 <= costBoth) {
            return (1LL * need1 * cost1) + (1LL * need2 * cost2);
        }

        // Buy common items for both requirements
        int both = min(need1, need2);
        ll total = 1LL * both * costBoth;

        need1 -= both;
        need2 -= both;

        // Buy remaining items
        if (need1 > 0) {
            total += 1LL * need1 * min(cost1, costBoth);
        } 
        else if (need2 > 0) {
            total += 1LL * need2 * min(cost2, costBoth);
        }

        return total;
    }
};