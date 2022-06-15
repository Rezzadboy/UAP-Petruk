#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <cstdio>
#include <time.h>
#include <stack>
#include <queue>
#define jmlh 5;
using namespace std;

struct Tampilan{
    stack<string> obat;
    int data = 0;

    void clear(){
        system("cls");
    }

    void Push(string medic){
        if(data == 5){
            cout<<"Penuh";

        }else{
            data++;
            obat.push(medic);
        }
    }


    void cetak(stack <string> medkit){
        while(!medkit.empty()){
            cout<< medkit.top()<<"\n";
            medkit.pop();
        }
    }


};

Tampilan menu;
void Home();
void kursor();
void gotoxy();
void login();
void admin();


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
    int x=2, y=3; // berfungsi untuk menggerakan kursor di void menu

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
                admin();
                break;
            case 211701009:
                break;
            case 2117051028:
                break;
        }
    }
}

void admin(){
    int pilih;
    string nama;

    do{
        menu.clear();
        menu.cetak(menu.obat);
        cin>>pilih;

        switch (pilih){
        case 1:
            cin>>nama;
            menu.Push(nama);
            break;

        default:

            break;
        }

    }while(pilih != 4);

}
