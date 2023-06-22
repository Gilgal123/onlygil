#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef void* elem_ptr; //pointer to element
typedef bool (*is_equal)(elem_ptr a,elem_ptr b); //pointer  to function that returns true if a=b, else false;
typedef bool (*a_is_grater)(elem_ptr a,elem_ptr b);// pointer to function that returns true iff a>b

int generic_bin_search(elem_ptr *a,int n,elem_ptr target,is_equal is_equal,a_is_grater a_is_grater)
{
    int left=0, right=n-1;
    int mid;
    while (left<=right)
    {
        mid=(left+right)/2;
        if (is_equal(a+mid,target))
        {
            return mid;
        }
        else if (a_is_grater(a+mid,target))
        {
            right=mid-1;
        }
        else
        {
            left=mid+1;
        }
    }
    return -1;
}

bool compare_ints(elem_ptr a, elem_ptr b) {
    int num1 = *(int*)a;
    int num2 = *(int*)b;
    return num1 == num2;
}

// User-defined comparison function for floating-point numbers
bool compare_floats(elem_ptr a, elem_ptr b) {
    float num1 = *(float*)a;
    float num2 = *(float*)b;
    return num1 == num2;
}

int main() {
    // Test case 1: Binary search on an array of integers
    int int_array[7] = {2, 4, 6, 8, 10, 12, 14};
    int target_int = 8;
    int n = sizeof(int_array) / sizeof(int);
    
    int index = generic_bin_search((elem_ptr*)int_array, n, &target_int, compare_ints, NULL);
    
    if (index != -1) {
        printf("Target found at index: %d\n", index);
    } else {
        printf("Target not found.\n");
    }
    return 0;
}
