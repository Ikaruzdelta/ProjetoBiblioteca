#include <iostream>
#include <stdlib.h>
#include <fstream>


using namespace std;
//=========Funções=======
void Cliente();
void LerArqLivro();
void CadastroLivro();
float valor(float valor, float recebido);
void AlugarLivro();
void Devolucao();
int valor(int n);
//=======================
//=======Structs=========
struct cadastrar_cliente
{
    string nome;
    string endereco;
    string cpf;
    string nada;
    string NomeLivro;
    string TipoLivro;
    int CodLivro;
    int QuantLivro;
};

struct Cadastro
{
    string nada;
    string NomeLivro;
    string TipoLivro;
    int CodLivro;
    int QuantLivro;
    float valor;

};

struct multa
{
    int dia;
    int mes;
    int ano;
};


struct cadastrar_cliente cliente[200];
struct multa multa[200];
struct Cadastro livros[200];
//=======================

//Variavel global
int i = 0, esc, sair, opcao, IdCod, IdNome, posc, QuantCadast=0, AdcLivro=0, Qcliente=0;
int CodBusca, aux, existe, verdade, Qfuncio = 0;
string AuxCpf,aux1;
//=====================================

int main()
{
    setlocale(LC_ALL,"portuguese");
    system("cls");
    cout<<"========= MENU BIBLIOTECA =========" << endl;
    cout<<"'                                  '"<< endl;
    cout<<"'Insira (1)Para Gerenciar Livro    '"<< endl;
    cout<<"'Insira (2)Para Gerenciar Cliente  '"<< endl;
    cout<<"'Insira (3)Para Aluguel de livro   '"<< endl;
    cout<<"'Insira (4)Para Devolução de livro '"<< endl;
    cout<<"'Insira (5)Para Encerrar           '"<< endl;
    cout<<"'                                  '"<< endl;
    cout<<"===================================" << endl;
    cin>>opcao;
    switch(opcao)
    {
    case 1:
        system("cls");
        CadastroLivro();
        break;
    case 2:
        system("cls");
        Cliente();
        break;
    case 3:
        system("cls");
        AlugarLivro();
        break;
    case 4:
        system("cls");
        Devolucao();
        break;
    case 5:
        exit(0);
        break;
    default:
        cout << "Numero invalido" << endl;
        system("pause");
        main();
        break;
    }


    return 0;
}

void Cliente()
{
    do
    {
        cout<< "========== CADASTRO DE CLIENTE =========" << endl;
        cout<< "'                                      '" << endl;
        cout<< "'Insira(1)Para Cadastrar Cliente       '" << endl;
        cout<< "'Insira(2)Mostrar Clientes Cadastrados '" << endl;
        cout<< "'Insira(0)Sair                         '" << endl;
        cout<< "'                                      '" << endl;
        cout<< "========================================" << endl;
        cin>> opcao;
        if(opcao == 1)
        {

            do
            {
                system("cls");

                cout <<"            CADASTRO CLIENTE:"<<endl;
                fstream saida("Arquivo_Cliente.txt",ios::out|ios::app);

                Qcliente = Qcliente + 1;

                getline(cin,cliente[Qcliente].nada);
                cout<<"\n===== Cadastro de Cliente =====" << endl;
                cout<<"Cliente: " << endl;
                getline(cin,cliente[Qcliente].nome);
                cout<<"Endereco: " << endl;
                getline(cin,cliente[Qcliente].endereco);

                verdade = 1;
                while(verdade == 1)
                {
                    existe = 0;
                    cout<<"Insira o CPF do Cliente"<<endl;
                    cin>>AuxCpf;
                    for(int j=0; j<Qcliente; j++)
                    {
                        if(cliente[j].cpf == AuxCpf)
                        {
                            cout<<"CPF ja Existente:"<<endl;
                            existe = 1;

                        }
                    }
                    if(existe == 0)
                    {
                        cliente[Qcliente].cpf = AuxCpf;
                        verdade = 0;
                    }

                }
                cout<<"\nDeseja Cadastrar Novo Cliente?  (0)NAO ou (1)SIM: ";
                cin>>sair;

                //Entrada para o aquivo:
                saida << "Cliente: " << cliente[Qcliente].nome << endl;
                saida << "CPF: " << cliente[Qcliente].cpf << endl;
                saida << "Endereco: " << cliente[Qcliente].endereco << endl;
                saida <<"=================================" << endl;
            }
            while(sair == 1);
            system("cls");
        }
        if(opcao == 2)
        {
            do
            {
                char* carregar = "Arquivo_Cliente.txt";
                ifstream printar(carregar);
                string aux;
                while(getline(printar,aux))
                {

                    cout << aux <<endl;

                }
                cout << "Insira 0 para sair: " << endl;
                cin >> sair;
            }
            while(sair == 1);
            system("cls");
        }
    }
    while(opcao < 2 && opcao > 0);
    system("cls");
    main();
}

void CadastroLivro()
{



    do
    {
        system("cls");
        cout <<"=================== MENU LIVRO ======================" << endl;
        cout <<"'                                                   '" << endl;
        cout <<"'Insira (1) para cadastro de livro:                 '" << endl;
        cout <<"'Insira (2) para consultar informacoes dos livro    '" << endl;
        cout <<"'Insira (0) para sair                               '" << endl;
        cout <<"'                                                   '" << endl;
        cout <<"=====================================================" << endl;
        cin>>opcao;


        if(opcao == 1)
        {
            system("cls");
            cout <<"            CADASTRO LIVRO:"<<endl;
            ofstream entrada ("Cadastro_livro.txt",ios::out|ios::app);
            do
            {
                system("cls");

                QuantCadast = QuantCadast +1;
                for(i+i; i<QuantCadast; i++)
                {
                    getline(cin,livros[i].nada);
                    cout <<"Insira o Nome do " << i+1 <<" livro:"<< endl;
                    getline(cin,livros[i].NomeLivro);
                    cout <<"Insira o Genero do Livro:" << endl;
                    getline(cin,livros[i].TipoLivro);
                    cout <<"Insira Quantas Unidade do Livro Quer Cadastrar:"<<endl;
                    cin >>livros[i].QuantLivro;
                    cout <<"Valor do Livro: " << endl;
                    cin >> livros[i].valor;
                    verdade = 1;
                    while(verdade == 1)
                    {
                        existe = 0;
                        cout<<"Insira o Codigo do Livro"<<endl;
                        cin>>aux;
                        for(int j=0; j<QuantCadast; j++)
                        {
                            if(livros[j].CodLivro == aux)
                            {
                                cout<<"Codigo ja Existente:"<<endl;
                                existe = 1;

                            }
                        }
                        if(existe==0)
                        {
                            livros[i].CodLivro = aux;
                            verdade = 0;
                        }

                    }
                    entrada <<"Nome: "<<livros[i].NomeLivro<<endl;
                    entrada <<"Genero: "<<livros[i].TipoLivro<<endl;
                    entrada <<"Quantidade : "<<livros[i].QuantLivro<<endl;
                    entrada <<"Valor : " << livros[i].valor<< endl;
                    entrada <<"Codigo do Livro: "<<livros[i].CodLivro<<endl;
                    entrada << "================================================"<<endl;
                }
                cout <<"Deseja Cadastrar Outro (1)Sim (2)Nao" << endl;
                cin >> sair;

            }
            while(sair == 1);
            entrada.close();
        }
        if(opcao == 2)
        {
            system("cls");
            LerArqLivro();
        }
        if(opcao == 0)
        {
            break;
        }
        cout<<"Para voltar ao Menu Insira (1)";
        cin >> esc;
    }
    while(esc == 0);
    main();
}

void LerArqLivro()
{
    char* BibliotecaLivros = "Cadastro_livro.txt";
    ifstream saida(BibliotecaLivros);
    string aux;
    while(getline(saida,aux))
    {
        cout << aux <<endl;

    }
}

void AlugarLivro()
{
    system("cls");
    string cpf;
    do
    {
        cout<<"======== CLIENTES CADASTRADOS ===========" << endl;
        for(int i=1; i<= Qcliente; i++)
        {
            cout<<"Cliente: " << cliente[i].nome << endl;
            cout<<"CPF: " << cliente[i].cpf << endl;
            cout<<"Endereco: " << cliente[i].endereco << endl;
            cout<<endl;
        }
        getline(cin,cliente[Qcliente].nada);
        cout << "Digite CPF do Cliente Que Deseja Alugar o Livro: " << endl;
        getline(cin,cpf);

        for(i=0; i <= Qcliente; i++)
        {
            if(cpf == cliente[i].cpf)
            {
                system("cls");
                int codigo;
                float recebido, res;
                fstream livro ("Cliente_e_Livro.txt",ios::out|ios::app);
                cout << "======= Livros Cadastrados =======" << endl;
                for(i=0; i < QuantCadast; i++)
                {
                    cout <<"Nome: "<< livros[i].NomeLivro << endl;
                    cout <<"Genero: "<< livros[i].TipoLivro << endl;
                    cout <<"Quantidade Disponivel: "<<livros[i].QuantLivro << endl;
                    cout <<"Valor: " << livros[i].valor <<endl;
                    cout <<"Codigo do Livro: " << livros[i].CodLivro << endl;
                    cout << endl;

                }

                do
                {
                    cout << "Digite o Codigo do Livro Que Deseja: " << endl;
                    cin >> codigo;
                    for(i=0; i < QuantCadast; i++)
                    {
                        if(codigo == livros[i].CodLivro && livros[i].QuantLivro > 0)
                        {
                            cliente[Qcliente].NomeLivro = livros[i].NomeLivro;
                            cliente[Qcliente].TipoLivro = livros[i].TipoLivro;
                            cliente[Qcliente].QuantLivro = livros[i].QuantLivro;
                            cliente[Qcliente].CodLivro = livros[i].CodLivro;
                            livros[i].QuantLivro = livros[i].QuantLivro - 1;
                            //Salvando o arquivo de alugueis

                            livro<< "Cliente: " << cliente[Qcliente].nome << endl;
                            livro<< "CPF: " << cliente[Qcliente].cpf << endl;
                            livro<< "Endereco: " << cliente[Qcliente].endereco << endl;
                            livro<< "Nome: "<< livros[i].NomeLivro << endl;
                            livro<< "Genero: "<< livros[i].TipoLivro << endl;
                            livro<< "Codigo do Livro: " << livros[i].CodLivro << endl;

                            system("cls");

                            cout << "Data de Aluguel: " << endl;
                            cout << "Dia: " << endl;
                            cin  >> multa[Qcliente].dia;
                            cout << "Mes: " << endl;
                            cin  >> multa[Qcliente].mes;
                            cout << "Ano: " << endl;
                            cin  >> multa[Qcliente].ano;

                            livro<< "Data de aluguel: " << multa[Qcliente].dia << "/" << multa[Qcliente].mes <<"/"<<multa[Qcliente].ano << endl;
                            livro<< "=================================" << endl;

                            cout << "=====   Pagamento     ====" << endl;
                            cout << "Valor do livro é: " << livros[i].valor << endl;
                            cout << "Quanto recebido: " << endl;
                            cin  >> recebido;
                            res  = valor(livros[i].valor,recebido);
                            cout << "Troco a ser Devolvido : " << res << endl;
                            system("pause");
                            cout << "Livro Alugado com Sucesso " << endl;
                            cout <<"Digite (0)Para Voltar ao Menu" << endl;
                            cin  >> verdade;

                        }

                    }

                }
                while(verdade == 1);
                livro.close();
                system("cls");
                main();
            }

        }


    }
    while(sair = 1);

}

float valor(float valor, float recebido)
{
    float  resultado;
    if(valor < recebido || valor == recebido)
    {
        resultado = recebido - valor;

    }
    else if(valor > recebido)
    {
        cout << "Valor Invalido" << endl;
        cout << "Digite Valor Suficiente ao Pagamento: " << endl;
        cin >> recebido;
        resultado = recebido - valor;
    }
    return resultado;
}

void Devolucao()
{
    int multaAno=0,dia=0,mes=0,ano=0,DT=0,AUX,aux, aux_mes = 0, cont, cont1;
    int auxdev;
    string cpf;
    do
    {
        cout<<"======== CLIENTES CADASTRADOS =====" << endl;
        for(int i=1; i<= Qcliente; i++)
        {
            cout<<"Cliente: " << cliente[i].nome << endl;
            cout<<"CPF: " << cliente[i].cpf << endl;
            cout<<"Endereco: " << cliente[i].endereco << endl;
            cout<<endl;
        }
        getline(cin,cliente[Qcliente].nada);
        cout << "Digite CPF do Cliente: " << endl;
        getline(cin,cpf);
        auxdev = livros[i].QuantLivro;
        livros[i].QuantLivro = auxdev - 1;
        for(Qcliente=0; i <= 200; Qcliente++)
        {
            if(cpf == cliente[Qcliente].cpf)
            {

                cout << "INFORME DIA MES E ANO DA DEVOLUCAO:\n";
                cout << "Dia:" << endl;
                cin >> dia;
                cout << "Mes:" << endl;
                cin >> mes;
                cout << "Ano:" << endl;
                cin >> ano;

                // devolução no mesmo mes
                if(dia >= multa[Qcliente].dia && mes == multa[Qcliente].mes)
                {
                    DT = dia - multa[Qcliente].dia;
                    valor(DT);
                    system("pause");
                    main();
                }
                // de um mes para o outro
                if(dia <= multa[Qcliente].dia && mes > multa[Qcliente].mes)
                {
                    AUX = 31 - multa[Qcliente].dia;
                    DT = AUX + dia;
                    valor(DT);
                    system("pause");
                    main();
                }
                // de um mes para o outro
                if(dia >= multa[Qcliente].dia && mes > multa[Qcliente].mes)
                {
                    DT = (dia - multa[Qcliente].dia)+31;
                    valor(DT);
                    system("pause");
                    main();
                }
                // data invalida
                if(dia <= multa[Qcliente].dia && mes <= multa[Qcliente].mes )
                {
                    DT = 0;
                    valor(DT);
                    system("pause");
                    main();
                }


            }

        }
        cout << "digita 0";
        cin >> sair;
    }
    while(sair == 1);

}

int valor(int n)
{

    if(n >0 && n <= 10)
    {
        cout << "Devolucao Realizada Com Sucesso"<< endl;
    }
    if(n > 10 && n <= 20)
    {
        cout << "Multa Minima : 10,00" << endl;
    }
    if(n > 20 && n < 30)
    {
        cout << "Multa Media : 15,00" << endl;
    }
    if(n > 30 )
    {
        cout << "Multa Maxima : 50,00" << endl;
    }
    if(n == 0)
    {
        cout<< "Data Invalida"<<endl;
    }
    return 0;
}
