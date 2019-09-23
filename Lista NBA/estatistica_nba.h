struct ModeloApp
{
    char jogador[26];
    int gp;
    float ppg;
    int ac;
};
typedef struct ModeloApp TEstatNba;

void mostre_tabela_nba(TEstatNba nba)
{
    printf("  %c%-25s  %c  %2d  %c   %.1f%c   %c  %3d   %c\n",179,nba.jogador,179, nba.gp,179,
           nba.ppg,37,179,nba.ac,179);
}

int cmp_nome_jogador(const void *a, const void *b)
{
    TEstatNba *pa = (TEstatNba *) a;
    TEstatNba *pb = (TEstatNba *) b;
    return strcmp(pa->jogador, pb->jogador);
}

int cmp_gp(const void *a, const void *b)
{
    TEstatNba *pa = (TEstatNba *) a;
    TEstatNba *pb = (TEstatNba *) b;
    return pb->gp - pa->gp;
}

int cmp_ppg(const void *a, const void *b)
{
    TEstatNba *pa = (TEstatNba *) a;
    TEstatNba *pb = (TEstatNba *) b;
    int vpa = (int) (pa->ppg * 100);
    int vpb = (int) (pb->ppg * 100);
    return vpb - vpa;
}

int cmp_ac(const void *a, const void *b)
{
    TEstatNba *pa = (TEstatNba *) a;
    TEstatNba *pb = (TEstatNba *) b;
    return pb->ac - pa->ac;
}
