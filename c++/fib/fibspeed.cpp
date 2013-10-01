#include <cstdio>

static const int terms = 45;

/*
 *  fibonacci - generate nth term in the classical sequence.
 *              precondition :  n > 0
 *              postcondition:  returns the nth term
 */

static int fibonacci (int n)
{
  if (n <= 2)
    return 1;
  else
    return fibonacci (n-1) + fibonacci (n-2);
}


/*
 *  main - first user function executed.
 *         precondition :  none.
 *         postcondition:  returns 0 (silently).
 */

int main (int argc, char *argv[])
{
  printf ("Fibonacci value for the first %d are: ", terms);
  printf ("... %d\n", fibonacci (terms));
}
