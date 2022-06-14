#include <stdio.h>
#include <string.h>
#include <locale.h>


FILE *fp;
FILE *fpmod;
//estrutura de dados
struct dados{
char nome[30];
char endereco[30];
int anonasc;
char cpf[12];
char cel[10];
char email[50];
}d1;

struct dadosmod{
char nome[30];
char endereco[30];
int anonasc;
char cpf[12];
char cel[10];
char email[50];
}dmod;

//para receber os dados
void cadastro(){

{
    setlocale(LC_ALL, "");

    fflush(stdin);
    printf("\nDigite o nome:");
    gets(d1.nome);

    printf("\nDigite o endereço:");
    gets(d1.endereco);

    printf("\nDigite o ano que nasceu:");
    fflush(stdin);
    scanf("%i", &d1.anonasc);

    printf("\nDigite o cpf:");
    fflush(stdin);
    gets(d1.cpf);

    printf("\nDigite o número de celular:");
    gets(d1.cel);

    printf("\nDigite o e-mail:");
    gets(d1.email);
}
{
    //escrevendo os dados dentro do arquivo
    fp=fopen("arquivo.txt","ab+");//ab+ permite que eu n escreva dados 1 por 1 sem apagar o anterior
    fwrite(&d1, sizeof(struct dados),1, fp);
    fclose(fp);
    getch();

    menu();
}
};

void pnome(){

     setlocale(LC_ALL, "");

     int a=0;
     char nome[30];

     fflush(stdin);
     printf("\nDigite o nome:");
     gets(nome);

{
    fp=fopen("arquivo.txt", "rb");

    while(fread(&d1,sizeof(d1),1,fp)==1){
            if(strcmp(d1.nome,nome)==0){
            a++;
            printf("\nCadastro encontrado!");

            printf("\nNome: %s", d1.nome);
            printf("\nEndereço: %s", d1.endereco);
            printf("\nNacimento: %i", &d1.anonasc);
            printf("\nCPF: %s", d1.cpf);
            printf("\nCel: %s", d1.cel);
            printf("\nE-mail: %s", d1.email);
            }
    }
    if(a==0){
        printf("\nDesculpe, cadastro não encontrado.");
        getchar();
    }
    fclose(fp);

    menu();;
}
};

void pendereco(){

     setlocale(LC_ALL, "");

     int b=0;
     char endereco[30];

     fflush(stdin);
     printf("\nDigite o endereço:");
     gets(endereco);

{
    fp=fopen("arquivo.txt", "rb");

    while(fread(&d1,sizeof(d1),1,fp)==1){
            if(strcmp(d1.endereco, endereco)==0){
            b++;
            printf("\nCadastro encontrado!");

            printf("\nNome: %s", d1.nome);
            printf("\nEndereço: %s", d1.endereco);
            printf("\nNacimento: %i", &d1.anonasc);
            printf("\nCPF: %s", d1.cpf);
            printf("\nCel: %s", d1.cel);
            printf("\nE-mail: %s", d1.email);
            }
    }
    if(b==0){
        printf("\nDesculpe, cadastro não encontrado.");
        getchar();
    }
    fclose(fp);

    menu();
}
};

void pnascimento(){

     setlocale(LC_ALL, "");

     int c=0;
     int ano;

     fflush(stdin);
     printf("\nDigite o nascimento:");
     scanf("%i", &ano);

{
    fp=fopen("arquivo.txt", "rb");

    while(fread(&d1,sizeof(d1),1,fp)==1){
            if(strcmp(d1.anonasc, &ano)==0){
            c++;
            printf("\nCadastro encontrado!");

            printf("\nNome: %s", d1.nome);
            printf("\nEndereço: %s", d1.endereco);
            printf("\nNacimento: %i", &d1.anonasc);
            printf("\nCPF: %s", d1.cpf);
            printf("\nCel: %s", d1.cel);
            printf("\nE-mail: %s", d1.email);
            }
    }
    if(c==0){
        printf("\nDesculpe, cadastro não encontrado.");
        getchar();
    }
    fclose(fp);

    menu();;
}
};

void pcpf(){

     setlocale(LC_ALL, "");

     int d=0;
     char cpf[12];

     fflush(stdin);
     printf("\nDigite o cpf:");
     gets(cpf);

{
    fp=fopen("arquivo.txt", "rb");

    while(fread(&d1,sizeof(d1),1,fp)==1){
            if(strcmp(d1.cpf, cpf)==0){
            d++;
            printf("\nCadastro encontrado!");

            printf("\nNome: %s", d1.nome);
            printf("\nEndereço: %s", d1.endereco);
            printf("\nNacimento: %i", &d1.anonasc);
            printf("\nCPF: %s", d1.cpf);
            printf("\nCel: %s", d1.cel);
            printf("\nE-mail: %s", d1.email);
            }
    }
    if(d==0){
        printf("\nDesculpe, cadastro não encontrado.");
        getchar();
    }
    fclose(fp);

    menu();;
}
};

void pcel(){

     setlocale(LC_ALL, "");

     int e=0;
     char cel[10];

     fflush(stdin);
     printf("\nDigite o n do celular:");
     gets(cel);

{
    fp=fopen("arquivo.txt", "rb");

    while(fread(&d1,sizeof(d1),1,fp)==1){
            if(strcmp(d1.cel, cel)==0){
            e++;
            printf("\nCadastro encontrado!");

            printf("\nNome: %s", d1.nome);
            printf("\nEndereço: %s", d1.endereco);
            printf("\nNacimento: %i", &d1.anonasc);
            printf("\nCPF: %s", d1.cpf);
            printf("\nCel: %s", d1.cel);
            printf("\nE-mail: %s", d1.email);
            }
    }
    if(e==0){
        printf("\nDesculpe, cadastro não encontrado.");
        getchar();
    }
    fclose(fp);

    menu();;
}
};

void pemail(){

     setlocale(LC_ALL, "");

     int e=0;
     char email[50];

     fflush(stdin);
     printf("\nDigite o e-mail:");
     gets(email);

{
    fp=fopen("arquivo.txt", "rb");

    while(fread(&d1,sizeof(d1),1,fp)==1){
            if(strcmp(d1.email, email)==0){
            e++;
            printf("\nCadastro encontrado!");

            printf("\nNome: %s", d1.nome);
            printf("\nEndereço: %s", d1.endereco);
            printf("\nNacimento: %i", &d1.anonasc);
            printf("\nCPF: %s", d1.cpf);
            printf("\nCel: %s", d1.cel);
            printf("\nE-mail: %s", d1.email);
            }
    }
    if(e==0){
        printf("\nDesculpe, cadastro não encontrado.");
        getchar();
    }
    fclose(fp);

    menu();;
}
};

void menu(){
{
    setlocale(LC_ALL, "");
    int opt;

    printf("\n\nDeseja retornar ao menu inicial?");
    printf("\n#1-SIM\n#2-NÃO");
    printf("\nOpção:");
    scanf("%i", &opt);

     switch(opt)
        {

            case 1:
            system("cls");
            main();

            case 2:
            printf("ENCERRANDO...");
            break;
        }

}
};

void edit(){
    setlocale(LC_ALL, "");

     int e=0;
     char nomeedit[30];

     fflush(stdin);
     printf("\nDigite o nome do usuário que deseja editar:");
     gets(nomeedit);

{
    fp=fopen("arquivo.txt", "rb");
    fpmod=fopen("temp.txt", "ab+");

    while(fread(&d1,sizeof(d1),1,fp)==1){
            if(strcmp(d1.nome, nomeedit)==0){
            e++;
            printf("\nCadastro encontrado!");

            printf("\nNome: %s", d1.nome);
            printf("\nEndereço: %s", d1.endereco);
            printf("\nNacimento: %i", &d1.anonasc);
            printf("\nCPF: %s", d1.cpf);
            printf("\nCel: %s", d1.cel);
            printf("\nE-mail: %s", d1.email);

            fflush(stdin);
            printf("\n\nDigite a alteração do nome:");
            gets(dmod.nome);
            printf("\nDigite a alteração do endereço:");
            gets(dmod.endereco);
            fflush(stdin);
            printf("\nDigite a alteração do ano de nascimento:");
            scanf("%i", &dmod.anonasc);
            fflush(stdin);
            printf("\nDigite a alteração do cpf:");
            gets(dmod.cpf);
            printf("\nDigite a alteração do celular:");
            gets(dmod.cel);
            printf("\nDigite a alteração do e-mail:");
            gets(dmod.email);

            fwrite(&dmod, sizeof(struct dadosmod),1, fpmod);
            }
            else if(strcmp(d1.nome, nomeedit)!=0){
                fwrite(&d1, sizeof(struct dados),1, fpmod);
            }
    }
    if(e==0){
        printf("\nDesculpe, cadastro não encontrado.");
        getchar();
    }
    fclose(fp);
    fclose(fpmod);

    remove("arquivo.txt");
    rename("temp.txt", "arquivo.txt");

    menu();;
}
};

void del(){
   setlocale(LC_ALL, "");

     int e=0;
     char nomeedit[30];

     fflush(stdin);
     printf("\nDigite o nome do usuário que deseja editar:");
     gets(nomeedit);

{
    fp=fopen("arquivo.txt", "rb");
    fpmod=fopen("temp.txt", "ab+");

    while(fread(&d1,sizeof(d1),1,fp)==1){
            if(strcmp(d1.nome, nomeedit)==0){
            e++;
            printf("\nCadastro encontrado!");

            printf("\nNome: %s", d1.nome);
            printf("\nEndereço: %s", d1.endereco);
            printf("\nNacimento: %i", &d1.anonasc);
            printf("\nCPF: %s", d1.cpf);
            printf("\nCel: %s", d1.cel);
            printf("\nE-mail: %s", d1.email);

            printf("\nDELETANDO...");
            }
            else if(strcmp(d1.nome, nomeedit)!=0){
                fwrite(&d1, sizeof(struct dados),1, fpmod);
            }
    }
    if(e==0){
        printf("\nDesculpe, cadastro não encontrado.");
        getchar();
    }
    fclose(fp);
    fclose(fpmod);

    remove("arquivo.txt");
    rename("temp.txt", "arquivo.txt");

    menu();;
}
};

int main()
{
    setlocale(LC_ALL, "");

    int op;

    printf("****Opções****");
    printf("\n#1:Cadastrar");
    printf("\n#2:Procurar");
    printf("\n#3:Editar");
    printf("\n#4:Deletar");

    printf("\n\nConforme o número digite qual opção deseja:");
    scanf("%i", &op);

    switch(op){

    case 1:
        cadastro();
        break;
    case 2:
       system("cls");
       {
           int op;
           printf("Ok, deseja pesquisar por:\n#1-Nome\n#2-Endereço\n#3-Nascimento\n#4-CPF\n#5-Celular\n#6-e-mail\n\nDigite a opção:");
           scanf("%i", &op);

           switch(op){

           case 1:
            pnome();
            break;

           case 2:
            pendereco();
            break;

           case 3:
            pnascimento();
            break;

           case 4:
            pcpf();
            break;

           case 5:
            pcel();
            break;

           case 6:
            pemail();
            break;
           }
       }
       break;

    case 3:
        edit();
        break;

    case 4:
        del();
        break;
    }
    return 0;
}
