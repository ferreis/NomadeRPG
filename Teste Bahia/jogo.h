#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

ifstream salas;
string line;
int escolha;
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
        setlocale(LC_ALL, "portuguese");
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
         jogador.idex+=1;
         jogador.ivida-=1;
         jogador.sraca = "Halfling";
         break;
   }
   system("cls");
   //Nomaderpg();
   cout << "Escolha a Classe: \n 1) Guerreiro \n 2) Mago \n 3) Ladino: \n\nEscolha : \n";
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
    cout<<"|Magia: "<< status.imagia<< "   |Vida: "<< status.ivida<<"   |Defesa: "<< status.idef<<"| \n";
    cout<<"----------------------------------------------------------------------------" << endl;
}

void escrever(Fase s[][3],int i, int j){
    salas.open("jogo.txt");
    for(int m=0; m<(s[i][j].F); m++)
    {
        getline(salas,line);
        if(m >= (s[i][j].I)){
            cout << line<< endl;
        }
    }
    salas.close();
    cin >> escolha;
    system("cls");
    switch(escolha){
    case 1:
        escrever(s,i,j+1);
        break;
    case 2:
        escrever(s,i,j+2);
        break;
    }
}

void Menu(Personagem &P1){
    Fase s[10][3];
    int x = 0;
    for(int i=0; i<10; i++){
        for(int j=0; j<2; j++){
            Fases(s[i][j], x);
        }
    }
    int espera;
    int voltar;
    string desenhomenu[31][11];
    for (int x = 0; x < 31;x++){
        for (int y = 0; y < 11; y++){
            if(x==10){
                desenhomenu[x][1]="            Menu            ";
                desenhomenu[x][3]="         1- Inicio          ";
                desenhomenu[x][5]="         2- Status          ";
                desenhomenu[x][7]="         3- Salvar          ";
                desenhomenu[x][9]="         4-  Sair           ";
            }else if (x==0||y==0||x==30||y==10){
                desenhomenu[x][y]="#";
            }
            else if(y%2==0){
                desenhomenu[x][y]="-";
            }else if(y%2 == 0){
                desenhomenu[x][y] = " ";
            }
        }
    }
       for (int y = 0; y < 11;y++){
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
        escrever(s,0,0);
        break;
    case 2:
        tela_status(P1);
        cout << "Para voltar digite 1: ";
        cin >> voltar;
        system("cls");
        Menu(P1);
        break;
    }
}
/*void historia (){
   fstream arquivo;
   arquivo.open("jogo.txt",fstream::in|fstream::out|fstream::app);

}*/
