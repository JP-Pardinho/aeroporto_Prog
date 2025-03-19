#include "variaveis.h"

// FUNcaO DE LIMPAR A TELA

void limpa_tela()
{

    /* Função responsável por limpar o terminal sempre que for usada. */

#ifdef _WIN32
    limpa_tela("cls");
#else
    system("clear");
#endif
}

// FUNCOES DE ARQUIVO

int carregar_arquivo(const char *nome_arquivo, void **dados, size_t tamanho_elemento, int *tamanho_maximo)
{

    /* Função responsável por ler os dados de um arquivo que é passado como parametro
     assim que o programa é iniciado ele carrega esses dados para o programa,
     exibe mensagem de erro caso o arquivo esteja com algum erro. */

    FILE *arquivo = fopen(nome_arquivo, "rb");
    if (arquivo == NULL)
    {
        printf("Erro: Arquivo %s nao encontrado ou corrompido!\n", nome_arquivo);
        return 0;
    }

    int total = 0;
    while (fread((char *)(*dados) + total * tamanho_elemento, tamanho_elemento, 1, arquivo))
    {
        total++;
        if (total >= *tamanho_maximo)
        {
            *tamanho_maximo *= 2;
            void *temp = realloc(*dados, *tamanho_maximo * tamanho_elemento);
            if (!temp)
            {
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

void salvar_arquivo(const char *nome_arquivo, void *dados, size_t tamanho_elemento, int total)
{

    /* Função responsável por salvar os dados do programa no arquivo passado como parametro,
     exibe mensagem de erro caso tenha algum erro na hora de abrir o arquivo. */

    FILE *arquivo = fopen(nome_arquivo, "wb");
    if (arquivo)
    {
        fwrite(dados, tamanho_elemento, total, arquivo);
        fclose(arquivo);
    }
    else
    {
        printf("Erro ao abrir arquivo para gravacao: %s\n", nome_arquivo);
    }
}

// FUNcoES DE ALOCAcaO

Aeroporto *alocaVetAeroportos(int tam)
{
    /* Função que realiza a alocação de memória para o ponteiro dos aeroportos.
    Será exibida uma mensagem de erro, caso a alocação seja mal sucedida e retorna
    o ponteiro *vetAeroportos. */

    Aeroporto *vetAeroportos = (Aeroporto *)malloc(tam * sizeof(Aeroporto));
    if (vetAeroportos == NULL)
    {
        printf("Erro: alocacao mal sucedida!");
        exit(1);
    }
    return vetAeroportos;
}

Rota *alocaVetRotas(int tam)
{
    /* Função que realiza a alocação de memória para o ponteiro das rotas.
    Será exibida uma mensagem de erro, caso a alocação seja mal sucedida e retorna
    o ponteiro *vetRotas. */

    Rota *vetRotas = (Rota *)malloc(tam * sizeof(Rota));
    if (vetRotas == NULL)
    {
        printf("Erro: alocacao mal sucedida!");
        exit(1);
    }
    return vetRotas;
}

Passageiro *alocaVetPassageiros(int tam)
{
    /* Função que realiza a alocação de memória para o ponteiro dos passageiros.
    Será exibida uma mensagem de erro, caso a alocação seja mal sucedida e retorna
    o ponteiro *vetPassageiros. */

    Passageiro *vetPassageiros = (Passageiro *)malloc(tam * sizeof(Passageiro));
    if (vetPassageiros == NULL)
    {
        printf("Erro: alocacao mal sucedida!");
        exit(1);
    }
    return vetPassageiros;
}

Funcionario *alocaVetFuncionarios(int tam)
{
    /* Função que realiza a alocação de memória para o ponteiro dos funcionarios.
    Será exibida uma mensagem de erro, caso a alocação seja mal sucedida e retorna
    o ponteiro *vetFuncionarios. */

    Funcionario *vetFuncionarios = (Funcionario *)malloc(tam * sizeof(Funcionario));
    if (vetFuncionarios == NULL)
    {
        printf("Erro: alocacao mal sucedida!");
        exit(1);
    }
    return vetFuncionarios;
}

Venda *alocaVetVenda(int tam)
{

    /* Função que realiza a alocação de memória para o ponteiro das vendas.
    Será exibida uma mensagem de erro, caso a alocação seja mal sucedida e retorna
    o ponteiro *vetVendas. */

    Venda *vetVendas = (Venda *)malloc(tam * sizeof(Venda));
    if (vetVendas == NULL)
    {
        printf("Erro: alocacao mal sucedida!");
        exit(1);
    }
    return vetVendas;
}

// Funções de Verificão
int rota_existe(Rota *rotas, int total_rotas, const char *nome)
{

    /* Função responsável em percorer o vetor de rotas e verificar se ela existe. */

    for (int i = 0; i < total_rotas; i++)
    {
        if (strcasecmp(rotas[i].nome, nome) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int aeroporto_existe(Aeroporto *aeroportos, int total_aeroportos, const char *nome)
{

    /* Função responsável em percorer o vetor de aeroportos e verificar se ele existe. */

    for (int i = 0; i < total_aeroportos; i++)
    {
        if (strcasecmp(aeroportos[i].nome, nome) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int passageiro_existe(Passageiro *passageiros, int total_passageiros, const char *nome)
{

    /* Função responsável em percorer o vetor de passageiros e verificar se ele existe. */

    for (int i = 0; i < total_passageiros; i++)
    {
        if (strcasecmp(passageiros[i].nome, nome) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int funcionario_existe(Funcionario *funcionarios, int total_funcionarios, const char *nome)
{

    /* Função responsável em percorer o vetor de funcionarios e verificar se ele existe. */

    for (int i = 0; i < total_funcionarios; i++)
    {
        if (strcasecmp(funcionarios[i].nome, nome) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int contem_apenas_numeros(const char *str)
{

    /* Função responsável por verificar se foi passado apenas numeros pelo usuario. */

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]))
        {
            return 0;
        }
    }
    return 1;
}

int contem_apenas_letras(const char *str)
{

    /* Função responsável por verificar se foi passado apenas letras pelo usuario. */

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isalpha(str[i]) && str[i] != ' ')
        {
            return 0;
        }
    }
    return 1;
}

// FUNcoES DE CADASTRO / ALTERAcaO
void cadastrar_aeroporto(Aeroporto *aeroportos, int *total)
{

    /* Função responsável pelo cadastro de aeroportos no programa,
    pede para que o usuario insira todos os dados do aeroporto, caso codigo tenha o numero de letras erradas,
    será exibida  uma mensagem de erro, caso o estado tenha o numero de letras erradas, também será exibido uma mensagem de erro,
    será exibida uma mensagem de confirmação caso o aeroporto seja cadastrado de forma correta. */

    limpa_tela();
    printf("=== CADASTRO DE AEROPORTO ===\n\n");

    char codigo[4];
    printf("Codigo (3 letras): ");
    scanf("%s", codigo);

    if (strlen(codigo) != 3 || !contem_apenas_letras(codigo))
    {
        printf("Erro: Codigo deve ter exatamente 3 letras!\n");
        getchar();
        printf("\nAperte enter para continuar...\n");
        getchar();
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        codigo[i] = toupper(codigo[i]);
    }

    for (int i = 0; i < *total; i++)
    {
        if (strcmp(aeroportos[i].codigo, codigo) == 0)
        {
            printf("Erro: Codigo do aeroporto ja existe!\n");
            getchar();
            printf("\nAperte enter para continuar...\n");
            getchar();
            return;
        }
    }

    strcpy(aeroportos[*total].codigo, codigo);

    char nome[50];
    printf("Nome: ");
    scanf(" %[^\n]", nome);

    if (aeroporto_existe(aeroportos, *total, nome))
    {
        printf("Erro: Aeroporto com o mesmo nome ja existe!\n");
        getchar();
        printf("\nAperte enter para continuar...\n");
        getchar();
        return;
    }

    strcpy(aeroportos[*total].nome, nome);

    printf("Cidade: ");
    scanf(" %[^\n]", aeroportos[*total].cidade);

    char estado[3];
    printf("Estado (2 letras): ");
    scanf("%s", estado);
    if (strlen(estado) != 2 || !contem_apenas_letras(estado))
    {
        printf("Erro: Estado deve ter exatamente 2 letras!\n");
        getchar();
        printf("\nAperte enter para continuar...\n");
        getchar();
        return;
    }

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

void cadastrar_rota(Rota *rotas, int *total, Aeroporto *aeroportos, int total_aeroportos)
{

    /* Função responsável pelo cadastro de rotas no programa,
    pede para que o usuario insira todos os dados da rota,
    será exibida uma mensagem de confirmação caso a rota seja cadastrado de forma correta. */

    limpa_tela();
    printf("=== CADASTRO DE ROTA ===\n\n");

    if (total_aeroportos == 0)
    {
        printf("Erro: Nenhum aeroporto cadastrado. Cadastre aeroportos antes de criar rotas.\n");
        getchar();
        printf("\nAperte enter para continuar...\n");
        getchar();
        return;
    }

    int codigo;
    printf("Codigo da rota (numero): ");
    scanf("%d", &codigo);
    for (int i = 0; i < *total; i++)
    {
        if (rotas[i].codigo == codigo)
        {
            printf("Erro: Codigo da rota ja existe!\n");
            getchar();
            printf("\nAperte enter para continuar...\n");
            getchar();
            return;
        }
    }
    rotas[*total].codigo = codigo;

    char origem[4], destino[4];
    char nome[100];
    printf("Nome da rota: ");
    scanf(" %[^\n]", nome);
    if (rota_existe(rotas, *total, nome))
    {
        printf("Erro: Uma rota com o nome '%s' ja existe!\n", nome);
        getchar();
        printf("\nAperte enter para continuar...\n");
        getchar();
        return;
    }
    strcpy(rotas[*total].nome, nome);

    printf("Codigo de origem (3 letras): ");
    scanf("%s", origem);
    if (strlen(origem) != 3 || !contem_apenas_letras(origem))
    {
        printf("Erro: Codigo de origem deve ter exatamente 3 letras!\n");
        getchar();
        printf("\nAperte enter para continuar...\n");
        getchar();
        return;
    }
    for (int i = 0; i < 3; i++)
    {
        origem[i] = toupper(origem[i]);
    }
    int origem_encontrada = 0;
    for (int i = 0; i < total_aeroportos; i++)
    {
        if (strcmp(aeroportos[i].codigo, origem) == 0)
        {
            origem_encontrada = 1;
            break;
        }
    }
    if (!origem_encontrada)
    {
        printf("Erro: Aeroporto de origem '%s' nao encontrado!\n", origem);
        getchar();
        printf("\nAperte enter para continuar...\n");
        getchar();
        return;
    }
    strcpy(rotas[*total].origem, origem);

    printf("Codigo de destino (3 letras): ");
    scanf("%s", destino);
    if (strlen(destino) != 3 || !contem_apenas_letras(destino))
    {
        printf("Erro: Codigo de destino deve ter exatamente 3 letras!\n");
        getchar();
        printf("\nAperte enter para continuar...\n");
        getchar();
        return;
    }
    for (int i = 0; i < 3; i++)
    {
        destino[i] = toupper(destino[i]);
    }
    int destino_encontrado = 0;
    for (int i = 0; i < total_aeroportos; i++)
    {
        if (strcmp(aeroportos[i].codigo, destino) == 0)
        {
            destino_encontrado = 1;
            break;
        }
    }
    if (!destino_encontrado)
    {
        printf("Erro: Aeroporto de destino '%s' nao encontrado!\n", destino);
        getchar();
        printf("\nAperte enter para continuar...\n");
        getchar();
        return;
    }
    strcpy(rotas[*total].destino, destino);

    printf("Distancia em milhas: ");
    scanf("%f", &rotas[*total].distancia);
    if (rotas[*total].distancia <= 0)
    {
        printf("Erro: A distancia deve ser um valor positivo!\n");
        getchar();
        printf("\nAperte enter para continuar...\n");
        getchar();
        return;
    }

    printf("Numero total de poltronas: ");
    scanf("%d", &rotas[*total].poltronas_total);
    if (rotas[*total].poltronas_total <= 0)
    {
        printf("Erro: O numero de poltronas deve ser positivo!\n");
        getchar();
        printf("\nAperte enter para continuar...\n");
        getchar();
        return;
    }
    rotas[*total].poltronas_disponiveis = rotas[*total].poltronas_total;

    rotas[*total].assentos = (char *)malloc(rotas[*total].poltronas_total * sizeof(char));
    if (rotas[*total].assentos == NULL)
    {
        printf("Erro: Falha ao alocar memoria para assentos!\n");
        getchar();
        printf("\nAperte enter para continuar...\n");
        getchar();
        return;
    }

    for (int i = 0; i < rotas[*total].poltronas_total; i++)
    {
        rotas[*total].assentos[i] = 'L';
    }
    int num_horarios;
    printf("Quantidade de horarios para esta rota (maximo 10): ");
    scanf("%d", &num_horarios);
    if (num_horarios < 1 || num_horarios > 10)
    {
        printf("Erro: O numero de horarios deve estar entre 1 e 10!\n");
        getchar();
        printf("\nAperte enter para continuar...\n");
        getchar();
        return;
    }
    for (int i = 0; i < num_horarios; i++)
    {
        char horario[6];
        printf("Horario %d (formato HH:MM): ", i + 1);
        scanf("%s", horario);
        if (strlen(horario) != 5 || horario[2] != ':')
        {
            printf("Erro: Formato de horario invalido! Use HH:MM.\n");
            getchar();
            printf("\nAperte enter para continuar...\n");
            getchar();
            return;
        }
        strcpy(rotas[*total].horarios[i], horario);
    }

    printf("Dias da semana (1=DOM, 2=SEG, 3=TER, 4=QUA, 5=QUI, 6=SEX, 7=SAB, 0=TODOS): ");
    scanf("%s", rotas[*total].dias_semana);

    printf("A rota tem conexao? (S/N): ");
    char tem_conexao;
    scanf(" %c", &tem_conexao);
    if (tem_conexao == 'S' || tem_conexao == 's')
    {
        printf("Codigo do aeroporto de conexao (3 letras): ");
        scanf("%s", rotas[*total].conexao);
        if (strlen(rotas[*total].conexao) != 3 || !contem_apenas_letras(rotas[*total].conexao))
        {
            printf("Erro: Codigo de conexao deve ter 3 letras!\n");
            getchar();
            printf("\nAperte enter para continuar...\n");
            getchar();
            return;
        }
        int conexao_encontrada = 0;
        for (int i = 0; i < total_aeroportos; i++)
        {
            if (strcmp(aeroportos[i].codigo, rotas[*total].conexao) == 0)
            {
                conexao_encontrada = 1;
                break;
            }
        }
        if (!conexao_encontrada)
        {
            printf("Erro: Aeroporto de conexao '%s' nao encontrado!\n", rotas[*total].conexao);
            getchar();
            printf("\nAperte enter para continuar...\n");
            getchar();
            return;
        }
    }
    else
    {
        strcpy(rotas[*total].conexao, "");
    }

    (*total)++;
    salvar_arquivo("rotas.dat", rotas, sizeof(Rota), *total);

    printf("\nRota cadastrada com sucesso!\n");

    getchar();
    printf("\nAperte enter para concluir esse cadastro!...\n");
    getchar();
}

int cadastrar_passageiro(Passageiro *passageiros, int *total)
{

    /* Função responsável pelo cadastro de passageiros no programa,
    pede para que o usuario insira todos os dados do passageiro, caso cpf tenha o numero de digitos errado,
    será exibida uma mensagem de confirmação caso o passageiro seja cadastrado de forma correta. */

    limpa_tela();
    printf("=== CADASTRO DE PASSAGEIRO FIDELIZADO ===\n\n");

    passageiros[*total].codigo = *total + 1;

    char nome[100];
    char CPF[12];
    printf("Nome: ");
    scanf(" %[^\n]", nome);

    for (int i = 0; i < *total; i++)
    {
        if (strcasecmp(passageiros[i].nome, nome) == 0)
        {
            printf("Erro: Passageiro com o mesmo nome ja existe!\n");
            getchar();
            printf("\nAperte enter para continuar...\n");
            getchar();
            return 0;
        }
    }

    strcpy(passageiros[*total].nome, nome);

    printf("RG: ");
    scanf("%s", passageiros[*total].RG);

    printf("CPF (apenas numeros): ");
    scanf("%s", CPF);
    for (int i = 0; i < *total; i++)
    {
        if (strcasecmp(passageiros[i].CPF, CPF) == 0)
        {
            printf("Erro: Passageiro com esse CPF ja existe!\n");
            getchar();
            printf("\nAperter enter para continuar...\n");
            getchar();
            return 0;
        }
    }
    strcpy(passageiros[*total].CPF, CPF);

    if (strlen(passageiros[*total].CPF) != 11)
    {
        printf("Erro: CPF deve ter 11 digitos!\n");
        getchar();
        printf("\nAperte enter para continuar...\n");
        getchar();
        return 0;
    }

    printf("Data de nascimento (DD/MM/AAAA): ");
    scanf("%s", passageiros[*total].data_nasc);

    if (strlen(passageiros[*total].data_nasc) != 10 || passageiros[*total].data_nasc[2] != '/' || passageiros[*total].data_nasc[5] != '/')
    {
        printf("Erro: Data de nascimento deve estar no formato DD/MM/AAAA!\n");
        getchar();
        printf("\nAperte enter para continuar...\n");
        getchar();
        return 0;
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
    return 1;
}

void pesquisar_alterar_passageiro(Passageiro *passageiros, int total)
{

    /* Função responsável por pesquisar ou alterar um passageiro já cadastrado,
    pede para que o usuario digite o cpf do passageiro que deseja procurar ou alterar,
    caso não encontre, será exibida uma mensagem de passageiro não encontrado, caso encontre o passageiro,
    é mostrado na tela todos os dados do passageiro e é perguntado se deseja alterar os dados, caso queira,
    é pedido para que insira os novos dados e por fim é mostrado uma tela de confirmação de dados cadastrados. */

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

    /* Função responsável pelo cadastro de funcionários,
    é exibido uma mensagem de confirmação de cadastro ao final. */

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

    /* Função responsável por pesquisar ou alterar um funcionário já cadastrado,
    pede para que o usuario digite a matricula do funcionario que deseja procurar ou alterar,
    caso não encontre, será exibida uma mensagem de funcionario não encontrado, caso encontre o funcionario,
    é mostrado na tela todos os dados do funcionario e é perguntado se deseja alterar os dados, caso queira,
    é pedido para que insira os novos dados e por fim é mostrado uma tela de confirmação de dados cadastrados. */

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

    /* Função responsável por fazer todos os calculos e passar o valor da passagem para o usuario. */

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

    float fator_dia;
    switch (tipo_dia)
    {
    case 'F':
        fator_dia = 3.56;
        break;
    case 'S':
        fator_dia = 1.21;
        break;
    default:
        fator_dia = 1.00;
        break;
    }

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

    return rota.distancia * preco_milha * fator_periodo * fator_dia * fator_retorno * fator_procura;
}

int dias_ate_viagem(int dia, int mes, int ano)
{

    /* Função responsável por fazer a contagem de quantos dias faltam até a viagem. */

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

int data_valida(int dia, int mes, int ano)
{

    /* Função responsável por verificar se o formato que o usuario passou a data esta correto. */

    if (mes < 1 || mes > 12)
    {
        return 0;
    }

    int dias_no_mes;
    switch (mes)
    {
    case 2:
        if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
        {
            dias_no_mes = 29;
        }
        else
        {
            dias_no_mes = 28;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        dias_no_mes = 30;
        break;
    default:
        dias_no_mes = 31;
        break;
    }

    if (dia < 1 || dia > dias_no_mes)
    {
        return 0;
    }

    if (ano < 2025)
    {
        return 0;
    }

    return 1;
}

int realizar_pagamento(Venda *venda, Rota *rota, Funcionario *funcionarios, int total_funcionarios)
{

    /* Função responsável por verificar e validar a forma de pagamento do cliente,
     exibe mensagens de erro caso a data seja invalida,
     caso o formato da data seja invalida e caso o formato escolhido for dinheiro e o usuario digite um funcionario invalido. */

    int dias_antecedencia;
    char tipo_dia;
    char data[11];
    float percentual_ocupacao;
    int dias_retorno;

    printf("\n=== ETAPA 4: REALIZAR PAGAMENTO ===\n\n");

    int dia, mes, ano;

    while (1)
    {
        printf("Digite a data da viagem (DD/MM/AAAA): ");
        scanf("%10s", data);

        if (sscanf(data, "%d/%d/%d", &dia, &mes, &ano) == 3)
        {
            if (data_valida(dia, mes, ano))
            {
                break;
                ;
            }
            else
            {
                printf("Data invalida! Tente novamente.\n");
                return 0;
            }
        }
        else
        {
            printf("Formato invalido! Use o formato DD/MM/AAAA.\n");
        }
    }

    dias_antecedencia = dias_ate_viagem(dia, mes, ano);

    printf("Tipo de dia (F = Feriado, S = Final de Semana, U = Dia Util): ");
    scanf(" %c", &tipo_dia);

    percentual_ocupacao = ((float)(rota->poltronas_total - rota->poltronas_disponiveis) / rota->poltronas_total) * 100;

    printf("Quantos dias ate o retorno (0 se for so ida)? ");
    scanf("%d", &dias_retorno);

    float valor_passagem = calcular_preco(*rota, dias_antecedencia, tipo_dia, percentual_ocupacao, dias_retorno);
    printf("\nValor da passagem: R$ %.2f\n", valor_passagem);

    printf("\nEscolha a forma de pagamento:\n");
    printf("[1] Cartao de Credito\n");
    printf("[2] Cartao de Debito\n");
    printf("[3] Dinheiro\n");
    int forma_pagamento;
    scanf("%d", &forma_pagamento);

    if (forma_pagamento < 1 || forma_pagamento > 3)
    {
        printf("Forma de pagamento invalida!\n");
        getchar();
        printf("\nAperte enter para continuar...\n");
        getchar();
        return 0;
    }

    if (forma_pagamento == 3)
    {
        int matricula_funcionario;
        printf("Digite a matricula do funcionario: ");
        scanf("%d", &matricula_funcionario);

        int funcionario_valido = 0;
        for (int i = 0; i < total_funcionarios; i++)
        {
            if (funcionarios[i].matricula == matricula_funcionario)
            {
                funcionario_valido = 1;
                break;
            }
        }

        if (!funcionario_valido)
        {
            printf("Matricula do funcionario invalida!\n");
            getchar();
            printf("\nAperte enter para continuar...\n");
            getchar();
            return 0;
        }
    }

    venda->valor_total = valor_passagem;
    if (forma_pagamento == 1)
    {
        strcpy(venda->forma_pagamento, "Cartao de Credito");
    }
    else if (forma_pagamento == 2)
    {
        strcpy(venda->forma_pagamento, "Cartao de Debito");
    }
    else
    {
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

void realizar_venda(Rota *rotas, int *total_rotas, Passageiro *passageiros, int *total_passageiros, Venda *vendas, int *total_vendas, Funcionario *funcionarios, int total_funcionarios)
{

    /* Função responsável pela venda da passagem, pede os dados da rota escolida e do passageiro,
    exibe mensagem de erro caso a rota não seja encontrada, caso o numero do assento seja invalido,
    caso o assento ja esteja ocupado e caso o passageiro não for encontrado. */

    Venda nova_venda;
    int ver_passageiro;
    int rota_selecionada = -1;
    Passageiro passageiro_atual;
    char passageiro_fidelizado;
    int assento_escolhido = -1;

    if (rotas == NULL || passageiros == NULL || vendas == NULL)
    {
        printf("Erro: Ponteiros invalidos!\n");
        return;
    }
    limpa_tela();
    printf("=== VENDA DE PASSAGEM - ETAPA 1/5: ORIGEM E DESTINO ===\n\n");

    printf("Rotas disponiveis:\n");
    printf("-----------------------------------------------------\n");
    printf("COD | NOME DA ROTA                | ORIGEM | DESTINO\n");
    printf("-----------------------------------------------------\n");

    for (int i = 0; i < *total_rotas; i++)
    {
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

    for (int i = 0; i < *total_rotas; i++)
    {
        if (rotas[i].codigo == codigo_rota)
        {
            rota_selecionada = i;
            break;
        }
    }

    if (rota_selecionada == -1)
    {
        printf("\nRota nao encontrada!\n");
        getchar();
        printf("\nAperte enter para continuar...\n");
        getchar();
        return;
    }

    nova_venda.codigo_rota = rotas[rota_selecionada].codigo;
    strcpy(nova_venda.origem, rotas[rota_selecionada].origem);
    strcpy(nova_venda.destino, rotas[rota_selecionada].destino);

    printf("\nRota selecionada: %s (%s -> %s)\n",
           rotas[rota_selecionada].nome,
           rotas[rota_selecionada].origem,
           rotas[rota_selecionada].destino);

    printf("\nHorarios disponiveis:\n");
    for (int i = 0; i < 10 && rotas[rota_selecionada].horarios[i][0] != '\0'; i++)
    {
        printf("[%d] %s\n", i + 1, rotas[rota_selecionada].horarios[i]);
    }

    printf("Escolha o horario: ");
    int horario_escolhido;
    scanf("%d", &horario_escolhido);
    strcpy(nova_venda.horario, rotas[rota_selecionada].horarios[horario_escolhido - 1]);

    printf("\nEscolha o assento:\n");

    for (int i = 0; i < rotas[rota_selecionada].poltronas_total; i++)
    {
        if (rotas[rota_selecionada].assentos[i] == 'L')
        {
            printf("\033[34m[%d]\033[0m ", i + 1);
        }
        else
        {
            printf("\033[31m[%d]\033[0m ", i + 1);
        }
    }
    printf("\n");

    printf("\nDigite o numero do assento desejado (1 a %d): ", rotas[rota_selecionada].poltronas_total);
    scanf("%d", &assento_escolhido);

    if (assento_escolhido < 1 || assento_escolhido > rotas[rota_selecionada].poltronas_total)
    {
        printf("Numero de assento invalido! Use numeros de 1 a %d.\n", rotas[rota_selecionada].poltronas_total);
        getchar();
        printf("\nAperte enter para continuar...\n");
        getchar();
        return;
    }

    if (rotas[rota_selecionada].assentos[assento_escolhido - 1] == 'O')
    {
        printf("Assento ja ocupado!\n");
        getchar();
        printf("\nAperte enter para continuar...\n");
        getchar();
        return;
    }

    printf("\nO passageiro eh fidelizado? (S/N): ");
    scanf(" %c", &passageiro_fidelizado);
    if (passageiro_fidelizado == 'S' || passageiro_fidelizado == 's')
    {
        printf("Digite o CPF do passageiro: ");
        char cpf[12];
        scanf("%s", cpf);
        int encontrado = -1;
        for (int i = 0; i < *total_passageiros; i++)
        {
            if (strcmp(passageiros[i].CPF, cpf) == 0)
            {
                encontrado = i;
                break;
            }
        }
        if (encontrado == -1)
        {
            printf("Passageiro nao encontrado!\n");
            getchar();
            printf("\nAperte enter para continuar...\n");
            getchar();
            return;
        }
        passageiro_atual = passageiros[encontrado];
    }
    else
    {
        ver_passageiro = cadastrar_passageiro(passageiros, total_passageiros);

        if (ver_passageiro)
        {
            passageiro_atual = passageiros[*total_passageiros - 1];
        }
        else
        {
            return;
        }
    }
    printf("\nConfirme os dados da compra:\n");
    printf("Passageiro: %s\n", passageiro_atual.nome);
    printf("Rota: %s -> %s\n", nova_venda.origem, nova_venda.destino);
    printf("Horario: %s\n", nova_venda.horario);
    printf("Assento: %d\n", assento_escolhido);

    printf("\nDeseja confirmar a compra? (S/N): ");
    char confirmacao;
    scanf(" %c", &confirmacao);

    if (confirmacao == 'S' || confirmacao == 's')
    {
        rotas[rota_selecionada].assentos[assento_escolhido - 1] = 'O';
        rotas[rota_selecionada].poltronas_disponiveis--;

        nova_venda.codigo_venda = *total_vendas + 1;
        strcpy(nova_venda.cpf_passageiro, passageiro_atual.CPF);
        sprintf(nova_venda.assento, "%d", assento_escolhido);
        nova_venda.valor_total = calcular_preco(rotas[rota_selecionada], 0, 'U', 0.0, 0);

        vendas[*total_vendas] = nova_venda;
        (*total_vendas)++;
        salvar_arquivo("vendas.dat", vendas, sizeof(Venda), *total_vendas);
        salvar_arquivo("rotas.dat", rotas, sizeof(Rota), *total_rotas);

        if (realizar_pagamento(&nova_venda, &rotas[rota_selecionada], funcionarios, total_funcionarios))
        {
            rotas[rota_selecionada].assentos[assento_escolhido - 1] = 'O';
            rotas[rota_selecionada].poltronas_disponiveis--;

            vendas[*total_vendas] = nova_venda;
            (*total_vendas)++;
            salvar_arquivo("vendas.dat", vendas, sizeof(Venda), *total_vendas);
            salvar_arquivo("rotas.dat", rotas, sizeof(Rota), *total_rotas);

            gerar_eticket(nova_venda, passageiro_atual, rotas[rota_selecionada]);
            printf("\nVenda realizada com sucesso!\n");
        }
        else
        {
            rotas[rota_selecionada].assentos[assento_escolhido - 1] = 'L';
            rotas[rota_selecionada].poltronas_disponiveis++;
            return;
        }
    }
    else
    {
        printf("\nCompra cancelada. O assento permanece disponivel.\n");
    }

    getchar();
    printf("\nAperte enter para continuar...\n");
    getchar();
}

// Funcoes de Menu

void exibir_menu_principal()
{
    /* Função responsável por mostrar o menu principal na tela,
    pede para que o usuario insira uma das opções mostrada no menu principal. */

    limpa_tela();
    printf("=== SISTEMA DE VENDAS DE PASSAGENS AEREAS ===\n\n");
    printf("[1] Configuracoes\n");
    printf("[2] Vendas\n");
    printf("[3] Sair\n");
    printf("\nEscolha uma opcao: ");
}

void menu_configuracoes(Aeroporto *aeroportos, int *total_aeroportos, Rota *rotas, int *total_rotas, Passageiro *passageiros, int *total_passageiros, Funcionario *funcionarios, int *total_funcionarios)
{

    /* Função responsável por mostrar o menu de configurações na tela,
    pede para que o usuario insira uma das opções mostrada no menu de configurações,
    caso escolha uma opção que não existe, será exibido uma mensagem de opção inválida. */

    int opcao;

    do
    {
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

        switch (opcao)
        {
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

void menu_vendas(Rota *rotas, int *total_rotas, Passageiro *passageiros, int *total_passageiros, Venda *vendas, int *total_vendas, Funcionario *funcionarios, int total_funcionarios)
{

    /* Função responsável por mostrar o menu de vendas na tela,
    pede para que o usuario insira uma das opções mostrada no menu de vendas,
    caso escolha uma opção que não existe, será exibido uma mensagem de opção inválida. */

    int opcao;

    do
    {
        limpa_tela();
        printf("=== MENU DE VENDAS ===\n\n");
        printf("[11] Selecionar origem e destino [Etapa 1 de 5]\n");
        printf("[12] Voltar\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
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

    /* Função responsável por gerar o eticket da venda, gera um novo arquivo .txt com todos os dados do passageiro, voo, valor e forma de pagamento. */

    (void)rota;
    srand(time(NULL));
    int numero_eticket = rand() % 900000 + 100000;

    char nome_arquivo[50];
    sprintf(nome_arquivo, "etickets/eticket_%d.txt", numero_eticket);

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
