/*

Problem Link :
1. https://bit.ly/3rhv153
2. https://leetcode.com/problems/pascals-triangle/

Three types of problem might ask from pascal's triangle :

A) Given Row and Column, tell the element at that place.
   Example : R = 5, C = 3

    Solve : 
    It will be solved by combinatorics i.e, (n-1)C(r-1).
    For eg : (4)C(2) = 6.

    There is a shortcut to solve the combinatronics,
    nCr = n! / ((r!) * (n-r)!)
    Let for (10)C(3) = (10 * 9 * 8) / (3 * 2 * 1)


B) Print any Nth row of pascal's triangle :
   Example : N = 5

   Solve :
   It will be solved by two approaches :
   1. By calling nCr for every element,
   2. solve it by the help of indexes.

C) Given N, Print the entire triangle :
   Example : N = 6

   Solve : 
   Either you can use first method or second method to generate the solution
   Or 
   you can use extra space to achieve it.


Solution :
https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/


*/

#include <bits/stdc++.h>
using namespace std;



// Type A Solution :
int nCr(int n, int r){
   int num = 1, rem = 1 ;
   for(int i = 0 ; i < (n-r) ; i++){
      num *= (n - i) ;
      rem *= (n - r - i) ;
   }
   return num/rem ;
}


// Type B Solution :
vector<int>  nth_row(int n){

   vector<int> res = {1} ;
   if(n == 1)
      return res ;
   
   if(n == 2){
      res.push_back(1) ;
      return res ;
   }

   int num = n, den = 1 ;
   for(int i = 1 ; i <= n ; i++ ){
      res.push_back( res[i-1] * ((double)num/den) );
      num-- ;
      den++ ;
   }
   return res ;
}


// Type C Solution :
vector<vector<int>> nth_triangle(int n){
   vector<vector<int>> res ;

   for(int i = 1 ; i <= n ; i++){
      res.push_back(nth_row(i)) ;
   }
   return res ;

}



int main()
{
    ios::sync_with_stdio(0);cin.tie(0);

   // Your Code

   // Type A :
   // int res = nCr(10, 7) ;
   // cout << res ;


   // Type B :
   // vector<int> nth_elements = nth_row(10) ;
   // for(auto i : nth_elements)
   //    cout << i << " " ;

   // Type C :
   int n = 10 ;
   vector<vector<int>> nth_tri = nth_triangle(n) ;
   for(int i = 0 ; i < n ; i++){
      for(auto j : nth_tri[i]){
         cout << j << " " ;
      }
      cout << "\n" ;
   }


    

    return 0;
}