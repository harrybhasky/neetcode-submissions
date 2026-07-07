class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxl =0;
        int left =0;
        int max_freq=0;

        unordered_map <char,int> count;

        for(int i = 0; i<s.size(); i++){
            count[s[i]]++;
            max_freq = max(max_freq, count[s[i]]);

            while (((i-left+1) - max_freq )>k){
                count[s[left]]--;
                left++;
            }

            maxl = max(maxl, i-left+1);
        }
        return maxl;
    }
};
