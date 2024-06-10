#include "../includes/index.h"
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
        answer = tolower(answer);
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

void creditsCreator()
{
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