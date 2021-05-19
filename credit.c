#include <stdio.h>
#include <cs50.h>
#include <math.h>

// MASTERCARD: 16-Digit #'s, Start with: 51, 52, 53, 54, or 55
// VISA: 13-16-Digit #'s, Start with: 4
// AMEX: 15-Digit #'s, Star with: 34 or 37

// Luhn's Algorithm:
// 1. Multiply every other digit by 2, starting with the second number to the last
// 2. Add the sum of those digits
// 3. Add the sum of the other digits
// 4. If the total sum ends with a 0, it is valid!

int main(void) {
    // Global variables
    int count = 0;
    long cc;
    long ccNUM;
    string card;
    int result;

    // Prompt user
    do {
        cc = get_long("Enter credit card number: ");
    } while (cc < 0);

    ccNUM = cc;

    // Count cc length
    while (cc > 0) {
        cc = cc / 10;
        count++;
    }

    // Check if cc num length is valid
    if (count != 13 && count != 15 && count != 16) {
        printf("INVALID");
    }

    // Luhn's Algorithm
    // Looping variables for computation
    long digit;
    int multi;
    int sum1 = 0;
    int sum2 = 0;
    // Iterate 1 through length of CC
    for (int i = 0; i < count; i++) {
        // Create factor
        long factor = pow(10, i);

        // Formulate first set of digits (2nd from last)
        if (i % 2 != 0 && count == 16) {
            digit = (ccNUM / factor) % 10;
            multi = digit * 2;

    sum1 += digit * 2 / 10 + digit * 2 % 10;
        }
    }


     // Define which card type
    int test = ccNUM / pow(10, count - 2);
    if (count == 16 && test / 10 == 4)
    {
        card = "VISA";
        // print("card");
    }
    else if ((count == 13 || count == 16) && test >= 51 && test <= 55)
    {
        card = "MASTERCARD";

    }
    else if (count == 15 && (test == 34 || test == 37))
    {
        card = "AMEX";

    }
    else
    {
        card = "INVALID";

    }


    // Compute final sum
    result = sum1 + sum2;

    // Final verification
    if (result % 10 == 0) {
        printf("%s\n", card);
    }
    else {
        printf("INVALID\n");
    }
}