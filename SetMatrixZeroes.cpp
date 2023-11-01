#include <bits/stdc++.h>
using namespace std;

 void markrow(int i,vector<vector<int>>& matrix, int m,vector<vector<bool>>& mark){
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] != 0) {
               mark[i][j]=true;
             
            }
        }
    }
    
    void markcol(int j,vector<vector<int>>& matrix, int n,vector<vector<bool>>& mark){
        for (int i = 0; i < n; i++) {
            if (matrix[i][j] != 0) {
               mark[i][j]=true;
            }
        }
    }
 void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<bool>>mark(n,vector<bool>(m,false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    markrow(i,matrix, m,mark);
                    markcol(j,matrix, n,mark);
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mark[i][j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

int main(){
    vector<vector<int>> v = {{1, 1,1}, {1,0,1}, {1,1,1}};
    setZeroes(v);
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}