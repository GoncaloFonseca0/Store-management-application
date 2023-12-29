

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct dadoscliente
{ // Estrutura dos dados do cliente (nome, nif, etc...)
    char nome[100];
    char morada[200];
    int telefone;
    int nif;

}; // array of 100 clients

struct dadosprodutos
{
    char nome[50];
    int nump; // Número do produto
    // int stock;
    float preco;
};

void inserir_cliente() // Feito
{
    FILE *dados;
    struct dadoscliente cliente;

    dados = fopen("InfoClientes.txt", "a");

    if (dados == 0)
    {
        printf("*ERROR*\n");
        printf("Arquivo não encontrado");
    }
    else
    {
        printf("---------------------------------------------------------------------------------------------\n");
        printf("* Inserir dados do Cliente *\n");
        printf("---------------------------------------------------------------------------------------------\n");
        fflush(stdin);
        printf("Digite o nome do Cliente:");
        fgets(cliente.nome, sizeof(cliente.nome), stdin);
        fflush(stdin);
        printf("Digite a morada do Cliente:");
        fgets(cliente.morada, sizeof(cliente.morada), stdin);
        fflush(stdin);
        printf("Digite o telefone do Cliente:");
        scanf("%d", &cliente.telefone);
        printf("Digite o NIF do Cliente:");
        scanf("%d", &cliente.nif);

        fprintf(dados, "\nCliente:\n");
        fprintf(dados, "Nome: %s", cliente.nome); // Como utilizamos fgets nao podemos usar /n
        fprintf(dados, "Morada: %s", cliente.morada);
        fprintf(dados, "Telefone: %d\n", cliente.telefone);
        fprintf(dados, "Nif:%d", cliente.nif);

        fclose(dados);
    }
}

void inserir_produto()
{

    FILE *dados1;
    struct dadosprodutos produto;

    dados1 = fopen("InfoProdutos.txt", "a");

    if (dados1 == NULL)
    {
        printf("ERROR\n");
        printf("Arquivo não encontrado\n");
    }
    else
    {
        printf("---------------------------------------------------------------------------------------------\n");
        printf("* Inserir dados do Produto *\n");
        printf("---------------------------------------------------------------------------------------------\n");

        printf("Digite o nome do produto:");
        fgets(produto.nome, sizeof(produto.nome), stdin);

        printf("Digite o preço do produto:");
        scanf("%f", &produto.preco);

        fprintf(dados1, "\nProduto:\n");
        fprintf(dados1, "Nome: %s", produto.nome);
        fprintf(dados1, "Preço: %.2f €\n", produto.preco);

        fclose(dados1);

        int escolha;
        printf("\n---------------------------------------------------------------------------------------------\n");
        printf("Pretende introduzir mais algum produto?\n");
        printf("1- Sim\n");
        printf("2- Não\n");
        printf("R:");
        scanf("%d", &escolha);

        if (escolha == 1)
        {
            inserir_produto();
        }
    }
}

void pesquisar_cliente()
{
    struct dadoscliente clientes; // coloquei como o filipe disse para nao baralhar
    int nif_client, tele_client;
    int telefone_client;
    int clienteEncontrado = 0;
    char line[256];

    FILE *dados = fopen("InfoClientes.txt", "r"); // Read only
    if (dados == NULL)
    {
        printf("oops, file can't be read \n");
        exit(-1);
    };
    int geral;
    printf("\n---------------------------------------------------------------------------------------------\n");
    printf("1 - Digite o NIF do Cliente:\n");
    printf("2- Digite o Telemovel:");
    scanf("%d", &geral);

    if (geral == 1)
    {
        printf("Você escolheu a Opção 1.\n");
        printf("Introduza o NIF:\n");
        scanf("%d", &geral);
        while (fgets(line, sizeof(line), dados))
        {
            sscanf(line, "Nome: %[^\n]", clientes.nome);
            sscanf(line, "Morada: %[^\n]", clientes.morada);
            sscanf(line, "Telefone: %d", &clientes.telefone);
            sscanf(line, "Nif: %d", &clientes.nif);

            if (geral == clientes.nif)
            {
                printf("Informações do cliente:\n");
                printf("Nome:%s\n Morada:%s\n Telefone:%d\n Nif: %d\n", clientes.nome, clientes.morada, clientes.telefone, clientes.nif);
                clienteEncontrado = 1;
                int escolha2;
                printf("\n---------------------------------------------------------------------------------------------\n");
                printf("Pretende procurar mais algum cliente?\n");
                printf("1- Sim\n");
                printf("2- Não\n");
                printf("R:");
                scanf("%d", &escolha2);

                if (escolha2 == 1)
                {
                    pesquisar_cliente();
                }
                else
                {
                    break;
                }
            }
        }
    }
    else if (geral == 2)
    {
        printf("Você escolheu a Opção 2.\n");
        printf("Introduza o Telemovel:\n");
        scanf("%d", &geral);
        while (fgets(line, sizeof(line), dados))
        {
            sscanf(line, "Nome: %[^\n]", clientes.nome);
            sscanf(line, "Morada: %[^\n]", clientes.morada);
            sscanf(line, "Telefone: %d", &clientes.telefone);
            sscanf(line, "Nif: %d", &clientes.nif);

            if (geral == clientes.telefone)
            {
                printf("\n---------------------------------------------------------------------------------------------\n");
                printf("Informações do cliente:\n");
                printf("Nome:%s\n Morada:%s\n Telefone:%d\n Nif: %d\n", clientes.nome, clientes.morada, clientes.telefone, clientes.nif);
                clienteEncontrado = 1;
                int escolha2;
                printf("\n---------------------------------------------------------------------------------------------\n");
                printf("Pretende procurar mais algum cliente?\n");
                printf("1- Sim\n");
                printf("2- Não\n");
                printf("R:");
                scanf("%d", &escolha2);

                if (escolha2 == 1)
                {
                    pesquisar_cliente();
                }
                else
                {

                    break;
                }
            }
        }
    }

    if (!clienteEncontrado)
    {

        printf("\n---------------------------------------------------------------------------------------------\n");
        printf("\nNIF inserido não encontrado: %d\n", nif_client);

        int escolha;
        printf("\n---------------------------------------------------------------------------------------------\n");
        printf("Pretende introduzir mais algum cliente?\n");
        printf("1- Sim\n");
        printf("2- Não\n");
        printf("R:");
        scanf("%d", &escolha);

        if (escolha == 1)
        {
            pesquisar_cliente();
        }
        else
        {
            printf("Close");
        }

        fclose(dados);
    }
}
void pesquisar_produto()
{
}

void alterar_cliente()
{
}

void alterar_produto()
{
}

void apagar_cliente()
{
}

void apagar_produtos()
{
}

void inserir_venda_preco()
{
}

void historico_cliente()
{
}

int main()
{ // Menu e todas as opções

    int esc;

    do
    {

        printf("---------------------------------------------------------------------------------------------\n");
        printf("* Gestão de Loja *\n");
        printf("---------------------------------------------------------------------------------------------\n");

        printf("1- Inserir cliente\t\t");

        printf("2- Inserir produto\t\t");

        printf("3 - Pesquisar cliente\n");

        printf("4- Pesquisar produto\t\t");

        printf("5- Alterar cliente\t\t");

        printf("6- Alterar produto\n");

        printf("7- Apagar cliente\t\t");

        printf("8- Apagar produtos\t\t");

        printf("9- Inserir venda\n");

        printf("10- Histórico de compras\t");

        printf("0- Fechar o programa\n");

        printf("---------------------------------------------------------------------------------------------\n");

        printf("Digite a sua opção:");
        scanf("%d", &esc);

        switch (esc)
        {
        case 1:
            inserir_cliente();
            break;
        case 2:
            inserir_produto();
            break;
        case 3:
            pesquisar_cliente();
            break;
        }

    } while (esc != 0);

    printf("* Saiu do programa *");
}