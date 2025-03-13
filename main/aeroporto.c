#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "variaveis.h"


// Função Principal 

int main() 
{
    Aeroporto aeroportos[50];
    Rota rotas[100];
    Passageiro passageiros[200];
    Funcionario funcionarios[20];
    Venda vendas[1000];

    int total_aeroportos = carregar_arquivo("voos.dat", aeroportos, sizeof(Aeroporto));
    int total_rotas = carregar_arquivo("voos.dat", rotas, sizeof(Rota));
    int total_passageiros = carregar_arquivo("passageiros.dat", passageiros, sizeof(Passageiro));
    int total_funcionarios = carregar_arquivo("funcionarios.dat", funcionarios, sizeof(Funcionario));
    int total_vendas = carregar_arquivo("vendas.dat", vendas, sizeof(Venda));

    int opcao;
    do
    {
        exibir_menu_principal();
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            menu_configuracoes(aeroportos, &total_aeroportos, rotas, &total_rotas, passageiros, &total_passageiros, funcionarios, &total_funcionarios);
            break;
        case 2:
            menu_vendas(rotas, total_rotas, passageiros, total_passageiros, vendas, &total_vendas);
            break;
        case 3:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida!\n");
        }
    } while (opcao != 3);

    return 0;
}






