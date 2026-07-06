class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxl =0;
        int last;
        
        unordered_set<char> charSet;

        for(int i=0; i < s.size(); i++ ){
            while (charSet.find(s[i]) != charSet.end()){

            charSet.erase(s[last]);
            last++;
        }
        
        charSet.insert(s[i]);
        maxl = max(maxl, i - last +1);
        }
        return maxl;
    }
    
};
