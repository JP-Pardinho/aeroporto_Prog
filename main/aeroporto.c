#include "variaveis.h"

// Função Principal 

int main() 
{
    // ALTERANDO PARA PONTEIRO PRECISAMOS ALTERAR TODAS AS FUNÇÕES
    Aeroporto *aeroportos = NULL;
    Rota *rotas = NULL;
    Passageiro *passageiros = NULL;
    Funcionario *funcionarios = NULL;
    Venda *vendas = NULL;

    int tam_aeroportos = 10;
    int tam_rotas = 10;
    int tam_passageiros = 10;
    int tam_funcionarios = 10;
    int tam_vendas = 10;


    // ALOCAÇÃO APARENTEMENTE ESTÁ FUNCIONANDO
    aeroportos = alocaVetAeroportos(tam_aeroportos);
    rotas = alocaVetRotas(tam_rotas);
    passageiros = alocaVetPassageiros(tam_passageiros);
    funcionarios = alocaVetFuncionarios(tam_funcionarios);
    vendas = alocaVetVenda(tam_vendas);
    

    // FUNÇÃO carregar_arquivo("aeroportos.dat") e carregar_arquivo("rotas.dat") não estão funcionando
    int total_aeroportos = carregar_arquivo("aeroportos.dat", (void **)&aeroportos, sizeof(Aeroporto), &tam_aeroportos);
    int total_rotas = carregar_arquivo("rotas.dat", (void **)&rotas, sizeof(Rota), &tam_rotas);
    int total_passageiros = carregar_arquivo("passageiros.dat", (void **)&passageiros, sizeof(Passageiro), &tam_passageiros);
    int total_funcionarios = carregar_arquivo("funcionarios.dat", (void **)&funcionarios, sizeof(Funcionario), &tam_funcionarios);
    int total_vendas = carregar_arquivo("vendas.dat", (void**)&vendas, sizeof(Venda), &tam_vendas);

    if(total_vendas == 0){
        total_vendas = 0;
    }

    int opcao;
    do
    {   
        printf("Aeroportos: %d\n", total_aeroportos);
        printf("rotas: %d\n", total_rotas);
        printf("passageiros: %d\n", total_passageiros);
        printf("funcionarios: %d\n", total_funcionarios);
        printf("vendas: %d\n", total_vendas);
        
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

    free(aeroportos);
    free(rotas);
    free(passageiros);
    free(funcionarios);
    free(vendas);

    return 0;
}






