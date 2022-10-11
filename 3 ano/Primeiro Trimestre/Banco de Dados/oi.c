#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

class Pessoa
{

public:
    string nome;
    string data_nascimento;
    string email;
    string numero_celular;

    short unsigned int idade;

    void GET_CPF();

private:
    string endereco;
    string CPF;

};

void Pessoa::GET_CPF()
    {
        system("cls");

        cout << "Digite seu CPF (sem pontos e tracos): ";
        cin >> CPF;

        while(CPF.size() != 11)
        {
            system("cls");

            cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
            cout << "  SEU CPF ESTA EM UM FORMATO INVALIDO\n";
            cout << "---------------------------------------\n";
            cout << "- esperamos um valor de 11 caracteres -\n";
            cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";

            cout << "\nDigite seu CPF novamente: ";
            cin >> CPF;

        }

    }

void menu ()
{

    char opcao;
    char opcao_2;

    system("cls");

    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
    cout << "    BANCO DE DADOS DOS VERDADEIROS     \n";
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
    cout << "        - O que deseja fazer? -        \n";
    cout << "---------------------------------------\n";
    cout << "1 - Cadastrar usuario\n";
    cout << "2 - Procurar dados do usario\n";
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
    cout << "\n";
    cout << "Opcao escolhida: ";

    cin >> opcao;

    switch (opcao)
    {

        case '1':
        {
            Pessoa *roberto = new Pessoa();
            roberto->GET_CPF();

            break;
        }

        case '2':
        {
            break;

        }

        default:

            cout << "\n- Opcao invalida, deseja continuar? (S ou N ) -\n";

            cin >> opcao_2;

            opcao_2 = toupper(opcao_2);

            while(opcao_2 != 'S' && opcao_2 != 'N')
            {
                system("cls");

                cout << "\n- Opcao novamente invalida, deseja continuar? (S ou N ) -\n";
                cin >> opcao_2;

                opcao_2 = toupper(opcao_2);

            }

            if(opcao_2 == 'S')
            {
                menu();
            }

            if(opcao_2 == 'N')
            {
                system("cls");
                cout << "\nEncerrando programa...\n";
            }

    }

}

int main()
{
    menu();

    return 0;
}
