#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Info {
    string motivo;
    string fecha;
};

//Complejidad: 0(1)
string ipWithoutPort(string ip) {
    int pos = 0;
    string newIp;
    bool verifica = false;
    while (pos < ip.size() && verifica == false) {
        if (ip[pos] == ':') {
            verifica = true;
        }
        else {
            newIp = newIp + ip[pos];
        }

        pos++;
    }
    return newIp;
}

//Complejidad: 0(n)
void loadData(unordered_map<string, vector<Info>>& hashTable) {
    cout << "Cargando datos" << endl;
    Info Data;
    ifstream archivo;
    int iSepPos, cant = 0;
    string sLinea, mes, dia, hora, ip, motivo, ipPortless;
    archivo.open("bitacoraACT5_2.txt");
    while (!archivo.eof()) // Mientras no sea el final del archivo
    {
        getline(archivo, sLinea);
        iSepPos = sLinea.find(" ");
        mes = sLinea.substr(0, iSepPos);//

        sLinea.erase(0, iSepPos + 1);
        iSepPos = sLinea.find(" ");
        dia = sLinea.substr(0, iSepPos);//

        sLinea.erase(0, iSepPos + 1);
        iSepPos = sLinea.find(" ");
        hora = sLinea.substr(0, iSepPos);//

        sLinea.erase(0, iSepPos + 1);
        iSepPos = sLinea.find(" ");
        ip = sLinea.substr(0, iSepPos);//

        sLinea.erase(0, iSepPos + 1);
        motivo = sLinea.substr(0, iSepPos);
        
        ipPortless = ipWithoutPort(ip);

        //Añadimos la informacion a un unordered map con la llave de IP y sus datos en un struct
        Data.fecha = mes + " " + dia + "   " + hora;
        Data.motivo = motivo;
        hashTable[ipPortless].push_back(Data);
        cant++;
    }
    archivo.close();
    cout << "Se cargaron " << cant-1 << " datos." << endl;

}

//Complejidad: 0(n)
void displayData(unordered_map<string, vector<Info>>& hashTable) {
    int size, finishInt;
    bool finish = false, verificaInput = false;
    string ip;
    while (!finish){
        //Pedimos input del usuario
        cout << "Numero de IP que quiere investigar: ";
        cin >> ip;
        size = hashTable[ip].size();
        cout << "\n\n\n\n----------------------------------------" << endl;
        cout << "Numero de casos con la IP " << ip << ": " << size<<endl;
        //Buscamos la IP y sus datos
        for (int i = 0; i < size; i++) {
            cout << "Momento: " << hashTable[ip][i].fecha << endl;
            cout << "Motivo: " << hashTable[ip][i].motivo << endl;
            cout << endl;
        }
        cout << "----------------------------------------" << endl;
        
        //Repite el proceso para buscar de nuevo o terminar el programa
        while (!verificaInput) {
            cout << "¿Quiere buscar otra IP? Teclee el numero" << endl;
            cout << "1) Si \n0) No" << endl;
            cout << "Opcion: ";
            cin >> finishInt;
            if (finishInt == 0) {
                finish = true;
                verificaInput = true;
            }
            else if (finishInt == 1) {
                verificaInput = true;
            }
            else {
                cout << "Dato no valido, intente de nuevo" << endl;
            }
        }
        verificaInput = false;

    }

    
}

int main()
{
    unordered_map<string, vector<Info>> hashTable;
    loadData(hashTable);
    displayData(hashTable);
}


