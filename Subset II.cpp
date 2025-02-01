class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        sort(nums.begin(),nums.end());
        createSubset(nums,0,res,subset);
        return res;
    }
    void createSubset(vector<int> &nums,int index, vector<vector<int>> &res,vector<int> & subset)
    {
        if(index == nums.size())
        {
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[index]);
        createSubset(nums,index+1,res,subset);
        subset.pop_back();
        index = index+1;
        while(index<nums.size()&&nums[index]==nums[index-1])
        {
            index++;
        }
        createSubset(nums,index,res,subset);
    }
};