/* Problem Summary
The idea is to check whether a number remains the same after reversing it twice. For example:

123 → reverse → 321 → reverse again → 123 ✅
1200 → reverse → 21 → reverse again → 12 ❌
✅ Logic Explanation
If the number is 0, it stays 0 after any number of reversals.
For any other number:
If it ends in 0, reversing it will drop the trailing zeros (e.g., 1200 → 21).
Reversing again won’t restore the original number.
So, if num % 10 == 0, it won’t be the same after double reversal.
*/

#include <stdio.h>
#include <stdbool.h>

// Function to check if a number remains the same after double reversal
bool isSameAfterReversals(int num) {
    if (num == 0) {
        return true;
    }
    return num % 10 != 0;
}

int main() {
    int num;

    // Prompt user for input
    printf("Enter a number: ");
    scanf("%d", &num);

    // Check and display result
    if (isSameAfterReversals(num)) {
        printf("The number %d remains the same after double reversal.\n", num);
    } else {
        printf("The number %d does NOT remain the same after double reversal.\n", num);
    }

    return 0;
}
