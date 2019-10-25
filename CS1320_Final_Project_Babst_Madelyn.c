/**************************************/
/*   Madelyn Babst                      */
/*   Summer, 2017                     */
/*   Final Project                    */
/**************************************/
/* This program computes and displays the
                                            */
#include <stdio.h>
#include <math.h>
#define PI 3.14159
#define e 2.71828


unsigned long long fact(int u);
double numConfig(int N, int n);
double prob(int x, int N, int n);
double stirling(int N);

int main()
{
/*  Declare variables */
    double O;                     // Probability of achieving a particular configuration.
    double W;                     // The number of configurations for a given n.
    double P;                     // Single element probability
    int x;                        // The number of possible states of a single element.
    int N;                        // The total number of elements in the system.
    int n;                        // The total number of elements that satisfy the criterion.

    char yn;                      // Yes or No for switch statement
    char example[3][47] = {"Using 6 sided dice: x = 6", "Total number of dice is 2: N = 2", "Number of dice that show a certain face: n = 1"}; // Array just because
    int g=0;                      // Counter for matrix processing.


/* Declare program purpose */
        printf("This program is used for computing the probability of a particular state of a system. \n");

/* Ask the user if they would like to see an example */
        printf("\nWould you like to see an example problem? Enter Y for yes, N for no.\n");
        scanf(" %c", &yn);

/* Test the users input */
        switch (yn)
        {
            case 'y':       // Displays Example for user.
            case 'Y':
/* Display the most shoehorned array in existence */
            for (g=0; g<3; g++)
            {
                printf("%s\n", example[g]);
            }

            P = prob(6, 2, 1);      // single element probability of example
            W = numConfig(2, 1);    // number of configurations of example
            O = W * P;              // Overall probability of example

            printf("\nThe single element probability is %.4f and the number of configurations is %.4f \n", P, W);
            printf("The overall probability of this configuration is %.9f \n", O);
            break;

            case 'n':
            case 'N':
/* User assigns values to criterion */
                printf("You must enter the number of states possible for a single element. \nFor example, for a 2 sided coin, x=2. For a 6 sided die, x=6. \n"); // User assigns value to x
                printf("Please enter value for x: \n");
                scanf("%d", &x);

                printf("Please enter the total number of elements in this system (e.g. How many dice, how many coins): \n"); // User assigns value to N
                scanf("%d", &N);

                printf("Please enter the number of elements that satisfy your criterion (How many heads. How many 1s on a dice): \n"); // User assigns value to n
                scanf("%d", &n);

                printf("You have entered %d possible states, %d total elements, and %d elements that satisfy your criterion.\n \n", x,N, n); // Echo print user input

/* Test to see if use has entered valid inputs */
                if (x<=0 || N < 0 || n < 0)
                {
                    printf("You have entered invalid data. Data must consist of positive nonzero integers. \n Please restart the program and try again.\n");
                    return 0;
                }
                else
                {
                    P = prob(x, N, n); // single element probability

                    W = numConfig(N, n); // number of configurations

                    O = W * P; // The probability of user entered configuration


                    printf("\nThe single element probability is %.9f and the number of configurations is %.2f. \n", P, W);
                    printf("The overall probability of this configuration is approximately %f. \n", O);
                }
                break;

            default:  // If the user entered something other than y or n, display this message.
                printf("Invalid entry. Ensure you are using y or n and try again. \n");
        }
    return 0; /* Exit program. */

}

// function to compute factorials
unsigned long long fact(int u)
{
  long long int c;
  unsigned long long factorial = 1;

  for (c=1; c <= u; c++)
        {
        factorial = factorial * c;
        }

//    printf("\n%d! returned %u\n", u, factorial); // code to check factorial output

  return (factorial);
}

// Function to compute the total number of configurations that satisfy the criterion
double numConfig(int N, int n)
{
    int N_n;
    double W;                  // Number of configurations
    unsigned long long z;                  // stirling value after pass to stirling function

    N_n = N - n;                // single value to pass to factorial function

    if (N>=20){                 // Use stirlings formula for large N
        z = stirling(N);
        W = z/((fact(n))*(fact(N_n)));}
    else {                      // Otherwise, compute factorial of N directly
        W = (fact(N))/((fact(n))*(fact(N_n)));}

    return (W);
}

// Function to compute single element probabilities
double prob(int x, int N, int n)
{
    double p;                      // Probability that criterion is satisfied.
    double q;                      // Probability that criterion is not satisfied.
    int N_n;
    double p_n, q_n;
    double P;                      // Probability of one state.

    N_n = N - n;                   // Created single value in order to pass to power function.
    p = powf(x,-1);
    q = 1 - p;

    p_n = powf(p,n);
    q_n = powf(q,N_n);
    P = p_n * q_n;

    return (P);
}

// Function to approximate very large factorials.
// If N is too large we must approximate it using stirling's formula.
// The larger N is the more accurate this approximation is.
double stirling(int N)
{
    double z,y,x;
    double N_e;

    N_e = N/e;      // created single value in order to pass to power function.

    y = powf(N_e,N);
    z = sqrt(2*PI*N);
    x = y*z;

    return (x);
}
