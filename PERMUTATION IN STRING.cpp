class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.length();
        int n2=s2.length();
        unordered_map<char,int> umap;
        for(int i=0;i<n1;i++){
            umap[s1[i]]++;
        }
        int k = n1;
        int j=0;
        int i=0;
        int cnt=umap.size();
        while(i<n2 && j<n2){
            if(umap.find(s2[j])!=umap.end()){
                umap[s2[j]]--;
                if(umap[s2[j]]==0){
                    cnt--;
                }
            }
            if(j-i+1!=k){
                j++;
            }
            else if(j-i+1==k){
                if(cnt==0){
                    return true;
                }
                if(umap.find(s2[i])!=umap.end()){
                    umap[s2[i]]++;
                    if(umap[s2[i]]==1){
                        cnt++;
                    }
                }
            
            i++;
            j++;
            }
        }
        return false;
        
        
        
    }
    
};
