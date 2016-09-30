

//Author    : Aadesh Salecha
//Course    : Nand2Tetris
//Date      : March 2016


#include <iostream>
#include <cstdlib>
using namespace std;

// Please write your code, within the "BEGIN-END" blocks given below.
// A "BEGIN-END" block is identified as follows :
//
// "//// BEGIN: Some string DONT_ERASE_xx_yy"
//
//
// "//// END: Some other string DONT_ERASE_xx_yy"
//
// where "xx" is the block number and "yy" is the
// marks allocated for the block
//
// The FIRST block (BLOCK 1 i.e. DONT_ERASE_01_0) carries 0 marks and
// is a placeholder for your personal information, to be written as a comment.
//
// WARNING :
// (1) Do NOT write any cout or cin statements
// (2) Do NOT delete or modify the existing code i.e. main function, comments, blocks, etc.
// (3) Write your code in between BEGIN and END of the respective blocks only
// (4) Do NOT rename the .cpp file

//// ---------------------------------------------------------------------------
//// BEGIN: Fill your details as comments below DONT_ERASE_01_0
//// Name: Aadesh Salecha
////
//// END: Fill your details as comments above DONT_ERASE_01_0
//// ---------------------------------------------------------------------------



//// ---------------------------------------------------------------------------
//// BEGIN: Write a function getArray1D DONT_ERASE_02_4
//// The function should return a 1D array to the function getArray2D from where it is called

int * getArray1D(int n, int *A)
{
    A = new int[n];
    return A;
}

//// END: End of function code DONT_ERASE_02_4
//// ---------------------------------------------------------------------------



//// ---------------------------------------------------------------------------
//// BEGIN: Write function getArray2D DONT_ERASE_03_6
//// The function should return a 2D array to the main function
//// Call the function getArray1D in this function

int ** getArray2D(int m, int n, int** A)
{
    int** a;
    a = new int* [m];

    for (int i = 0 ; i < n ; i++)
    {
        a[i] = getArray1D(n, a[i]);
    }
    A = a;
    return a;
}

//// END: End of function code DONT_ERASE_03_6
//// ---------------------------------------------------------------------------



int main() {
  int **Array;
  int m, n;
  cin>>m>>n;
  Array = getArray2D(m,n,Array);
  for(int i=0;i<m;i++)
    for(int j=0;j<n;j++){
      cin >> Array[i][j];
    }
    cout<<endl;
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      cout<<Array[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}

