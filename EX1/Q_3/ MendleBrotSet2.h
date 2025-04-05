#ifndef MENDLEBROTSET2_H
#define MENDLEBROTSET2_H
#include <stdio.h>
#include <math.h>
#include <complex.h>
#include <stdbool.h>
#define LIMIT 10000

double absoluteValue(double complex z);
bool isInMendleSet(double complex input,int N);

#endif
