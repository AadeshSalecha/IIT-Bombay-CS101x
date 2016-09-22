

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
//// Name:
////
//// END: Fill your details as comments above DONT_ERASE_01_0
//// ---------------------------------------------------------------------------

int main() {

   int number, max_cycles=10;
   int finalNumber, cycle_no=0;
   cout << "Enter a number " << endl;
   cin >> number;

//// ---------------------------------------------------------------------------
//// BEGIN: Write code below to check whether the number entered is a happy number or not (for max 10 cycles).  DONT_ERASE_02_10
   int temp_num = number;
   int countr = 0;
    int countr1 = 0;
   int sum = 0;
   int sum1 = 0;

   // Counting the number of digits in the entered integer
   for(cycle_no = 0; cycle_no < max_cycles ; cycle_no++)
   {
       temp_num = number;
       countr = 0;
       while (temp_num != 0)
       {
           temp_num = temp_num / 10;
           countr++;
       }

       temp_num = number;
       sum = 0;
       do
       {
            sum += (temp_num % 10) * (temp_num % 10);
            countr--;
            temp_num = temp_num / 10;
       }
       while(countr != 0);

        countr1 = 0;
       temp_num = sum;
       while (temp_num != 0)
       {
           temp_num = temp_num / 10;
           countr1++;
       }
        temp_num = sum;
        sum1 = 0;
       do
       {
            sum1 += temp_num % 10;
            countr1--;
            temp_num = temp_num / 10;
       }
       while(countr1 != 0);

       if (sum1 == 1){
        finalNumber = 1;
        cycle_no+= 2;
        break;
       }
       else {
            finalNumber = sum;
            number = sum;
       }

  }


//// END: End of your code DONT_ERASE_02_10
//// ---------------------------------------------------------------------------

   if ( finalNumber == 1 )
      cout << "The number is a happy number. Detected after " << cycle_no << " cycles " <<endl;
   else
      cout << "Could not establish the fact that the number entered by the user is a happy number or not. The number obtained in " << cycle_no << " cycles is " << finalNumber << endl;

   return 0;
}
