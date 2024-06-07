#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <ctype.h>

// #include <string.h>
//?? Is there a way to set null values in variables that are not pointers?
#define INITIAL_VALUE_FOR_CALCULABLE_NUMBER 0

#ifdef __linux__
#include <stdlib.h>
#elif _WIN32
#include <windows.h>
#else
#endif

void clear_screen()
{
    printf("\n\n[PRESS ENTER] OU QUALQUER TECLA PARA CONTINUAR O PROCEDIMENTO...");
    char press = getchar();
#ifdef __linux__
    system("clear");
#elif _WIN32
    system("cls");
#else
#endif
}

void welcomeScreen();
void executeEquation();
float calculateDelta(float xQuadratic, float xNumberPow, float num);
float *calculateBhaskara(float raiz, float xQuadratic, float xNumElevateToOne);
void EquationWrite(float xQuadratic, float xNumElevateToOne, float num);
int main()
{
    setlocale(LC_ALL, "portuguese");
    welcomeScreen();
    return (0);
}

void welcomeScreen()
{
    int repeat = INITIAL_VALUE_FOR_CALCULABLE_NUMBER;
    char answer;
    do
    {
        char press;
        printf("\n|────────────────────────────────────────────────────────|");
        printf("\n|\t\t\tBEM-VINDO !!\t\t\t |");
        printf("\n|────────────────────────────────────────────────────────|\n");
        printf("|\t\tCalculadora de equação do 2º\t\t |");
        printf("\n|--------------------------------------------------------|\n");
        printf("|\tPRESS: [S|s] Para iniciar  [N|n] Para sair\t |");
        printf("\n|--------------------------------------------------------|\n");

        printf("PRESS: ");
        scanf("%c", &answer);
        answer= tolower(answer);
        if (answer == 's')
        {
            executeEquation();
        }
        else if (answer == 'n')
        {
            scanf("%c", &press);
            clear_screen();
            printf("\n|────────────────────────────────────────────────────────|");
            printf("\n|\t\t   PROGRAMA ENCERRADO...\t\t |\n");
            printf("|\t\t\t\t\t\t\t |");
            printf("\n|--------------------------------------------------------|\n");
            printf("|\t\t  developed by Synxther©\t\t |\n");
            printf("|\t GITHUB:https://github.com/MagnoQueiroz\t\t |");
            printf("\n|    REPO:https://github.com/MagnoQueiroz/equac_second\t |");

            printf("\n|────────────────────────────────────────────────────────|");
            printf("\n");
            repeat = 1;
        }
        else
        {
            printf("\n\n\t\tVALOR INVALIDO. TENTE DE NOVO!!\n");
            scanf("%c", &press);
            clear_screen();
        }

    } while (repeat == 0);
}

float calculateDelta(float xQuadratic, float xNumberPow, float num)
{
    float delta = xNumberPow - (4 * (xQuadratic * num));
    return (delta);
}

// this function is a pointer to returned a vector xOne xTwo
float *calculateBhaskara(float raiz, float xQuadratic, float xNumElevateToOne)
{
    /**
     * Poderia passar apenas parâmetros com ponteiros *xOne e *xTwo pegando apenas o endereço das variáveis. Porem optei por essa opção
     */
    float xOne, xTwo;
    //// static float vectorValues[2];
    float *vectorValues = (float *)malloc(2 * sizeof(float));
    if (vectorValues == NULL)
    {
        printf("ERROR: FALHA AO ALOCAR MEMORIA");
        exit(1);
    }

    xOne = (-xNumElevateToOne + raiz) / (2 * xQuadratic);
    xTwo = (-xNumElevateToOne - raiz) / (2 * xQuadratic);

    vectorValues[0] = xOne;
    vectorValues[1] = xTwo;

    return (vectorValues);
}

void executeEquation()
{
    float xQuadratic = INITIAL_VALUE_FOR_CALCULABLE_NUMBER, xNumElevateToOne = INITIAL_VALUE_FOR_CALCULABLE_NUMBER, num = INITIAL_VALUE_FOR_CALCULABLE_NUMBER;
    char press;
    printf("\n|---------------------------------|\n");
    printf("|          Equação do 2º          |\n");
    printf("|---------------------------------|\n");
    printf("|\t ax² + bx + c = 0\t  |\n");
    printf("|---------------------------------|\n");

    do
    {
        printf(" Digite a: ");
        scanf("%f", &xQuadratic);

        if (xQuadratic == 0)
        {
            printf("Ax não pode ser zero. Digite um valor valido\n");
        }

    } while (xQuadratic == 0);

    printf(" Digite b: ");
    scanf("%f", &xNumElevateToOne);

    printf(" Digite c: ");
    scanf("%f", &num);

    EquationWrite(xQuadratic, xNumElevateToOne, num);

    scanf("%c", &press);
    clear_screen();
}

void EquationWrite(float xQuadratic, float xNumElevateToOne, float num)
{
    float raiz, xNumberPow = pow(xNumElevateToOne, 2);
    float delta;
    float *raizesBask;
    delta = calculateDelta(xQuadratic, xNumberPow, num);
    raiz = sqrt(delta);

    raizesBask = calculateBhaskara(raiz, xQuadratic, xNumElevateToOne);
    printf("\n|───────────────────────────────────────────────────────────────────────────────────────|\n");
    printf("|\t\t\t\t\tΔ DELTA:\t\t\t\t\t|");
    printf("\n|---------------------------------------------------------------------------------------|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t\tΔ = (b)² - 4×a×c\t\t\t\t|\n");

    printf("|\t\t\t\t\tΔ = (%.0f)² - 4×%.0f×%.0f\t\t\t\t|\n", xNumElevateToOne, xQuadratic, num);
    if (xNumberPow >= 100)
    {
        printf("|\t\t\t\t\tΔ = (%.0f) - 4×%.0f×%.0f\t\t\t\t|\n", xNumberPow, xQuadratic, num);
    }
    else if (xNumberPow == 0 || xQuadratic == 0 || num == 0)
    {
        printf("|\t\t\t\t\tΔ = (%.0f) - 4×%.0f×%.0f\t\t\t\t|\n", xNumberPow, xQuadratic, num);
    }
    else
    {
        if (xQuadratic < 0 || num < 0)
        {
            printf("|\t\t\t\t\tΔ = (%.0f) - 4×%.0f×%.0f\t\t\t\t|\n", xNumberPow, xQuadratic, num);
        }
        else
        {
            printf("|\t\t\t\t\tΔ = (%.0f) - 4×%.0f×%.0f\t\t\t\t\t|\n", xNumberPow, xQuadratic, num);
        }
    }
    if (delta <= -1004)
    {
        printf("|\t\t\t\t\tΔ = %.0f\t\t\t\t\t\t|\n", delta);
    }
    if (delta >= 1000)
    {
        printf("|\t\t\t\t\tΔ = %.0f\t\t\t\t\t|\n", delta);
    }
    else
    {
        printf("|\t\t\t\t\tΔ = %.0f\t\t\t\t\t\t|\n", delta);
    }
    printf("|\t\t\t\t\t\t\t\t\t\t\t|");

    printf("\n|---------------------------------------------------------------------------------------|\n");
    printf("|\t\t\t\t\tBHASKARA:\t\t\t\t\t|");
    printf("\n|---------------------------------------------------------------------------------------|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t|");
    printf("\n|\t\t\t\t\t-(b) +- √Δ\t\t\t\t\t|\n|\t\t\t\t_____________________________\t\t\t\t|\n|\t\t\t\t\t    2×a\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t|\n");

    if (delta < 0)
    {
        printf("|\t\t\t\t\t\t\t\t\t\t\t|\n");
        printf("|→ Não existe raiz quadrada negativa no números raiz\t\t\t\t\t|\n");
        printf("|\t\t\t\t\t\t\t\t\t\t\t|\n");
        printf("|→ Logo Não é possível passar deste ponto:\t\t\t\t\t\t|");
        printf("\n|\t\t\t\t\t\t\t\t\t\t\t|");
        printf("\n|\t\t\t\t    -(%.2f) +- √%.2f\t\t\t\t\t|\n|\t\t\t\t________________________________\t\t\t|\n|\t\t\t\t\t     %.0f\t\t\t\t\t\t|\n",
               xNumElevateToOne, delta, (2 * xQuadratic));
        printf("|\t\t\t\t\t\t\t\t\t\t\t|");

        printf("\n|---------------------------------------------------------------------------------------|\n");
    }
    else
    {
        printf("|\t\t\t\t\t\t\t\t\t\t\t|\n");
        printf("|\t\t\t\t   -(%.2f) +- √%.2f\t\t\t\t\t|\n|\t\t\t\t  ___________________\t\t\t\t\t|\n|\t\t\t\t\t  2×%.0f\t\t\t\t\t\t|\n",
               xNumElevateToOne, delta, xQuadratic);
        printf("|\t\t\t\t\t\t\t\t\t\t\t|\n");
        printf("|\t\t\t\t    -(%.2f) +- %.2f\t\t\t\t\t|\n|\t\t\t\t  ___________________\t\t\t\t\t|\n|\t\t\t\t\t    %.0f\t\t\t\t\t\t|",
               xNumElevateToOne, raiz, (2 * xQuadratic));
        printf("\n|\t\t\t\t\t\t\t\t\t\t\t|");
        printf("\n|---------------------------------------------------------------------------------------|\n");
        printf("|\t\t\t\tRaízes|soluções possíveis:\t\t\t\t|");
        printf("\n|---------------------------------------------------------------------------------------|");
        printf("\n|\t\t\t\t\t\t\t\t\t\t\t|\n");
        if (raizesBask[0] == 0 && raizesBask[1] == 00)
        {
            printf("|\t\t\t\t\tX¹X²: %.2f\t\t\t\t\t|", raizesBask[0]);
        }
        else
        {
            printf("|\t\t\t\t\tX¹: %.2f\t\t\t\t\t|\n", raizesBask[0]);
            printf("|\t\t\t\t\tX²: %.2f\t\t\t\t\t|", raizesBask[1]);
        }
    }

    printf("\n|───────────────────────────────────────────────────────────────────────────────────────|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t    GITHUB:https://github.com/MagnoQueiroz\t\t\t|");
    printf("\n|\t\t     REPO:https://github.com/MagnoQueiroz/equac_second\t\t\t|");
    printf("\n|\t\t\t\t\t\t\t\t\t\t\t|");

    printf("\n|───────────────────────────────────────────────────────────────────────────────────────|\n");
    printf("|\t\t\t\t   developed by SYNXTHER©\t\t\t\t|");
    printf("\n|───────────────────────────────────────────────────────────────────────────────────────|\n");
    printf("\n");
}