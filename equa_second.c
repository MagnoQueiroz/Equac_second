#include <stdio.h>
#include <locale.h>
#include <math.h>

#ifdef __linux__

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

float *calcbask(float raiz, float xqua, float xnum);

void processEquaAndWrite(float xqua, float xnum, float num);

int main() {
    setlocale(LC_ALL, "portuguese");
    int repeat;
    char answer;
    float xQua, xNum, num;

    do {
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

        if ((answer == 'S') || (answer == 's')) {
            printf("\n|---------------------------------|\n");
            printf("|          Equação do 2º          |\n");
            printf("|---------------------------------|\n");
            printf("|\t ax² + bx + c = 0\t  |\n");
            printf("|---------------------------------|\n");

            do {
                printf(" Digite a: ");
                scanf("%f", &xQua);

                if (xQua == 0) {
                    printf("Ax não pode ser zero. Digite um valor valido\n");
                }

            } while (xQua == 0);

            printf(" Digite b: ");
            scanf("%f", &xNum);

            printf(" Digite c: ");
            scanf("%f", &num);

            processEquaAndWrite(xQua, xNum, num);

            scanf("%c", &press);
            clear_screen();
        } else if ((answer == 'n') || (answer == 'N')) {
            scanf("%c", &press);
            clear_screen();
            printf("\n|────────────────────────────────────────────────────────|");
            printf("\n|\t\t   PROGRAMA ENCERRADO...\t\t |\n");
            printf("|\t\t\t\t\t\t\t |");
            printf("\n|--------------------------------------------------------|\n");
            printf("|\t\t  developed by Synxther©\t\t |\n");
            printf("|\t GITHUB:https://github.com/MagnoQueiroz\t\t |");
            printf("\n|────────────────────────────────────────────────────────|");
            repeat = 1;
        } else {
            printf("\n\n\t\tVALOR INVALIDO. TENTE DE NOVO!!\n");
            scanf("%c", &press);
            clear_screen();
        }

    } while (repeat == 0);

    return (0);
}

float calcdelta(float xqua, float xNumPow, float num) {
    float delta = xNumPow - (4 * (xqua * num));
    return (delta);
}

float *calcbask(float raiz, float xqua, float xnum) {
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
    float *raizesBask;
    delta = calcdelta(xqua, xNumPow, num);
    raiz = sqrt(delta);

    raizesBask = calcbask(raiz, xqua, xnum);
    printf("\n|───────────────────────────────────────────────────────────────────────────────────────|\n");
    printf("|\t\t\t\t\tΔ DELTA:\t\t\t\t\t|");
    printf("\n|---------------------------------------------------------------------------------------|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t\tΔ = (b)² - 4×a×c\t\t\t\t|\n");

    printf("|\t\t\t\t\tΔ = (%.0f)² - 4×%.0f×%.0f\t\t\t\t|\n", xnum, xqua, num);
    if (xNumPow >= 100) {
        printf("|\t\t\t\t\tΔ = (%.0f) - 4×%.0f×%.0f\t\t\t\t|\n", xNumPow, xqua, num);
    } else if (xNumPow == 0 || xqua == 0 || num == 0) {
        printf("|\t\t\t\t\tΔ = (%.0f) - 4×%.0f×%.0f\t\t\t\t|\n", xNumPow, xqua, num);
    } else {
        printf("|\t\t\t\t\tΔ = (%.0f) - 4×%.0f×%.0f\t\t\t\t|\n", xNumPow, xqua, num);
    }
    if (delta <= -10) {
        printf("|\t\t\t\t\tΔ = %.0f\t\t\t\t\t\t|\n", delta);

    } if(delta >=1000) {
        printf("|\t\t\t\t\tΔ = %.0f\t\t\t\t\t|\n", delta);

    } else {
        printf("|\t\t\t\t\tΔ = %.0f\t\t\t\t\t\t|\n", delta);
    }
    printf("|\t\t\t\t\t\t\t\t\t\t\t|");

    printf("\n|---------------------------------------------------------------------------------------|\n");
    printf("|\t\t\t\t\tBHASKARA:\t\t\t\t\t|");
    printf("\n|---------------------------------------------------------------------------------------|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t|");
    printf("\n|\t\t\t\t\t-(b) +- √Δ\t\t\t\t\t|\n|\t\t\t\t_____________________________\t\t\t\t|\n|\t\t\t\t\t    2×a\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t|\n");

    if (delta < 0) {
        printf("|\t\t\t\t\t\t\t\t\t\t\t|\n");
        printf("|→ Não existe raiz quadrada negativa no números raiz\t\t\t\t\t|\n");
        printf("|\t\t\t\t\t\t\t\t\t\t\t|\n");
        printf("|→ Logo Não é possível passar deste ponto:\t\t\t\t\t\t|");
        printf("\n|\t\t\t\t\t\t\t\t\t\t\t|");
        printf("\n|\t\t\t\t    -(%.2f) +- √%.2f\t\t\t\t\t|\n|\t\t\t\t________________________________\t\t\t|\n|\t\t\t\t\t     %.0f\t\t\t\t\t\t|\n",
               xnum, delta, (2 * xqua));
        printf("|\t\t\t\t\t\t\t\t\t\t\t|");

        printf("\n|---------------------------------------------------------------------------------------|\n");
    } else {
        printf("|\t\t\t\t\t\t\t\t\t\t\t|\n");
        printf("|\t\t\t\t   -(%.2f) +- √%.2f\t\t\t\t\t|\n|\t\t\t\t  ___________________\t\t\t\t\t|\n|\t\t\t\t\t  2×%.0f\t\t\t\t\t\t|\n",
               xnum, delta, xqua);
        printf("|\t\t\t\t\t\t\t\t\t\t\t|\n");
        printf("|\t\t\t\t    -(%.2f) +- %.2f\t\t\t\t\t|\n|\t\t\t\t  ___________________\t\t\t\t\t|\n|\t\t\t\t\t    %.0f\t\t\t\t\t\t|",
               xnum, raiz, (2 * xqua));
        printf("\n|\t\t\t\t\t\t\t\t\t\t\t|");
        printf("\n|---------------------------------------------------------------------------------------|\n");
        printf("|\t\t\t\tRaízes|soluções possíveis:\t\t\t\t|");
        printf("\n|---------------------------------------------------------------------------------------|");
        printf("\n|\t\t\t\t\t\t\t\t\t\t\t|\n");
        if (raizesBask[0] == 0 && raizesBask[1] == 00) {
            printf("|\t\t\t\t\tX¹X²: %.2f\t\t\t\t\t|", raizesBask[0]);
        } else {
            printf("|\t\t\t\t\tX¹: %.2f\t\t\t\t\t|\n", raizesBask[0]);
            printf("|\t\t\t\t\tX²: %.2f\t\t\t\t\t|", raizesBask[1]);
        }
        printf("\n|\t\t\t\t\t\t\t\t\t\t\t|");
        printf("\n|───────────────────────────────────────────────────────────────────────────────────────|\n");
        printf("|\t\t\t\t   developed by Synxther©\t\t\t\t|\n");
        printf("|\t\t\t    GITHUB:https://github.com/MagnoQueiroz\t\t\t|");
        printf("\n|───────────────────────────────────────────────────────────────────────────────────────|\n");
    }
}