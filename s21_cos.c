#include "s21_math.h"
long double s21_cos(double x) { 
	long double n = 1;
	long double i = 1;
	long double res = 1;
	x = s21_fmod(x, 2 * M_PI);
	while(s21_fabs(n) > 1e-16) {
		n = ((4 * (x * x) / (((2 * i - 1 ) * (2 * i - 1 )) * (M_PI * M_PI))));
		res *= (1 - n);
		i++;
}
  return res;
}