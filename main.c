#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL,"portuguese");//definindo portugu�s como a lingua

    //Criar um switch para separar os pap�is
    //Criar um switch para cada, gestorUniesp,Engenheiro,Mestre,Fornecedor
    char nova_obra, mensagem[100],finalizar_compra,nova_obra_eng;
    float custo_materiais, custo_materiais2,custo_funcionarios,total_funcionarios,total_materiais;
    float custo_total,custo_compra = 0,compras_realizadas[100];
    int papeis, menu_Gestor, Menu_Engenheiro, Menu_Mestre,i = 0, j = 0,Menu_Fornecedor,num_funcionarios = 0;
    int novas_obras = 0,solicitar_obra = 0,solicitar_compra = 0,nova_compra_int = 0, k = 0;
    char nova_compra,confirmar_compra,especialidade[100],fornecedor1[50],fornecedor2[50],fornecedor3[50];
    float valor_fornecedor1 = 0,valor_fornecedor2 = 0,valor_fornecedor3 = 0,valor_fornecedor_total = 0;
    int selecionar_fornecedor,recebimento_compra = 0;

    do
    {
        printf("\nDigite o numero que se pede no menu para selecionar um dos papeis abaixo\n");
        printf("1: Gestor UNIESP\n");
        printf("2: Engenheiro\n");
        printf("3: Mestre de Obra\n");
        printf("4: fornecedores\n");
        printf("0: Sair\n");

        scanf("%d",&papeis);

        system("cls");

        switch(papeis)
        {
        case 1:
            {
                printf("\nSelecione uma opcoes que o Gestor UNIESP deseja realizar\n");
                printf("1: Solicitar Nova Obra\n");
                printf("2: Verificar custo da obra(Quanto ja gastou com material e funcionarios)\n");
                printf("3: Verificar historico da obra\n");
                printf("0: Voltar ao menu inicial\n");

                scanf("%d",&menu_Gestor);
                switch(menu_Gestor)
                {
                    case 1:
                        {
                            getchar();//evitar buffer;
                            printf("\nDeseja solicitar uma nova obra?(pressione s para sim)\n");
                            scanf("%c",&nova_obra);

                            nova_obra = toupper(nova_obra);

                            system("cls");//para n�o deixar a tela poluida

                            if(nova_obra == 'S')
                            {
                                printf("\nUma nova obra foi solicitada\n\n");
                                solicitar_obra++;

                            }
                            else
                            {
                                printf("\nUma nova obra nao foi solicitada\n\n");
                            }
                            break;

                    case 2:
                        {
                            system("cls");//para n�o deixar a tela poluida

                            printf("\nO custo total da obra foi de %.2f R$\n\n",custo_total);
                            break;
                        }
                    case 3:
                        {
                            system("cls");//para n�o deixar a tela poluida

                            printf("\nHistorico da obra:\n");
                            printf("Gasto com funcionarios: %.1f R$\n",total_funcionarios);
                            printf("Gasto com materiais: %.1f R$\n",custo_materiais2);
                            printf("Total de confirmacoes no recebimento das compras: %d\n",recebimento_compra);
                            printf("Gasto com fornecedores: %.1f R$\n",valor_fornecedor_total);
                            printf("Mensagem de acompanhamento: %s\n\n",mensagem);
                            break;
                        }
                    case 0:
                        {
                            system("cls");//para n�o deixar a tela poluida

                            printf("\n");
                            break;
                        }
                    default:
                        system("cls");//para n�o deixar a tela poluida

                        printf("\nInsira os valores corretamente\n\n");
                        break;
                    }
                }
                 break;

            }
            case 2:
                {
                    printf("\nSelecione uma das opcoes para o Engenheiro:\n");
                    printf("1: Iniciar Obra\n");
                    printf("2: Contratar funcionarios\n");
                    printf("3: Verificiar o custo da obra(Quanto ja gastou com material e funcionarios)\n");
                    printf("4: Selecionar fornecedor e finalizar compra\n");
                    printf("5: Adicionar mensagem no historico de acompanhamento da obra\n");
                    printf("0: Voltar ao menu inicial\n");

                    scanf("%d",&Menu_Engenheiro);

                    switch(Menu_Engenheiro)
                {
                case 1:
                    {
                        getchar();
                        printf("O total de obras solicitadas foi de %d\n",solicitar_obra);
                        printf("Deseja iniciar uma nova obra?(Digite S para sim)\n");

                        scanf("%c",&nova_obra_eng);

                        nova_obra_eng = toupper(nova_obra_eng);

                        system("cls");//para n�o deixar a tela poluida

                            if(nova_obra_eng == 'S')
                            {
                                printf("\nUma nova obra foi iniciada\n\n");

                                solicitar_obra = 0;

                                novas_obras++;
                            }
                            else
                            {
                                printf("Uma nova obra nao foi iniciada\n\n");
                            }

                        break;
                    }
                case 2:
                    {
                        printf("Digite o salario do funcionario contratado: \n");

                        scanf("%f",&custo_funcionarios);

                        custo_total += custo_funcionarios;
                        total_funcionarios += custo_funcionarios;

                        system("cls");//para n�o deixar a tela poluida

                        printf("O funcionario foi contratado com sucesso, e o gasto ja esta contabilizado no custo total da obra\n\n");

                        num_funcionarios++;



                        break;
                    }
                case 3:
                    {
                        system("cls");//para n�o deixar a tela poluida

                        custo_total = custo_funcionarios + valor_fornecedor_total;
                        printf("\nO custo total da obra foi de %.2f R$\n\n",custo_total);
                        break;
                    }
                case 4:
                    {
                        getchar();
                        if (valor_fornecedor1 != 0 || valor_fornecedor2 != 0 || valor_fornecedor3 != 0)
                        {


                        printf("\nSelecione comprar do fornecedor desejado conforme o menu abaixo: \n");
                        printf("1: Fornecedor: %s \t Cotacao: %.2f R$\n",fornecedor1,valor_fornecedor1);
                        printf("2: Fornecedor: %s \t Cotacao: %.2f R$\n",fornecedor2,valor_fornecedor2);
                        printf("3: Fornecedor: %s \t Cotacao: %.2f R$\n",fornecedor3,valor_fornecedor3);

                        scanf("%d",&selecionar_fornecedor);

                        switch(selecionar_fornecedor)
                        {
                        case 1:
                            {

                            getchar();

                            printf("A compra ficou com um preco total de %.2f R$, deseja finalizar?(Digite S para sim)\n",valor_fornecedor1);
                            scanf("%c",&finalizar_compra);

                            finalizar_compra = tolower(finalizar_compra);

                            system("cls");//para n�o deixar a tela poluida

                            if(finalizar_compra == 's')
                            {
                                printf("A compra foi finalizada com sucesso\n\n");
                                custo_total = custo_funcionarios + valor_fornecedor1 + custo_materiais2;

                                valor_fornecedor_total = valor_fornecedor1;
                            }
                            else
                                printf("A compra nao foi finalizada\n\n");
                            break;
                                }
                        case 2:
                            {

                            getchar();

                            printf("A compra ficou com um preco total de %.2f R$, deseja finalizar?(Digite S para sim)\n",valor_fornecedor2);
                            scanf("%c",&finalizar_compra);

                            finalizar_compra = tolower(finalizar_compra);

                            system("cls");//para n�o deixar a tela poluida

                            if(finalizar_compra == 's')
                            {
                                printf("A compra foi finalizada com sucesso\n\n");

                                custo_total = custo_funcionarios + valor_fornecedor2 + custo_materiais2;

                                valor_fornecedor_total = valor_fornecedor2;
                            }
                            else
                                printf("A compra nao foi finalizada\n\n");
                            break;
                            }
                        case 3:
                            {

                            getchar();

                            printf("A compra ficou com um preco total de %.2f R$, deseja finalizar?(Digite S para sim)\n",valor_fornecedor3);
                            scanf("%c",&finalizar_compra);

                            finalizar_compra = tolower(finalizar_compra);

                            system("cls");//para n�o deixar a tela poluida

                            if(finalizar_compra == 's')
                            {
                                printf("A compra foi finalizada com sucesso\n\n");

                                custo_total = custo_funcionarios + valor_fornecedor3 + custo_materiais2;

                                valor_fornecedor_total = valor_fornecedor3;
                            }
                            else
                                printf("A compra nao foi finalizada\n\n");
                            break;
                            }
                            }
                        }
                        else
                        {
                            system("cls");

                            printf("Nenhum fornecedor foi cadastrado ate o momento\n");
                        }

                        break;
                    }
                case 5:
                    {
                        printf("Digite uma mensagem para o historico de acompanhamento de obra: ");

                        getchar();//evitar buffer

                        gets(mensagem);

                        system("cls");//para n�o deixar a tela poluida

                        printf("A mensagem foi salva no historico com sucesso\n");

                        break;
                    }
                case 0:
                    {
                        system("cls");//para n�o deixar a tela poluida

                        printf("\n");
                        break;
                    }
                default:
                    system("cls");//para n�o deixar a tela poluida

                    printf("Insira os valores corretamente\n\n");
                    break;
                }
                break;
                }
            case 3:
                {
                    printf("\nSelecione uma das opcoes do menu abaixo para o Mestre de Obra: \n");
                    printf("1: Solicitacao de Compra\n");
                    printf("2: Confirmar recebimento de compra\n");
                    printf("3: Listar compras realizadas\n");
                    printf("4: Solicitar novos funcionarios ao Engenheiro(definindo a especialidade)\n");
                    printf("0: Voltar ao menu inicial\n");

                    scanf("%d",&Menu_Mestre);

                    switch(Menu_Mestre)
                    {
                    case 1:
                        {
                            getchar();
                            printf("Deseja solicitar uma nova compra?(Digite S para sim)\n");

                            scanf("%c",&nova_compra);

                            nova_compra = toupper(nova_compra);

                            system("cls");//para n�o deixar a tela poluida

                            if(nova_compra == 'S')
                            {
                                printf("Uma nova compra foi solicitada\n");

                                printf("Digite o valor dessa nova compra: ");
                                scanf("%f",&custo_materiais);

                                nova_compra_int++;

                                custo_materiais2 += custo_materiais;

                                compras_realizadas[i] = custo_materiais;

                                i++;
                            }
                            else
                            {
                                printf("Uma nova compra nao foi solicitada\n");
                            }
                            break;
                        }
                    case 2:
                        {
                            if(nova_compra_int != 0 )
                            {
                                printf("A quantidade de solicitacoes de novas compras realizadas foram de %d\n",nova_compra_int);

                                printf("Com o valor total de %.2f R$\n",custo_materiais2);

                                getchar();

                                printf("Deseja confirmar o recebimento da compra ? (Digite S para sim)\n");
                                scanf("%c",&confirmar_compra);

                                confirmar_compra = toupper(confirmar_compra);

                                system("cls");//para n�o deixar a tela poluida

                                if(confirmar_compra == 'S')
                                {
                                      printf("Recebimento de compra confirmado com suceso\n");

                                      recebimento_compra++;
                                }
                                else
                                {
                                    printf("O recebimento das compras nao foram confirmados\n");
                                }
                            }
                            else
                            {
                                system("cls");//para n�o deixar a tela poluida

                                printf("Nao existe nenhuma solicitacao de compra no momento\n");
                            }
                            break;
                        }
                    case 3:
                        {
                            getchar();
                            printf("Deseja listar as compras realizadas ? (Digite S para sim)");
                            scanf("%c",&confirmar_compra);

                            confirmar_compra = tolower(confirmar_compra);

                            system("cls");//para n�o deixar a tela poluida

                            if (confirmar_compra == 's')
                            {
                                printf("As compras foram listadas com sucesso\n\n");

                                printf("Aqui esta a lista de gasto com as compras:\n");

                                while (compras_realizadas[j] >= 1 ){
                                    printf("%.2f R$\t",compras_realizadas[j]);
                                    j++;
                                }
                                printf("\n");

                            }
                            else
                            {
                                printf("As compras nao foram listadas\n");
                            }
                            break;
                        }
                    case 4:
                        {
                            printf("Digite a especialidade do funcionario que vc deseja solicitar ao Engenheiro: ");
                            scanf("%s",especialidade);
                            k++;

                            getchar();//evitar buffer

                            system("cls");//para n�o deixar a tela poluida

                            printf("A requisicao foi feita com sucesso\n\n");
                            break;
                        }
                    case 0:
                        {
                            system("cls");//para n�o deixar a tela poluida

                            printf("\n");
                            break;
                        }
                    default:

                        system("cls");//para n�o deixar a tela poluida

                        printf("Digite os valores corretamente\n");
                        break;
                    }
                break;

                }
                case 4:
                    {
                        printf("\nSelecione uma das opcoes do menu para os Fornecedores: \n");
                        printf("1: Visualizar os chamados de compra\n");
                        printf("2: Adicionar o valor de tres fornecedores(cotacao)\n");
                        printf("0: Voltar para o menu inicial\n");

                        scanf("%d",&Menu_Fornecedor);

                        switch(Menu_Fornecedor)
                        {
                        case 1:
                            {
                                system("cls");
                                printf("As solicitacoes de compras foram: %d \n",nova_compra_int);
                                break;
                            }
                        case 2:
                            {
                                printf("Digite o nome do primeiro fornecedor: ");
                                scanf("%s",fornecedor1);

                                printf("\nDigite a cotacao desse fornecedor: ");
                                scanf("%f",&valor_fornecedor1);

                                printf("\n\nDigite o nome do segundo fornecedor: ");
                                scanf("%s",fornecedor2);

                                printf("\nDigite a cotacao desse fornecedor: ");
                                scanf("%f",&valor_fornecedor2);

                                printf("\n\nDigite o nome do terceiro fornecedor: ");
                                scanf("%s",fornecedor3);

                                printf("\nDigite a cotacao desse fornecedor: ");
                                scanf("%f",&valor_fornecedor3);

                                system("cls");

                                printf("As cotacoes de cada fornecedor foi salva com sucesso\n\n");

                                break;
                            }
                            case 0:
                                {
                                    system("cls");

                                    printf("\n");

                                    break;
                                }
                            default:

                                system("cls");

                                printf("Entre com os valores corretamente\n");

                                break;
                            }
                            break;

                        }


        }



    }while(papeis != 0);



    return 0;
}
