class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        int num_sum;
        int nums_length = nums.size();
        for (int i = 0; i < nums_length; i++){
            for(int j = i+1; j <nums_length; j++){
                num_sum = nums[i] + nums[j];
                if(num_sum == target){
                    result.push_back(i);
                    result.push_back(j);
                    break;
                }
            }
        }
        return result;
    }
};