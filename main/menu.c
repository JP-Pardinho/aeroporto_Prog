#include "variaveis.h"

// Completando o arquivo passagens.c com as funções necessárias

// Implementação das funções de Alocação Dinâmica
Aeroporto* alocaVetAeroportos(int tam)
{
    /*Função que realiza a alocação de memória para o ponteiro dos aeroportos.
    Será exibida uma mensagem de erro, caso a alocação seja mal sucedida e retorna 
    o ponteiro *vetAeroportos*/
    Aeroporto *vetAeroportos = (Aeroporto*)malloc(tam* sizeof(Aeroporto));
    if (vetAeroportos == NULL){
        printf("Erro: alocação mal sucedida!");
        exit(1);
    }
    return vetAeroportos;
}

Rota* alocaVetRotas(int tam)
{
    Rota *vetRotas = (Rota*)malloc(tam* sizeof(Rota));
    if (vetRotas == NULL){
        printf("Erro: alocação mal sucedida!");
        exit(1);
    }
    return vetRotas;
}

Passageiro* alocaVetPassageiros(int tam)
{
    Passageiro *vetPassageiros = (Passageiro*)malloc(tam* sizeof(Passageiro));
    if (vetPassageiros == NULL){
        printf("Erro: alocação mal sucedida!");
        exit(1);
    }
    return vetPassageiros;
}

Funcionario* alocaVetFuncionarios(int tam)
{
    Funcionario *vetFuncionarios = (Funcionario*)malloc(tam* sizeof(Funcionario));
    if (vetFuncionarios == NULL){
        printf("Erro: alocação mal sucedida!");
        exit(1);
    }
    return vetFuncionarios;
}

Venda* alocaVetVenda(int tam){
    Venda *vetVendas = (Venda*)malloc(tam* sizeof(Venda));
    if (vetVendas == NULL){
        printf("Erro: alocação mal sucedida!");
        exit(1);
    }
    return vetVendas;
}

// Funções de Menu

void exibir_menu_principal()
{
    system("cls");
    printf("=== SISTEMA DE VENDAS DE PASSAGENS AEREAS ===\n\n");
    printf("[1] Configuracoes\n");
    printf("[2] Vendas\n");
    printf("[3] Sair\n");
    printf("\nEscolha uma opcao: ");
}

void menu_configuracoes(Aeroporto *aeroportos, int *total_aeroportos, Rota *rotas, int *total_rotas, Passageiro *passageiros, int *total_passageiros, Funcionario *funcionarios, int *total_funcionarios) {
    int opcao;
    do {
        system("cls");
        printf("=== MENU DE CONFIGURACOES ===\n\n");
        printf("[4] Cadastrar aeroportos\n");
        printf("[5] Cadastrar voos/trechos\n");
        printf("[6] Cadastrar passageiros fidelizados\n");
        printf("[7] Pesquisar/alterar passageiros\n");
        printf("[8] Cadastrar funcionarios\n");
        printf("[9] Pesquisar/alterar funcionarios\n");
        printf("[10] Voltar\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 4:
                cadastrar_aeroporto(aeroportos, total_aeroportos);
                break;
            case 5:
                cadastrar_rota(rotas, total_rotas);
                break;
            case 6:
                cadastrar_passageiro(passageiros, total_passageiros);
                break;
            case 7:
                pesquisar_alterar_passageiro(passageiros, *total_passageiros);
                break;
            case 8:
                cadastrar_funcionario(funcionarios, total_funcionarios);
                break;
            case 9:
                pesquisar_alterar_funcionario(funcionarios, *total_funcionarios);
                break;
            case 10:
                break;
            default:
                printf("Opcao invalida!\n");
                system("pause");
        }
    } while (opcao != 10);
}

void menu_vendas(Rota *rotas, int total_rotas, Passageiro *passageiros, int total_passageiros, Venda *vendas, int *total_vendas)
{
    int opcao;

    do
    {
        system("cls");
        printf("=== MENU DE VENDAS ===\n\n");
        printf("[11] Selecionar origem e destino [Etapa 1 de 5]\n");
        printf("[12] Voltar\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 11:
            realizar_venda(rotas, total_rotas, passageiros, total_passageiros, vendas, total_vendas);
            break;
        case 12:
            break;
        default:
            printf("Opcao invalida!\n");
            system("pause");
        }
    } while (opcao != 12);
}

void cadastrar_aeroporto(Aeroporto *aeroportos, int *total)
{
    system("cls");
    printf("=== CADASTRO DE AEROPORTO ===\n\n");

    printf("Codigo (3 letras): ");
    scanf("%s", aeroportos[*total].codigo);

    // Validação do código do aeroporto
    if (strlen(aeroportos[*total].codigo) != 3)
    {
        printf("Erro: Codigo deve ter exatamente 3 letras!\n");
        system("pause");
        return;
    }

    // Converter para maiúsculas
    for (int i = 0; i < 3; i++)
    {
        aeroportos[*total].codigo[i] = toupper(aeroportos[*total].codigo[i]);
    }

    printf("Nome: ");
    scanf(" %[^\n]", aeroportos[*total].nome);
    printf("Cidade: ");
    scanf(" %[^\n]", aeroportos[*total].cidade);
    printf("Estado (2 letras): ");
    scanf("%s", aeroportos[*total].estado);

    // Validação do estado
    if (strlen(aeroportos[*total].estado) != 2)
    {
        printf("Erro: Estado deve ter exatamente 2 letras!\n");
        system("pause");
        return;
    }

    // Converter para maiúsculas
    aeroportos[*total].estado[0] = toupper(aeroportos[*total].estado[0]);
    aeroportos[*total].estado[1] = toupper(aeroportos[*total].estado[1]);

    (*total)++;
    salvar_arquivo("aeroportos.dat", aeroportos, sizeof(Aeroporto), *total);

    printf("\nAeroporto cadastrado com sucesso!\n");
    system("pause");
}

void cadastrar_rota(Rota *rotas, int *total)
{
    system("cls");
    printf("=== CADASTRO DE ROTA ===\n\n");

    printf("Codigo da rota: ");
    scanf("%d", &rotas[*total].codigo);
    printf("Nome da rota: ");
    scanf(" %[^\n]", rotas[*total].nome);
    printf("Codigo de origem: ");
    scanf("%s", rotas[*total].origem);
    printf("Codigo de destino: ");
    scanf("%s", rotas[*total].destino);
    printf("Distancia em milhas: ");
    scanf("%f", &rotas[*total].distancia);

    // Inicializar poltronas totais e disponíveis
    printf("Numero total de poltronas: ");
    scanf("%d", &rotas[*total].poltronas_total);
    rotas[*total].poltronas_disponiveis = rotas[*total].poltronas_total;

    // Cadastrar horários
    int num_horarios;
    printf("Quantidade de horarios para esta rota: ");
    scanf("%d", &num_horarios);

    for (int i = 0; i < num_horarios && i < 10; i++)
    {
        printf("Horario %d (formato HH:MM): ", i + 1);
        scanf("%s", rotas[*total].horarios[i]);
    }

    // Cadastrar dias da semana
    printf("Dias da semana (1=DOM, 2=SEG, 3=TER, 4=QUA, 5=QUI, 6=SEX, 7=SAB, 0=TODOS): ");
    scanf("%s", rotas[*total].dias_semana);

    (*total)++;
    salvar_arquivo("rotas.dat", rotas, sizeof(Rota), *total);

    printf("\nRota cadastrada com sucesso!\n");
    system("pause");
}   

void cadastrar_passageiro(Passageiro *passageiros, int *total) {
    system("cls");
    printf("=== CADASTRO DE PASSAGEIRO FIDELIZADO ===\n\n");

    passageiros[*total].codigo = *total + 1; // Código sequencial

    printf("Nome: ");
    scanf(" %[^\n]", passageiros[*total].nome);

    printf("RG: ");
    scanf("%s", passageiros[*total].RG);

    printf("CPF (apenas numeros): ");
    scanf("%s", passageiros[*total].CPF);

    // Validação básica de CPF
    if (strlen(passageiros[*total].CPF) != 11) {
        printf("Erro: CPF deve ter 11 digitos!\n");
        system("pause");
        return;
    }

    printf("Data de nascimento (DD/MM/AAAA): ");
    scanf("%s", passageiros[*total].data_nasc);

    // Validação básica da data de nascimento
    if (strlen(passageiros[*total].data_nasc) != 10 || passageiros[*total].data_nasc[2] != '/' || passageiros[*total].data_nasc[5] != '/') {
        printf("Erro: Data de nascimento deve estar no formato DD/MM/AAAA!\n");
        system("pause");
        return;
    }

    printf("Telefone: ");
    scanf("%s", passageiros[*total].telefone);

    printf("Email: ");
    scanf("%s", passageiros[*total].email);

    printf("Contato de emergencia: ");
    scanf(" %[^\n]", passageiros[*total].contato_emergencia);

    printf("Bagagem extra (S/N): ");
    char bagagem;
    scanf(" %c", &bagagem);
    passageiros[*total].bagagem_extra = (bagagem == 'S' || bagagem == 's') ? 'S' : 'N';

    (*total)++;
    salvar_arquivo("passageiros.dat", passageiros, sizeof(Passageiro), *total);

    printf("\nPassageiro fidelizado cadastrado com sucesso!\n");
    system("pause");
}

void pesquisar_alterar_passageiro(Passageiro *passageiros, int total)
{
    char cpf_busca[12];
    int encontrado = -1;

    system("cls");
    printf("=== PESQUISAR/ALTERAR PASSAGEIRO ===\n\n");

    printf("Digite o CPF do passageiro: ");
    scanf("%s", cpf_busca);

    for (int i = 0; i < total; i++)
    {
        if (strcmp(passageiros[i].CPF, cpf_busca) == 0)
        {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1)
    {
        printf("\nPassageiro nao encontrado!\n");
        system("pause");
        return;
    }

    // Exibir os dados atuais
    printf("\nDados do passageiro:\n");
    printf("Codigo: %d\n", passageiros[encontrado].codigo);
    printf("Nome: %s\n", passageiros[encontrado].nome);
    printf("RG: %s\n", passageiros[encontrado].RG);
    printf("CPF: %s\n", passageiros[encontrado].CPF);
    printf("Data de nascimento: %s\n", passageiros[encontrado].data_nasc);
    printf("Telefone: %s\n", passageiros[encontrado].telefone);
    printf("Email: %s\n", passageiros[encontrado].email);
    printf("Contato de emergencia: %s\n", passageiros[encontrado].contato_emergencia);
    printf("Bagagem extra: %c\n", passageiros[encontrado].bagagem_extra);

    printf("\nDeseja alterar os dados? (S/N): ");
    char opcao;
    scanf(" %c", &opcao);

    if (opcao == 'S' || opcao == 's')
    {
        printf("\nNovos dados (pressione Enter para manter o valor atual):\n");

        printf("Nome [%s]: ", passageiros[encontrado].nome);
        char buffer[100];
        scanf(" %[^\n]", buffer);
        if (strlen(buffer) > 0)
            strcpy(passageiros[encontrado].nome, buffer);

        printf("RG [%s]: ", passageiros[encontrado].RG);
        scanf(" %[^\n]", buffer);
        if (strlen(buffer) > 0)
            strcpy(passageiros[encontrado].RG, buffer);

        printf("Telefone [%s]: ", passageiros[encontrado].telefone);
        scanf(" %[^\n]", buffer);
        if (strlen(buffer) > 0)
            strcpy(passageiros[encontrado].telefone, buffer);

        printf("Email [%s]: ", passageiros[encontrado].email);
        scanf(" %[^\n]", buffer);
        if (strlen(buffer) > 0)
            strcpy(passageiros[encontrado].email, buffer);

        printf("Contato de emergencia [%s]: ", passageiros[encontrado].contato_emergencia);
        scanf(" %[^\n]", buffer);
        if (strlen(buffer) > 0)
            strcpy(passageiros[encontrado].contato_emergencia, buffer);

        printf("Bagagem extra (S/N) [%c]: ", passageiros[encontrado].bagagem_extra);
        char bagagem;
        scanf(" %c", &bagagem);
        if (bagagem == 'S' || bagagem == 's' || bagagem == 'N' || bagagem == 'n')
        {
            passageiros[encontrado].bagagem_extra = (bagagem == 'S' || bagagem == 's') ? 'S' : 'N';
        }

        salvar_arquivo("passageiros.dat", passageiros, sizeof(Passageiro), total);
        printf("\nDados atualizados com sucesso!\n");
    }

    system("pause");
}

void cadastrar_funcionario(Funcionario *funcionarios, int *total)
{
    system("cls");
    printf("=== CADASTRO DE FUNCIONARIO ===\n\n");

    printf("Matricula: ");
    scanf("%d", &funcionarios[*total].matricula);

    printf("Nome: ");
    scanf(" %[^\n]", funcionarios[*total].nome);

    printf("Cargo: ");
    scanf(" %[^\n]", funcionarios[*total].cargo);

    (*total)++;
    salvar_arquivo("funcionarios.dat", funcionarios, sizeof(Funcionario), *total);

    printf("\nFuncionario cadastrado com sucesso!\n");
    system("pause");
}

void pesquisar_alterar_funcionario(Funcionario *funcionarios, int total)
{
    int matricula_busca;
    int encontrado = -1;

    system("cls");
    printf("=== PESQUISAR/ALTERAR FUNCIONARIO ===\n\n");

    printf("Digite a matricula do funcionario: ");
    scanf("%d", &matricula_busca);

    for (int i = 0; i < total; i++)
    {
        if (funcionarios[i].matricula == matricula_busca)
        {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1)
    {
        printf("\nFuncionario nao encontrado!\n");
        system("pause");
        return;
    }

    // Exibir os dados atuais
    printf("\nDados do funcionario:\n");
    printf("Matricula: %d\n", funcionarios[encontrado].matricula);
    printf("Nome: %s\n", funcionarios[encontrado].nome);
    printf("Cargo: %s\n", funcionarios[encontrado].cargo);

    printf("\nDeseja alterar os dados? (S/N): ");
    char opcao;
    scanf(" %c", &opcao);

    if (opcao == 'S' || opcao == 's')
    {
        printf("\nNovos dados (pressione Enter para manter o valor atual):\n");

        printf("Nome [%s]: ", funcionarios[encontrado].nome);
        char buffer[100];
        scanf(" %[^\n]", buffer);
        if (strlen(buffer) > 0)
            strcpy(funcionarios[encontrado].nome, buffer);

        printf("Cargo [%s]: ", funcionarios[encontrado].cargo);
        scanf(" %[^\n]", buffer);
        if (strlen(buffer) > 0)
            strcpy(funcionarios[encontrado].cargo, buffer);

        salvar_arquivo("funcionarios.dat", funcionarios, sizeof(Funcionario), total);
        printf("\nDados atualizados com sucesso!\n");
    }

    system("pause");
}

void salvar_arquivo(const char *nome_arquivo, void *dados, size_t tamanho_elemento, int total) {
    FILE *arquivo = fopen(nome_arquivo, "wb");
    if (arquivo) {
        fwrite(dados, tamanho_elemento, total, arquivo);
        fclose(arquivo);
    } else {
        printf("Erro ao abrir arquivo para gravacao: %s\n", nome_arquivo);
    }
}

int carregar_arquivo(const char *nome_arquivo, void **dados, size_t tamanho_elemento, int *tamanho_maximo)
{
    FILE *arquivo = fopen(nome_arquivo, "rb");
    int total = 0;
    if (arquivo) {
        while (fread((char *)(*dados) + total * tamanho_elemento, tamanho_elemento, 1, arquivo)) {
            total++;
            if (total >= *tamanho_maximo) {
                *tamanho_maximo *= 2;
                dados = realloc(*dados, *tamanho_maximo * tamanho_elemento);
                if (!*dados) {
                    printf("Erro: Falha ao realocar memória!\n");
                    fclose(arquivo);
                    return -1;
                }
            }
        }
        fclose(arquivo);
    } else {
        printf("Erro: Arquivo %s não encontrado ou não pode ser aberto.\n", nome_arquivo);
        return -1;
    }
    return total;
}

float calcular_preco(Rota rota, int dias_antecedencia, char tipo_dia, float percentual_ocupacao, int dias_retorno)
{
    // Preço por milha
    float preco_milha;
    if (rota.distancia <= 500.0)
    {
        preco_milha = 0.36;
    }
    else if (rota.distancia <= 800.0)
    {
        preco_milha = 0.29;
    }
    else
    {
        preco_milha = 0.21;
    }

    // Fator de período (antecedência)
    float fator_periodo;
    if (dias_antecedencia <= 3)
    {
        fator_periodo = 4.52;
    }
    else if (dias_antecedencia <= 6)
    {
        fator_periodo = 3.21;
    }
    else if (dias_antecedencia <= 10)
    {
        fator_periodo = 2.25;
    }
    else if (dias_antecedencia <= 15)
    {
        fator_periodo = 1.98;
    }
    else if (dias_antecedencia <= 20)
    {
        fator_periodo = 1.78;
    }
    else if (dias_antecedencia <= 30)
    {
        fator_periodo = 1.65;
    }
    else
    {
        fator_periodo = 1.45;
    }

    // Fator de dia útil, feriado ou final de semana
    float fator_dia;
    switch (tipo_dia)
    {
    case 'F': // Feriado
        fator_dia = 3.56;
        break;
    case 'S': // Final de semana
        fator_dia = 1.21;
        break;
    default: // Dia útil
        fator_dia = 1.00;
        break;
    }

    // Fator de retorno
    float fator_retorno;
    if (dias_retorno <= 2)
    {
        fator_retorno = 1.09;
    }
    else if (dias_retorno <= 5)
    {
        fator_retorno = 1.05;
    }
    else if (dias_retorno <= 8)
    {
        fator_retorno = 1.02;
    }
    else
    {
        fator_retorno = 1.00;
    }

    // Fator de procura (ocupação)
    float fator_procura;
    if (percentual_ocupacao < 10.0)
    {
        fator_procura = 0.75;
    }
    else if (percentual_ocupacao < 30.0)
    {
        fator_procura = 0.85;
    }
    else if (percentual_ocupacao < 40.0)
    {
        fator_procura = 0.95;
    }
    else if (percentual_ocupacao < 60.0)
    {
        fator_procura = 1.00;
    }
    else if (percentual_ocupacao < 80.0)
    {
        fator_procura = 1.15;
    }
    else if (percentual_ocupacao < 90.0)
    {
        fator_procura = 1.20;
    }
    else
    {
        fator_procura = 1.35;
    }

    // Cálculo final do preço
    return rota.distancia * preco_milha * fator_periodo * fator_dia * fator_retorno * fator_procura;
}

void gerar_eticket(Venda venda, Passageiro passageiro, Rota rota)
{
    (void)rota;
    // Gerar número único para o e-ticket
    srand(time(NULL));
    int numero_eticket = rand() % 900000 + 100000; // Número de 6 dígitos

    char nome_arquivo[50];
    sprintf(nome_arquivo, "etickets/eticket_%d.txt", numero_eticket);

// Criar diretório se não existir
#ifdef _WIN32
    system("mkdir etickets 2> nul");
#else
    system("mkdir -p etickets");
#endif

    FILE *arquivo = fopen(nome_arquivo, "w");
    if (!arquivo)
    {
        printf("Erro ao criar arquivo de e-ticket!\n");
        return;
    }

    // Dados do e-ticket
    fprintf(arquivo, "===================================================\n");
    fprintf(arquivo, "                     E-TICKET                      \n");
    fprintf(arquivo, "===================================================\n\n");
    fprintf(arquivo, "Número do E-ticket: %d\n", numero_eticket);
    fprintf(arquivo, "Código da venda: %d\n\n", venda.codigo_venda);

    fprintf(arquivo, "PASSAGEIRO\n");
    fprintf(arquivo, "Nome: %s\n", passageiro.nome);
    fprintf(arquivo, "CPF: %s\n", passageiro.CPF);
    fprintf(arquivo, "Bagagem extra: %s\n\n", passageiro.bagagem_extra == 'S' ? "Sim" : "Não");

    fprintf(arquivo, "VOO\n");
    fprintf(arquivo, "Origem: %s\n", venda.origem);
    fprintf(arquivo, "Destino: %s\n", venda.destino);
    fprintf(arquivo, "Horário: %s\n", venda.horario);
    fprintf(arquivo, "Assento: %s\n\n", venda.assento);

    fprintf(arquivo, "Valor total: R$ %.2f\n", venda.valor_total);
    fprintf(arquivo, "Forma de pagamento: %s\n\n", venda.forma_pagamento);

    fprintf(arquivo, "===================================================\n");
    fprintf(arquivo, "    Apresente este e-ticket no portão de embarque  \n");
    fprintf(arquivo, "===================================================\n");

    fclose(arquivo);

    // Também adicionar ao arquivo consolidado de e-tickets
    arquivo = fopen("etickets.txt", "a");
    if (arquivo)
    {
        fprintf(arquivo, "E-TICKET %d\n", numero_eticket);
        fprintf(arquivo, "Passageiro: %s\n", passageiro.nome);
        fprintf(arquivo, "CPF: %s\n", passageiro.CPF);
        fprintf(arquivo, "Voo: %s para %s\n", venda.origem, venda.destino);
        fprintf(arquivo, "Horário: %s\n", venda.horario);
        fprintf(arquivo, "Assento: %s\n", venda.assento);
        fprintf(arquivo, "Valor: R$ %.2f\n", venda.valor_total);
        fprintf(arquivo, "---------------------------------------------------\n\n");
        fclose(arquivo);
    }

    printf("\nE-ticket gerado com sucesso! Número: %d\n", numero_eticket);
    printf("Arquivo salvo em: %s\n", nome_arquivo);
}

void realizar_venda(Rota *rotas, int total_rotas, Passageiro *passageiros, int total_passageiros, Venda *vendas, int *total_vendas) {

    Venda nova_venda;
    int rota_selecionada = -1;
    Passageiro passageiro_atual;
    char passageiro_fidelizado;

    // ETAPA 1: Selecionar origem e destino
    system("cls");
    printf("=== VENDA DE PASSAGEM - ETAPA 1/5: ORIGEM E DESTINO ===\n\n");

    printf("Rotas disponíveis:\n");
    printf("-----------------------------------------------------\n");
    printf("COD | NOME DA ROTA                | ORIGEM | DESTINO\n");
    printf("-----------------------------------------------------\n");

    for (int i = 0; i < total_rotas; i++) {
        printf("%3d | %-25s | %-6s | %-6s\n",
               rotas[i].codigo,
               rotas[i].nome,
               rotas[i].origem,
               rotas[i].destino);
    }

    printf("-----------------------------------------------------\n\n");

    printf("Digite o código da rota desejada: ");
    int codigo_rota;
    scanf("%d", &codigo_rota);

    // Buscar rota pelo código
    for (int i = 0; i < total_rotas; i++) {
        if (rotas[i].codigo == codigo_rota) {
            rota_selecionada = i;
            break;
        }
    }

    if (rota_selecionada == -1) {
        printf("\nRota não encontrada!\n");
        system("pause");
        return;
    }

    // Armazenar informações na venda
    nova_venda.codigo_rota = rotas[rota_selecionada].codigo;
    strcpy(nova_venda.origem, rotas[rota_selecionada].origem);
    strcpy(nova_venda.destino, rotas[rota_selecionada].destino);

    printf("\nRota selecionada: %s (%s -> %s)\n",
           rotas[rota_selecionada].nome,
           rotas[rota_selecionada].origem,
           rotas[rota_selecionada].destino);

    // ETAPA 2: Selecionar horário
    printf("\nHorários disponíveis:\n");
    for (int i = 0; i < 10 && rotas[rota_selecionada].horarios[i][0] != '\0'; i++) {
        printf("[%d] %s\n", i + 1, rotas[rota_selecionada].horarios[i]);
    }
    printf("Escolha o horário: ");
    int horario_escolhido;
    scanf("%d", &horario_escolhido);
    strcpy(nova_venda.horario, rotas[rota_selecionada].horarios[horario_escolhido - 1]);

    // ETAPA 3: Selecionar assento
    // Implementar lógica para seleção de assentos

    // ETAPA 4: Informações do passageiro
    printf("\nO passageiro é fidelizado? (S/N): ");
    scanf(" %c", &passageiro_fidelizado);
    if (passageiro_fidelizado == 'S' || passageiro_fidelizado == 's') {
        printf("Digite o CPF do passageiro: ");
        char cpf[12];
        scanf("%s", cpf);
        int encontrado = -1;
        for (int i = 0; i < total_passageiros; i++) {
            if (strcmp(passageiros[i].CPF, cpf) == 0) {
                encontrado = i;
                break;
            }
        }
        if (encontrado == -1) {
            printf("Passageiro não encontrado!\n");
            system("pause");
            return;
        }
        passageiro_atual = passageiros[encontrado];
    } else {
        // Cadastrar novo passageiro
        cadastrar_passageiro(passageiros, &total_passageiros);
        passageiro_atual = passageiros[total_passageiros - 1];
    }

    // ETAPA 5: Confirmação e pagamento
    // Implementar lógica para confirmação e pagamento

    // Salvar venda
    vendas[*total_vendas] = nova_venda;
    (*total_vendas)++;
    salvar_arquivo("vendas.dat", vendas, sizeof(Venda), *total_vendas);

    printf("\nVenda realizada com sucesso!\n");
    system("pause");


    printf("Aperte enter para concluir esse etapa!...\n");
    getchar();
    gerar_eticket(nova_venda, passageiro_atual, rotas[rota_selecionada]);
    getchar();
}