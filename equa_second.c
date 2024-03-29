#include <stdio.h>
#include <locale.h>
#include <math.h>

#ifdef __linux
#include <stdlib.h>
#elif _WIN32
#include <windows.h>
#else
#endif

void clear_screen() {
    printf("\n\n[PRESS ENTER] OU QUALQUER TECLA PARA CONTINUAR O PROCEDIMENTO...");
    char press = getchar();
#ifdef __linux__

    system("clear");
#elif _WIN32
    system("cls");
#else

#endif
}

float calcdelta(float xqua, float xNumPow, float num);

float * calcbask(float raiz, float xqua, float xnum);

void processEquaAndWrite(float xqua, float xnum, float num);

int main() {
    setlocale(LC_ALL, "portuguese");
    int repeat = 1;
    float xQua, xNum, num;

    while (repeat == 1) {
        char press;
        printf("\n\t|-------------------------|");
        printf("\n\t|   \tBEM-VINDO !!\t  |\n");
        printf("\t|-------------------------|\n\n");
        printf("Calculadora de equação do 2º\n");
        printf("Digite:\n1- para iniciar programa\n2-para sair do programa\n");
        printf("Escolha: ");
        scanf("%d", &repeat);
        if (repeat == 1) {

            printf("|---------------------------------|\n");
            printf("|          Equação do 2º          |\n");
            printf("|---------------------------------|\n");
            printf("|\t  ax² + bx + c = 0        |\n");
            printf("|---------------------------------|\n");

            do {
                printf("Digite a: ");
                scanf("%f", &xQua);

                if (xQua == 0) {
                    printf("Ax não pode ser zero. Digite um valor valido\n");
                }

            } while (xQua == 0);

            printf("Digite b: ");
            scanf("%f", &xNum);

            printf("Digite c: ");
            scanf("%f", &num);

            processEquaAndWrite(xQua, xNum, num);

            scanf("%c", &press);
            clear_screen();
        } else if (repeat == 2) {
            printf("\nSAINDO...\n\n");
            scanf("%c", &press);
            clear_screen();

            repeat = 0;
        } else {
            printf("Valor invalido. TENTE DE NOVO!!\n");
            scanf("%c", &press);
            clear_screen();
        }

    }
    return (0);
}

float calcdelta(float xqua, float xNumPow, float num) {
    float delta = xNumPow - (4 * (xqua * num));
    return (delta);
}

float * calcbask(float raiz, float xqua, float xnum) {
    float xOne, xTwo;
    static float vetorValores[2];

    xOne = (-xnum + raiz) / (2 * xqua);
    xTwo = (-xnum - raiz) / (2 * xqua);
    vetorValores[0] = xOne;
    vetorValores[1] = xTwo;

    return (vetorValores);
}

void processEquaAndWrite(float xqua, float xnum, float num) {
    float raiz, xNumPow = pow(xnum, 2);
    float delta;
    float * raizesBask;
    delta = calcdelta(xqua, xNumPow, num);
    raiz = sqrt(delta);

    raizesBask = calcbask(raiz, xqua, xnum);

    printf("\n|--------------------------------------------------------------------|\n");
    printf("\n\tDELTA:\n\n");
    printf("\t\tΔ = (b)² - 4×a×c\n");
    printf("\t\tΔ = (%.0f)² - 4×%.0f×%.0f\n", xnum, xqua, num);
    printf("\t\tΔ = (%.0f) - 4×%.0f×%.0f\n", xNumPow, xqua, num);
    printf("\t\tΔ = %.0f\n", delta);
    printf("\n|--------------------------------------------------------------------|\n");
    printf("\n\tBHASKARA:\n");
    printf("\n\t\t   -(b) +- √Δ\n\t\t_________________\n\t\t      2×a\n\n");


    if (delta < 0) {

        printf("\tNão existe raiz quadrada negativa no números raiz\n\n");
        printf("\tLogo Não é possível passar deste ponto:\n");
        printf("\n\t\t-(%.2f) +- √%.2f\n\t\t___________________\n\t\t         %.0f\n", xnum, delta, (2 * xqua));
        printf("\n|--------------------------------------------------------------------|\n");
    } else {

        printf("\t\t-(%.2f) +- √%.2f\n\t\t___________________\n\t\t        2×%.0f\n\n", xnum, delta, xqua);
        printf("\t\t -(%.2f) +- %.2f\n\t\t___________________\n\t\t         %.0f\n\n", xnum, raiz, (2 * xqua));

        printf("\n|--------------------------------------------------------------------|\n");
        printf("\n\tRaízes|soluções possíveis:\n\n");
        printf("\t\tX¹: %.2f\n", raizesBask[0]);
        printf("\t\tX²: %.2f\n", raizesBask[1]);
        printf("|--------------------------------------------------------------------|\n");
    }
}