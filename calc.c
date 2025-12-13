#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parseFactor(char **expression) {
  if (**expression >= '0' && **expression <= '9') {
    int result = **expression - '0';
    (*expression)++;
    return result;
  } else if (**expression == '-') {
    (*expression)++;
    return -parseFactor(expression);
  } else {
    printf("Not a digit");
  }
  return 0;
}

int parseProduct(char **expression) {
  int fac1 = parseFactor(expression);
  while (**expression == '*' || **expression == '/') {
    int mulOrDiv = 1;
    if (**expression == '/')
      mulOrDiv = 0;

    ++(*expression);
    int fac2 = parseFactor(expression);
    if (mulOrDiv == 1) {
      fac1 = fac1 * fac2;
    } else {

      fac1 = fac1 / fac2;
    }
  }
  return fac1;
};

int parseSum(char **expression) {
  int fac1 = parseProduct(expression);

  while (**expression == '+' || **expression == '-') {
    // Addition is default 1; Subtraction is 0;
    int addOrSub = 1;
    if (**expression == '-')
      addOrSub = 0;

    ++(*expression);
    int fac2 = parseProduct(expression);
    if (addOrSub == 1) {
      fac1 = fac1 + fac2;
    } else {
      fac1 = fac1 - fac2;
    }
  }

  return fac1;
};

int main(int argc, char *argv[]) {
  char *expression = argv[1];

  int result = parseSum(&expression);

  printf("Result: %d\n", result);
  return 0;
}
