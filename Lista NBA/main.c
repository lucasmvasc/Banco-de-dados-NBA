#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "auxiliares.h"
#include "estatistica_nba.h"
#include "lista_nba.h"

int menu_principal()
{
    caracteres(72, '=');printf("\n");
    printc("Jogadores em destaque da NBA p\xa2s-temporada",72); printf("\n");
    caracteres(72, '='); printf("\n");
    printf("  1 - Mostrar estat%cscas da p%cs temporada\n", 161,162);
    printf("  2 - Inserir novo jogador\n");
    printf("  3 - Excluir um jogador\n");
    printf("  4 - Alterar informa\x87\xE4\x65s de um jogador\n");
    printf("  5 - Encontrar um jogador\n");
    printf("  6 - Legenda e informa\x87\xe4\x65s a respeito das estat\xa1sticas analisadas\n");
    printf("  7 - Manual de uso\n");
    printf("  ----------------------\n");
    printf("  0 - Sair do Aplicativo\n");
    printf("\n  Escolha uma op%c%co: ", 135, 198);
    fflush(stdin);
    return getchar();
}

int submenu()
{
    caracteres(72, '=');printf("\n");
    printc("Estat\xa1sticas da p\xa2s-temporada",72); printf("\n");
    caracteres(72, '='); printf("\n");
    printf("  1 - Ordenada pelo nome do jogador\n");
    printf("  2 - ordenada por GP\n");
    printf("  3 - Ordenada por PPG\n");
    printf("  4 - Ordenada por AC\n");
    printf("  ----------------------------\n");
    printf("  0 - Voltar ao menu principal\n");
    printf("\n  Escolha uma op%c%co: ", 135, 198);
    fflush(stdin);
    return getchar();
}
void inserir_jogador(TListaNBA *lis)
{
    TEstatNba nba;
    printf("  Nome do jogador: ");
    fflush(stdin);
    gets(nba.jogador);
    printf("\n");
    printf("  GP obtido nessa temporada: ");
    scanf("%d", &nba.gp);
    printf("\n");
    //le_inteiro(&nba.gp);
    printf("  PPG obtido nessa temporada: ");
    //le_inteiro(&nba.ppg);
    scanf("%f", &nba.ppg);
    printf("\n");
    printf("  AC obtido nessa temporada: ");
    //le_inteiro(&nba.ac);
    scanf("%d", &nba.ac);
    printf("\n");
    insere_lis_nba(lis, nba);
    printf("  << Jogador adicionado com sucesso >>\n\n");
}

void buscar_jogador(TListaNBA *lis)
{
    TEstatNba nba;
    printf("  Digite o nome do jogador: ");
    fflush(stdin);
    gets(nba.jogador);
    if(existe_lis_nba(*lis,nba)>0)
    {
        printf("  %c",218);caractabela(27);printf("%c",194);caractabela(6);printf("%c",194);caractabela(11);printf("%c",194);caractabela(8);printf("%c\n",191);
        printf("  %cNome                       %c  GP  %c    PPG    %c   AC   %c\n",179,179,179,179,179);
        printf("  %c",195);caractabela(27);printf("%c",197);caractabela(6);printf("%c",197);caractabela(11);printf("%c",197);caractabela(8);printf("%c\n",180);
    }
    busca_lis_nba(*lis,nba);

}
void alterar_jogador(TListaNBA *lis)
{
    int z;
    char resp[1];
    TEstatNba nba;
    printf("  Nome do jogador a ser alterado: ");
    fflush(stdin);
    gets(nba.jogador);
    printf("\n");
    while(1)
    {
        if (busca_lis_nba2(*lis,nba)>=0)
        {
            printf("  Valor da GP: ");
            fflush(stdin);
            scanf("%d",&nba.gp);
            printf("\n");
            printf("  Valor da PPG: ");
            fflush(stdin);
            scanf("%f",&nba.ppg);
            printf("\n");
            printf("  Valor da AC: ");
            fflush(stdin);
            scanf("%d",&nba.ac);
            printf("\n  Deseja alterar as informa%c%ces desse jogador? (s/n):",135,198);
            fflush(stdin);
            gets(resp);
                    switch(*resp)
                    {
                        case 'n':
                                printf("\n  << Altera\x87\xC6o cancelada >>\n\n");
                                break;
                        case 's':
                                z = busca_lis_nba2(*lis,nba);
                                altera_ele_lis_nba(lis,z,nba);
                                printf("\n  << Altera\x87\xC6o realizada >>\n\n");
                                break;
                        default:
                                printf("\n  *** Caractere inv%clido - Opera%c%co cancelada ***\n\n",160,135,198);
                    }
                    break;
        }
        else
        {
            printf("  *** Jogador n%co encontrado ***\n\n",198);
            break;
        }

    }

}
void excluir_jogador(TListaNBA *lis)
{
    int z;
    char resp[1];
    TEstatNba nba;
    while(1)
    {
        printf("  Nome do jogador: ");
        fflush(stdin);
        gets(nba.jogador);
        if(busca_lis_nba2(*lis,nba)>=0)
        {
            printf("\n  Deseja mesmo excluir esse jogador? (s/n):");
            fflush(stdin);
            gets(resp);
                    switch(*resp)
                    {
                        case 'n':
                                printf("\n  << Altera\x87\xC6o cancelada >>\n\n");
                                break;
                        case 's':
                                z = busca_lis_nba2(*lis,nba);
                                remove_lis_nba(lis,z);
                                printf("\n  << Altera\x87\xC6o realizada >>\n\n");
                                break;
                        default:
                            printf("\n  *** Caractere inv%clido - Opera%c%co cancelada ***\n\n",160,135,198);
                    }
                    break;
        }
        else
        {
            printf("\n  ***Jogador n%co encontrado ***\n\n",198);
            break;
        }

    }

}
int main()
{

    char vall[1];
    TListaNBA lis_nba;
    carrega_lis_nba(&lis_nba, "tabela_NBA.arq");

    char op, op2;
    while(1)
    {
        op = menu_principal();
        if (op == '0')
        {
            printf("\n  Deseja salvar o arquivo? (s/n)");printf("\n  Ou pressione qualquer outra tecla para cancelar: ");
            fflush(stdin);
            gets(vall);
            switch(*vall)
            {
                case 's':
                    salva_lis_nba(lis_nba, "tabela_NBA.arq");
                    printf("\n  %c%c Arquivo salvo com sucesso %c%c\n",174,174,175,175);
                    printf("\n  ** Fim do aplicativo **");
                    sleep(3);
                    exit(0);
                case 'n':
                    printf("\n  %c%c Arquivo n%co salvo %c%c\n",174,174,198,175,175);
                    printf("\n  ** Fim do aplicativo **");
                    sleep(3);
                    exit(0);
                default:
                    printf("\n  *** Opera%c%co cancelada ***\n",135,198);
            }

        }
        switch(op)
        {
            case '1':
                while(1)
                {
                    op2 = submenu();
                    if (op2 == '0')
                    {
                        break;
                    }
                    switch(op2)
                    {
                        case '1':
                            caracteres(72, '-'); printf("\n");
                            printc("Tabela ordenada pelo nome do jogador",72); printf("\n");
                            caracteres(72, '-'); printf("\n");
                            printf("  %c",218);caractabela(27);printf("%c",194);caractabela(6);printf("%c",194);caractabela(11);printf("%c",194);caractabela(8);printf("%c\n",191);
                            printf("  %cNome                       %c  GP  %c    PPG    %c   AC   %c\n",179,179,179,179,179);
                            printf("  %c",195);caractabela(27);printf("%c",197);caractabela(6);printf("%c",197);caractabela(11);printf("%c",197);caractabela(8);printf("%c\n",180);
                            qsort(lis_nba.elementos, lis_nba.num_ele, sizeof(TEstatNba), cmp_nome_jogador);
                            mostre_lis_nba(lis_nba);
                            printf("  %c",192);caractabela(27);printf("%c",193);caractabela(6);printf("%c",193);caractabela(11);printf("%c",193);caractabela(8);printf("%c\n",217);
                            break;
                        case '2':
                            caracteres(72, '-'); printf("\n");
                            printc("Tabela de estat\xa1sticas pelo GP",72); printf("\n");
                            caracteres(72, '-'); printf("\n");
                            printf("  %c",218);caractabela(27);printf("%c",194);caractabela(6);printf("%c",194);caractabela(11);printf("%c",194);caractabela(8);printf("%c\n",191);
                            printf("  %cNome                       %c  GP  %c    PPG    %c   AC   %c\n",179,179,179,179,179);
                            printf("  %c",195);caractabela(27);printf("%c",197);caractabela(6);printf("%c",197);caractabela(11);printf("%c",197);caractabela(8);printf("%c\n",180);
                            qsort(lis_nba.elementos, lis_nba.num_ele, sizeof(TEstatNba), cmp_gp);
                            mostre_lis_nba(lis_nba);
                            printf("  %c",192);caractabela(27);printf("%c",193);caractabela(6);printf("%c",193);caractabela(11);printf("%c",193);caractabela(8);printf("%c\n",217);
                            break;
                        case '3':
                            caracteres(72, '-'); printf("\n");
                            printc("Tabela de estat\xa1stica pelo PPG",72); printf("\n");
                            caracteres(72, '-'); printf("\n");
                            printf("  %c",218);caractabela(27);printf("%c",194);caractabela(6);printf("%c",194);caractabela(11);printf("%c",194);caractabela(8);printf("%c\n",191);
                            printf("  %cNome                       %c  GP  %c    PPG    %c   AC   %c\n",179,179,179,179,179);
                            printf("  %c",195);caractabela(27);printf("%c",197);caractabela(6);printf("%c",197);caractabela(11);printf("%c",197);caractabela(8);printf("%c\n",180);
                            qsort(lis_nba.elementos, lis_nba.num_ele, sizeof(TEstatNba), cmp_ppg);
                            mostre_lis_nba(lis_nba);
                            printf("  %c",192);caractabela(27);printf("%c",193);caractabela(6);printf("%c",193);caractabela(11);printf("%c",193);caractabela(8);printf("%c\n",217);
                            break;
                        case '4':
                            caracteres(72, '-'); printf("\n");
                            printc("Tabela de estat\xa1stica pelo AC",72); printf("\n");
                            caracteres(72, '-'); printf("\n");
                            printf("  %c",218);caractabela(27);printf("%c",194);caractabela(6);printf("%c",194);caractabela(11);printf("%c",194);caractabela(8);printf("%c\n",191);
                            printf("  %cNome                       %c  GP  %c    PPG    %c   AC   %c\n",179,179,179,179,179);
                            printf("  %c",195);caractabela(27);printf("%c",197);caractabela(6);printf("%c",197);caractabela(11);printf("%c",197);caractabela(8);printf("%c\n",180);
                            qsort(lis_nba.elementos, lis_nba.num_ele, sizeof(TEstatNba), cmp_ac);
                            mostre_lis_nba(lis_nba);
                            printf("  %c",192);caractabela(27);printf("%c",193);caractabela(6);printf("%c",193);caractabela(11);printf("%c",193);caractabela(8);printf("%c\n",217);
                            break;
                        default:
                            printf("\n\n  *** Op%c%co inv%clida ***\n\n",135,198,160);
                    }
                }
                break;
            case '2':
                caracteres(72, '-'); printf("\n");
                printc("Inserir novo jogador", 72); printf("\n");
                caracteres(72, '-'); printf("\n");
                inserir_jogador(&lis_nba);
                break;
            case '3':
                caracteres(72, '-'); printf("\n");
                printc("Excluir um jogador", 72); printf("\n");
                caracteres(72, '-'); printf("\n");
                excluir_jogador(&lis_nba);
                break;
            case '4':
                caracteres(72, '-'); printf("\n");
                printc("Alterar informa\x87\xE4\x65s de um jogador", 72); printf("\n");
                caracteres(72, '-'); printf("\n");
                alterar_jogador(&lis_nba);
                break;
            case '5':
                caracteres(72, '-'); printf("\n");
                printc("Encontrar um jogador", 72); printf("\n");
                caracteres(72, '-'); printf("\n");
                buscar_jogador(&lis_nba);
                break;
            case '6':
                caracteres(72, '='); printf("\n");
                printc("Legendas e informa\x87\xE4\x65s \xA3teis",72); printf("\n");
                caracteres(72, '='); printf("\n");
                printf("  A fun%c%co desse aplicativo %c apresentar os dados realativos a peformance\n",135,198,130);
                printf("  dos jogadores da NBA (liga americana de basquete). H%c diversas a%c%ces em\n",160,135,228);
                printf("  jogos que s%co levados em considera%c%co para a forma%c%co dessa tabela, como\n",198,135,198,135,198);
                printf("  a pontua%c%co de um jogador, m%cdia de pontos por jogo, tempo em quadra e\n",135,198,130);
                printf("  entre outras vari%cveis. Diante disso, a legenda referente aos dados\n",160);
                printf("  apontados pela tabela estar%co logo abaixo para esclarecimento do leitor.\n\n  %c",198,218);
                caractabela(62);printf("%c\n",191);
                printf("  %c GP (Games played) - N%cmero de jogos participados pelo jogador%c\n  %c",179,163,179,195);
                caractabela(62);printf("%c\n",180);
                printf("  %c PPG (Points per game) - Pontos por jogo em percentual        %c\n  %c",179,179,195);
                caractabela(62);printf("%c\n",180);
                printf("  %c AC - Aremessos convertidos                                   %c\n  %c",179,179,192);
                caractabela(62);printf("%c\n\n",217);
                printf("  *** Obrigado pela aten%c%co ! ***",135,198);
                printc("\n\n  Dev by: Lucas Vasconcelos\n",72);
                break;
            case '7':
                caracteres(72, '='); printf("\n");
                printc("Regras para o funcionamento correto do aplicativo",72); printf("\n");
                caracteres(72, '='); printf("\n");
                printf("  1 - %c necessess%crio digitar os valor referentes a GP, PPG e AC de forma\n",144,160);
                printf("  correta no momento de inserir um jogador ou alterar suas informa%c%ces,\n",135,228);
                printf("  seguindo o padr%co logo abaixo:\n\n",198);
                printf("   1.1 GP - Valores menores que 100 e maiores ou iguais a 0.\n");
                printf("   1.2 PPG - Valores menores que 100 e maiores que 0 antes do ponto.\n");
                printf("    1.2.1 - Valores acima de um d%cgito ap%cs o ponto ser%co arredondados.\n",161,162,198);
                printf("   1.3 AC - Valores menores que 1000 e maiores ou iguais a 0.\n\n");
                printf("  2 - %c estritamente proibido o uso de caracteres n%co num%cricos nos dados\n",144,198,130);
                printf("  citados anteriormente (em caso de erro, basta modificar as informa%c%ces\n",135,228);
                printf("  desse jogador no comando de altera%c%co).\n\n",135,198);
                break;
            default:
                printf("\n  *** Op%c%co inv%clida ***\n\n",135,198,160);
        }
    }
    return 0;
}
