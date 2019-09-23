#define MAX 200

typedef int tipo;   // Tipo dos elementos da lista

struct lista_gen
{
    int num_ele;
    tipo elementos[MAX];
};
typedef struct lista_gen TListaGen;

/* Verifica se a lista está cheia */
int esta_cheia(TListaGen lis)
{
    return lis.num_ele == MAX;
}

/* Verifica se a lista vazia */
int esta_vazia(TListaGen lis)
{
    return lis.num_ele == 0;
}

/* Retorna o número de elementos na lista */
int num_de_elementos(TListaGen lis)
{
    return lis.num_ele;
}

/* Retorna a capacidade máxima da lista */
int capacidade(TListaGen lis)
{
    return MAX;
}

/* Mostra os elementos da lista */
void mostre_lis_gen(TListaGen lis)
{
    int i;
    printf("[");
    for(i=0; i<lis.num_ele-1; i++)
        printf("%d, ", lis.elementos[i]);
    if(lis.num_ele > 0)
        printf("%d]\n", lis.elementos[i]);
    else
        printf("]");
}

/* Insere elemento no final da lista */
void insere_lis_gen(TListaGen *lis, tipo val)
{
    lis->elementos[lis->num_ele] = val;
    lis->num_ele++;
}

/* Faz uma busca linear do valor (val) e
   retorna o índice desse valor na lista
   Retorna -1 se o valor não for encontrado */
int busca_lis_gen(TListaGen lis, tipo val)
{
    int i;
    for(i=0; i<lis.num_ele; i++)
        if(val == lis.elementos[i])
            return i;
    return -1;
}

/* Remove um elemento da lista, dado o seu
   índice e retorna seu valor */
tipo remove_lis_gen(TListaGen *lis, int ind)
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
void altera_ele_lis_gen(TListaGen *lis, tipo ind, tipo val)
{
    lis->elementos[ind] = val;
}

/* Função de comparaçãp
   Retorna < 0 se a < b
   Retorna = 0 se a = b
   Retorna > a se a > b*/
int cmp_gen(const void *a, const void *b)
{
    tipo *pa = (tipo *) a;
    tipo *pb = (tipo *) b;
    return *pa - *pb;
}

/* Ordena os elementos de lis e retorna a lista ordenada  */
TListaGen ordena_lis_gen(TListaGen lis)
{
    qsort(lis.elementos, lis.num_ele, sizeof(tipo), cmp_gen);
    return lis;
}

/* Salva a lista em um arquivo de nome dado */
void salva_lis_gen(TListaGen lis, char *nome)
{
    FILE *fp;
    fp = fopen(nome , "wb");
    fwrite(&lis.num_ele, sizeof(tipo), 1, fp);
    fwrite(lis.elementos, sizeof(tipo), lis.num_ele, fp);
    fclose(fp);
}

/* Carrega os dados do arquivo de nome fornecido para
   lista */
void carrega_lis_gen(TListaGen *lis, char *nome)
{
    FILE *fp;
    fp = fopen(nome, "rb");
    fread(&lis->num_ele, sizeof(tipo), 1, fp);
    fread(lis->elementos, sizeof(tipo), lis->num_ele, fp);
    fclose(fp);
}

