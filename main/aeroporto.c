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
    
    int opcao;
    int tam_aeroportos = 30;
    int tam_rotas = 30;
    int tam_passageiros = 30;
    int tam_funcionarios = 30;
    int tam_vendas = 30;


    // ALOCAÇÃO APARENTEMENTE ESTÁ FUNCIONANDO
    
    aeroportos = alocaVetAeroportos(tam_aeroportos);
    rotas = alocaVetRotas(tam_rotas);
    passageiros = alocaVetPassageiros(tam_passageiros);
    funcionarios = alocaVetFuncionarios(tam_funcionarios);
    vendas = alocaVetVenda(tam_vendas);
    
    int total_aeroportos = carregar_arquivo("aeroportos.dat", (void **)&aeroportos, sizeof(Aeroporto), &tam_aeroportos);
    int total_rotas = carregar_arquivo("rotas.dat", (void **)&rotas, sizeof(Rota), &tam_rotas);
    int total_passageiros = carregar_arquivo("passageiros.dat", (void **)&passageiros, sizeof(Passageiro), &tam_passageiros);
    int total_funcionarios = carregar_arquivo("funcionarios.dat", (void **)&funcionarios, sizeof(Funcionario), &tam_funcionarios);
    int total_vendas = carregar_arquivo("vendas.dat", (void**)&vendas, sizeof(Venda), &tam_vendas);
    
    if(total_vendas == 0){
        total_vendas = 0;
    }

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
            menu_vendas(rotas, &total_rotas, passageiros, total_passageiros, vendas, &total_vendas, funcionarios, total_funcionarios);
            break;
        case 3:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida!\n");
        }
    } while (opcao != 3);

    free(aeroportos);
    free(passageiros);
    free(funcionarios);
    free(vendas);
    for (int i = 0; i < total_rotas; i++) {
        free(rotas[i].assentos); // Liberar o array de ponteiros
    }
    free(rotas);

    return 0;
}






