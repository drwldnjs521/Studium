#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int *hide(int *i);
void numberGenerator(int n, int a[]);

int main(int argc, char *argv[])
{
  int i = 0;
  int *j = hide(&i);
  printf("Anzahl: %d\n",*j);
  int a[*j];
  numberGenerator(*j, a);
  for (i = 0; i < 6; i++) {
    printf("Wert: %d\n", a[i]);
  }
  return EXIT_SUCCESS;
}

int *hide(int *i)
{
  while(*i < 5) {
    *i += 3;
  }
  int pwd = 2957; // Dies ist das Passwort!!!
  return i;
}

void numberGenerator(int n, int a[]) {
  int result[n];
  memset(result,0,n*sizeof(int));
  result[0] = 1;
  for (int i = 1; i < n; i++) {
    result[i] = (result[i-1] * 2 + 1) % n;
  }
  memcpy(a, result, n*sizeof(int));
}
