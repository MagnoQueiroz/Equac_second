#include "../includes/index.h"
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