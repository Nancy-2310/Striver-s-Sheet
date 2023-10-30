#include <bits/stdc++.h>
using namespace std;

int merge(vector<int>& v, vector<int>& temp, int left, int mid, int right){
    int i, j ,k;
    int invCount = 0;

    i =  left;
    j = mid; 
    k = left;
    while((i <= mid-1) && (j <= right)){
        if(v[i] <= v[j]){
            temp[k++] = v[i++];
        }
        else {
            temp[k++] = v[j++];

            invCount = invCount + (mid - i);
        }
    }

    while(i <= mid - 1)
        temp[k++] = v[i++];
    while(j <= right)
        temp[k++] = v[j++];

    for(i = left; i <= right; i++){
        v[i] = temp[i];
    }
    return invCount;
}
int mergeSort(vector<int>& v, vector<int>& temp, int left, int right){
    int mid, invCount = 0;
    if(right > left){

       mid = (right + left) / 2;

        invCount += mergeSort(v, temp, left, mid);
        invCount += mergeSort(v, temp, mid + 1, right);

        invCount += merge(v, temp, left, mid+1, right);
    }
    return invCount;
}

int main(){
    vector<int> v = {5, 3 , 2 , 4, 1};
    int n = v.size();
    vector<int> temp(n);
    int ans = mergeSort(v, temp, 0 , n -1);
    cout << "Number of Inversions are: " << ans;
    return 0;
}