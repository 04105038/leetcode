class Solution {
public:
    int numSquares2(int n,int deep,int min){
        if(deep>=min) return min;  //太妙了
        int sq=sqrt(n);
        if(sq*sq==n) return 1;
        for(int i=sq;i>0;i--){
            if(n-i*i>=0){
            int temp=1+numSquares2(n-i*i,deep+1,min);
            if(temp<min) min=temp;}
        }
        return min;
    }
    int numSquares(int n) {
        if(n==0||n==1) return n;
        return numSquares2(n,1,n);
    }
};