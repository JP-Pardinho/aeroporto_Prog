#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Definir essas informações na função Menu!!
#define MAX_AEROPORTOS 100
#define MAX_ROTAS 100
#define MAX_PASSAGEIROS 1000
#define MAX_ASSENTOS 100
// Definir essas informações na função Menu!!

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
    char contato_emergencia[50];
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

// Definir essas informações na função Menu!!
aeroporto aeroportos[MAX_AEROPORTOS];
rota rotas[MAX_ROTAS];
passageiro passageiros[MAX_PASSAGEIROS];
funcionario funcionarios[MAX_PASSAGEIROS];
assento assentos[MAX_ASSENTOS];
int num_aeroportos = 0;
int num_rotas = 0;
int num_passageiros = 0;
int num_funcionarios = 0;
// Definir essas informações na função Menu!!

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
void menu_principal();
void menu_configuracoes();
void menu_vendas();
void cadastrar_aeroporto();
void cadastrar_rota();
void cadastrar_passageiro();
void cadastrar_funcionario();
void selecionar_origem_destino();
void selecionar_horario();
void escolher_assento();
void realizar_pagamento();


// Função Principal 

int main() 
{
    menu_principal();
    return 0;
}

// Implementação das funções de Alocação Dinâmica
aeroporto* alocaVetAeroportos(int tam)
{

}

rota* alocaVetRotas(int tam)
{

}

passageiro* alocaVetPassageiros(int tam)
{

}

funcionario* alocaVetFuncionarios(int tam)
{

}

assento* alocaVetAssentos(int tam)
{

}

// Implementação das funções de Verificação 

void normalizaString(char *str)
{
    /*Função responsável por transformar as letras que o usuário 
    passa nas entradas em maiusculas. Ele não retorna nada. */
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int verificaExistenciaAeroporto(aeroporto*P, int tam, char* nome)
{
    /*
        A função verifica se o aeroporto digitado pelo usuário existe, a fim de não registrar outro com o
        mesmo nome. Ela retorna 1 caso o partido exista, caso contrário, retorna 0
    */
    int i;
    char nomeNormal[50];
    strcpy(nomeNormal, nome);
    normalizaString(nomeNormal);

    for(i=0; i<tam; i++){
        normalizaString(P[i].nome_Aeroporto);
        if(strcmp(P[i].nome_Aeroporto, nomeNormal) == 0){
            return 1; //Aeroporto encontrato
        } 
    }
    return 0; // Aeroporto não encontrato
}

int verificaExistenciaFuncionario(funcionario*P, int tam, char* nome)
{
    /*
        A função verifica se o funcionario digitado pelo usuário existe, a fim de não registrar outro com o
        mesmo nome. Ela retorna 1 caso o partido exista, caso contrário, retorna 0
    */
    int i;
    char nomeNormal[50];
    strcpy(nomeNormal, nome);
    normalizaString(nomeNormal);

    for(i=0; i<tam; i++){
        normalizaString(P[i].nome_Funcionario);
        if(strcmp(P[i].nome_Funcionario, nomeNormal) == 0){
            return 1; //funcionario encontrato
        } 
    }
    return 0; // funcionario não encontrato
}

int verificaExistenciaCliente(cliente*P, int tam, char* nome)
{
    /*
        A função verifica se o cliente digitado pelo usuário existe, a fim de não registrar outro com o
        mesmo nome. Ela retorna 1 caso o partido exista, caso contrário, retorna 0
    */
    int i;
    char nomeNormal[50];
    strcpy(nomeNormal, nome);
    normalizaString(nomeNormal);

    for(i=0; i<tam; i++){
        normalizaString(P[i].nome_Cliente);
        if(strcmp(P[i].nome_Cliente, nomeNormal) == 0){
            return 1; //cliente encontrato
        } 
    }
    return 0; // cliente não encontrato
}

int verificaCodigoAeroporto(aeroporto*P, int tam, char* nome)
{
    /*A função verifica se a sigla do aeroporto digitado pelo usuário existe, a fim de não registrar outro com o
        mesmo nome. Ela retorna 1 caso o partido exista, caso contrário, retorna 0*/
        int i;
        char nomeNormal[10];
        strcpy(nomeNormal, nome);
        normalizaString(nomeNormal);
    
        for(i=0; i<tam; i++){
            normalizaString(P[i].codigo_Aeroporto);
            if(strcmp(P[i].codigo_Aeroporto, nomeNormal) == 0){
                return 1; //codigo encontrada
            }
        }
        return 0; //codigo não encontrada
}

int letras(char *soLetra)
{
    /*A função é utilizada para verificar a entrada do usuário é apenas letra.
    É utilizado em todas as funções de cadastro, para que não haja número no nome e na sigla.
    A função retorna zero, se não tem apenas letra, caso contrário retorna 1*/
    int i;
    for (i = 0; soLetra[i] != '\0'; i++) {
        if (!(isalpha((unsigned char)soLetra[i]) || (soLetra[i] & 0x80) || soLetra[i] == ' ')) {
            // isalpha verifica letras padrão; (soLetra[i] & 0x80) verifica se é um caractere com acento
            return 0; // erro
        }
    }
    return 1; // só letra
}

int verificaNomePassageiro(passageiro*C, int tam, char* nomeC)
{
    /*A função verifica se o nome do passageiro digitado pelo usuário existe, 
    a fim de não registrar outro com o mesmo. Ela retorna 1 caso o nome 
    do candidato exista, caso contrário, retorna 0*/
    int i;
    char nomeNormal[50];
    strcpy(nomeNormal, nomeC);
    normalizaString(nomeNormal);

    for(i=0; i<tam; i++){
        normalizaString(C[i].nome_Passageiro);
        if(strcmp(C[i].nome_Passageiro, nomeNormal) == 0){
            return 1; //Passageiro encontrado
        }
    }
    return 0; //Passageiro não encontrado
}

int obterInteiro()
{
    /*Verifica se o que o usuário passou na entra é número. Retorna o valor que o usuário passou, caso contrário retorna mensagem de erro.*/
    int valor;
    char ch;

    while (1) {

        if (scanf("%d", &valor) == 1) {
            // Verificar se sobrou algo no buffer de entrada
            ch = getchar();
            if (ch == '\n') {
                return valor;  // Entrada válida, retorna o número
            } else {
                // Se sobrou algo no buffer, é uma entrada inválida
                
                printf("Por favor, digite apenas números inteiros.\n");
                printf("-> ");
                while (getchar() != '\n');  // Limpar o buffer
            }
        } else {
            // Limpar o buffer se scanf falhar
            printf("Entrada inválida.\n");
            printf("Por favor, digite apenas números inteiros.\n");
            while (getchar() != '\n');  // Limpar o buffer
        }
    }
}


// Implementação das funções de cadastro e impressão
void menu_principal() {
    int opcao;
    // Alocação Aeroportos
    aeroporto* AEROPORTOS = NULL;
    int tamAeroportos = 10;
    
    // Alocação Rotas
    rota* ROTAS = NULL;
    int tamRotas = 10;

    // Alocação Passageiros
    passageiro* PASSAGEIROS = NULL;
    int tamPassageiros = 10;

    // Alocação Funcionarios
    funcionario* FUNCIONARIOS = NULL;
    int tamFuncionarios = 10;

    // Alocação Assentos
    assento* ASSENTOS = NULL;
    int tamAssuntos = 10;

    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("[1] Configurações\n");
        printf("[2] Vendas\n");
        printf("[3] Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                menu_configuracoes();
                break;
            case 2:
                menu_vendas();
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 3);
}

void menu_configuracoes() {
    int opcao;
    do {
        printf("\n=== CONFIGURAÇÕES ===\n");
        printf("[4] Cadastrar aeroportos\n");
        printf("[5] Cadastrar voos/trechos\n");
        printf("[6] Cadastrar passageiros fidelizados\n");
        printf("[7] Pesquisar/alterar dados de passageiros fidelizados\n");
        printf("[8] Cadastrar funcionários\n");
        printf("[9] Pesquisar/Alterar funcionários\n");
        printf("[10] Voltar\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 4:
                cadastrar_aeroporto();
                break;
            case 5:
                cadastrar_rota();
                break;
            case 6:
                cadastrar_passageiro();
                break;
            case 7:
                // Implementar pesquisa/alterar passageiros
                break;
            case 8:
                cadastrar_funcionario();
                break;
            case 9:
                // Implementar pesquisa/alterar funcionários
                break;
            case 10:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 10);
}

void menu_vendas() {
    int opcao;
    do {
        printf("\n=== VENDAS ===\n");
        printf("[11] Selecionar origem e destino\n");
        printf("[12] Voltar\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 11:
                selecionar_origem_destino();
                break;
            case 12:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 12);
}

void cadastrar_aeroporto() {
    if (num_aeroportos >= MAX_AEROPORTOS) {
        printf("Limite de aeroportos atingido!\n");
        return;
    }

    printf("\n=== CADASTRAR AEROPORTO ===\n");
    printf("Código: ");
    scanf("%s", aeroportos[num_aeroportos].codigo);
    printf("Nome: ");
    scanf("%s", aeroportos[num_aeroportos].nome);
    printf("Cidade: ");
    scanf("%s", aeroportos[num_aeroportos].cidade);
    printf("Estado: ");
    scanf("%s", aeroportos[num_aeroportos].estado);

    num_aeroportos++;
    printf("Aeroporto cadastrado com sucesso!\n");
}

void cadastrar_rota() {

    if (num_rotas >= MAX_ROTAS) {
        printf("Limite de rotas atingido!\n");
        return;
    }

    printf("\n=== CADASTRAR ROTA ===\n");
    printf("Código: ");
    scanf("%s", rotas[num_rotas].codigo);
    printf("Nome: ");
    scanf("%s", rotas[num_rotas].nome);
    printf("Horários: ");
    scanf("%s", rotas[num_rotas].horarios);
    printf("Número de poltronas: ");
    scanf("%d", &rotas[num_rotas].poltronas);
    printf("Distância (em milhas): ");
    scanf("%f", &rotas[num_rotas].distancia);

    num_rotas++;
    printf("Rota cadastrada com sucesso!\n");
}

void cadastrar_passageiro() {
    if (num_passageiros >= MAX_PASSAGEIROS) {
        printf("Limite de passageiros atingido!\n");
        return;
    }

    printf("\n=== CADASTRAR PASSAGEIRO ===\n");
    printf("Código: ");
    scanf("%d", &passageiros[num_passageiros].codigo);
    printf("Nome: ");
    scanf("%s", passageiros[num_passageiros].nome);
    printf("RG: ");
    scanf("%s", passageiros[num_passageiros].rg);
    printf("CPF: ");
    scanf("%s", passageiros[num_passageiros].cpf);
    printf("Data de Nascimento (dd/mm/aaaa): ");
    scanf("%s", passageiros[num_passageiros].data_nascimento);
    printf("Telefone: ");
    scanf("%s", passageiros[num_passageiros].telefone);
    printf("Email: ");
    scanf("%s", passageiros[num_passageiros].email);
    printf("Contato de Emergência: ");
    scanf("%s", passageiros[num_passageiros].contato_emergencia);
    printf("Bagagem Extra (SIM/NÃO): ");
    scanf("%s", passageiros[num_passageiros].bagagem_extra);

    num_passageiros++;
    printf("Passageiro cadastrado com sucesso!\n");
}

void cadastrar_funcionario() {
    if (num_funcionarios >= MAX_PASSAGEIROS) {
        printf("Limite de funcionários atingido!\n");
        return;
    }

    printf("\n=== CADASTRAR FUNCIONÁRIO ===\n");
    printf("Matrícula: ");
    scanf("%d", &funcionarios[num_funcionarios].matricula);
    printf("Nome: ");
    scanf("%s", funcionarios[num_funcionarios].nome);
    printf("Cargo: ");
    scanf("%s", funcionarios[num_funcionarios].cargo);

    num_funcionarios++;
    printf("Funcionário cadastrado com sucesso!\n");
}

void selecionar_origem_destino() {
    printf("\n=== SELECIONAR ORIGEM E DESTINO ===\n");
    // Implementar lógica para selecionar origem e destino
}

void selecionar_horario() {
    printf("\n=== SELECIONAR HORÁRIO ===\n");
    // Implementar lógica para selecionar horário
}

void escolher_assento() {
    printf("\n=== ESCOLHER ASSENTO ===\n");
    // Implementar lógica para escolher assento
}

void realizar_pagamento() {
    printf("\n=== REALIZAR PAGAMENTO ===\n");
    // Implementar lógica para realizar pagamento
}


void gerar_e_ticket() {
    printf("\n=== GERAR E-TICKET ===\n");
    // Implementar lógica para gerar e-ticket
}



