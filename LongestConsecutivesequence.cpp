#include <bits/stdc++.h>
using namespace std;

int lcs(vector<int>& nums) {
        
int ans = INT_MIN;
        int n = nums.size();
        if(n == 0) return 0;
        unordered_set<int> st;
        for(int i = 0; i < n; i++){
            st.insert(nums[i]);
        }

        for(auto it : st){
            if(st.find(it - 1) == st.end()){
                int x = it;
                int ct = 1;
                 
                while(st.find(x+1) != st.end()){
                    x++;
                    ct++;
                }

                ans = max(ans, ct);
            }
            
        }
        return ans;
    }
int main(){
    vector<int> v = {2,2,3,2,2};
    int ans = lcs(v);
    cout << ans;
    return 0;
}