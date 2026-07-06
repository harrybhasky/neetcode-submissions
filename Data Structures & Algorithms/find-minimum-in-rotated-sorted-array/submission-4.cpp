class Solution {
public:
    int findMin(vector<int> &nums) {
        int i =0;
        int j = nums.size()-1;
        int x;

        while (i<j){
            if(nums[i] < nums[j]){
                x = min(x, nums[i]);
            
            break;
            }

            int mid = i + (j-i)/2;
            x = min(x,nums[mid]);

            if(nums[mid]>= nums[i]){
                i = mid +1;
            }
            else{
                j = mid -1;
            }
        }
        return x;



    }
};
