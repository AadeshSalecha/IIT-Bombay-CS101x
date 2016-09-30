

//Author    : Aadesh Salecha
//Course    : Nand2Tetris
//Date      : March 2016


#include <iostream>
#include <cmath>

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

int comparator(float marksarray[][2], int index1, int index2);
int selectionSort2(float array[][2], int numElements);
int merge(float sortedarray[][2], float mergedarray[][2], int break_point, int numElements);

int main()
{
    float studentmarks[100][2]= {0}, mergedmarks[100][2] = {0};
    int i, j, N;

    cout<<"Enter no. of students"<<endl;
    cin >> N;	// Enter number of the students
    if ((N < 0) || (N >= 100))
    {
        cout << "Invalid input!" << endl;
        return -1;
    }

    cout << "Enter marks of all students: " << endl;
    for(i=0; i<N; i++)
    {
        cout << "Student " << i+1 << " :" << endl;
        cout << "Midsem: ";
        cin >> studentmarks[i][0];
        cout << "Endsem: ";
        cin >> studentmarks[i][1];
        cout << endl;
    }
//
//    cout << "Comparison results:" << endl;
//    for(i=0; i < N; i++)
//    {
//        for(j=0; j < N; j++)
//        {
//            cout << "(" << i << "," << j << ") : " << comparator(studentmarks,i,j) << endl;
//        }
//        cout << endl;
//    }
//
    int break_point = selectionSort2(studentmarks, N);

    cout << endl << "Break point detected at row : " << break_point << endl << endl;
//    cout<< "Sorted marks: " << endl;
//    for(i=0; i < N ; i++)
//    {
//        cout << studentmarks[i][0] <<" "<< studentmarks[i][1]<<endl;
//    }
    int nonDuplicate = merge(studentmarks, mergedmarks, break_point, N);

    cout << endl << "Merged marks: "<<endl;
    for(i=0; i<nonDuplicate; i++)
    {
        cout << mergedmarks[i][0] <<" "<< mergedmarks[i][1] << endl;
    }
    return 0;
}

int comparator(float marksarray[][2],int index1, int index2)
{
////-----------------------------------------------------------------------
//// BEGIN: write your code to calculate RMS, compare them, and return either -1, 0, or 1  DONT_ERASE_02_2
int rms1 = 0;
int rms2 = 0;

rms1 = sqrt(0.5 * (pow(marksarray[index1][0],2) + pow(marksarray[index1][1],2)));
rms2 = sqrt(0.5 * (pow(marksarray[index2][0],2) + pow(marksarray[index2][1],2)));

if (rms1 > rms2)
    {return -1;}
if (rms2 > rms1)
    {return 1;}

if (rms1 == rms2)
    {
        if (marksarray[index1][1] > marksarray[index2][1])
            {return -1;}
        else if (marksarray[index2][1] > marksarray[index1][1])
            {return 1;}
        else
            {return 0;}
    }
////END: End of function code 'compare' DONT_ERASE_02_2
////------------------------------------------------------------------------
}


int selectionSort2(float array[][2], int numElements)
{
////-----------------------------------------------------------------------
//// BEGIN: write your code to find out the breakpoint Sort the upper part of array (if required) DONT_ERASE_03_4
//// Hint: Use the comparator function

int breakpoint = 0;
for (int i = numElements - 1 ; i >= 0 ; i--)
{
    if (comparator(array,i,i-1) == -1)
    {   breakpoint = i;
        break;
    }
}


      int i, j, flag = 1;    // set flag to 1 to start first pass
      float temp,temp1;             // holding variable
      int numLength = breakpoint;
      for(i = 1; (i <= numLength) && flag; i++)
     {
          flag = 0;
          for (j=0; j < (numLength -1); j++)
         {
              if (comparator(array,j+1,j)== 1)      // ascending order simply changes to <
              {
                    temp = array[j][0];
                    temp1 = array[j][1];             // swap elements
                    array[j][0] = array[j+1][0];
                    array[j][1] = array[j+1][1];
                    array[j+1][0] = temp;
                    array[j+1][1] = temp1;
                    flag = 1;               // indicates that a swap occurred.
               }
          }
     }

return breakpoint;
////END: End of function code DONT_ERASE_03_4
////-----------------------------------------------------------------------
}


int merge(float sortedarray[][2], float mergedarray[][2], int break_point, int numElements)
{
////----------------------------------------------------------------------------
//// BEGIN: Write your code to merge non-duplicate array rows of Part A and Part B DONT_ERASE_04_4
for (int i = 0 ; i < break_point ; i++)
{
    for (int j = break_point ; i < numElements ; i++)
    {
        if((sortedarray[i][0] == sortedarray[j][0]) &&
           (sortedarray[i][1] == sortedarray[j][1]))
        {
            for(int k = j+1; k < numElements; k++)
            {
                sortedarray[k][0] = sortedarray[k + 1][0];
                sortedarray[k][1] = sortedarray[k + 1][1];
            }
            numElements--;
        }
    }
}

for (int i = break_point ; i < numElements ; i++)
{
    for (int j = break_point ; i < numElements ; i++)
    {
        if((sortedarray[i][0] == sortedarray[j][0]) &&
           (sortedarray[i][1] == sortedarray[j][1]))
        {
            for(int k = j+1; k < numElements; k++)
            {
                sortedarray[k][0] = sortedarray[k + 1][0];
                sortedarray[k][1] = sortedarray[k + 1][1];
            }
            numElements--;
        }
    }
}

for (int i = 0 ; i < break_point ; i++)
{
    for (int j = i+1 ; j < break_point ; j++)
    {
        if((sortedarray[i][0] == sortedarray[j][0]) &&
           (sortedarray[i][1] == sortedarray[j][1]))
        {
            for(int k = j; k < numElements; k++)
            {
                sortedarray[k][0] = sortedarray[k + 1][0];
                sortedarray[k][1] = sortedarray[k + 1][1];
            }
            break_point--;
            numElements--;
        }
    }
}


for(int i = 0; i < numElements; i++)
{
    for (int j = 0; j < 2; j++)
    {
        mergedarray[i][j] = sortedarray[i][j];
    }
}

return numElements;

//// END: End of your code to merge   DONT_ERASE_04_4
////---------------------------------------------------------------------------------
}

