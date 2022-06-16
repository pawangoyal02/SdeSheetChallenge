#include <bits/stdc++.h> 
void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
    int col0=1, rows= matrix.size(), cols= matrix[0].size();
    for(int i=0; i<rows; i++) {
        //Checking if 0 is present in 0th column
        if(matrix[i][0]==0) {
            col0= 0;
        }
        for(int j=1; j<cols; j++) {
            if(matrix[i][j]==0) {
                matrix[i][0]= 0;
                matrix[0][j]= 0;
            }
        }
    }
    
    //Traverse in reverse direction and check if row or col has 0 or not and set values
    for(int i= rows-1; i>=0; i--) {
        for(int j= cols-1; j>=1; j--) {
            if(matrix[i][0]==0 || matrix[0][j]==0) {
                matrix[i][j]=0;
            }
        }
        if(col0==0) {
            matrix[i][0]=0;
        }
    }
}