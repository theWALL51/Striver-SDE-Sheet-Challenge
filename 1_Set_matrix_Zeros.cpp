/* 

Problem Link :
1. https://leetcode.com/problems/set-matrix-zeroes/
2. https://www.codingninjas.com/codestudio/problems/set-matrix-zeros_3846774?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website


Solution : 
There are two different approaches to the problem
1. Using additional memory
2. Without using any space

*/ 



#include <bits/stdc++.h>
using namespace std;

// Using Additional Memory :
class Solution_1{
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        set<int> row, column ;

        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix[i].size() ; j++)
                if(matrix[i][j] == 0){
                    row.insert(i) ;
                    column.insert(j) ;
                }
        }
        
        for(auto i : row){
            for(int j = 0 ; j < matrix[i].size() ; j++){
                matrix[i][j] = 0 ;
            }
        }
        
        for(auto i : column){
            for(int j = 0 ; j < matrix.size() ; j++){
                matrix[j][i] = 0 ;
            }
        }
            
    }
};





// Space Efficient :
class Solution_2{
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        bool col = true ; 
        
        for(int i = 0 ; i < matrix.size() ; i++){
            if(matrix[i][0] == 0) col = false ;
            for(int j = 1 ; j < matrix[i].size() ; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = matrix[0][j] = 0 ;
                }
            }
        }
        
        for(int i = matrix.size()-1 ; i >= 0 ; i--){
            for(int j = matrix[i].size()-1 ; j >= 1 ; j--){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0 ;
                }
            }
            if(col == false) matrix[i][0] = 0 ;
        }
    }
};



int main()
{
    ios::sync_with_stdio(0);cin.tie(0);

    // Your Code
    vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}, {0, 1, 2 }} ;


    Solution_1 obj ;
    obj.setZeroes(matrix) ;


    for(int i = 0 ; i < matrix.size() ; i++){
        for(auto j : matrix[i])
            cout << j << " " ;
        cout << "\n" ;
    }
    

    return 0;
}