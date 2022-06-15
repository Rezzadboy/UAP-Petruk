#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <cstdio>
#include <time.h>
#include <stack>
#include <queue>
#define jmlh 20
using namespace std;

struct Tampilan{
    stack<string> obat;
    queue<string> obat1;
    int data = 0, data1 = 0;
    
    void clear(){
        system("cls");
    }

    void Push(string medic){
        if(data == jmlh){
            cout<<"Penuh";

        }else{
            data++;
            obat.push(medic);
        }
    }

    void Pop(){
        if(!obat.empty()){
            data--;
            obat.pop();
        
        }else if (data == 0){
            cout<<"Tidak ada Daftar Obat";
        }
    }
    
    void cetak(stack <string> medkit){
        while(!medkit.empty()){
            cout<< medkit.top()<<"\n";
            medkit.pop();
        }
    }

    void Enqueue(){

    }


};

Tampilan menu;
void Home();
void kursor();
void gotoxy();
void login();
void admin(string username);
void pembeli(string name);
void header();
void daftar();
int keluar();

int main(){
    Home();
}

void Home(){
    cout<<"==================\n"; // 18
    cout<<"| Selamat Datang |\n";
    cout<<"==================\n";
    cout<<"|   LOGIN        |\n";
    cout<<"|   EXIT         |\n";
    cout<<"==================\n";
    kursor();
}

void gotoxy(int x, int y){

    COORD garis = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), garis);
}

void kursor(){
    char arah;
    int x=2, y=3;

    gotoxy(x,y);
    cout<<">";

    while(true){
        arah = getch();
        
        switch(arah){
            case 'w':
                if (y == 3){
                  
                }else{
                    gotoxy(x,y-=1);
                    printf(">");
                    gotoxy(x, y+1);
                    printf("  ");
                }
                gotoxy(x,y);
                printf(">");
                break;
             
            case 's': 
                if (y == 4){
                    
                }else{
                    gotoxy(x, y+=1);
                    printf(">");
                    gotoxy(x, y-1);
                    printf("  ");    
                }
                gotoxy(x,y);
                printf(">");
                break;
            case 'p':
                if(y==3){
                    login();
                }else{
                    
                }
                break;
        }
    }
}

void login(){
    string username;
    int pass;

    menu.clear();
    cout<<"Masukkan Username: ";
    getline(cin, username);

    if(username == "Reza Nur" || username == "Nathania Santa" || username == "Enjelita Aini"){
        cout<<"Masukkan Password: ";
        cin>> pass;

        switch(pass){
            case 2117051057:
                admin(username);
                break;
            case 211701009:
                admin(username);
                break;
            case 2117051028:
                admin(username);
                break;
            default:
                login();
                break;
        }
    }else{
        pembeli(username);
    }
}

void header(){
    cout<<"==================\n";
    cout<<"| Daftar Obat    |\n";
    cout<<"==================\n";
}

void admin(string name){
    string med, pilih;

    do{
        menu.clear();
        cout<<"| HELLO, " << name <<"|\n";
        header();
        menu.cetak(menu.obat);
        daftar();
        cout<<"\nInputkan Pilihan (Push/Pop/exit): ";
        cin>>pilih;

        if(pilih == "Push" || pilih == "push"){
            cout<<"Masukkan Nama Obat: ";
            cin.ignore(1,'\n');
            getline(cin,med);
            menu.Push(med);
        
        }else if(pilih == "Pop" || pilih == "pop"){
            menu.Pop();

        }

    }while(pilih != "exit" && pilih != "Exit");
    cin.ignore(1,'\n');
    login();
}

void pembeli(string name){
    string obat, pilih;

    do{
        menu.clear();
        cout<<"| HELLO, " << name <<"|\n";
        header();
        menu.cetak(menu.obat);
        daftar();
        cout<<"Masukkan Pilihan(beli/batal/exit): ";
        cin>> pilih;


    }while(pilih != "exit");
}

void daftar(){
    string obat[5] = {"Amoxillin", "Ampicillin", "Anankira","Amonium Klorida","Aminofilin"};

    for(int i = 0; i < 5; i++){
        cout<<obat[i] <<"\n";
    }
}

int keluar(){
    return 0;
}
