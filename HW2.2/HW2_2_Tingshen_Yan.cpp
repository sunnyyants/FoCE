//
//  HW2_2_Tingshen_Yan.cpp
//  HW2--Problem 2
//
//  OS: MAC OS X 10.8.5 64bit version.
//  Coding Platform: Xcode5.0.
//
//  Created by Tingshen Yan on 9/23/13.
//  Copyright (c) 2013 Northeastern University. All rights reserved.
//

#include <iostream>

using namespace std;

int misterya(int n);
int newFunction(int n);

int main(int argc, const char * argv[])
{
    // Testing the misterya(int n)funcion is calculating the result or not ?
    int n = 10;
    cout << "The result of function misterya(int n) when n = 10 should be 385: " << misterya(n)<< endl;
    // Now testing the result of the newFunction(int n) and it should output the same result as misterya(int n).
    printf("The resulf of the funtion newFunction(int n) is the same as misterya(int n ): %s\n" , misterya(n) == newFunction(n) ? "True" : "False");
 }

int misterya (int n) {
    int S = 0;
    for (int i = 1; i < n + 1; i++) {
        S += i * i;
    }
    return S;
}

/*
1.    What does the algorithm compute?

        Solution:

        This algorithm compute the sum of square of i while i 	is from 1 to n. 
        That is S = 1^2 + 2^2 + 3^2 + ... + n^2.

2.	 What is its basic operation?

        Solution:

        The basic operation is S += i * i.


3.	  How many times is the basic operation executed?

        Solution:

        The basic operation will be executed n times.


4.	  What is the efficiency class (i.e., the time complexity) of this algorithm?

        Solution:

        The time complexity of this algorithm is O(n).

5.	  Suggest a better algorithm (write its pseudo-code or its C++ code) for computing the same function and indicate its complexity.
        If you cannot do it, prove that, in fact, this cannot be done.
 
        Solution:

        From the time complexity of the original algorithm above shows that its time complexity is O(n). If we 	want to have a better algorithm for
        computing the same function which means with a less time complexity algorithm, we have to find out a kind of algorithm that the complexity
        is either O(log n) or 0(1)  . 	As we know there is a formula that compute the same function as above. 
 
        That is S = 1^2 +2^2 + 3^2 + ... + n^2 = (n * (n + 1) * (2 * n + 1)) / 6.
 
        If we use run this formula, the time complexity of the total algorithm will become O(1), which is much better than the old one.
*/

int newFunction(int n) {
    int sum;
    sum = (n *(n + 1) * (2 *n + 1)) / 6;
    return sum;
}


