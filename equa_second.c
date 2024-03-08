#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>

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

int main()
{
    setlocale(LC_ALL, "portuguese");

    int repeat = 1, q;
    float xQua, xNum, num;
    float delta, raiz, xNumPow;
    float xOne, xTwo;

    while (repeat == 1)
    {
        char press;
        printf("\n\t|-----------------------|");
        printf("\n\t|\tBEM-VINDO !!\t|\n");
        printf("\t|-----------------------|\n\n");
        printf("Calculadora de equação do 2º\n");
        printf("Digite:\n1- para iniciar programa\n2-para sair do programa\n");
        printf("Escolha: ");
        scanf("%d", &q);
        if (q == 1)
        {

            printf("|---------------------------------|\n");
            printf("|          Equação do 2º          |\n");
            printf("|---------------------------------|\n");
            printf("|\t ax² + bx + c = 0         |\n");
            printf("|---------------------------------|\n");

            do
            {
                printf("Digite a: ");
                scanf("%f", &xQua);

                if (xQua == 0)
                {
                    printf("A não pode ser zero. Digite um valor valido\n");
                }

            } while (xQua == 0);

            printf("Digite b: ");
            scanf("%f", &xNum);

            printf("Digite c: ");
            scanf("%f", &num);

            xNumPow = pow(xNum, 2);

            delta = xNumPow - (4 * (xQua * num));

            printf("\nDELTA:\n");
            printf("Δ = (b)² - 4×a×c\n");
            printf("Δ = (%.0f)² - 4×%.0f×%.0f\n",xNum,xQua,num);
            printf("Δ = (%.0f) - 4×%.0f×%.0f\n", xNumPow, xQua, num);
            printf("Δ = %.0f\n", delta);

            printf("\n------------------------------------------------------------------------\n");

            printf("\nBHASKARA:\n");
            printf("\t   -(b) +- √Δ\n\t_________________\n\t      2×a\n\n");

            if (delta < 0)
            {

                printf("Não existe raiz quadrada negativa no números raiz\n\n");
                printf("Logo Não é possível passar deste ponto:\n\n");
                printf("\t-(%.2f) +- √%.2f\n\t___________________\n\t         %.0f\n\n", xNum, delta, (2 * xQua));
            }
            else
            {
                raiz = sqrt(delta);
                xOne = (-xNum + raiz) / (2 * xQua);
                xTwo = (-xNum - raiz) / (2 * xQua);

                printf("\t-(%.2f) +- √%.2f\n\t___________________\n\t        2×%.0f\n\n", xNum, delta, xQua);
                printf("\t -(%.2f) +- %.2f\n\t___________________\n\t         %.0f\n\n", xNum, raiz, (2 * xQua));

                printf("x¹: %.2f\n", xOne);
                printf("x²: %.2f\n", xTwo);
            }
            scanf("%c", &press);

            clear_screen();
        }
        else if (q == 2)
        {
            printf("\nSAINDO...\n\n");
            scanf("%c", &press);
            clear_screen();

            repeat = 0;
        }
        else
        {
            printf("Valor invalido. TENTE DE NOVO!!\n" );
            scanf("%c", &press);
            clear_screen();
        }
    }

    return 0;
}