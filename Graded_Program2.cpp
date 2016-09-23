

//Author    : Aadesh Salecha
//Course    : Nand2Tetris
//Date      : March 2016


#include <iostream>
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

int main() {

   int arraySize, priceArray[5];
   cout << "Enter price of shares (in integer format) of a company for 5 days: " << endl;

   for(int i=0;i<5;i++)
      cin >> priceArray[i];
   int profitEarned;

//// ---------------------------------------------------------------------------
//// BEGIN: Write code below to find maximum profit.  DONT_ERASE_02_10
//// Assign the maximum profit calculated to the variable 'profitEarned'
    signed int tmp_profit = 0;
    signed int current_profit = priceArray[1] - priceArray[0];
    for (int i = 0 ; i < 5 ; i++)
    {
        for (int j = i ; j < 5 ; j++)
        {
            if (i != j)
            {
                tmp_profit = priceArray[j] - priceArray[i];
                if (tmp_profit > current_profit){current_profit = tmp_profit;}
            }
        }
    }
    profitEarned = current_profit;

//// END: End of your code DONT_ERASE_02_10
//// ---------------------------------------------------------------------------

   cout << "Maximum profit earned is " <<  profitEarned << endl;
   return 0;
}
