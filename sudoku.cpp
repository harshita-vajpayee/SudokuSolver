#include<iostream>
#include<stdio.h>
#include<math.h>

void print(int board[][9],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            std::cout<<board[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}

bool isSafe(int board[][9],int row,int col,int val,int n){
    for(int i=0;i<n;i++){
        //checking row
        if(board[row][i]==val)
            return false;
        //checking column
        if(board[i][col]==val)
            return false;
    }
    //checking grid
    int rn=sqrt(n);
    int si=row-row%rn;
    int sj=col-col%rn;
    for(int row=si;row<si+rn;row++){
        for(int col=sj;col<sj+rn;col++){
            if(board[row][col]==val)
                return false;
        }
    }
    return true;
}


bool sudokuSolver(int board[][9],int row,int col,int n){
    //base case
    if(row==n){
        print(board,n);
        return true;
    }
    //last column
    if(col==n)
        return sudokuSolver(board,row+1,0,n);
    //if cell is alraedy filled
    if(board[row][col]!=0)
        return sudokuSolver(board,row,col+1,n);
    //if cell empty
    for(int val=1;val<=9;val++){
        if(isSafe(board,row,col,val,n)){
            board[row][col]=val;
            //recursive
            bool moreSolve=sudokuSolver(board,row,col+1,n);
            if(moreSolve)
                return true;
            else    //backtracking
                board[row][col]=0;
        }
    }
    return false;
}

int main(){
    int n=9;
    int board[9][9]={
        {0,0,7,1,0,0,0,6,0},{1,0,5,2,0,8,0,0,0},{6,0,0,0,0,7,1,2,0},
        {3,1,2,4,0,5,0,0,8},{0,0,6,0,9,0,2,0,0},{0,0,0,0,0,3,0,0,1},
        {0,0,1,0,0,4,9,8,6},{8,0,3,9,0,6,0,0,0},{0,6,0,0,8,2,7,0,3}
    };
    sudokuSolver(board,0,0,n);
    return 0;
}