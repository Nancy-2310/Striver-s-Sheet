#include<bits/stdc++.h>
#include<iostream>
using namespace std;
vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);

        pre[0] = 1;
        int p = nums[0];

        for(int i = 1; i < n; i++){
            pre[i] = p;
            p *= nums[i];
        }
       
        p = nums[n-1];
        
        for(int i = n-2; i >= 0; i--){
            pre[i] *= p;
            p *= nums[i];
        }

        return pre;
    }
int main(){
    int n;
    cin >> n;
    vector<int> v = {5,3,4,7,9};
    
    v = productExceptSelf(v);

    for(int i = 0; i  < n ;i++){
        cout << v[i] << endl;
    }
   
    return 0;

}