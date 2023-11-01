#include <bits/stdc++.h>
using namespace std;

 void sortColors(vector<int>& nums) {
      int lo=0;
      int mid=0;
      int high=nums.size()-1;
      while(mid<=high){
          if(nums[mid]==2){
              swap(nums[mid],nums[high]);
              high--;
          }
          else if(nums[mid]==0){
              swap(nums[lo],nums[mid]);
              lo++;
              mid++;

          }
          else{
              mid++;
          }
      }  
    }
int main(){
    vector<int> v = {1, 2, 3};
    sortColors(v);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        }
        cout << endl;
    return 0;
}