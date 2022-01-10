#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    int broj = 1000000;
    char izbor;
    string kodiranje;
    char bukva;
    int najgolem = 0;
    int cifri = 0;
    vector<int> kodirana;
    string dekodirana;
    int goleminaV = 0;
    int goleminaS = 0;
    
    //Proverka dali brojot e pogolem od 6 cifri
    while(broj > 999999){
    cout<<"Vnesi broj nepoveke od 6 cifri za kodiranje: "<<endl;
    cin>>broj;
    if(broj > 999999){
        cout<<"Brojot sostoi poveke od 6 cifri"<<endl;
    }
    }
    
    //Presmetka na brojot
    najgolem = broj % 10;
    while(broj > 0){
        broj /=10;
        if(najgolem < broj % 10){
            najgolem = broj % 10;;
        }
        cifri++;
    }
    if(cifri > najgolem){
        broj = cifri - najgolem;
    }else{
        broj = najgolem - cifri;
    }
    
    //Pocetok na programata
    do{
        cout<<"a) Kodiraj \nb) Dekodiraj \nc) Iskluci \nIzbor: ";
        cin>>izbor;
        
        //Kodiranje poraka
        if(izbor == 'a' || izbor == 'A'){
            kodiranje = "";
            goleminaS = 0;
            kodirana.clear();
            goleminaV = 0;
            dekodirana = "";
            cout<<"Vnesete poraka ne pogolema od 300 karakteri koja ne sodrzi brojki: "<<endl;
            cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
            getline(cin, kodiranje);
            goleminaS = kodiranje.length();
            //Proverka dali sodrzi povekje od 300 karakteri
            if(goleminaS > 300){
                cout<<"Vnesenata poraka e pogolema od 300 karakteri."<<endl;
                //Proverka dali porakata sodrzi brojki
            }else if(any_of(kodiranje.begin(), kodiranje.end(), ::isdigit)){
                cout<<"Vnesenata poraka sodrzi brojki"<<endl;
                cout<<"\n------------------------------------------------------------------------\n"<<endl;
            }
            //Kodiranje
            else{
            kodirana.clear();
            for(int i = 0; i < goleminaS; i++){
                bukva = kodiranje.at(i);
                cout<<int(bukva)+broj;
                kodirana.push_back(int(bukva)+broj);
            }
            cout<<"\n------------------------------------------------------------------------\n"<<endl;
            }
            
            //Dekodiranje poraka
        }else if(izbor == 'b' || izbor == 'B'){
            goleminaV = kodirana.size();
            for(int i = 0; i < goleminaV; i++){
                cout<<kodirana.at(i);
            }
            cout<<endl;
            for(int i = 0; i < goleminaV; i++){
            dekodirana += char(kodirana.at(i)-broj);
            }
            cout<<dekodirana;
            cout<<"\n------------------------------------------------------------------------\n"<<endl;
            
        }else if(izbor != 'c' && izbor != 'C'){
            cout<<"Nevaliden vnes";
            cout<<"\n------------------------------------------------------------------------\n"<<endl;
        }
    }while(izbor != 'c' && izbor != 'C');
    cout<<"\n\t---Programata zavrsi---\n"<<endl;
    }