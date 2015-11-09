class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> result(n);
        int leftsum=1,rightsum=1;
        for(int i=n-1;i>=0;i--){
            result[i]=rightsum;
            rightsum*=nums[i];
        }
        for(int i=0;i<n;i++){
            result[i]*=leftsum;
            leftsum*=nums[i];
        }
        return result;
    }
};