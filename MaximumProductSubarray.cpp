#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) {
        int maximum=INT_MIN;
        int pre=1;
        int suff=1;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(pre==0) pre=1;
            if(suff==0) suff=1;
            pre=pre*nums[i];
            suff=suff*nums[n-1-i];
            maximum=max(maximum,max(pre,suff));
        }
        return maximum;
}
int main(){
    vector<int> v = {2,4,5,6,8};
    cout<<"Maximum product is "<<maxProduct(v);
    return 0;
}