#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stddef.h>
using namespace std;
#include "DoubleLinkedList.h"


//Complejidad: 0(1)

//Tiene como parametro de entrada un string de IP
//Cambia el string por un long long para comparacion de elementos en DoubleLinkedList
long long ipToLong(string ip) {
    int idx = 0;
    long long datoFinal = 0, dato = 0;
    while (idx < ip.size()) {
        if (ip[idx] != '.' && ip[idx] != ':') { 
            dato = dato * 10 + ip[idx] - '0';
            
        }
        else {
            datoFinal = datoFinal * 1000 + dato;
            dato = 0;
        }
        idx++;
    }
    datoFinal = datoFinal * 10000 + dato;
    return datoFinal;
}

//Complejidad 0(Largo de la lista)
//Carga los datos de la bitacora en una nueva lista de DoubleLinkedLst
//Recibe como parametro un DoubleLinkedList y lo guarda los datos en 
//la lista los datos principales como key que se transoformo a un long long
//Los datos como apuntan a la lista, es valido de ocupar en la lista en el main.
void cargarData(DoubleLinkedList &lista) {
    ifstream archivo;
    int iSepPos;
    Info Data;
    string sLinea, mes, dia, hora, ip, motivo, motivoBusqueda;
    archivo.open("bitacora.txt");
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


        Data.key = ipToLong(ip);
        Data.fechaHora = mes + '_' + dia + '_' + hora;
        Data.ip = ip;
        Data.motivo = motivo;

        lista.addLast(Data);

    }
    cout << "Informacion cargada en la lista correctamente" << endl;
}

int main()
{
    DoubleLinkedList lista;
    string input1, input2;
    long long busqueda1, busqueda2;
    //Carga la informacion de la lista mediante la funcion cargarData(DoubleLinkedList lista);
    cargarData(lista);

    //Imprime la informacion ordenada de menor a mayor.
    //Parametro de print:
    //  Si parametro = 1 -> Despliega de head a tail la lista.
    //  Si parametro != 1 -> Despliega de tail a head la lista.
    lista.print(1);
    cout << "Press enter to continue" << endl;
    cin.ignore();


    cout << "Estoy ordenando..." << endl;

    //Ordena la lista de menor a mayor (Head contiene el valor menor y tail el valor mayor)
    lista.sort();
    cout << "Press enter to continue" << endl;
    cin.ignore();

    //Imprime datos 
    //Imprime la informacion ordenada de menor a mayor.
    //Parametro de print:
    //  Si parametro = 1 -> Despliega de head a tail la lista.
    //  Si parametro != 1 -> Despliega de tail a head la lista.
    lista.print(1);
    cout << "Press enter to continue" << endl;
    cin.ignore();

    //Guarda la informacion ordenada de mayor a menor la informacion en un txt "bitacoraOrdeanada.txt"
    lista.escribir();
    cout << "Press enter to continue" << endl;
    cin.ignore();

    //Declara variables para la busqueda
    
    cout << "Teclee la primera IP del rango a desplegar 1" << endl;
    cin >> input1;
    cin.ignore();
    cout << "Teclee la segunda IP del rango a desplegar 2" << endl;
    cin >> input2;
    cin.ignore();

    busqueda1 = ipToLong(input1);
    busqueda2 = ipToLong(input2);
    //variables busqueda para probar
    //busqueda2 = ipToLong("694.78.591.36:5537");
    //busqueda1 = ipToLong("311.49.840.89:4145");

    //Realiza la busqueda basado en las variables busqueda1 y busqueda2.
    //No importa la orden de los parametros, la funcion realizara la busqueda de mayor a menor
    lista.search(busqueda1, busqueda2);
    cout << "Press enter to continue" << endl;
    cin.ignore();

    //Elimina toda la lista
    cout << "Eliminado" << endl;
    lista.deleteAll();
    lista.print(1);
    cout << "Press enter to continue" << endl;
    cin.ignore();

    //Carga datos sin ordenar
    cargarData(lista);
    cout << "Press enter to continue" << endl;
    cin.ignore();

    //Imprime la informacion.
    lista.print(1);
    cout << "Press enter to continue" << endl;
    cin.ignore();
    

}

    