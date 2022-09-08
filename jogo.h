#ifndef JOGO_H_INCLUDED
#define JOGO_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <windows.h>
#include <time.h>

using namespace std;


ifstream salas, menu;
fstream save;
string line;
bool fruit;
int escolha, p = 0, q = 0, c=0, f=0, chec[30], *v[30];
 //atributos do jogador
struct Personagem
{
   string snome;
   string sraca;
   string sclasse;
   int ifor;
   int idex;
   int isorte;
   int ivida;
   int idef;
   int imagia;
};
Personagem orc;
//items
struct Equipamento
{
   string sarmadura;
   string sespada;
   string sextra;
   int ipotion;
};

void Nomaderpg(){
    menu.open("nomade.txt");
    while(menu.eof() == false)
    {
        getline(menu,line);
        cout << line<< endl;
    }
    menu.close();
}
 //função de inicialização do jogador
void IniJogador(Personagem &jogador){
    int raca;
    int classe;
    jogador.ifor=0;
    jogador.idex=0;
    jogador.isorte=0;
    jogador.ivida=3;
    jogador.idef=0;
    jogador.imagia=0;
    cout << "CRIE SEU PERSONAGEM\n\nNome: ";
    cin >> jogador.snome;
    system("cls");
    //Nomaderpg();
    cout << "Escolha a sua Raca: \n 1) Anao \n 2) Elfo \n 3) Halfling\n\nEscolha : ";
    cin >> raca;
    system("cls");
    //Nomaderpg();
        while(raca < 1 || raca > 3){
        cout << "Opcao inexistente, tente novamente:\n";
        cin >> raca;
        system("cls");
        cout << "Escolha a sua Raca: \n 1) Anao \n 2) Elfo \n 3) Halfling\n\nEscolha : ";
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
   cout << "Escolha a Classe: \n 1) Guerreiro \n 2) Mago \n 3) Ladino \n\nEscolha : ";
   cin>>classe;
   switch (classe) {
      case 1:
         jogador.ifor+=4;
         jogador.idex+=1;
         jogador.ivida+=3;
         jogador.idef+=2;
         jogador.sclasse = "Guerreiro";
         break;
      case 2:
         jogador.ifor+=2;
         jogador.imagia+=5;
         jogador.idex+=1;
         jogador.ivida+=2;
         jogador.sclasse = "Mago";
         break;
      case 3:
         jogador.ifor+=3;
         jogador.idex+=2;
         jogador.ivida+=2;
         jogador.isorte+=3;
         jogador.sclasse = "Ladino";
         break;
      default:
         jogador.ifor+=3;
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

void batalha(Personagem &P1, int &f, bool vantagem=false){
    orc.idef = 1 + (rand()%3), orc.ifor = 1 + (rand()%3), orc.ivida = 4;
    cout << "VOCE ENCONTROU UM ORC!!! PREPARE-SE PARA LUTAR\n\n";
    system("pause");
    system ("cls");
    int turno=0
    while(P1.ivida > 0 && orc.ivida > 0){
        int ataqueP = P1.ifor + rand()%6;
        int ataqueO = orc.ifor + rand()%6;
        int defesaP = P1.idef + rand()%6;
        int defesaO = orc.idef + rand()%6;
        if(turno==0 && vantagem==true){
            ataqueP += 6;
            defesaP += 6;
            turno++;
        }else{
            turno++;
        }
        if(ataqueP > defesaO){
            orc.ivida--;
            cout << ataqueP << " - " << defesaO;
            cout << "Seu ataque funcionou, vida do Orc: " << orc.ivida << "\n\n";
            system("pause");
            system ("cls");
        }
        else{
                cout << ataqueP << " - " << defesaO;
            cout << "Seu ataque falhou, vida do Orc: " << orc.ivida << "\n\n";
            system("pause");
            system ("cls");
        }
        if((ataqueO > defesaP) && orc.ivida > 0){
            P1.ivida--;
            cout << "Ataque do orc funcionou, sua vida: " << P1.ivida << "\n\n";
            system("pause");
            system ("cls");
        }
        else if((ataqueO < defesaP) && orc.ivida >0){
            cout << "Ataque do orc falhou, sua vida: " << P1.ivida << "\n\n";
            system("pause");
            system ("cls");
        }
    }
    if(P1.ivida == 0){
        f=50;
    }
    if(orc.ivida == 0){
        cout << "Voce ganhou a batalha!!\n\n";
        system("pause");
        system ("cls");
    }
}
void emboscada(Personagem &jogador){
    if(jogador.sraca =="Halfling" jogador.sraca=="Anao"){
            cout<<jogador.idex<<endl;
        if(jogador.sclasse == "Ladino"){
            jogador.idex+=3;
            cout<<jogador.idex<<endl;
        }else{
            cout<<jogador.idex<<endl;
        jogador.idex+=1;
        }
    }
    if(jogador.idex<=rand()%11){
        batalha(jogador, f, true);
    }else{
        batalha(jogador, f);
    }
    if(jogador.sraca =="Halfling" jogador.sraca=="Anao"){
        cout<<jogador.idex<<endl;
        if(jogador.sclasse == "Ladino"){
            cout<<jogador.idex<<endl;
            jogador.idex-=3;
        }else{
            cout<<jogador.idex<<endl;
        jogador.idex-=1;
        }
    }
}
int escrever(int p, int q,int escolha=0){
    salas.open("jogo.txt");
    for(int m=0; m<q; m++)
    {
        getline(salas,line);
        if(m >= p){
            cout << line<< endl;
        }
    }
    salas.close();
    if(escolha!= 1){
        cout << "Escolha (Menu:5) : ";
        cin >> escolha;
        system("cls");
        return escolha;
    }

}

int descansar(Personagem P1, int f){
    int sorte = rand()%(3+P1.isorte);
    if(sorte==0){
        return 50;
    }
    else{
        cout << "Descansa tranquilamente, e recupera sua vida perdida...\n\n";
        system("pause");
        system("cls");
        return f;
    }
}

void Pantano(Personagem &P1, int &f){
    escolha = escrever(0, 8);
    if(escolha == 1){
        f=50;
    }
    else if(escolha == 2){
        escolha = escrever(8, 19);
        if(escolha == 1){
            f=1;
        }
        else if(escolha == 2){
            f=2;
        }
    }
}

void Rio(Personagem &P1, int &f){
    if(chec[1]==0){
        escolha = escrever(19, 28);
        if(escolha == 1){
            if(P1.sraca != "Halfling")
            {
                cout << "Fruta venenosa: -1 de vida\n\n";
                system("pause");
                system("cls");
                P1.ivida--;
            }
            else{
                cout << "Voce se sente mais forte: +1 de forca\n\n";
                system("pause");
                system("cls");
                P1.ifor++;
            }
        }
        else if(escolha == 2){
            cout << "Fruta adiquirida!\n\n";
            system("pause");
            system("cls");
            fruit = true;
        }
        chec[1]=1;
    }
    escolha = escrever(28, 37);
    if(escolha == 1){
        escolha = escrever(37,44);
        if(escolha == 1){
            if(P1.sraca == "Anao"){
                f=50;
            }
            else{
                f=2;
            }
        }
    }
    else if(escolha == 2){
        f=3;
    }
}

void Cabana(Personagem &P1, int &f){
    escolha = escrever(45, 55);
    if(escolha == 1){
        f=3;
    }
    else if(escolha == 2){
        batalha(P1, f);
        if(f==50){}
        else{

        }
    }
    else if(escolha == 3 && chec[2] == 0){
        P1.ivida+=2;
        f=descansar(P1, f);
        chec[2]= 1;
    }
    else if(escolha == 3 && chec[2] == 1){
        cout << "Voce ja descansou!\n\n";
        system("pause");
        system ("cls");
    }
}

void Cidade(Personagem &P1, int &f){
    escolha = escrever(66,74);
    if(escolha == 1){
        P1.ivida++;
        escolha = escrever(74,85);
        if(escolha == 1){
            f=8;
        }
        else if(escolha == 2){
            escrever(144,161,1);
            system("pause");
            system("cls");
            f=40;
        }
    }
    else if(escolha == 2){
        escolha = escrever(85,97);
        if(escolha == 1){
            escolha = escrever(127,144);
            if(escolha == 1){
                f=8;
            }
            else if(escolha == 2 && chec[3]==0){
                P1.ifor++;
                chec[3] = 1;
            }
            else if(escolha == 2 && chec[3]==1){
                cout << "Você ja pegou tudo da mochila!!\n\n";
                system("pause");
                system("cls");
            }
        }
        else if(escolha == 2){

        }
        else if(escolha == 3){

        }
        else if(escolha == 4){

        }
    }
}

void PedraOrc(Personagem &P1, int &f){
    escrever(161,178);
    if(escolha == 1){
        escrever(178,195);
        if(escolha == 1){
            escrever(202,222,1);
            system("pause");
            system("cls");
            f=40;
        }
    }
}

void salvar(Personagem P1, int p, int q, int chec[]){
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
    save << f << "\n";
    for(int i=0; i<30; i++)
    {
        save << chec[i] << "\n";
    }
    save.close();
    cout << "Salvamento realizado com sucesso!!\n";
    Sleep(2000);
    system("cls");
}

void carregar(Personagem &P1, int &p, int &q, int *v[]){
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
    f = atoi(load.c_str());
    for(int i=0; i<30; i++){
        getline(save, load);
        *v[i] = atoi(load.c_str());
    }
    save.close();
    cout << "Carregamento realizado com sucesso!!\n";
    Sleep(2000);
    system("cls");
}

void Fase(Personagem &P1,int &f){
    if(escolha == 5){}
    else if (f == 0){
        Pantano(P1, f);
        Fase(P1, f);
    }
    else if(f == 1){
        Rio(P1, f);
        Fase(P1, f);
    }
    else if(f == 2){
        Cabana(P1, f);
        Fase(P1, f);
    }
    else if(f == 3){
        Cidade(P1, f);
        Fase(P1, f);
    }
    else if(f == 4){

    }
    else if(f == 8){
        PedraOrc(P1, f);
        Fase(P1, f);
    }
    else if(f == 40){
        menu.open("fim.txt");
        while(menu.eof() == false)
        {
            getline(menu,line);
            cout << line<< endl;
        }
        menu.close();
    }
    else if(f == 50){
        escrever(59,63,1);
        system("pause");
        system("cls");
        f=40;
        Fase(P1,f);
    }
}

void Menu(Personagem &P1, int &f){
    srand(time(NULL));
    int espera;
    int voltar;
    Nomaderpg();
    menu.open("menu.txt");
    while(menu.eof() == false)
    {
        getline(menu,line);
        cout << line<< endl;
    }
    menu.close();
    cin>>espera;
    system("cls");
    switch(espera){
    case 1:
        if(c==0 || f==40)
        {
            f=0;
            IniJogador(P1);
            for(int i; i<30; i++)
            {
                chec[i]=0;
            }
        }
        escolha=0;
        c++;
        Fase(P1, f);
        Menu(P1, f);
        break;
    case 2:
        tela_status(P1);
        cout << "Para voltar digite 1: ";
        cin >> voltar;
        system("cls");
        Menu(P1, f);
        break;
    case 3:
        if(c!=0){
            cout << "Deseja salvar realmente? (1-sim / 2-nao) ";
            cin >> escolha;
            system("cls");
            if(escolha == 1){
                salvar(P1, p, q, chec);
            }
        }
        else{
            cout << "NADA PARA SALVAR!";
            Sleep(2000);
            system("cls");
        }
        Menu(P1, f);
        break;
    case 4:
        cout << "Deseja carregar um salvamento? (1-sim / 2-nao) ";
        cin >> escolha;
        system("cls");
        if(escolha == 1){
            for(int i=0; i<30; i++){
                v[i] = &chec[i];
            }
            carregar(P1, p, q, v);
        }
        c++;
        Menu(P1, f);
        break;
    case 5:
        break;

    }
}
#endif // JOGO_H_INCLUDED