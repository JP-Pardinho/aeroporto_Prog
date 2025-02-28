#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "variaveis.h"


typedef struct
{
    char codigo[10];
    char nome[10]; 
    char cidade[10];
    char estado[10];
} aeroporto;

typedef struct
{
    char codigo_rota[10];
    char nome[50];
    char horario[100];
    int poltronas;
    float distancia;
} rota;

typedef struct
{
    int codigo_passagem;
    char nome[50];
    char rg[20];
    char cpf[15];
    char data_nascimento[11];
    char telefone[15];
    char email[50];
    char contato_emergencia[50]; // Opcional
    char bagagem_extra[3]; // SIM ou NÃO
} passageiro;

typedef struct
{
    int matricula;
    char nome[50];
    char cargo[50];
} funcionario;

typedef struct
{
    int numero;
    char status[10];
} assento;

// Funções de Alocação

aeroporto* alocaVetAeroportos();
rota* alocaVetRotas();
passageiro* alocaVetPassageiros();
funcionario* alocaVetFuncionarios();
assento* alocaVetAssentos();

// Funções de Verificações
void normalizaString();
int verificaExistenciaAeroporto();
int verificaExistenciaFuncionario();
int verificaExistenciaCliente();
int verificaCodigoAeroporto();
int letras();
int verificaNomePassageiro();
int obterInteiro();

// Funções de Cadastro
// void menu_principal();
// void menu_configuracoes();
// void menu_vendas();
// void cadastrar_aeroporto();
// void cadastrar_rota();
// void cadastrar_passageiro();
// void cadastrar_funcionario();
// void selecionar_origem_destino();
// void selecionar_horario();
// void escolher_assento();
// void realizar_pagamento();


// Função Principal 

int main() 
{
    menu_principal();
    return 0;
}







