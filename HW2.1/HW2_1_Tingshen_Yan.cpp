//
//  HW2_1_Tingshen_Yan.cpp
//  HW2--Problem 1
//
//  OS: MAC OS X 10.8.5 64bit version.
//  Coding Platform: Xcode5.0.
//
//  Created by Tingshen Yan on 9/23/13.
//  Copyright (c) 2013 Northeastern University. All rights reserved.
//

#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>



using namespace std;

void insertionSort(vector<int> &A);
void populateVector(vector<int> &A, double m);
void printVector(vector<int> A);


int main()
{
    // Generated a vector to test the function of insertionSort(vector<int> &A);
    
    vector<int> test1 = {5,4,3,2,1,2,3,4,5,1,2};
    
    printf("Origin vector for testing the insertionSort function:\n");
    printVector(test1);
    insertionSort(test1);
    printf("Result vector for testing the insertionSort function:\n");
    printVector(test1);
    
    // To create a new vector by using the function populateVector(vector<int> &A, double m);
    
    // Generated some parameters;
    vector<int> newVector;
    double m;
    
    // Input an a double number to indicate the range of elements of the new generated vector.
    printf("Please input the real number m in order to define the range of the vector: \n");
    cin >> m;
    while (m < 1.0) {
        cin.clear();
        printf("Wrong input! Please input the real number m > 1.0 in order to define the range of the vector: \n");
        cin >> m;
    }
    
    // Running the poputlateVector(vector<int> &A, double m) funtion;
    populateVector(newVector, m);
    
    // To test the result of new generated vector;
    printf("To test the output of the new generated vector: \n");
    printVector(newVector);
    
    // To sort the new generated vector by using the insertionSort(vector<int> &A) function;
    printf("After sorting by insertionSort: \n");
    insertionSort(newVector);
    printVector(newVector);
    
    return 0;
}


void insertionSort(vector<int> &A )
{
    // Generated 2 iterator in order to iterate the elements of the vector;
    vector<int>::iterator iter1;
    vector<int>::iterator iter2;
    
    // The major part of inserting sort;
    for(iter1 = A.begin() + 1; iter1 != A.end(); ++iter1) {
        int insertValue = *iter1;
        iter2 = (iter1 - 1);
        while((iter2 >= A.begin()) && (insertValue < *iter2)) {
            *(iter2 + 1) = *iter2;
            iter2--;
        }
        *(iter2 + 1) = insertValue;
    }
    
    
}

void populateVector(vector<int> &A, double m)
{
    // Input the number n to indicate the size of vector;
    int n;
    printf("Please input an integer n to define the size of the vector: \n");
    cin >> n;
    // Check the input n is an integer greater than 1 or not;
    while (n < 1) {
        cin.clear();
        printf("Wrong input! Please input an integer n > 1 to define the size of the vector: \n");
        cin >> n;
    }
    
    
    // To fix the double m to an integer
    int randNum = 0;
    int m_int = (int)(m + 0.5);
    
    
    srand((unsigned)time(NULL));
    
    // Generated a number randomly that satisfied the uniform distribution in the range of [-m,m];
    for(int i = 0; i < n; i++) {
        randNum = rand() % (2 * m_int + 1) - m_int;
        
        // Push the new generated random number into the vector;
        A.push_back(randNum);
    }
}

void printVector(vector<int> A)
{
    // Generated an iterator to visit the elements in vector;
    vector<int>::iterator i;
    printf("[ ");
    for(i = A.begin(); i != A.end(); ++i) {
        printf("%d", *i);
        printf(" ");
    }
    printf("]\n");
}

