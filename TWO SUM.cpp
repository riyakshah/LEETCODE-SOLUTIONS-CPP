class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
        vector<pair<int,int>> v;
        for(int i=0;i<nums.size();i++){
            v.push_back(make_pair(nums[i],i));
        }
        sort(v.begin(),v.end());
        int ptr1=0;
        int ptr2=nums.size()-1;
        while(ptr1<ptr2){
            if(v[ptr1].first+v[ptr2].first==target){
                ans.push_back(v[ptr1].second);
                ans.push_back(v[ptr2].second);
                return ans;
            }
            if(v[ptr1].first+v[ptr2].first<target){
                ptr1++;
            }
            if(v[ptr1].first+v[ptr2].first>target){
                ptr2--;
            }
        }
        return ans;
    }
};
