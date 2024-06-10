#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <ctype.h>
#include <stdio.h>
#ifdef __linux__
#include <stdlib.h>
#elif _WIN32
#include <windows.h>
#else
#endif

#define INITIAL_VALUE_FOR_CALCULABLE_NUMBER 0

void clear_screen();
void welcomeScreen();
void executeEquation();
float calculateDelta(float axQuadratic, float bxNumberPow, float cxNumberElevateZero);
float *calculateBhaskara(float raiz, float axQuadratic, float bxNumElevateToOne);
void EquationWrite(float axQuadratic, float bxNumElevateToOne, float cxNumberElevateZero);
void complexRootSquare(float axQuadratic, float bxNumElevateToOne, float cxNumberElevateZero, float delta);
void bhaskaraRootSquareWrite(float axQuadratic, float bxNumElevateToOne, float delta, float raiz);
void returnRootsXOneXTwo(float raiz, float axQuadratic, float bxNumElevateToOne);
void creditsCreator();