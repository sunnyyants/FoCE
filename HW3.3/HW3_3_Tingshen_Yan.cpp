//
//  HW3_3_Tingshen_Yan.cpp
//  HW3 -- Problem 3
//
//  OS: MAC OSX 10.8.5 64bit version
//  Platform: Xcode5.0
//
//  Created by Sunny on 10/1/13.
//  Copyright (c) 2013 Northeastern University. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void selectMax(int start, int end, int *arr, int *max);
void printArray(int *arr, int size);

int main(int argc, const char * argv[])
{
    
    int n;
    printf("Please input an integer n to define the size of the vector: \n");
    cin >> n;
    // Check the input n is an integer greater than 1 or not;
    while (n < 1) {
        cin.clear();
        printf("Wrong input! Please input an integer n > 1 to define the size of the vector: \n");
        cin >> n;
    }
    int arr[n];
    
    srand((unsigned)time(NULL));
    
    // Generated a number randomly
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    printf("The original array is: ");
    printArray(arr,n);
    int max = 0;

    selectMax(0, n-1, arr, &max);
    cout<<"The maximum number is: "<< max <<endl;
    
    // Worst-case analysis
    cout<<"The worst-case situation:"<<endl;
    int arr2[10] = {1,2,3,4,5,6,7,8,9,10};
    printArray(arr2,10);
    int max2 = 0;
    selectMax(0, 9, arr2, &max2);
    cout<<"The maximum number in this worst-case situation is:  "<< max2<<endl;

    
}
void selectMax(int start, int end, int *arr, int *max) {
    if(end-start <=1){  // Base case and terminator
        *max = arr[start] > arr[end] ? (arr[start] > *max ? arr[start] : *max) : (arr[end] > *max ? arr[end] : *max);
        return;
    }
    int i;
    i = start + (end-start)/2; // Divide the problem into 2 subproblems.
    selectMax(start,i,arr,max); // recursively call
    selectMax(i+1,end,arr,max); // recursively call
}

void printArray(int *arr, int size) {
    printf("[ ");
    for(int i = 0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

/*
 (b) Write down a recurrence relation for the worse-case number of comparisons used by your algorithm when
        applied to the whole array.
 
        Solution:
 
        In the worst-case, that means all the number in the array are in the complete reverse order. Since we
        seperate the problem in two subproblems, hence the recurrence relation for the worse-case is that
        T(n) = 2T(n/2) + O(1);
 
 (c) Prove the correctness of your algorithm.
 
        Solution:
 
        From the major part of this algorithm showed below:
 
        void selectMax(int start, int end, int *arr, int *max) {                                                          Time cost
        if(end-start <=1){  // Base case and terminator                                                                     O(1)
        *max = arr[start] > arr[end] ? (arr[start] > *max ? arr[start] : *max) 
                : (arr[end] > *max ? arr[end] : *max);                                                                              O(1)
        return;
        }
        int i;
        i = start + (end-start)/2; // Divide the problem into 2 subproblems.                                    O(1)
        selectMax(start,i,arr,max); // recursively call                                                                          T(n/2)
        selectMax(i+1,end,arr,max); // recursively call                                                                      T(n/2)
        }
 
        After summing up the time cost, we cannot hard to get that the relation T(n) = 2T(n/2) + O(1).
        
        And the result in the console windows can prove that the result of this algorithm is correct not only
        in the random-case situation, but also in the worst-case situation.
 
 (d) Discuss whether your algorithm is optimal or not.
 
        Solution: 
        Since we have to use Divide and conquar to seperate the problem in 2 subproblems, from the recurrence
        relation T(n) = 2T(n/2) + O(1) and the master theorem we can get a = 2, b = 2, c = 1 Hence we can get 
        T(n) = Theta(n^(logb(a))) = Theta(n)
 
        If we want to inprove the algorithm, the runing time only can be O(log n), which means in the master 
        theorem the recurrence relation should become T(n) = T(n/2) + O(1). However, if we use this kind of 
        recurrence relation to code the algorithm, we cannot implement the requirement that The size of the
        subproblems should be half the size of the problem that generated them. Hence this algorithm above is 
        the optimal one.
 
 
 
 
 
 
 */
