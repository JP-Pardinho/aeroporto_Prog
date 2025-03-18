#include "variaveis.h"

// FUNcaO DE LIMPAR A TELA 

void limpa_tela() {
    #ifdef _WIN32
        limpa_tela("cls");  
        #else
        system("clear");  
    #endif
}


// FUNCOES DE ARQUIVO

int carregar_arquivo(const char *nome_arquivo, void **dados, size_t tamanho_elemento, int *tamanho_maximo) {
    FILE *arquivo = fopen(nome_arquivo, "rb");
    if (arquivo == NULL) {
        printf("Erro: Arquivo %s nao encontrado ou corrompido!\n", nome_arquivo);
        return 0;
    }

    int total = 0;
    while (fread((char *)(*dados) + total * tamanho_elemento, tamanho_elemento, 1, arquivo)) {
        total++;
        if (total >= *tamanho_maximo) {
            *tamanho_maximo *= 2;
            void *temp = realloc(*dados, *tamanho_maximo * tamanho_elemento);
            if (!temp) {
                printf("Erro: Falha ao realocar memoria!\n");
                fclose(arquivo);
                return -1;
            }
            *dados = temp;
        }
    }
    fclose(arquivo);
    return total;
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

// FUNcoES DE ALOCAcaO 

Aeroporto* alocaVetAeroportos(int tam)
{
    Aeroporto *vetAeroportos = (Aeroporto*)malloc(tam* sizeof(Aeroporto));
    if (vetAeroportos == NULL){
        printf("Erro: alocacao mal sucedida!");
        exit(1);
    }
    return vetAeroportos;
}

Rota* alocaVetRotas(int tam)
{
    Rota *vetRotas = (Rota*)malloc(tam* sizeof(Rota));
    if (vetRotas == NULL){
        printf("Erro: alocacao mal sucedida!");
        exit(1);
    }
    return vetRotas;
}

Passageiro* alocaVetPassageiros(int tam)
{
    Passageiro *vetPassageiros = (Passageiro*)malloc(tam* sizeof(Passageiro));
    if (vetPassageiros == NULL){
        printf("Erro: alocacao mal sucedida!");
        exit(1);
    }
    return vetPassageiros;
}

Funcionario* alocaVetFuncionarios(int tam)
{
    Funcionario *vetFuncionarios = (Funcionario*)malloc(tam* sizeof(Funcionario));
    if (vetFuncionarios == NULL){
        printf("Erro: alocacao mal sucedida!");
        exit(1);
    }
    return vetFuncionarios;
}

Venda* alocaVetVenda(int tam){
    Venda *vetVendas = (Venda*)malloc(tam* sizeof(Venda));
    if (vetVendas == NULL){
        printf("Erro: alocacao mal sucedida!");
        exit(1);
    }
    return vetVendas;
}

// Funções de Verificão
int rota_existe(Rota *rotas, int total_rotas, const char *nome) {
    for (int i = 0; i < total_rotas; i++) {
        if (strcasecmp(rotas[i].nome, nome) == 0) { // Comparação insensível a maiúsculas/minúsculas
            return 1; // Rota já existe
        }
    }
    return 0; // Rota não existe
}

int aeroporto_existe(Aeroporto *aeroportos, int total_aeroportos, const char *nome) {
    for (int i = 0; i < total_aeroportos; i++) {
        if (strcasecmp(aeroportos[i].nome, nome) == 0) { // Comparação insensível a maiúsculas/minúsculas
            return 1; // Aeroporto já existe
        }
    }
    return 0; // Aeroporto não existe
}

int passageiro_existe(Passageiro *passageiros, int total_passageiros, const char *nome) {
    for (int i = 0; i < total_passageiros; i++) {
        if (strcasecmp(passageiros[i].nome, nome) == 0) { // Comparação insensível a maiúsculas/minúsculas
            return 1; // Passageiro já existe
        }
    }
    return 0; // Passageiro não existe
}

int funcionario_existe(Funcionario *funcionarios, int total_funcionarios, const char *nome) {
    for (int i = 0; i < total_funcionarios; i++) {
        if (strcasecmp(funcionarios[i].nome, nome) == 0) { // Comparação insensível a maiúsculas/minúsculas
            return 1; // Funcionário já existe
        }
    }
    return 0; // Funcionário não existe
}

int contem_apenas_numeros(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0; // Contém caracteres não numéricos
        }
    }
    return 1; // Apenas números
}

int contem_apenas_letras(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isalpha(str[i]) && str[i] != ' ') { // Permite espaços
            return 0; // Contém caracteres não alfabéticos
        }
    }
    return 1; // Apenas letras
}

// FUNcoES DE CADASTRO / ALTERAcaO
void cadastrar_aeroporto(Aeroporto *aeroportos, int *total) {
    limpa_tela();
    printf("=== CADASTRO DE AEROPORTO ===\n\n");

    // Validar código do aeroporto
    char codigo[4];
    printf("Codigo (3 letras): ");
    scanf("%s", codigo);
    
    if (strlen(codigo) != 3 || !contem_apenas_letras(codigo)) {
        printf("Erro: Codigo deve ter exatamente 3 letras!\n");
        getchar();
        printf("\nAperte enter para continuar...\n");
        getchar();
        return;
    }

    // Converter para maiúsculas
    for (int i = 0; i < 3; i++) {
        codigo[i] = toupper(codigo[i]);
    }

    // Verificar se o código já existe
    for (int i = 0; i < *total; i++) {
        if (strcmp(aeroportos[i].codigo, codigo) == 0) {
            printf("Erro: Codigo do aeroporto ja existe!\n");
            getchar();
            printf("\nAperte enter para continuar...\n");
            getchar();
            return;
        }
    }

    strcpy(aeroportos[*total].codigo, codigo);

    // Validar nome do aeroporto
    char nome[50];
    printf("Nome: ");
    scanf(" %[^\n]", nome);

    if (aeroporto_existe(aeroportos, *total, nome)) {
        printf("Erro: Aeroporto com o mesmo nome já existe!\n");
        getchar();
        printf("\nAperte enter para continuar...\n");
        getchar();
        return;
    }

    strcpy(aeroportos[*total].nome, nome);

    printf("Cidade: ");
    scanf(" %[^\n]", aeroportos[*total].cidade);

    // Validar estado (2 letras)
    char estado[3];
    printf("Estado (2 letras): ");
    scanf("%s", estado);
    if (strlen(estado) != 2 || !contem_apenas_letras(estado)) {
        printf("Erro: Estado deve ter exatamente 2 letras!\n");
        getchar();
        printf("\nAperte enter para continuar...\n");
        getchar();
        return;
    }

    // Converter para maiúsculas
    estado[0] = toupper(estado[0]);
    estado[1] = toupper(estado[1]);

    strcpy(aeroportos[*total].estado, estado);

    getchar();
    printf("\nAeroporto cadastrado com sucesso!\n");
    printf("\nAperte enter para concluir esse cadastro!...\n");
    getchar();

    (*total)++;
    salvar_arquivo("aeroportos.dat", aeroportos, sizeof(Aeroporto), *total);
}


void cadastrar_rota(Rota *rotas, int *total, Aeroporto *aeroportos, int total_aeroportos) {
    limpa_tela();
    printf("=== CADASTRO DE ROTA ===\n\n");

    // Verificar se há aeroportos cadastrados
    if (total_aeroportos == 0) {
        printf("Erro: Nenhum aeroporto cadastrado. Cadastre aeroportos antes de criar rotas.\n");
        getchar();
        printf("\nAperte enter para continuar...\n");
        getchar();
        return;
    }
  
    // Validar código da rota (deve ser único)
    int codigo;
    printf("Codigo da rota: ");
    scanf("%d", &codigo);
    for (int i = 0; i < *total; i++) {
        if (rotas[i].codigo == codigo) {
            printf("Erro: Codigo da rota já existe!\n");
            getchar();
            printf("\nAperte enter para continuar...\n");
            getchar();
            return;
        }
    }
    rotas[*total].codigo = codigo;


    // Validar códigos de origem e destino (3 caracteres)
    char origem[4], destino[4];
    // Validar nome da rota (deve ser único)
    char nome[100];
    printf("Nome da rota: ");
    scanf(" %[^\n]", nome);
    if (rota_existe(rotas, *total, nome)) {
        printf("Erro: Uma rota com o nome '%s' já existe!\n", nome);
        getchar();
        printf("\nAperte enter para continuar...\n");
        getchar();
        return;
    }
    strcpy(rotas[*total].nome, nome);

    printf("Codigo de origem (3 letras): ");
    scanf("%s", origem);
    if (strlen(origem) != 3 || !contem_apenas_letras(origem)) {
        printf("Erro: Codigo de origem deve ter exatamente 3 letras!\n");
        getchar();
        printf("\nAperte enter para continuar...\n");
        getchar();
        return;
    }
    // Converter para maiúsculas
    for (int i = 0; i < 3; i++) {
        origem[i] = toupper(origem[i]);
    }
    // Verificar se o aeroporto de origem existe
    int origem_encontrada = 0;
    for (int i = 0; i < total_aeroportos; i++) {
        if (strcmp(aeroportos[i].codigo, origem) == 0) {
            origem_encontrada = 1;
            break;
        }
    }
    if (!origem_encontrada) {
        printf("Erro: Aeroporto de origem '%s' nao encontrado!\n", origem);
        getchar();
        printf("\nAperte enter para continuar...\n");
        getchar();
        return;
    }
    strcpy(rotas[*total].origem, origem);

    // Validar código de destino (deve ser um aeroporto existente)
    printf("Codigo de destino (3 letras): ");
    scanf("%s", destino);
    if (strlen(destino) != 3 || !contem_apenas_letras(destino)) {
        printf("Erro: Codigo de destino deve ter exatamente 3 letras!\n");
        getchar();
        printf("\nAperte enter para continuar...\n");
        getchar();
        return;
    }
    // Converter para maiúsculas
    for (int i = 0; i < 3; i++) {
        destino[i] = toupper(destino[i]);
    }
    // Verificar se o aeroporto de destino existe
    int destino_encontrado = 0;
    for (int i = 0; i < total_aeroportos; i++) {
        if (strcmp(aeroportos[i].codigo, destino) == 0) {
            destino_encontrado = 1;
            break;
        }
    }
    if (!destino_encontrado) {
        printf("Erro: Aeroporto de destino '%s' nao encontrado!\n", destino);
        getchar();
        printf("\nAperte enter para continuar...\n");
        getchar();
        return;
    }
    strcpy(rotas[*total].destino, destino);


    // Validar distância em milhas
    printf("Distancia em milhas: ");
    scanf("%f", &rotas[*total].distancia);
    if (rotas[*total].distancia <= 0) {
        printf("Erro: A distancia deve ser um valor positivo!\n");
        getchar();
        printf("\nAperte enter para continuar...\n");
        getchar();
        return;
    }

    // Validar número total de poltronas
    printf("Numero total de poltronas: ");
    scanf("%d", &rotas[*total].poltronas_total);
    if (rotas[*total].poltronas_total <= 0) {
        printf("Erro: O numero de poltronas deve ser positivo!\n");
        getchar();
        printf("\nAperte enter para continuar...\n");
        getchar();
        return;
    }
    rotas[*total].poltronas_disponiveis = rotas[*total].poltronas_total;


    // Alocar vetor de assentos dinamicamente
    rotas[*total].assentos = (char *)malloc(rotas[*total].poltronas_total * sizeof(char));
    if (rotas[*total].assentos == NULL) {
        printf("Erro: Falha ao alocar memoria para assentos!\n");
        getchar();
        printf("\nAperte enter para continuar...\n");
        getchar();
        return;
    }

    // Inicializar todos os assentos como livres ('L')
    for (int i = 0; i < rotas[*total].poltronas_total; i++) {
        rotas[*total].assentos[i] = 'L';
    }

    // Cadastrar horários
    int num_horarios;
    printf("Quantidade de horarios para esta rota (maximo 10): ");
    scanf("%d", &num_horarios);
    if (num_horarios < 1 || num_horarios > 10) {
        printf("Erro: O numero de horarios deve estar entre 1 e 10!\n");
        getchar();
        printf("\nAperte enter para continuar...\n");
        getchar();
        return;
    }
    for (int i = 0; i < num_horarios; i++) {
        char horario[6];
        printf("Horario %d (formato HH:MM): ", i + 1);
        scanf("%s", horario);
        if (strlen(horario) != 5 || horario[2] != ':') {
            printf("Erro: Formato de horario invalido! Use HH:MM.\n");
            getchar();
            printf("\nAperte enter para continuar...\n");
            getchar();
            return;
        }
        strcpy(rotas[*total].horarios[i], horario);
    }

    // Cadastrar dias da semana
    printf("Dias da semana (1=DOM, 2=SEG, 3=TER, 4=QUA, 5=QUI, 6=SEX, 7=SAB, 0=TODOS): ");
    scanf("%s", rotas[*total].dias_semana);

    // Verificar se a rota tem conexão
    printf("A rota tem conexao? (S/N): ");
    char tem_conexao;
    scanf(" %c", &tem_conexao);
    if (tem_conexao == 'S' || tem_conexao == 's') {
        printf("Codigo do aeroporto de conexao (3 letras): ");
        scanf("%s", rotas[*total].conexao);
        if (strlen(rotas[*total].conexao) != 3 || !contem_apenas_letras(rotas[*total].conexao)) {
            printf("Erro: Codigo de conexao deve ter 3 letras!\n");
            getchar();
            printf("\nAperte enter para continuar...\n");
            getchar();
            return;
        }
        // Verificar se o aeroporto de conexão existe
        int conexao_encontrada = 0;
        for (int i = 0; i < total_aeroportos; i++) {
            if (strcmp(aeroportos[i].codigo, rotas[*total].conexao) == 0) {
                conexao_encontrada = 1;
                break;
            }
        }
        if (!conexao_encontrada) {
            printf("Erro: Aeroporto de conexao '%s' nao encontrado!\n", rotas[*total].conexao);
            getchar();
            printf("\nAperte enter para continuar...\n");
            getchar();
            return;
        }
    } else {
        strcpy(rotas[*total].conexao, ""); // Sem conexão
    }


    // Salvar a rota no arquivo

    (*total)++;
    salvar_arquivo("rotas.dat", rotas, sizeof(Rota), *total);

    printf("\nRota cadastrada com sucesso!\n");

    getchar();
    printf("\nAperte enter para concluir esse cadastro!...\n");
    getchar();
}

int cadastrar_passageiro(Passageiro *passageiros, int *total) {
    limpa_tela();
    printf("=== CADASTRO DE PASSAGEIRO FIDELIZADO ===\n\n");
    
    passageiros[*total].codigo = *total + 1; // Código sequencial

    // Validar nome do passageiro
    char nome[100];
    char CPF[12];
    printf("Nome: ");
    scanf(" %[^\n]", nome);

    // Verificar se o nome já existe (comparação insensível a maiúsculas/minúsculas)
    for (int i = 0; i < *total; i++) {
        if (strcasecmp(passageiros[i].nome, nome) == 0) {
            printf("Erro: Passageiro com o mesmo nome já existe!\n");
            getchar();
            printf("\nAperte enter para continuar...\n");
            getchar();
            return 0; // Retorna 0 indicando que o cadastro falhou
        }
    }

    // Se o nome não existe, prosseguir com o cadastro
    strcpy(passageiros[*total].nome, nome);
    
    printf("RG: ");
    scanf("%s", passageiros[*total].RG);
    
    printf("CPF (apenas numeros): ");
    scanf("%s", CPF);
    for(int i = 0; i < *total; i++){
        if(strcasecmp(passageiros[i].CPF, CPF) == 0){
            printf("Erro: Passageiro com esse CPF ja existe!\n");
            getchar();
            printf("\nAperter enter para continuar...\n");
            getchar();
            return 0;
        }
    }
    strcpy(passageiros[*total].CPF, CPF);
    
    // Validação básica de CPF
    if (strlen(passageiros[*total].CPF) != 11) {
        printf("Erro: CPF deve ter 11 digitos!\n");
        getchar();
        printf("\nAperte enter para continuar...\n");
        getchar();
        return 0; // Retorna 0 indicando que o cadastro falhou
    }
    
    printf("Data de nascimento (DD MM AAAA): ");
    scanf("%s", passageiros[*total].data_nasc);
    
    // Validação básica da data de nascimento
    if (strlen(passageiros[*total].data_nasc) != 10 || passageiros[*total].data_nasc[2] != '/' || passageiros[*total].data_nasc[5] != '/') {
        printf("Erro: Data de nascimento deve estar no formato DD/MM/AAAA!\n");
        getchar();
        printf("\nAperte enter para continuar...\n");
        getchar();
        return 0; // Retorna 0 indicando que o cadastro falhou
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
    getchar();
    printf("\nAperte enter para concluir esse cadastro!...\n");
    getchar();
    return 1; // Retorna 1 indicando que o cadastro foi bem-sucedido
}

void pesquisar_alterar_passageiro(Passageiro *passageiros, int total)
{
    char cpf_busca[12];
    int encontrado = -1;
    
    limpa_tela();
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
        getchar();
        printf("\nAperte enter para continuar...\n");
        getchar();
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
    
    getchar();
    printf("\nAperte enter para concluir esse cadastro!...\n");
    getchar();
    
}

void cadastrar_funcionario(Funcionario *funcionarios, int *total)
{
    limpa_tela();
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
    
    getchar();
    printf("\nAperte enter para concluir esse cadastro!...\n");
    getchar();
}

void pesquisar_alterar_funcionario(Funcionario *funcionarios, int total)
{
    int matricula_busca;
    int encontrado = -1;
    
    limpa_tela();
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
        getchar();
        printf("\nAperte enter para continuar...\n");
        getchar();
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
    
    getchar();
    printf("\nAperte enter para concluir esse cadastro!...\n");
    getchar();
}

float calcular_preco(Rota rota, int dias_antecedencia, char tipo_dia, float percentual_ocupacao, int dias_retorno)
{
    // Preco por milha
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
    
    // Fator de periodo (antecedencia)
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
    
    // Fator de dia util, feriado ou final de semana
    float fator_dia;
    switch (tipo_dia)
    {
        case 'F': // Feriado
        fator_dia = 3.56;
        break;
        case 'S': // Final de semana
        fator_dia = 1.21;
        break;
        default: // Dia util
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
    
    // Fator de procura (ocupacao)
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
    
    // Calculo final do preco
    return rota.distancia * preco_milha * fator_periodo * fator_dia * fator_retorno * fator_procura;
}


int dias_ate_viagem(int dia, int mes, int ano) {
    time_t t = time(NULL);
    struct tm hoje = *localtime(&t);
    
    struct tm viagem = {0};
    viagem.tm_mday = dia;
    viagem.tm_mon = mes - 1;
    viagem.tm_year = ano - 1900;
    
    time_t t_hoje = mktime(&hoje);
    time_t t_viagem = mktime(&viagem);
    
    int diferenca = (t_viagem - t_hoje) / (60 * 60 * 24);
    
    return diferenca > 0 ? diferenca : 0;
}

int data_valida(int dia, int mes, int ano) {
    if (mes < 1 || mes > 12) {
        return 0;
    }

    int dias_no_mes;
    switch (mes) {
        case 2: 
            if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
                dias_no_mes = 29;
            } else {
                dias_no_mes = 28;
            }
            break;
        case 4: case 6: case 9: case 11: 
            dias_no_mes = 30;
            break;
        default: 
            dias_no_mes = 31;
            break;
    }

    if (dia < 1 || dia > dias_no_mes) {
        return 0;
    }

    if (ano < 2025) {
        return 0;
    }

    return 1;
}

int realizar_pagamento(Venda *venda, Rota *rota, Funcionario *funcionarios, int total_funcionarios) {
    // Variáveis para cálculo do preço
    int dias_antecedencia;
    char tipo_dia;
    char data[11];
    float percentual_ocupacao;
    int dias_retorno;

    // Solicitar informações para cálculo do preço
    printf("\n=== ETAPA 4: REALIZAR PAGAMENTO ===\n\n");

    // Solicitar data da viagem
    int dia, mes, ano;
    
    while (1) {
        printf("Digite a data da viagem (DD/MM/AAAA): ");
        scanf("%10s", data); 

        if (sscanf(data, "%d/%d/%d", &dia, &mes, &ano) == 3) {
            if (data_valida(dia, mes, ano)) {
                break;;
            } else {
                printf("Data inválida! Tente novamente.\n");
                return 0;
            }
        } else {
            printf("Formato inválido! Use o formato DD/MM/AAAA.\n");
        }
    }
    
    // Calcular dias de antecedência
    dias_antecedencia = dias_ate_viagem(dia, mes, ano);

    // Solicitar tipo de dia (Feriado, Final de Semana, Dia Útil)
    printf("Tipo de dia (F = Feriado, S = Final de Semana, U = Dia Útil): ");
    scanf(" %c", &tipo_dia);

    // Calcular percentual de ocupação
    percentual_ocupacao = ((float)(rota->poltronas_total - rota->poltronas_disponiveis) / rota->poltronas_total) * 100;

    // Solicitar dias de retorno (se houver)
    printf("Quantos dias até o retorno (0 se for só ida)? ");
    scanf("%d", &dias_retorno);

    // Calcular o preço da passagem
    float valor_passagem = calcular_preco(*rota, dias_antecedencia, tipo_dia, percentual_ocupacao, dias_retorno);
    printf("\nValor da passagem: R$ %.2f\n", valor_passagem);

    // Solicitar forma de pagamento
    printf("\nEscolha a forma de pagamento:\n");
    printf("[1] Cartão de Crédito\n");
    printf("[2] Cartão de Débito\n");
    printf("[3] Dinheiro\n");
    int forma_pagamento;
    scanf("%d", &forma_pagamento);

    // Validar forma de pagamento
    if (forma_pagamento < 1 || forma_pagamento > 3) {
        printf("Forma de pagamento inválida!\n");
        getchar();
        printf("\nAperte enter para continuar...\n");
        getchar();
        return 0;
    }

    // Se for pagamento em dinheiro, validar matrícula do funcionário
    if (forma_pagamento == 3) {
        int matricula_funcionario;
        printf("Digite a matrícula do funcionário: ");
        scanf("%d", &matricula_funcionario);

        // Validar matrícula do funcionário
        int funcionario_valido = 0;
        for (int i = 0; i < total_funcionarios; i++) {
            if (funcionarios[i].matricula == matricula_funcionario) {
                funcionario_valido = 1;
                return 0;
            }
        }

        if (!funcionario_valido) {
            printf("Matrícula do funcionário inválida!\n");
            getchar();
            printf("\nAperte enter para continuar...\n");
            getchar();
            return 0;
        }
    }

    // Atualizar os dados da venda
    venda->valor_total = valor_passagem;
    if (forma_pagamento == 1) {
        strcpy(venda->forma_pagamento, "Cartão de Crédito");
    } else if (forma_pagamento == 2) {
        strcpy(venda->forma_pagamento, "Cartão de Débito");
    } else {
        strcpy(venda->forma_pagamento, "Dinheiro");
    }

    printf("\nPagamento realizado com sucesso!\n");
    printf("Forma de pagamento: %s\n", venda->forma_pagamento);
    printf("Valor total: R$ %.2f\n", venda->valor_total);

    getchar();
    printf("\nAperte enter para continuar...\n");
    getchar();
    return 1;
}

void realizar_venda(Rota *rotas, int *total_rotas, Passageiro *passageiros, int *total_passageiros, Venda *vendas, int *total_vendas, Funcionario *funcionarios, int total_funcionarios) {
    Venda nova_venda;
    int ver_passageiro;
    int rota_selecionada = -1;
    Passageiro passageiro_atual;
    char passageiro_fidelizado;
    int assento_escolhido = -1; 

    if (rotas == NULL || passageiros == NULL || vendas == NULL) {
        printf("Erro: Ponteiros invalidos!\n");
        return;
    }

    // ETAPA 1: Selecionar origem e destino
    limpa_tela();
    printf("=== VENDA DE PASSAGEM - ETAPA 1/5: ORIGEM E DESTINO ===\n\n");

    printf("Rotas disponiveis:\n");
    printf("-----------------------------------------------------\n");
    printf("COD | NOME DA ROTA                | ORIGEM | DESTINO\n");
    printf("-----------------------------------------------------\n");

    for (int i = 0; i < *total_rotas; i++) {
        printf("%3d | %-25s | %-6s | %-6s\n",
               rotas[i].codigo,
               rotas[i].nome,
               rotas[i].origem,
               rotas[i].destino);
    }

    printf("-----------------------------------------------------\n\n");

    printf("Digite o codigo da rota desejada: ");
    int codigo_rota;
    scanf("%d", &codigo_rota);

    // Buscar rota pelo codigo
    for (int i = 0; i < *total_rotas; i++) {
        if (rotas[i].codigo == codigo_rota) {
            rota_selecionada = i;
            break;
        }
    }

    if (rota_selecionada == -1) {
        printf("\nRota nao encontrada!\n");
        getchar();
        printf("\nAperte enter para continuar...\n");
        getchar();
        return;
    }

    // Armazenar informacoes na venda
    nova_venda.codigo_rota = rotas[rota_selecionada].codigo;
    strcpy(nova_venda.origem, rotas[rota_selecionada].origem);
    strcpy(nova_venda.destino, rotas[rota_selecionada].destino);

    printf("\nRota selecionada: %s (%s -> %s)\n",
           rotas[rota_selecionada].nome,
           rotas[rota_selecionada].origem,
           rotas[rota_selecionada].destino);

    // ETAPA 2: Selecionar horario
    printf("\nHorarios disponiveis:\n");
    for (int i = 0; i < 10 && rotas[rota_selecionada].horarios[i][0] != '\0'; i++) {
        printf("[%d] %s\n", i + 1, rotas[rota_selecionada].horarios[i]);
    }

    printf("Escolha o horario: ");
    int horario_escolhido;
    scanf("%d", &horario_escolhido);
    strcpy(nova_venda.horario, rotas[rota_selecionada].horarios[horario_escolhido - 1]);

    // ETAPA 3: Selecionar assento (sem marcar como ocupado ainda)
    printf("\nEscolha o assento:\n");

    // Exibir assentos disponíveis
    for (int i = 0; i < rotas[rota_selecionada].poltronas_total; i++) {
        if (rotas[rota_selecionada].assentos[i] == 'L') {
            printf("\033[34m[%d]\033[0m ", i + 1); // Azul para livre
        } else {
            printf("\033[31m[%d]\033[0m ", i + 1); // Vermelho para ocupado
        }
    }
    printf("\n");

    // Escolher assento
    printf("\nDigite o número do assento desejado (1 a %d): ", rotas[rota_selecionada].poltronas_total);
    scanf("%d", &assento_escolhido);

    // Verificar se o número é válido (1 a poltronas_total)
    if (assento_escolhido < 1 || assento_escolhido > rotas[rota_selecionada].poltronas_total) {
        printf("Número de assento inválido! Use números de 1 a %d.\n", rotas[rota_selecionada].poltronas_total);
        getchar();
        printf("\nAperte enter para continuar...\n");
        getchar();
        return;
    }

    // Verificar se o assento está livre
    if (rotas[rota_selecionada].assentos[assento_escolhido - 1] == 'O') {
        printf("Assento já ocupado!\n");
        getchar();
        printf("\nAperte enter para continuar...\n");
        getchar();
        return;
    }

    // ETAPA 4: Informacoes do passageiro
    printf("\nO passageiro eh fidelizado? (S/N): ");
    scanf(" %c", &passageiro_fidelizado);
    if (passageiro_fidelizado == 'S' || passageiro_fidelizado == 's') {
        printf("Digite o CPF do passageiro: ");
        char cpf[12];
        scanf("%s", cpf);
        int encontrado = -1;
        for (int i = 0; i < *total_passageiros; i++) {
            if (strcmp(passageiros[i].CPF, cpf) == 0) {
                encontrado = i;
                break;
            }
        }
        if (encontrado == -1) {
            printf("Passageiro nao encontrado!\n");
            getchar();
            printf("\nAperte enter para continuar...\n");
            getchar();
            return;
        }
        passageiro_atual = passageiros[encontrado];
    } else {
        // Cadastrar novo passageiro
        ver_passageiro = cadastrar_passageiro(passageiros, total_passageiros);
        
        if (ver_passageiro) {
            passageiro_atual = passageiros[*total_passageiros - 1];
        } else {
            return;
        }
    }

    // ETAPA 5: Confirmacao e pagamento
    printf("\nConfirme os dados da compra:\n");
    printf("Passageiro: %s\n", passageiro_atual.nome);
    printf("Rota: %s -> %s\n", nova_venda.origem, nova_venda.destino);
    printf("Horario: %s\n", nova_venda.horario);
    printf("Assento: %d\n", assento_escolhido);

    printf("\nDeseja confirmar a compra? (S/N): ");
    char confirmacao;
    scanf(" %c", &confirmacao);

    if (confirmacao == 'S' || confirmacao == 's') {
        // Marcar o assento como ocupado apenas após a confirmação
        rotas[rota_selecionada].assentos[assento_escolhido - 1] = 'O';
        rotas[rota_selecionada].poltronas_disponiveis--;

        // Preencher os dados da venda
        nova_venda.codigo_venda = *total_vendas + 1;
        strcpy(nova_venda.cpf_passageiro, passageiro_atual.CPF);
        sprintf(nova_venda.assento, "%d", assento_escolhido); // Armazenar o número do assento
        nova_venda.valor_total = calcular_preco(rotas[rota_selecionada], 0, 'U', 0.0, 0); // Exemplo de cálculo de preço

        // Salvar venda
        vendas[*total_vendas] = nova_venda;
        (*total_vendas)++;
        salvar_arquivo("vendas.dat", vendas, sizeof(Venda), *total_vendas);
        salvar_arquivo("rotas.dat", rotas, sizeof(Rota), *total_rotas);

        if (realizar_pagamento(&nova_venda, &rotas[rota_selecionada], funcionarios, total_funcionarios)){
            gerar_eticket(nova_venda, passageiro_atual, rotas[rota_selecionada]);
            printf("\nVenda realizada com sucesso!\n");
        } else {
            rotas[rota_selecionada].assentos[assento_escolhido - 1] = 'L';
            rotas[rota_selecionada].poltronas_disponiveis++;
            return;
        }
        
    } else {
        printf("\nCompra cancelada. O assento permanece disponível.\n");
    }
    
    getchar();
    printf("\nAperte enter para continuar...\n");
    getchar();
}

// Funcoes de Menu

void exibir_menu_principal()
{
    limpa_tela();
    printf("=== SISTEMA DE VENDAS DE PASSAGENS AEREAS ===\n\n");
    printf("[1] Configuracoes\n");
    printf("[2] Vendas\n");
    printf("[3] Sair\n");
    printf("\nEscolha uma opcao: ");
}

void menu_configuracoes(Aeroporto *aeroportos, int *total_aeroportos, Rota *rotas, int *total_rotas, Passageiro *passageiros, int *total_passageiros, Funcionario *funcionarios, int *total_funcionarios) {
    int opcao;
    
    do {
        limpa_tela();
        printf("\n");
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
                cadastrar_rota(rotas, total_rotas, aeroportos, *total_aeroportos);
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
            getchar();
            printf("\nAperte enter para continuar...\n");
            getchar();
        }
    } while (opcao != 10);
}

void menu_vendas(Rota *rotas, int *total_rotas, Passageiro *passageiros, int *total_passageiros, Venda *vendas, int *total_vendas, Funcionario *funcionarios, int total_funcionarios) {
    int opcao;
    
    do {
        limpa_tela();
        printf("=== MENU DE VENDAS ===\n\n");
        printf("[11] Selecionar origem e destino [Etapa 1 de 5]\n");
        printf("[12] Voltar\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 11:
                realizar_venda(rotas, total_rotas, passageiros, total_passageiros, vendas, total_vendas, funcionarios, total_funcionarios);
                break;
            case 12:
                break;
            default:
                printf("Opcao invalida!\n");
                getchar();
                printf("\nAperte enter para continuar...\n");
                getchar();
        }
    } while (opcao != 12);
}

void gerar_eticket(Venda venda, Passageiro passageiro, Rota rota)
{
    (void)rota;
    // Gerar numero unico para o e-ticket
    srand(time(NULL));
    int numero_eticket = rand() % 900000 + 100000; // Numero de 6 digitos
    
    char nome_arquivo[50];
    sprintf(nome_arquivo, "etickets/eticket_%d.txt", numero_eticket);
    
    // Criar diretorio se nao existir
    #ifdef _WIN32
    system("mkdir etickets 2> nul");
    #else
    system("mkdir -p etickets");
    #endif
    
    FILE *arquivo = fopen(nome_arquivo, "w");
    if (!arquivo)
    {
        printf("Erro ao criar arquivo de e-ticket!\n");
        getchar();
        printf("\nAperte enter para continuar...\n");
        getchar();
        return;
    }
    
    // Dados do e-ticket
    fprintf(arquivo, "===================================================\n");
    fprintf(arquivo, "                     E-TICKET                      \n");
    fprintf(arquivo, "===================================================\n\n");
    fprintf(arquivo, "Numero do E-ticket: %d\n", numero_eticket);
    fprintf(arquivo, "Codigo da venda: %d\n\n", venda.codigo_venda);
    
    fprintf(arquivo, "PASSAGEIRO\n");
    fprintf(arquivo, "Nome: %s\n", passageiro.nome);
    fprintf(arquivo, "CPF: %s\n", passageiro.CPF);
    fprintf(arquivo, "Bagagem extra: %s\n\n", passageiro.bagagem_extra == 'S' ? "Sim" : "Nao");
    
    fprintf(arquivo, "VOO\n");
    fprintf(arquivo, "Origem: %s\n", venda.origem);
    fprintf(arquivo, "Destino: %s\n", venda.destino);
    fprintf(arquivo, "Horario: %s\n", venda.horario);
    fprintf(arquivo, "Assento: %s\n\n", venda.assento);
    
    fprintf(arquivo, "Valor total: R$ %.2f\n", venda.valor_total);
    fprintf(arquivo, "Forma de pagamento: %s\n\n", venda.forma_pagamento);
    
    fprintf(arquivo, "===================================================\n");
    fprintf(arquivo, "    Apresente este e-ticket no portao de embarque  \n");
    fprintf(arquivo, "===================================================\n");
    
    fclose(arquivo);
    
    // Tambem adicionar ao arquivo consolidado de e-tickets
    arquivo = fopen("etickets.txt", "a");
    if (arquivo)
    {
        fprintf(arquivo, "E-TICKET %d\n", numero_eticket);
        fprintf(arquivo, "Passageiro: %s\n", passageiro.nome);
        fprintf(arquivo, "CPF: %s\n", passageiro.CPF);
        fprintf(arquivo, "Voo: %s para %s\n", venda.origem, venda.destino);
        fprintf(arquivo, "Horario: %s\n", venda.horario);
        fprintf(arquivo, "Assento: %s\n", venda.assento);
        fprintf(arquivo, "Valor: R$ %.2f\n", venda.valor_total);
        fprintf(arquivo, "---------------------------------------------------\n\n");
        fclose(arquivo);
    }

    printf("\nE-ticket gerado com sucesso! Numero: %d\n", numero_eticket);
    printf("Arquivo salvo em: %s\n", nome_arquivo);
}
