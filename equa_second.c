#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    float xQua, xNum, num;
    float delta, raiz, xNumPow;
    float xOne, xTwo;
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
        // do while é ao contrario ao invés dele verificar se é falso ele verifica se é verdadeiro... ele vai verificar do falso e dps verdadeiro
    } while (xQua == 0);

    printf("Digite b: ");
    scanf("%f", &xNum);

    printf("Digite c: ");
    scanf("%f", &num);

    xNumPow = pow(xNum, 2);

    delta = xNumPow - (4 * (xQua * num));

    printf("O delta é: %.0f\n\n", delta);
    printf("\t  -(b) +- √Δ\n\t_________________\n\t      2×a\n\n");

    if (delta < 0)
    {
        printf("Não existe raiz quadrada negativa no números raiz\n\n");
        printf("Logo Não é possível passar deste ponto:\n\n");
        printf("\t-(%.2f) +- √%.2f\n\t___________________\n\t       %.0f\n\n", xNum, delta, (2 * xQua));
    }
    else
    {
        raiz = sqrt(delta);
        xOne = (-xNum + raiz) / (2 * xQua);
        xTwo = (-xNum - raiz) / (2 * xQua);

        printf("\t-(%.2f) +- √%.2f\n\t___________________\n\t       2×%.0f\n\n", xNum, delta, xQua);

        printf("\t-(%.2f) +- %.2f\n\t___________________\n\t       %.0f\n\n", xNum, raiz, (2 * xQua));

        printf("x¹: %f\n", xOne);
        printf("x²: %f\n", xTwo);
    }

    return (0);
}