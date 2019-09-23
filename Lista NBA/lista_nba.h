#define MAX 200

typedef TEstatNba tipo;   // Tipo dos elementos da lista

struct lista_nba
{
    int num_ele;
    tipo elementos[MAX];
};
typedef struct lista_nba TListaNBA;

/* Verifica se a lista está cheia */
int esta_cheia(TListaNBA lis)
{
    return lis.num_ele == MAX;
}

/* Verifica se a lista vazia */
int esta_vazia(TListaNBA lis)
{
    return lis.num_ele == 0;
}

/* Retorna o número de elementos na lista */
int num_de_elementos(TListaNBA lis)
{
    return lis.num_ele;
}

/* Retorna a capacidade máxima da lista */
int capacidade(TListaNBA lis)
{
    return MAX;
}

/* Mostra os elementos da lista */
void mostre_lis_nba(TListaNBA lis)
{
    int i;
    for(i=0; i<lis.num_ele; i++)
        mostre_tabela_nba(lis.elementos[i]);
}

/* Insere elemento no final da lista */
void insere_lis_nba(TListaNBA *lis, tipo val)
{
    lis->elementos[lis->num_ele] = val;
    lis->num_ele++;
}

/* Faz uma busca linear do valor (val) e
   retorna o índice desse valor na lista
   Retorna -1 se o valor não for encontrado */

void busca_lis_nba(TListaNBA lis, tipo val)
{

    int i,pos=0;

    for(i=0; i<lis.num_ele; i++)
        if(strncmp(val.jogador, lis.elementos[i].jogador,4) ==0)
        {
           //printf("  Nome                        GP       PPG      AC\n");
           mostre_tabela_nba(lis.elementos[i]);
            pos++;
        }
    if (pos==0)
    {
       printf("\n *** Jogador n%co encontrado *** \n\n",198);
    }
}
int existe_lis_nba(TListaNBA lis, tipo val)
{
    int i,num=0;
    for(i=0; i<lis.num_ele; i++)
        if(strncmp(val.jogador, lis.elementos[i].jogador,4) == 0)
            num++;
    return num;
}
int busca_lis_nba2(TListaNBA lis, tipo val)
{
    int i;
    for(i=0; i<lis.num_ele; i++)
        if(strcmp(val.jogador, lis.elementos[i].jogador) == 0)
        {
           return i;
        }
    return -1;
}
//void resultado busca_jogador(TListaNBA lis)
/* Remove um elemento da lista, dado o seu
   índice e retorna seu valor */
tipo remove_lis_nba(TListaNBA *lis, int ind)
{
    int i;
    tipo res = lis->elementos[ind];
    for(i=ind; i<lis->num_ele-1; i++)
        lis->elementos[i] = lis->elementos[i+1];
    lis->num_ele--;
    return res;
}

/* Altera o valor do elemento no índice (ind) para o novo
   valor (val) */
void altera_ele_lis_nba(TListaNBA *lis, int ind, tipo val)
{
    lis->elementos[ind] = val;
}


TListaNBA ordena_lis_nba(TListaNBA lis)
{

    return lis;
}

/* Salva a lista em um arquivo de nome dado */
void salva_lis_nba(TListaNBA lis, char *tabela_NBA)
{
    FILE *fp;
    fp = fopen("tabela_NBA.arq" , "wb");
    fwrite(&lis.num_ele, sizeof(tipo), 1, fp);
    fwrite(lis.elementos, sizeof(tipo), lis.num_ele, fp);
    fclose(fp);
}

/* Carrega os dados do arquivo de nome fornecido para
   lista */
void carrega_lis_nba(TListaNBA *lis, char *tabela_NBA)
{
    FILE *fp;
    fp = fopen("tabela_NBA.arq", "rb");
    fread(&lis->num_ele, sizeof(tipo), 1, fp);
    fread(lis->elementos, sizeof(tipo), lis->num_ele, fp);
    fclose(fp);
}


