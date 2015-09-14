#include <math.h>   
#include "stdafx.h" 

void factorize(int n, int *nFact, int fact[]);   

void transTableSetup(int sofar[], int actual[], int remain[],   
                       int *nFact,   
                       int *nPoints);   

void permute(int nPoint, int nFact,   
               int fact[], int remain[],   
               double xRe[], double xIm[],   
               double yRe[], double yIm[]);

void initTrig(int radix);

void fft_4(double aRe[], double aIm[]); 

void fft_5(double aRe[], double aIm[]);

void fft_8(); 

void fft_10();

void fft_odd(int radix);  

void twiddleTransf(int sofarRadix, int radix, int remainRadix,   
                      double yRe[], double yIm[]);   

void fft(int n, double xRe[], double xIm[],double yRe[], double yIm[]);

void IFFT(int n, double xRe[], double xIm[], double yRe[], double yIm[]); 