#include <stdio.h>
#include <locale.h>
#include <string.h>

//Estrutura do banco de dados
typedef struct cadastro
{
    char nome[50];
    char cpf[12];
    char email[50];
    char telefone[10];
    char endereco[50];
    int data[9];
}cad;

//Funçãopara cadastro
void cadastrar()
{
    setlocale(LC_ALL, "");

    //Declaração da Struct
    cad cad;

    fflush(stdin);

    printf("\nNome (Completo): ");
    gets(cad.nome);

    printf("CPF (Formato xxx.xxx.xxx-xx): ");
    gets(cad.cpf);

    printf("E-mail: ");
    gets(cad.email);

    printf("Telefone (Formato (+xx) xx x xxxx-xxxx): ");
    gets(cad.telefone);

    printf("Endereço: (País - Estado - Cidade - Bairro - Rua - Número da Residência): ");
    gets(cad.endereco);

    printf("Data de Nascimento (Formato xx/xx/xxxx): ");
    scanf("%i", &cad.data);

    //Manipulação de Arquivo
    FILE *fp;
    fp=fopen("banco.txt","ab+");
    fwrite(&cad,sizeof(cad),1,fp);

    fclose(fp);

    retorna();
}

//Função para procurar por nome
void procura_nome()
{
    setlocale(LC_ALL, "");
    
    //Declaração da Struct
    cad cad;

    int x=0;
    char nome[40];

    fflush(stdin);

    printf("\nEscreva o nome que deseja pesquisar: ");
    gets(nome);

    //Manipulação do Arquivo
    FILE *fp;
    fp=fopen("banco.txt","rb");
    
    while(fread(&cad,sizeof(cad),1,fp)==1)
        {
            if(strcmp(cad.nome,nome)==0)
            {
                x++;
                    printf("\nNome: %s\n",cad.nome);
                    printf("Cpf: %s\n",cad.cpf);
                    printf("Email: %s\n",cad.email);
                    printf("Telefone: %s\n",cad.telefone);
                    printf("Endereço: %s\n", cad.endereco);
                    printf("Data: %i\n", cad.data);
            }

        }
        
        if(x==0)
            {
                printf("Não encontrado.");
                    getchar();
            }

                    fclose(fp);

                    retorna();

}
//Função para procurar por cpf
void procura_cpf()
{
    setlocale(LC_ALL, "")
    
    //Declaração da Struct
    cad cad;

    int x=0;
    char cpf[12];

    fflush(stdin);

    printf("\nEscreva o cpf que deseja pesquisar: ");
    gets(cpf);

    //Manipulação do Arquivo
    FILE *fp;
    fp=fopen("banco.txt","rb");
    
    while(fread(&cad,sizeof(cad),1,fp)==1)
        {
            if(strcmp(cad.cpf,cpf)==0)
            {
                x++;
                    printf("\nNome: %s\n",cad.nome);
                    printf("Cpf: %s\n",cad.cpf);
                    printf("Email: %s\n",cad.email);
                    printf("Telefone: %s\n",cad.telefone);
                    printf("Endereço: %s\n", cad.endereco);
                    printf("Data: %i\n", cad.data);
            }
        }
            if(x==0)
            {
                printf("Não encontrado.");
                    getchar();
            }

                    fclose(fp);

                    retorna();
}

//Função para procurar por e-mail
void procura_email()
{

    setlocale(LC_ALL, "");

    cad cad;

    int x=0;
    char email[50];

    fflush(stdin);

    printf("\nEscreva o email que deseja pesquisar: ");
    gets(email);

     //Manipulação do Arquivo
    FILE *fp;
    fp=fopen("banco.txt","rb");
    
    while(fread(&cad,sizeof(cad),1,fp)==1)
        {
            if(strcmp(cad.email,email)==0)
            {
                
                x++;
                    printf("\nNome: %s\n",cad.nome);
                    printf("Cpf: %s\n",cad.cpf);
                    printf("Email: %s\n",cad.email);
                    printf("Telefone: %s\n",cad.telefone);
                    printf("Endereço: %s\n", cad.endereco);
                    printf("Data: %i\n", cad.data);
            }

        }
            if(x==0)
            {
                printf("Não encontrado.");
                    getchar();
            }

                fclose(fp);

                retorna();
}

//Função para procurar por telefone
void procura_telefone()
{

    setlocale(LC_ALL, "");
    
    //Declaração da Struct
    cad cad;

    int x=0;
    char telefone[10];

    fflush(stdin);

    printf("\nEscreva o telefone que deseja pesquisar: ");
    gets(telefone);

    //Manipulação do Arquivo
    FILE *fp;
    fp=fopen("banco.txt","rb");
    
    while(fread(&cad,sizeof(cad),1,fp)==1)
        {
        if(strcmp(cad.telefone,telefone)==0)
        {
            x++;
                printf("\nNome: %s\n",cad.nome);
                printf("Cpf: %s\n",cad.cpf);
                printf("Email: %s\n",cad.email);
                printf("Telefone: %s\n",cad.telefone);
                printf("Endereço: %s\n", cad.endereco);
                printf("Data: %i\n", cad.data);
        }

        }
            if(x==0)
            {
                printf("Não encontrado.");
                    getchar();
            }   

                fclose(fp);

                retorna();
}

//Função para procurar por endereço
void procura_endereco()
{

    setlocale(LC_ALL, "");

    //Declaração da Struct
    cad cad;

    int x=0;
    char endereco[50];

    fflush(stdin);

    printf("\nEscreva o endereco que deseja pesquisar: ");
    gets(endereco);

    //Manipulação do Arquivo
    FILE *fp;
    fp=fopen("banco.txt","rb");
    
    while(fread(&cad,sizeof(cad),1,fp)==1)
        {
            if(strcmp(cad.endereco,endereco)==0)
            {
                x++;
                    printf("\nNome: %s\n",cad.nome);
                    printf("Cpf: %s\n",cad.cpf);
                    printf("Email: %s\n",cad.email);
                    printf("Telefone: %s\n",cad.telefone);
                    printf("Endereço: %s\n", cad.endereco);
                    printf("Data: %i\n", cad.data);
            }

        }
            if(x==0)
            {
                printf("Não encontrado.");
                    getchar();
            }

                fclose(fp);

                retorna();
}

/*
void exclui(){

    setlocale(LC_ALL, "");

    cad cad;

    int x=0;
    char endereco[50];

    fflush(stdin);

    printf("\nO que você deseja excluir?:\n");
    gets();

    FILE *fp;
    fp=fopen("banco.txt","rb");
    while(fread(&cad,sizeof(cad),1,fp)==1){
        if(strcmp(cad.endereco,endereco)==0){
            x++;
            printf("\nNome: %s\n",cad.nome);
            printf("Cpf: %s\n",cad.cpf);
            printf("Email: %s\n",cad.email);
            printf("Telefone: %s\n",cad.telefone);
            printf("Endereço: %s\n", cad.endereco);
            printf("Data: %i\n", cad.data);
        }

    }
        if(x==0){
            printf("Não encontrado.");
            getchar();
        }

    fclose(fp);

}
*/

//Função para procurar para retornar à tela de seleção
void retorna()
{
    
    setlocale(LC_ALL, "");
    char option;

    fflush(stdin);
    printf("\n\nDeseja fazer algo a mais?(Digite s para SIM e n para NÃO)");
    scanf("%c", &option);

        switch(option)
        {

            case 's':
            system("cls");
            main();

            case 'n':
            printf("encerrando.");
            break;
        }
}

//Tela de seleção e operação
int main()
{
    setlocale(LC_ALL, "");
    printf("===========================\n");
    printf("BANCO DE DADOS\n");
    printf("===========================\n");
    printf("1 - Cadastrar Usuário\n");
    printf("2 - Procurar por Nome\n");
    printf("3 - Procurar por CPF\n");
    printf("4 - Procurar por E-MAIL\n");
    printf("5 - Procurar por Telefone\n");
    printf("6 - Procurar por Endereço\n");
    printf("7 - Excluir Usuário\n");
    printf("8 - Encerar Processo\n");
    printf("===========================\n");
    printf("NÚMERO SELECIONADO: ");


    int a;
    scanf("%i", &a);

    switch(a)
    {

    case 1:
    cadastrar();
    break;


    case 2:
    procura_nome();
    break;

    case 3:
    procura_cpf();
    break;

    case 4:
    procura_email();
    break;

    case 5:
    procura_telefone();
    break;

    case 6:
    procura_endereco();
    break;

    case 7:

    case 8:
        printf("\nencerrado.");
    break;

    }
}
