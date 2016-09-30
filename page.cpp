

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
// is a placeholder for your personal information.
//
// WARNING :
// (1) Do NOT write any cout or cin statements
// (2) Do NOT delete or modify the existing code i.e. main function, comments, blocks, etc.
// (3) Write your code in between BEGIN and END of the respective blocks only
// (4) Do NOT rename the .cpp file


//// ---------------------------------------------------------------------------
//// BEGIN: Fill your details as comments below DONT_ERASE_01_0
//// Name:Aadesh Salecha
////
//// END: Fill your details as comments above DONT_ERASE_01_0
//// ---------------------------------------------------------------------------


int main()
{
     int age, ageResult;
     cout<<"Enter your age in years:  ";
     cin>>age;

//// ---------------------------------------------------------------------------
//// BEGIN: Assign value -1 to 5 to the variable ageResult depending on the age DONT_ERASE_02_01
//// Store the result in ageResult

//   Assign -1 to variable ageResult if age is Less than 0
//   Assign 0 to variable ageResult if age is  0 to 5
//   Assign 1 to variable ageResult if age is 6 to 12
//   Assign 2 to variable ageResult if age is 13 - 19
//   Assign 3 to variable ageResult if age is 20 to 50
//   Assign 4 to variable ageResult if age is 51 to 60
//   Assign 5 to variable ageResult if age is 61 to 101
//   Assign -1 to variable ageResult if age is - Greater than 101
     ageResult = 0;

    if (age <= 5  && age > 0){
        ageResult = 0;
        }

    else if (age <= 12  && age > 5){
        ageResult = 1;
        }

    else if (age <= 19  && age > 12){
        ageResult = 2;
        }

    else if (age <= 50  && age > 19){
        ageResult = 3;
        }

    else if (age <= 61  && age > 50){
        ageResult = 4;
        }

    else if (age <= 101  && age > 61){
        ageResult = 5;
        }

    else{
        ageResult = -1;
        }


//// END: Code to display message DONT_ERASE_02_01
//// ---------------------------------------------------------------------------

     if(ageResult == -1)
        cout<<"Invalid Age"<<endl;
     if(ageResult == 0)
        cout<<"Baby"<<endl;
     if(ageResult == 1)
        cout<<"Junior"<<endl;
     if(ageResult == 2)
        cout<<"Teenager"<<endl;
     if(ageResult == 3)
        cout<<"Adult"<<endl;
     if(ageResult == 4)
        cout<<"Elderly"<<endl;
     if(ageResult == 5)
        cout<<"Senior Citizen"<<endl;

    return 0;
}
