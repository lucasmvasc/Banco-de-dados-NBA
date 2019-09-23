#include <ctype.h>

/* IMPRIME MÚLTIPLOS CARACTERES */
void caracteres(int nc, char c)
{
    int i;
    for(i=0; i<nc; i++)
        printf("%c", c);
}
void caractabela(int nc)
{
    int i;
    for(i=0; i<nc; i++)
        printf("%c",196);
}
/* IMPRIME A STRING S CENTRALIZADA EM TAM*/
void printc(char *s, int tam)
{
    int ne = (tam - strlen(s)) / 2;
    while(ne > 0)
    {
        printf(" ");
        ne--;
    }
    printf(s);
}

/* SUSPENDE A EXECUÇÃO DO APLICATIO POR delay SEGUNDOS */
void sleep(time_t delay)
{
    time_t timer0, timer1;
    time(&timer0);
    do
    {
        time(&timer1);
    } while((timer1 - timer0) < delay);
}

/* Verifica se a string snum pode ser convertida para um inteiro */
int e_inteiro(char *snum)
{
    int i = 0;
    if(snum[i] == '-')
        i++;
    while(snum[i] != '\0')
    {
        if(!isdigit(snum[i]))
            return 0;
        i++;
    }
    return 1;
}

int e_inteiropos(char *snum)
{
    int i = 0;
    if(snum[i] == '-')
        return 0;
    while(snum[i] != '\0')
    {
        if(!isdigit(snum[i]))
            return 0;
        i++;
    }
    return 1;
}

/* Verifica se a string snum pode ser convertida para um real */
int e_real(char *snum)
{
    int i = 0, np = 0;
    if(snum[i] == '-')
        i++;
    while(snum[i] != '\0')
    {
        if(!isdigit(snum[i])) {
            if(snum[i] != '.') {
                return 0;
            }
            else
            {
                np++;
                if(np > 1)
                    return 0;
            }
        }
        i++;
    }
    return 1;
}

/* Insere os divisores de milhar em um inteiro */
void div_milhar(unsigned long long num, char *snum)
{
    int i;
    int np; // número de pontos
    int ts; // tamanho da string
    int pu; // puxador
    sprintf(snum, "%I64u", num);
    ts = strlen(snum);
    np = (ts-1) / 3;
    snum[ts + np] = '\0';
    pu = ts + np - 1;
    while(np > 0) {
        for(i=0; i<3; i++)
        {
            snum[pu] = snum[pu-np];
            pu--;
        }
        snum[pu] = '.';
        if(np > 1)
            pu--;
        np--;
    }
}

int le_inteiro()
{
    char snum[31];
    fflush(stdin);
    gets(snum);
    while(!e_inteiro(snum))
    {
        printf("\n  Favor digitar um inteiro: ");
        fflush(stdin);
        gets(snum);
    }
    return atoi(snum);
}

int le_real()
{
    char snum[31];
    fflush(stdin);
    gets(snum);
    while(!e_real(snum))
    {
        printf("\n  Favor digitar um real: ");
        fflush(stdin);
        gets(snum);
    }
    return atof(snum);
}

