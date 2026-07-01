class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int n : nums) freq[n]++;

        // copy map entries into a vector of pairs so we can sort
        vector<pair<int,int>> arr(freq.begin(), freq.end()); // {value, count}

        sort(arr.begin(), arr.end(), [](pair<int,int>& a, pair<int,int>& b) {
            return a.second > b.second; // sort by frequency, descending
        });

        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(arr[i].first);
        }
        return result;
    }
};