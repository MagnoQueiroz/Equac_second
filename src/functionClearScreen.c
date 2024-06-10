#include "../includes/index.h"

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