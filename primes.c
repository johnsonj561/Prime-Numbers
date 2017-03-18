/*
* Justin J
* Practicing with prime numbers in C
* Prompt user to enter total number of prime numbers
* Calculate prime numbers and print to console for viewing
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

// function declaration
void printArray(int*, int);
int getUserInput();

// entry
void main() {

  // get user input
  int primeCount = getUserInput();
  int* primes = malloc(sizeof(int) * primeCount);

  // keep track of multiples of 6
  // we are relying on fact that all primes greater than 3 are a multiple of 6 + - 1
  int multipleOf6 = 6;
  int i;

  // store start time
  struct timeval begin, end;
  gettimeofday(&begin, NULL);

  for(i = 0; i < primeCount; ) {
    // handle cases of i == 0 || i == 1
    if(i == 0){
      primes[i++] = 2;
      continue;
    }
    else if(i == 1) {
      primes[i++] = 3;
      continue;
    }
    // else we know that next prime is multiple of 6 plus + - 1
    else {

      // check multipleOf6 - 1 to see if it's divisble by any previous primes
      // note that every non prime is a multiple of some prime
      int value = multipleOf6 - 1;
      int j;
      int isPrime = 1;
      for(j = 0; j < sqrt(i); j++) {
        if(value % primes[j] == 0) {
          isPrime = 0;
        }
      }
      // if number is prime, add to primes array
      if(isPrime) {
        primes[i++] = value;
      }

      // check multipleOf6 + 1 to see if it's divisble by any previous primes
      value = multipleOf6 + 1;
      isPrime = 1;
      for(j = 0; j < i - 1; j++) {
        if(value % primes[j] == 0) {
          isPrime = 0;
        }
      }
      // if number is prime, add to primes array
       if(isPrime) {
        primes[i++] = value;
      }

    }
   
    multipleOf6 += 6;

  }

  // get end time , calculate and display time elapsed
  gettimeofday(&end, NULL);
  double elapsed = (end.tv_sec - begin.tv_sec)*1000
                 + ((end.tv_usec - begin.tv_usec)/1000.0);

  // display results
  printArray(primes, primeCount);

  printf("\n%d prime numbers took %3f seconds to calculate\n\n", primeCount, elapsed);


}

/*
* Print array to console with 10 digits per row
*/
void printArray(int* a, int length) {
  printf("\n\nPRINTING ARRAY\n\n");
  int i;
  for(i = 0; i < length; i++) {
    // if at end of first row, add closing bar and new line
    if(i%10 == 0 && i != 0) {
      printf("|\n");
    }
    printf("|%6d", a[i]);
  }
  printf("|\n\n");
}

/*
* Prompt user to enter integer
* Return integer entered by user
*/
int getUserInput() {
  int input;
  printf("\n\n**********************************\n");
  printf("* WELCOME TO PRIME NUMBER COUNTER *\n");
 printf("**********************************\n");
  printf("How many prime numbers do you want to see?\n");
  scanf("%d", &input);
  return input;
}
