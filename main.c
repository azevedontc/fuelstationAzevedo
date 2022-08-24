#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "function.h"
#include "header.h"

// último código

int main()
{
    // variáveis gerais
    int quant = 0, tam = 0;
    int opcao, opcaoC = 0, i = 0;
    // cálculo dos combustíveis
    int valorG = 0, valorGA = 0, valorE = 0;
    // quantidade em litros dos combustíveis
    float valorGtotal, valorGAtotal, valorEtotal;
    // valores dos combustíveis
    float gasolina, aditivada, etanol;
    // variáveis relatórios
    int opcaoR = 0, opcaoRL = 0, opcaoRV = 0, atendidos = 0;
    float totalLitroG = 0, totalLitroGA = 0, totalLitroE = 0;
    // litros vendidos
    float aux1G = 0, aux1GA = 0, aux1E = 0;
    // valor arrecadado
    int auxG = 0, auxGA = 0, auxE = 0, totalVendG = 0, totalVendGA = 0, totalVendE = 0;
    // tanques
    int tanqueG = 200, tanqueGA = 200, tanqueE = 200;
    //------------------------------
    //------------------------------
    gasolina = otimiza("GasolinaComum");
    aditivada = otimiza("GasolinaAditivada");
    etanol = otimiza("Etanol");
    tam = otimiza("Fila");
    valida(gasolina, "Gasolina Comum");
    valida(aditivada, "Gasolina Aditivada");
    valida(etanol, "Etanol");
    valida(tam, "Fila");
    //------------------------------
    //------------------------------
    // introdução posto
    printf(C_GREEN "\n Seja bem-vindo ao Posto Azevedo !" C_RESET);
    // fila
    /*printf("\n\n Qual tamanho da fila de carros?: ");
    scanf("%d", &tam);
    // preço combustível
    printf("\n\n Informe os valores do combustivel: ");
    //------------------------------
    printf("\n\n Gasolina: ");
    scanf("%f", &gasolina);
    if (gasolina <= 0)
    {
        printf("\n Escolha um valor acima de 0 !\n");
        printf("\n Informe o valor da gasolina: ");
        scanf("%f", &gasolina);
    }
    printf("\n\n Preco adicionado com sucesso !");
    //------------------------------
    printf("\n\n Gasolina Aditivada: ");
    scanf("%f", &aditivada);
    if (aditivada <= 0)
    {
        printf("\n Escolha um valor acima de 0 !\n");
        printf("\n Informe o valor da gasolina aditivada: ");
        scanf("%f", &aditivada);
    }
    printf("\n\n Preco adicionado com sucesso !");
    //------------------------------
    printf("\n\n Etanol: ");
    scanf("%f", &etanol);
    if (etanol <= 0)
    {
        printf("\n Escolha um valor acima de 0 !\n");
        printf("\n Informe o valor do etanol: ");
        scanf("%f", &etanol);
    }
    printf("\n\n Preco adicionado com sucesso !\n\n");*/
    // menu
    printf(C_BLUE "\n\n 1 - Adicionar um carro na fila\n" C_RESET);
    printf(C_BLUE "\n 2 - Abastecimento\n" C_RESET);
    printf(C_BLUE "\n 3 - Chamar o próximo\n" C_RESET);
    printf(C_BLUE "\n 4 - Relatórios\n" C_RESET);
    printf(C_BLUE "\n 5 - Carro atual da fila\n" C_RESET);
    printf(C_BLUE "\n 6 - Todos os carros da fila\n" C_RESET);
    printf(C_BLUE "\n 7 - Encerrar\n" C_RESET);
    scanf("%d", &opcao);
    struct MCarro *carro1;
    carro1 = (struct MCarro *)malloc(tam * sizeof(struct MCarro));
    while (opcao != 7)
    {
        switch (opcao)
        {
        case 1:
            if (quant < tam)
            {
                limpaBuffer();
                printf("\nDigite o modelo do carro: ");
                lerString(carro1[quant].modelo, 30);
                printf("Digite a marca do carro: ");
                lerString(carro1[quant].marca, 30);
                printf("Digite o ano do carro: ");
                scanf("%d", &carro1[quant].ano);
                printf("Tamanho do tanque do carro em litros: ");
                scanf("%d", &carro1[quant].tanque);
                printf(C_RED "\n Dados do carro:\n" C_RESET);
                printf("\n Modelo: %s \n", carro1[quant].modelo);
                printf(" Marca: %s \n", carro1[quant].marca);
                printf(" Ano: %d \n", carro1[quant].ano);
                printf(" Tanque: %d litros \n", carro1[quant].tanque);
            }
            quant = op1(quant, tam);
            break;
        case 2:
            if (quant > 0)
            {
                printf(C_RED "\n Abastecimento\n" C_RESET);
                printf(C_RED "\n Escolha seu combustível\n" C_RESET);
                printf(C_BLUE "\n 1 - Gasolina \n" C_RESET);
                printf(C_BLUE "\n 2 - Gas. Aditivada \n" C_RESET);
                printf(C_BLUE "\n 3 - Etanol \n" C_RESET);
                scanf("%d", &opcaoC);
                switch (opcaoC)
                {
                // abastecimento das bombas
                case 1:
                    printf("\n Qual valor você deseja abastecer ?: ");
                    scanf("%d", &valorG);
                    if (valorG <= 0)
                    {
                        printf("\n Escolha um valor acima de 0 !\n");
                        printf("\n Qual valor você deseja abastecer ?: ");
                        scanf("%d", &valorG);
                    }
                    valorGtotal = valorG / gasolina;
                    // total de litros
                    aux1G = valorGtotal;
                    totalLitroG = totalLitroG + aux1G;
                    // valor arrecadado relatórios
                    auxG = valorG;
                    totalVendG = totalVendG + auxG;
                    if (valorGtotal > 200)
                    {
                        printf("\n O posto só abastece até 200 litros, escolha outra quantia.\n");
                        printf("\n Qual valor você deseja abastecer ?: ");
                        scanf("%d", &valorG);
                        valorGtotal = valorG / gasolina;
                    }
                    printf("\n Vamos abastecer: %.2f litros\n", valorGtotal);
                    // tanque
                    tanqueG = tanqueG - valorGtotal;
                    if (tanqueG <= 0)
                    {
                        printf("\n Não há combustível suficiente ! %d\n", tanqueG);
                    }
                    break;
                case 2:
                    printf("\n Qual valor você deseja abastecer ?: ");
                    scanf("%d", &valorGA);
                    if (valorGA <= 0)
                    {
                        printf("\n Escolha um valor acima de 0 !\n");
                        printf("\n Qual valor você deseja abastecer ?: ");
                        scanf("%d", &valorGA);
                    }
                    valorGAtotal = valorGA / aditivada;
                    // total de litros
                    aux1GA = valorGAtotal;
                    totalLitroGA = totalLitroGA + aux1GA;
                    // valor arrecadado relatórios
                    auxGA = valorGA;
                    totalVendGA = totalVendGA + auxGA;
                    if (valorGAtotal > 200)
                    {
                        printf("\n O posto só abastece até 200 litros, escolha outra quantia.\n");
                        printf("\n Qual valor você deseja abastecer ?: ");
                        scanf("%d", &valorGA);
                        valorGtotal = valorGA / aditivada;
                    }
                    printf("\n Vamos abastecer: %.2f litros\n", valorGAtotal);
                    // tanque
                    tanqueGA = tanqueGA - valorGAtotal;
                    if (tanqueGA <= 0)
                    {
                        printf("\n Não há combustível suficiente ! %d\n", tanqueGA);
                    }
                    break;
                case 3:
                    printf("\n Qual valor você deseja abastecer ?: ");
                    scanf("%d", &valorE);
                    if (valorE <= 0)
                    {
                        printf("\n Escolha um valor acima de 0 !\n");
                        printf("\n Qual valor você deseja abastecer ?: ");
                        scanf("%d", &valorE);
                    }
                    valorEtotal = valorE / etanol;
                    // total de litros
                    aux1E = valorEtotal;
                    totalLitroE = totalLitroE + aux1E;
                    // valor arrecadado relatórios
                    auxE = valorE;
                    totalVendE = totalVendE + auxE;
                    if (valorEtotal > 200)
                    {
                        printf("\n O posto só abastece até 200 litros, escolha outra quantia.\n");
                        printf("\n Qual valor você deseja abastecer ?: ");
                        scanf("%d", &valorE);
                        valorEtotal = valorE / etanol;
                    }
                    printf("\n Vamos abastecer: %.2f litros\n", valorEtotal);
                    // tanque
                    tanqueE = tanqueE - valorEtotal;
                    if (tanqueE <= 0)
                    {
                        printf("\n Não há combustível suficiente ! %d\n", tanqueE);
                    }
                    break;
                    /*default:
                        printf("Voce deve escolher uma opcao valida\n");
                        printf("Pressione qualquer tecla para voltar ao menu\n");
                        break;*/
                }
            }
            else
            {
                printf("\n Não tem carro na fila para abastecer !\n");
            }
            break;
        case 3:
            limpaBuffer();
            if (quant > 0)
            {
                atendidos++;
                printf(C_RED "\n Carro fora da fila\n" C_RESET);
                printf("\n Modelo do carro que foi removido: %s \n", carro1[0].modelo);
                printf(" Marca do carro que foi removido: %s \n", carro1[0].marca);
                printf(" Ano do carro que foi removido: %d \n", carro1[0].ano);
                printf(" Tamanho do tanque do carro que foi removido: %d \n", carro1[0].tanque);
                for (int i = 0; i < quant; i++)
                {
                    carro1[i] = carro1[i + 1];
                }
            }
            // função op3
            quant = op3(quant, tam);
            break;
        case 4:
            // while dentro do relatório
            while (opcaoR != 5)
            {
                // menu relatórios
                printf(C_RED "\n Relatórios\n" C_RESET);
                printf(C_BLUE "\n 1 - Quantidade de litros vendida (por tipo de combustível)\n" C_RESET);
                printf(C_BLUE "\n 2 - Total arrecadado com as vendas (por combustível)\n" C_RESET);
                printf(C_BLUE "\n 3 - Quantidade de carros atendidos\n" C_RESET);
                printf(C_BLUE "\n 4 - Quantidade de combustível restante em cada tanque\n" C_RESET);
                printf(C_BLUE "\n 5 - Sair de Relatórios\n" C_RESET);
                scanf("%d", &opcaoR);
                // escolha do relatório
                switch (opcaoR)
                {
                case 1:
                    printf(C_RED "\n\n Quantidade de litros vendida (por tipo de combustível)\n" C_RESET);
                    printf(C_BLUE "\n 1 - Gasolina \n" C_RESET);
                    printf(C_BLUE "\n 2 - Gas. Aditivada \n" C_RESET);
                    printf(C_BLUE "\n 3 - Etanol \n" C_RESET);
                    printf(C_BLUE "\n 4 - Sair \n" C_RESET);
                    scanf("%d", &opcaoRL);
                    // litros de todos combustíveis
                    while (opcaoRL != 4)
                    {
                        switch (opcaoRL)
                        {
                        case 1:
                            printf("\n Gasolina vendeu um total de %.2f litros \n", totalLitroG);
                            break;
                        case 2:
                            printf("\n Gasolina Adit. vendeu um total de %.2f litros \n", totalLitroGA);
                            break;
                        case 3:
                            printf("\n Etanol vendeu um total de %.2f litros \n", totalLitroE);
                            break;
                        case 4:
                            printf("\n Você pediu para sair. \n");
                            break;
                        }
                        printf("\n\n Quantidade de litros vendida (por tipo de combustível)\n");
                        printf("\n 1 - Gasolina \n");
                        printf("\n 2 - Gas. Aditivada \n");
                        printf("\n 3 - Etanol \n");
                        printf("\n 4 - Sair \n");
                        scanf("%d", &opcaoRL);
                    }
                    break;
                case 2:
                    printf(C_RED "\n Total arrecadado com as vendas (por tipo de combustível)\n" C_RESET);
                    printf(C_BLUE "\n 1 - Gasolina \n" C_RESET);
                    printf(C_BLUE "\n 2 - Gas. Aditivada \n" C_RESET);
                    printf(C_BLUE "\n 3 - Etanol \n" C_RESET);
                    printf(C_BLUE "\n 4 - Sair \n" C_RESET);
                    scanf("%d", &opcaoRV);
                    // lucros de todos combustíveis
                    while (opcaoRV != 4)
                    {
                        switch (opcaoRV)
                        {
                        case 1:
                            printf("\n Gasolina vendeu um total de R$%d reais \n", totalVendG);
                            break;
                        case 2:
                            printf("\n Gasolina Adit. vendeu um total de R$%d reais \n", totalVendGA);
                            break;
                        case 3:
                            printf("\n Etanol vendeu um total de R$%d reais \n", totalVendE);
                            break;
                        case 4:
                            printf("\n Você pediu para sair.\n");
                            break;
                        }
                        printf(C_RED "\n Total arrecadado com as vendas (por tipo de combustível)\n" C_RESET);
                        printf(C_BLUE "\n 1 - Gasolina \n" C_RESET);
                        printf(C_BLUE "\n 2 - Gas. Aditivada \n" C_RESET);
                        printf(C_BLUE "\n 3 - Etanol \n" C_RESET);
                        printf(C_BLUE "\n 4 - Sair \n" C_RESET);
                        scanf("%d", &opcaoRV);
                    }
                    break;
                case 3:
                    printf("\n Quantidade de carros atendidos é igual a: %d \n", atendidos);
                    break;
                case 4:
                    printf(C_RED "\n Quantidade de combustíveis restante em cada tanque\n" C_RESET);
                    printf(C_BLUE "\n Quantidade de combustível restante de Gasolina: " C_RESET);
                    printf("%d litros\n", tanqueG);
                    printf(C_BLUE "\n Quantidade de combustível restante de Gasolina Adit.: " C_RESET);
                    printf("%d litros\n", tanqueGA);
                    printf(C_BLUE "\n Quantidade de combustível restante de Etanol: " C_RESET);
                    printf("%d litros\n", tanqueE);
                    break;
                case 5:
                    printf("\n Sair de relatórios \n");
                    break;
                }
                break;
            }
            break;
        case 5:
            printf(C_RED "\n Carro atual da fila\n" C_RESET);
            printf("\n Modelo do carro: %s", carro1[0].modelo);
            printf("\n Marca do carro: %s", carro1[0].marca);
            printf("\n Ano do carro: %d", carro1[0].ano);
            printf("\n Tamanho do tanque: %d", carro1[0].tanque);
            break;
        case 6:
            if (quant > 0)
            {
                i = 0;
                printf(C_RED "\n Carros da fila:\n" C_RESET);
                while (quant > i)
                {
                    printf("\n Modelo do carro: %s", carro1[i].modelo);
                    printf("\n Marca do carro: %s", carro1[i].marca);
                    printf("\n Ano do carro: %d", carro1[i].ano);
                    printf("\n Tamanho do tanque: %d\n", carro1[i].tanque);
                    i++;
                }
                i = 0;
            }
            else
            {
                printf("\n Não há carros na fila\n");
            }
            break;
        case 7:
            printf("\n Você pediu para sair.\n");
            break;
        default:
            printf("\n Você deve escolher uma opção válida\n");
            printf("Pressione qualquer tecla para voltar ao menu\n");
        }
        printf(C_BLUE "\n\n 1 - Adicionar um carro na fila\n" C_RESET);
        printf(C_BLUE "\n 2 - Abastecimento\n" C_RESET);
        printf(C_BLUE "\n 3 - Chamar o próximo\n" C_RESET);
        printf(C_BLUE "\n 4 - Relatórios\n" C_RESET);
        printf(C_BLUE "\n 5 - Carro atual da fila\n" C_RESET);
        printf(C_BLUE "\n 6 - Todos os carros da fila\n" C_RESET);
        printf(C_BLUE "\n 7 - Encerrar\n" C_RESET);
        scanf("%d", &opcao);
    }

    printf(C_GREEN "\n Posto Azevedo agradece sua preferência !" C_RESET);

    return 0;
}
