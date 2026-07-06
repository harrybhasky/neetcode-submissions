class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int min_valid = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long totalHours = 0;
            for (int i = 0; i < piles.size(); i++) {
                totalHours += (piles[i] + mid - 1) / mid;
            }

            if (totalHours <= h) {
                min_valid = mid;   // mid works — save it as current best
                high = mid - 1;    // try to find something even smaller
            }
            else {
                low = mid + 1;     // too slow, need a bigger rate
            }
        }

        return min_valid;
    }
};