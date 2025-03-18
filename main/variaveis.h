#ifndef VARIAVEIS_H
#define VARIAVEIS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define FILAS 10
#define COLUNAS 6

// Structs

typedef struct
{
    char codigo[4];
    char nome[50];
    char cidade[50];
    char estado[3];
}Aeroporto;

typedef struct
{
    int codigo;
    char nome[100];
    char origem[4];
    char destino[4];
    char horarios[10][6];
    int poltronas_total;
    int poltronas_disponiveis;
    float distancia;
    char dias_semana[7];
    char *assentos;
    char conexao[4];
} Rota;

typedef struct
{
    int codigo;
    char nome[100];
    char RG[20];
    char CPF[12];
    char data_nasc[11];
    char telefone[15];
    char email[50];
    char contato_emergencia[100];
    char bagagem_extra;
} Passageiro;

typedef struct
{
    int matricula;
    char nome[100];
    char cargo[50];
} Funcionario;

typedef struct
{
    int codigo_venda;
    char cpf_passageiro[12];
    int codigo_rota;
    char origem[4];  // Adicionado
    char destino[4]; // Adicionado
    char horario[6];
    char data_voo[11];
    char assento[4];
    float valor_total;
    char forma_pagamento[20];
} Venda;

// Protótipos de funções

// Funções de alocação (COLOCAR OS PARAMETROS )
Aeroporto* alocaVetAeroportos(int tam);
Rota* alocaVetRotas(int tam);
Passageiro* alocaVetPassageiros(int tam);
Funcionario* alocaVetFuncionarios(int tam);
Venda* alocaVetVenda(int tam);

// Protótipos de funções
void exibir_menu_principal();
void menu_configuracoes(Aeroporto *aeroportos, int *total_aeroportos, Rota *rotas, int *total_rotas, Passageiro *passageiros, int *total_passageiros, Funcionario *funcionarios, int *total_funcionarios);
void menu_vendas(Rota *rotas, int *total_rotas, Passageiro *passageiros, int *total_passageiros, Venda *vendas, int *total_vendas, Funcionario *funcionarios, int total_funcionarios);
void cadastrar_rota(Rota *rotas, int *total, Aeroporto *aeroportos, int total_aeroportos);
void salvar_arquivo(const char *nome_arquivo, void *dados, size_t tamanho_elemento, int total);
int carregar_arquivo(const char *nome_arquivo, void **dados, size_t tamanho_elemento, int *tamanho_maximo);
float calcular_preco(Rota rota, int dias_antecedencia, char tipo_dia, float percentual_ocupacao, int dias_retorno);
void gerar_eticket(Venda venda, Passageiro passageiro, Rota rota);
int cadastrar_passageiro(Passageiro *passageiros, int *total);
void pesquisar_alterar_passageiro(Passageiro *passageiros, int total);
void cadastrar_funcionario(Funcionario *funcionarios, int *total);
void pesquisar_alterar_funcionario(Funcionario *funcionarios, int total);
void realizar_venda(Rota *rotas, int *total_rotas, Passageiro *passageiros, int *total_passageiros, Venda *vendas, int *total_vendas, Funcionario *funcionarios, int total_funcionarios);
int escolher_assento(Rota *rota);
int dias_ate_viagem(int dia, int mes, int ano); 
int data_valida(int dia, int mes, int ano);
void limpa_tela();
#endif
