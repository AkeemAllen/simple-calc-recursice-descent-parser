#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double parseSum(char **expression);

double parseFactor(char **expression) {
  double result = 0;
  while (**expression >= '0' && **expression <= '9') {
    result = (result * 10) + (**expression - '0');
    (*expression)++;
    if (**expression == '+' || **expression == '-' || **expression == '/' ||
        **expression == '*' || **expression == '\0' || **expression == '(' ||
        **expression == ')') {
      return result;
    }
  }

  if (**expression == '(') {
    (*expression)++;
    double inner_result = parseSum(expression);
    (*expression)++;
    return inner_result;
  }

  if (**expression == '-') {
    (*expression)++;
    return -parseFactor(expression);
  }

  printf("Error attempting to parse: %c \n", *expression[0]);
  assert(false);
}

double parseProduct(char **expression) {
  double fac1 = parseFactor(expression);

  while (**expression == '*' || **expression == '/' || **expression == '(') {
    int mulOrDiv = 1;
    if (**expression == '/')
      mulOrDiv = 0;

    if (**expression != '(')
      ++(*expression);
    double fac2 = parseFactor(expression);

    if (mulOrDiv == 1) {
      fac1 = fac1 * fac2;
    } else {
      fac1 = fac1 / fac2;
    }
  }
  return fac1;
};

double parseSum(char **expression) {
  double fac1 = parseProduct(expression);

  while (**expression == '+' || **expression == '-') {
    int addOrSub = 1;
    if (**expression == '-')
      addOrSub = 0;

    ++(*expression);
    double fac2 = parseProduct(expression);

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

  double result = parseSum(&expression);

  printf("Result: %.2f\n", result);
  return 0;
}
