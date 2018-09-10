/*
    Question : Find the point where a monotonically increasing function (x*x - 10*x - 20) becomes positive first time
    (i.e) the function value will be -2,-4,-1,0,1....
*/
#include <stdio.h>

/* Function that returns the result based on the x value */
int f(int x) { return (x*x - 10*x - 20);}

/** Function to compute the high value bound for the function to reach the positive value */
int findFirstPositive()
{
    //Lower bound value
    int i = 1;

    //check if f(0) is positive
    if(f(0) > 0)
        return 0;

    //Double the i value until the function returns a positive value
    while(f(i) <= 0)
    {
        i = (i*2);
    }

    return binSearch(i/2, i);
}

/* Function to search between the given range to find the point at which the function reaches the first positive value */
int binSearch(int low, int high)
{
    //Check if the bound is valid
    if(high >= low)
    {
        //Find the mid value
        int mid = low + (high - low)/2;

        /* Check if the mid point is the first point the function reaches the positive value
         * Base condition : f() is positive (i.e) greater than zero;
         * Sub conditions : 1) f(mid-1) is zero or 2) no more value below mid point can be found (i.e) mid == low
        */
        if(f(mid) > 0 && ((f(mid-1) <= 0) || mid == low))
        {
            return mid;
        }

        // if mid is negative search for the point in the upper half
        if(f(mid) < 0)
        {
            binSearch(mid+1, high);
        }
        // if mid is positive search for the point in the lower half
        else
        {
            binSearch(low, mid);
        }
    }
    // Return -1 when high and low crosses each other
    return -1;
}


int main()
{
    printf("The point where the given function becomes positive for the first time is %d", findFirstPositive());
    return 0;
}