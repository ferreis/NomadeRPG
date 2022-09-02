#ifndef JOGO_H_INCLUDED
#define JOGO_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <windows.h>

using namespace std;

ifstream salas;
fstream save;
string line;
int escolha, p = 0, q = 0, c=0;
 //atributos do jogador
struct Personagem
{
   string snome;
   string sraca;
   string sclasse;
   int ifor=0;
   int idex=0;
   int isorte=0;
   int ivida=0;
   int idef=0;
   int imagia=0;
};
//items
struct Equipamento
{
   string sarmadura;
   string sespada;
   string sextra;
   int ipotion;
};
struct Fase{
    int I, F;
};

void Fases(Fase &s, int &x){
    s.I = x;
    x = x + 7;
    s.F = x;
}

/*void Nomaderpg(){
cout << "╔═╦╗────────────╔╗───╔═╗╔═╗╔══╗\n";
cout << "║║║║╔═╗╔══╗╔═╗─╔╝║╔═╗║╬║║╬║║╔═╣\n";
cout << "║║║║║╬║║║║║║╬╚╗║╬║║╩╣║╗╣║╔╝║╚╗║\n";
cout << "╚╩═╝╚═╝╚╩╩╝╚══╝╚═╝╚═╝╚╩╝╚╝─╚══╝\n";
cout << "───────────────────────────────\n";
}*/
 //função de inicialização do jogador
void IniJogador(Personagem &jogador){
    int raca;
    int classe;
    cout << "CRIE SEU PERSONAGEM\n\nNome:";
    cin >> jogador.snome;
    system("cls");
    //Nomaderpg();
    cout << "Escolha a sua Raca: \n 1) Anao \n 2) Elfo \n 3) Halfling\n\nEscolha : \n";
    cin >> raca;
    system("cls");
    //Nomaderpg();
        while(raca < 1 || raca > 3){
        cout << "Opcao inexistente, tente novamente:\n";
        cin >> raca;
        system("cls");
        cout << "Escolha a sua Raca: \n 1) Anao \n 2) Elfo \n 3) Halfling\n\nEscolha : \n";
    }
    switch(raca){
    case 1:
         jogador.ifor+=1;
         jogador.ivida+=1;
         jogador.sraca = "Anao";
         break;
      case 2:
         jogador.imagia+=1;
         jogador.idex+=1;
         jogador.sraca = "Elfo";
         break;
      case 3:
         jogador.isorte+=2;
         jogador.idef+=1;
         jogador.ivida-= 1;
         jogador.sraca = "Halfling";
         break;
   }
   system("cls");
   //Nomaderpg();
   cout << "Escolha a Classe: \n 1) Guerreiro \n 2) Mago \n 3) Ladino \n\nEscolha : \n";
   cin>>classe;
   switch (classe) {
      case 1:
         jogador.ifor+=5;
         jogador.idex+=1;
         jogador.ivida+=3;
         jogador.idef+=2;
         jogador.sclasse = "Guerreiro";
         break;
      case 2:
         jogador.imagia+=7;
         jogador.idex+=1;
         jogador.ivida+=2;
         jogador.sclasse = "Mago";
         break;
      case 3:
         jogador.ifor+=1;
         jogador.idex+=4;
         jogador.ivida+=2;
         jogador.isorte+=3;
         jogador.sclasse = "Ladino";
         break;
      default:
         jogador.ifor+=2;
         jogador.idex+=2;
         jogador.ivida+=2;
         jogador.isorte+=2;
         jogador.idef+=2;
         jogador.sclasse = "Aldeao";
         break;
   }
   system("cls");
}
void tela_status(Personagem status){
    cout<<"----------------------------------------------------------------------------"<<endl;
    cout<<"|Nome: "<< status.snome<< "   |Classe: "<< status.sclasse<<"   |Raca: "<< status.sraca<<"| \n";
    cout<<"|Forca: "<< status.ifor<< "   |Destreza: "<< status.idex<<"   |Sorte: "<< status.isorte<<"| \n";
    cout<<"|Vida: "<< status.ivida<<"   |Defesa: "<< status.idef<<"   |Magia: "<< status.imagia<< "|\n";
    cout<<"----------------------------------------------------------------------------" << endl;
}

void escrever(Personagem &P1, Fase s[][3],int &p, int &q){
    salas.open("jogo.txt");
    for(int m=0; m<(s[p][q].F); m++)
    {
        getline(salas,line);
        if(m >= (s[p][q].I)){
            cout << line<< endl;
        }
    }
    salas.close();
    cout << "Escolha(1, 2, 3(Menu)) : ";
    cin >> escolha;
    system("cls");
    if(q==0){
        switch(escolha){
        case 1:
            q++;
            escrever(P1,s,p,q);
            break;
        case 2:
            q+=2;
            escrever(P1,s,p,q);
            break;
        case 3:
            break;
        }
    }
    else{
        switch(escolha){
        case 1:
            q=0;
            p++;
            escrever(P1,s,p,q);
            break;
        case 2:
            q=0;
            p+=2;
            escrever(P1,s,p,q);
            break;
        case 3:
            break;
        }
    }
}

void salvar(Personagem P1, int p, int q){
    save.open("save.csv");
    save << "sep=, \n";
    save << P1.snome << "\n";
    save << P1.sclasse << "\n";
    save << P1.sraca << "\n";
    save << P1.ifor << "\n";
    save << P1.idex << "\n";
    save << P1.isorte << "\n";
    save << P1.ivida << "\n";
    save << P1.idef << "\n";
    save << P1.imagia<< "\n";
    save << p << "\n" << q;
    save.close();
    cout << "Salvamento realizado com sucesso!!\n";
    Sleep(2000);
    system("cls");
}

void carregar(Personagem &P1, int &p, int &q){
    save.open("save.csv");
    string load;
    getline(save, load);
    getline(save, P1.snome);
    getline(save, P1.sclasse);
    getline(save, P1.sraca);
    getline(save, load);
    P1.ifor = atoi(load.c_str());
    getline(save, load);
    P1.idex = atoi(load.c_str());
    getline(save, load);
    P1.isorte = atoi(load.c_str());
    getline(save, load);
    P1.ivida = atoi(load.c_str());
    getline(save, load);
    P1.idef = atoi(load.c_str());
    getline(save, load);
    P1.imagia = atoi(load.c_str());
    getline(save, load);
    p = atoi(load.c_str());
    getline(save, load);
    q = atoi(load.c_str());
    save.close();
    cout << "Carregamento realizado com sucesso!!\n";
    Sleep(2000);
    system("cls");
}

void Menu(Personagem &P1){
    Personagem P2;
    Fase s[10][3];
    int x = 0;
    for(int i=0; i<10; i++){
        for(int j=0; j<2; j++){
            Fases(s[i][j], x);
        }
    }
    int espera;
    int voltar;
    string desenhomenu[31][13];
    for (int x = 0; x < 31;x++){
        for (int y = 0; y < 13; y++){
            if(x==10){
                desenhomenu[x][1]="            Menu            ";
                desenhomenu[x][3]="         1- Jogar           ";
                desenhomenu[x][5]="         2- Status          ";
                desenhomenu[x][7]="         3- Salvar          ";
                desenhomenu[x][9]="         4- Carregar        ";
                desenhomenu[x][11]="         5- Sair            ";
            }else if (x==0||y==0||x==30||y==12){
                desenhomenu[x][y]="#";
            }
            else if(y%2==0){
                desenhomenu[x][y]="-";
            }else if(y%2 == 0){
                desenhomenu[x][y] = " ";
            }
        }
    }
    for (int y = 0; y < 13;y++){
        for (int x = 0; x < 31; x++)
        {
              cout << desenhomenu[x][y];
        }
        cout<<endl;
    }
    cin>>espera;
    system("cls");
    switch(espera){
    case 1:
        if(c==0)
        {
            IniJogador(P1);
        }
        escrever(P1,s,p,q);
        Menu(P1);
        break;
    case 2:
        tela_status(P1);
        cout << "Para voltar digite 1: ";
        cin >> voltar;
        system("cls");
        Menu(P1);
        break;
    case 3:
        cout << "Deseja salvar realmente? (1-sim / 2-nao) ";
        cin >> escolha;
        system("cls");
        if(escolha == 1){
            salvar(P1, p, q);
        }
        Menu(P1);
        break;
    case 4:
        cout << "Deseja carregar um salvamento? (1-sim / 2-nao) ";
        cin >> escolha;
        system("cls");
        if(escolha == 1){
            carregar(P1, p, q);
        }
        c++;
        Menu(P1);
        break;
    case 5:
        break;

    }
}
/*cout << "Deseja comecar um novo jogo? (1-Sim / 2-Nao) ";
        cin >> escolha;
        system("cls");
        if(escolha == 2){
            Menu(P1);
        }
        else{*/


#endif // JOGO_H_INCLUDED
