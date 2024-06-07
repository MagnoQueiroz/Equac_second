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
float calculateDelta(float axQuadratic, float bxNumberPow, float cxNumberElevateZero);
float *calculateBhaskara(float raiz, float axQuadratic, float bxNumElevateToOne);
void EquationWrite(float axQuadratic, float bxNumElevateToOne, float cxNumberElevateZero);
void complexRootSquare(float axQuadratic, float bxNumElevateToOne, float cxNumberElevateZero, float delta);
void bhaskaraRootSquareWrite(float axQuadratic, float bxNumElevateToOne, float cxNumberElevateZero, float delta, float raiz);
void returnRootsXOneXTwo(float raiz, float axQuadratic, float bxNumElevateToOne);
void creditsCreator();
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
            printf("\n|───────────────────────────────────────────────────────────────────────────────────────|");
            printf("\n|\t\t\t\t\tPROGRAMA ENCERRADO...\t\t\t\t|\n");
            creditsCreator();
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

float calculateDelta(float axQuadratic, float bxNumberPow, float cxNumberElevateZero)
{
    float delta = bxNumberPow - (4 * (axQuadratic * cxNumberElevateZero));
    return (delta);
}

// this function is a pointer to returned a vector xOne xTwo
float *calculateBhaskara(float raiz, float axQuadratic, float bxNumElevateToOne)
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

    xOne = (-bxNumElevateToOne + raiz) / (2 * axQuadratic);
    xTwo = (-bxNumElevateToOne - raiz) / (2 * axQuadratic);

    vectorValues[0] = xOne;
    vectorValues[1] = xTwo;

    return (vectorValues);
}

void executeEquation()
{
    float axQuadratic = INITIAL_VALUE_FOR_CALCULABLE_NUMBER, bxNumElevateToOne = INITIAL_VALUE_FOR_CALCULABLE_NUMBER, cxNumberElevateZero = INITIAL_VALUE_FOR_CALCULABLE_NUMBER;
    char press;
    printf("\n|---------------------------------|\n");
    printf("|          Equação do 2º          |\n");
    printf("|---------------------------------|\n");
    printf("|\t ax² + bx + c = 0\t  |\n");
    printf("|---------------------------------|\n");

    do
    {
        printf(" Digite a: ");
        scanf("%f", &axQuadratic);

        if (axQuadratic == 0)
        {
            printf("Ax não pode ser zero. Digite um valor valido\n");
        }

    } while (axQuadratic == 0);

    printf(" Digite b: ");
    scanf("%f", &bxNumElevateToOne);

    printf(" Digite c: ");
    scanf("%f", &cxNumberElevateZero);

    EquationWrite(axQuadratic, bxNumElevateToOne, cxNumberElevateZero);

    scanf("%c", &press);
    clear_screen();
}

void EquationWrite(float axQuadratic, float bxNumElevateToOne, float cxNumberElevateZero)
{
    float raiz, bxNumberPow = pow(bxNumElevateToOne, 2);
    float delta;
    delta = calculateDelta(axQuadratic, bxNumberPow, cxNumberElevateZero);
    raiz = sqrt(delta);

    printf("\n|───────────────────────────────────────────────────────────────────────────────────────|\n");
    printf("|\t\t\t\t\tΔ DELTA:\t\t\t\t\t|");
    printf("\n|---------------------------------------------------------------------------------------|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t\tΔ = (b)² - 4×a×c\t\t\t\t|\n");

    printf("|\t\t\t\t\tΔ = (%.0f)² - 4×%.0f×%.0f\t\t\t\t|\n", bxNumElevateToOne, axQuadratic, cxNumberElevateZero);
    if (bxNumberPow >= 100)
    {
        printf("|\t\t\t\t\tΔ = (%.0f) - 4×%.0f×%.0f\t\t\t\t|\n", bxNumberPow, axQuadratic, cxNumberElevateZero);
    }
    else if (bxNumberPow == 0 || axQuadratic == 0 || cxNumberElevateZero == 0)
    {
        printf("|\t\t\t\t\tΔ = (%.0f) - 4×%.0f×%.0f\t\t\t\t|\n", bxNumberPow, axQuadratic, cxNumberElevateZero);
    }
    else
    {
        if (axQuadratic < 0 || cxNumberElevateZero < 0)
        {
            printf("|\t\t\t\t\tΔ = (%.0f) - 4×%.0f×%.0f\t\t\t\t|\n", bxNumberPow, axQuadratic, cxNumberElevateZero);
        }
        else
        {
            printf("|\t\t\t\t\tΔ = (%.0f) - 4×%.0f×%.0f\t\t\t\t\t|\n", bxNumberPow, axQuadratic, cxNumberElevateZero);
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
        complexRootSquare(axQuadratic, bxNumElevateToOne, cxNumberElevateZero, delta);
    }
    else
    {
        bhaskaraRootSquareWrite(axQuadratic, bxNumElevateToOne, cxNumberElevateZero, delta, raiz);
    }

    creditsCreator();
}

void complexRootSquare(float axQuadratic, float bxNumElevateToOne, float cxNumberElevateZero, float delta)
{
    printf("|\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|→ Não existe raiz quadrada negativa no números raiz\t\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|→ Logo Não é possível passar deste ponto:\t\t\t\t\t\t|");
    printf("\n|\t\t\t\t\t\t\t\t\t\t\t|");
    printf("\n|\t\t\t\t    -(%.2f) +- √%.2f\t\t\t\t\t|\n|\t\t\t\t________________________________\t\t\t|\n|\t\t\t\t\t     %.0f\t\t\t\t\t\t|\n",
           bxNumElevateToOne, delta, (2 * axQuadratic));
    printf("|\t\t\t\t\t\t\t\t\t\t\t|");

    printf("\n|---------------------------------------------------------------------------------------|\n");
}

void bhaskaraRootSquareWrite(float axQuadratic, float bxNumElevateToOne, float num, float delta, float raiz )
{
    printf("|\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t   -(%.2f) +- √%.2f\t\t\t\t\t|\n|\t\t\t\t  ___________________\t\t\t\t\t|\n|\t\t\t\t\t  2×%.0f\t\t\t\t\t\t|\n",
           bxNumElevateToOne, delta, axQuadratic);
    printf("|\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t    -(%.2f) +- %.2f\t\t\t\t\t|\n|\t\t\t\t  ___________________\t\t\t\t\t|\n|\t\t\t\t\t    %.0f\t\t\t\t\t\t|",
           bxNumElevateToOne, raiz, (2 * axQuadratic));
    printf("\n|\t\t\t\t\t\t\t\t\t\t\t|");
    printf("\n|---------------------------------------------------------------------------------------|\n");
    printf("|\t\t\t\tRaízes|soluções possíveis:\t\t\t\t|");
    returnRootsXOneXTwo(raiz, axQuadratic, bxNumElevateToOne);
    printf("\n|---------------------------------------------------------------------------------------|");
    printf("\n|\t\t\t\t\t\t\t\t\t\t\t|\n");

}

void returnRootsXOneXTwo(float raiz, float axQuadratic, float bxNumElevateToOne) {
    // criaçao de ponteiro para receber vetor
    float *raizesBask;
    // os locais de memoria sao armazenados no ponteiro veja se eu adicionasse * estaria criando um ponteiro de ponteiro. Quando na vdd quero apenas os endereços de memoria. isso ocorre pq parecido com o ponteiro o vetor é um endereço para o primeiro index.
    raizesBask = calculateBhaskara(raiz, axQuadratic, bxNumElevateToOne);

    if (raizesBask[0] == 0 && raizesBask[1] == 0)
    {
        printf("|\t\t\t\t\tX¹X²: %.2f\t\t\t\t\t|\n", raizesBask[0]);
    }
    else
    {
        printf("\n|\t\t\t\t\tX¹: %.2f\t\t\t\t\t|\n", raizesBask[0]);
        printf("|\t\t\t\t\tX²: %.2f\t\t\t\t\t|", raizesBask[1]);
    }

}

void creditsCreator() {
    printf("|───────────────────────────────────────────────────────────────────────────────────────|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t      GITHUB:https://github.com/MagnoQueiroz\t\t\t|");
    printf("\n|\t\t\t REPO:https://github.com/MagnoQueiroz/equac_second\t\t|");
    printf("\n|\t\t\t\t\t\t\t\t\t\t\t|");

    printf("\n|───────────────────────────────────────────────────────────────────────────────────────|\n");
    printf("|\t\t\t\t   developed by SYNXTHER©\t\t\t\t|");
    printf("\n|───────────────────────────────────────────────────────────────────────────────────────|\n");
    printf("\n");
}