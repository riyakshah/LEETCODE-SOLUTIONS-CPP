class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans;
        unordered_map<int,int> umap;
        for(int i=0;i<n;i++){
            umap[nums[i]]++;
            
        }
        priority_queue<pair<int,int>> pq;
        for(auto it=umap.begin();it!=umap.end();it++){
            pq.push(make_pair(it->second,it->first));
        }
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;        
        
    }
};
