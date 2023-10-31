#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE

vector<int> f1(vector<int> v){
    int n = v.size();
    vector<int> ans;
    int count;
    for(int i = 0; i < n; i++){
        count = 0;
        if(ans.size() == 0 || ans[0] != v[i]){
                for(int j = 0; j < n; j++){
                    if(v[i] == v[j]) count++; 
                }
                if (count > n/3) ans.push_back(v[i]);
                if(ans.size() == 2) break;
        }
    }
    return ans;
}

// BETTER SOLUTION 
vector<int> f2(vector<int> v){
    int n = v.size();
    map<int, int> hash;
    vector<int> ans;
    int num = (int)(n/3)+1;
    for(int i = 0; i < n; i++){
        hash[v[i]]++;
        if (hash[v[i]] == num) ans.push_back(v[i]);   
        if(ans.size() == 2) break;
    }
    sort(ans.begin(), ans.end());
    return ans;
}

// OPTIMUM SOLUTION 
vector<int> f3(vector<int> v){
    int ct1=0, ct2=0;
    int n = v.size();  
    int el1 = INT_MIN, el2 = INT_MIN;
    vector<int> ans;
    int num = (int)(n/3)+1;
    for(int i = 0; i < n; i++){
        if(ct1 == 0 &&  el2 != v[i]){
            ct1 = 1;
            el1 = v[i];
        }
        else if(ct2 == 0 && el1 != v[i]){
            ct2 = 1; el2 = v[i];
        }
        else if(el1 == v[i]) ct1++;

        else if(el2 == v[i]) ct2++;

        else{
            ct1--;
            ct2--;
        }
    }
    
    ct1= 0; ct2 =0;
    for(int i = 0; i < n; i++) {
        if(el1 == v[i]) ct1++;
        if(el2 == v[i]) ct2++;
    }
    if(ct1 >= num) ans.push_back(el1);
    if(ct2 >= num) ans.push_back(el2);
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<int> nums1 = {1, 2, 1, 1, 1, 2, 2 , 3};
    vector<int> v2 = f3(nums1);
    for(int i = 0;i < v2.size(); i++){
        cout << v2[i] << " ";
    }
    cout << endl;
    return 0;
}