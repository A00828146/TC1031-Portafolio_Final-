/*
    Evidencia Act 3.4 - Actividad Integral de BST
    Integrantes del equipo #5:
      Christián Eduardo Terrón García - A00828146
      Juan Angel Mora Moreno - A00517141
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "BST.h"

//Complejidad:  0(n)
//Convierte un string a un numero long long
long long ipToLong(string ip) {
    int idx = 0;
    long long datoFinal = 0, dato = 0;
    bool verifica = false;
    while (idx < ip.size() && verifica == false) {
        if (ip[idx] != '.' && ip[idx] != ':') {
            dato = dato * 10 + ip[idx] - '0';

        }
        else {
            if (ip[idx] == ':') {
                verifica = true;
            }
            datoFinal = datoFinal * 1000 + dato;
            dato = 0;
        }
        idx++;
    }
    datoFinal = datoFinal + dato;
    return datoFinal;
}

//Complejidad: 0(n)
//Convierte un string IP y regresa la misma IP en string sin puerto
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

//Complejidad 0(n)
//Carga los datos al BST
void cargarData(BST& nuestroArbol) {
    ifstream archivo;
    int iSepPos, contAcc = 0;
    long long ipAnt = 0, ipActual = 0;
    string sLinea, mes, dia, hora, ip, motivo, ipClean;
    archivo.open("bitacoraOrdenada.txt");
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

        //Parte de la funcion que agrega la IP, Key y Num. de accesos
        ipActual = ipToLong(ip);        
        if (ipActual != ipAnt && contAcc > 0) {      
            ipClean = ipWithoutPort(ip);
            nuestroArbol.add(contAcc, ipActual, ipClean);
            ipAnt = ipActual;
            contAcc = 1;            
        }
        else {
            contAcc++;
        }
    }
    archivo.close();
}


int main()
{
    BST nuestroArbol;
    cargarData(nuestroArbol);
    //Parametro de entrada: La cantidad de datos que quiere que se despliegue del BST
    //Ordenamiento: Mas numero de veces e IP mas pequeña
    nuestroArbol.inordenC(5);
}
