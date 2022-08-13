class Solution {
public:
    int reverse(int x) {
        int r=0;
        bool n=0;
        if(x<0){
            n=1;
            
            if(x!=INT_MIN){
            x=(-1)*x;
            }
            else{
                return 0;
            }
            
        }
        while(x>0){
            int k=x%10;
            x=x/10;
            if(r>((INT_MAX-k)/10)){
                return 0;
            }
            r=(r*10)+k;
           
        }
        if(n){
            r=(-1)*r;
        }
        return r;
        
        
        
    }
};
