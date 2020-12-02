#include "Node.h"
class DoubleLinkedList {
public:
    DoubleLinkedList();
    ~DoubleLinkedList();
    void addFirst(Info data);
    void addLast(Info data);
    void print(int orden);
    bool isEmpty();
    void sort();
    void search(long long range1, long long range2);
    void escribir();
    int deleteAll();
private:
    Node* head;
    Node* tail;
    int size;
};


//Complejidad: 0(1)
DoubleLinkedList::DoubleLinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

//Complejidad: 0(1)
DoubleLinkedList::~DoubleLinkedList() {
    deleteAll();
}

//Añade informacion al principio de la lista.
//Parametro de entrada: Info data
//Complejidad: 0(1)
void DoubleLinkedList::addFirst(Info data) {
    //Declara nuevos nodos, un auxiliar que sera la cabeza y un nodo que sera el que se genera
    Node* node = new Node(data);
    Node* aux = head;
    //Si no se tiene una lista, genera un nuevo nodo con la informacion y se vincula Tail y Head
    if (head == nullptr) {
        head = node;
        tail = node;
        size++;
    }
    //Utiliza el nodo ya generado con la informacion, configura el head con el nuevo nodo, mientras que
    //este mismo se le vincula con el nodo anterior y el anterior con el setNext el nodo nuevo genero.
    else {
        node->setNext(head);
        head = node;
        node->getNext()->setPrev(node);
        size++;
    }
}

//Añade nueva informacion en nodos que esten al final de la lista y se mueve el tail.
//Complejidad: 0(n)
void DoubleLinkedList::addLast(Info data) {
    //Genera nodos temporales
    Node* node = new Node(data);
    Node* aux = tail;
    //Verifica si tiene informacion, si no tiene una lista, genera una nueva con un addFirst.
    if (head == nullptr) {
        addFirst(data);
    }
    //Añade nueva informacion al final de la lista, funciona similar con el add first, solamente se inverte la informacion
    else {
        //Utiliza el nodo ya creado y establece el prev de ese nodo con el tail.
        node->setPrev(tail);
        //Mueve el tail a el nuevo nodo
        tail = node;
        //Se establece el anterior nodo y despues el setNext del siguiente nodo mismo
        node->getPrev()->setNext(node);
        size++;
    }
}

//Complejidad: 0(n^2)
//Ordena la lista establecida de mayor a menor mediante el metodo de organizacion Burbuja.
//No tiene parametro de entrada o salida, solamente organiza la lista mediante el uso de los mismos nodos y swap.
void DoubleLinkedList::sort() {
    //Se establecen dos Info auxiliar y un nuevo nodo que apunta al nodo del inicio de la lista.
    Node* curr = head;
    Info aux1;
    Info aux2;
    //Si la lista esta vacia, se acaba la funcion e imprime que la lista no tiene elementos.
    if (curr == nullptr) {
        cout << "---------------" << endl;
        cout << "Lista vacia" << endl;
        cout << "---------------" << endl;
        return;
    }
    //Si la lista tiene elementos, entonces realiza el ordenamiento.
    else {
        //Se organiza la lista por el tamaño de la misma para asegurarse de que no ocurra un overflow de la misma lista.
        for (int i = 0; i < size; i++) {
            //Resetea al nodo head para volver al inicio de la lista para repetir el bubble sort
            curr = head;
            //Verifica que se realiza el swap hasta que encuentre el final o un nullptr
            while (curr->getNext() != nullptr) {
                //Verifica si el nodo actual con su informacion.key y el siguiente es mas grande, entonces realiza un swap.
                if (curr->getData().key > curr->getNext()->getData().key) {
                    //Guarda ambos datos en auxiliares.
                    aux1 = curr->getData();
                    aux2 = curr->getNext()->getData();
                    //Realiza el intercambio o swap
                    curr->setData(aux2);
                    curr->getNext()->setData(aux1);
                }
                //Recorre al siguiente elemento. 
                curr = curr->getNext();
            }
        }
    }
    cout << "Informacion ordenada exitosamente" << endl;
}

//Funcion que realiza la busqueda de elementos de una lista en un rango que este definido por el usuario.
//Parametros:
//  long long range1 -> Rango uno que introduce el usuario o parametro.
//  long long range2 -> Rango dos que introduce el usuario o parametro.
//Complejidad: 0(n)
void DoubleLinkedList::search(long long range1, long long range2) {
    //Nodo temporal que apunte al head
    Node* curr = head;
    //Verifica que la lista no este vacia
    if (curr == nullptr) {
        cout << "---------------" << endl;
        cout << "Lista vacia" << endl;
        cout << "---------------" << endl;
        return;
    }
    //Realiza la busqueda mediante busqueda secuencial
    else {
        cout << "\nBuscando informacion: " << endl;
        //Obtiene un long long auxiliar
        //Variable verifica por si encuentra datos que esten dentro del rango
        long long aux;
        bool verifica = false;
        //If que verifica que el rango11 sea mas pequeño que el rango2
        //Si el rango2 es mas pequeño que el rango1, intercambia ambos valores.
        if (range2 < range1) {
            aux = range1;
            range1 = range2;
            range2 = aux;
        }
        //Realiza la busqueda por el nodo auxiliar hasta que encuentre un nullptr
        while (curr != nullptr) {
            //Verifica si el key que se busca este dentro del rango, mientras que key sea mas grande que rango2 y mas pequeño que el rango1
            if (curr->getData().key >= range1 && curr->getData().key <= range2) {
                cout << curr->getData().key << " " << curr->getData().fechaHora << " " << curr->getData().ip << " " << curr->getData().motivo << endl;
                //Si encuentra un dato, el verifica cambia a true de qeu encontro informacion
                verifica = true;
            }
            //Recorre la lista a la siguiente
            curr = curr->getNext();
        }
        //Si no encontro datos o entro al IF, entonces imprime que no se encontro informacion.
        if (verifica == false) {
            cout << "No se encontro informacion." << endl;
        }
    }
    cout << "Informacion que se buscaba desplegada." << endl;
}

//Guarda la informacion en bitacoraOrdenada.txt
//Complejidad: 0(n)
void DoubleLinkedList::escribir() {
    //Crea un nuevo nodo que sea tail.
    Node* curr = tail;
    //Crea el archivo
    ofstream archivo("bitacoraOrdenada.txt");
    archivo.close();

    //Abre el archivo para escribir informacion
    ofstream guardar;
    guardar.open("bitacoraOrdenada.txt", ios::app);
    //Recorre la lista de mayor a menor para guardarlo en la misma lista con toda la informacion que es respecto a .key .fechaHora .ip .motivo
    while (curr != nullptr) {
        guardar << " " << curr->getData().key << " " << curr->getData().fechaHora << " " << curr->getData().ip << " " << curr->getData().motivo << endl;
        curr = curr->getPrev();
    }
    guardar.close();
    cout << "Informacion guardada" << endl;
}



//Funcion print que imprime todo el contenido de la lista.
//Tiene un parametro de entrada que permite que la lista se despliegue desde Head->Tail o Tail->Head
//El parametro es:
//  int orden == 1 -> Imprime desde Head hasta Tail.
//  int orden != 1 -> Imprime desde Tail hasta Head.
//Orden: 0(n)
void DoubleLinkedList::print(int orden) {
    //Verifica que la lista tenga elementos. 
    if (size == 0) {
        cout << "---------------" << endl;
        cout << "No hay nada por imprimir" << endl;
        cout << "---------------" << endl;
    }
    //Si la lista tiene elementos, realiza el proceso dedesplegar
    else {
        //Se crea un nodo temporal
        Node* curr;
        //Si el orden == 1;
        //Imprime desde head e imprime hasta tail.
        if (orden == 1) {
            //El nodo curr sera el head. 
            curr = head;
            cout << "Contenido de la DoubleLinkedList" << endl;
            cout << "Size: " << size << endl;
            while (curr != nullptr) {
                cout << curr->getData().key << " " << curr->getData().fechaHora << " " << curr->getData().ip << " " << curr->getData().motivo << endl;
                //Obtiene el siguiente elemento de la lista. 
                curr = curr->getNext();
            }
        }
        //Si el orden != 1
        //Imprime todos los elementos desde Tail hast Head. 
        else {
            //El nodo curr sera el tail. 
            curr = tail;
            cout << "Contenido de la DoubleLinkedList" << endl;
            cout << "Size: " << size << endl;
            //Recorre la lista hast que encuentre un nullptr
            while (curr != nullptr) {
                cout << curr->getData().key << " " << curr->getData().fechaHora << " " << curr->getData().ip << " " << curr->getData().motivo << endl;
                //Obtiene el elemento anterior de la lista. 
                curr = curr->getPrev();
            }
        }
    }
    
    
}

//Verifica si la lista esta vacia.
bool DoubleLinkedList::isEmpty() {
    //Crea un nodo que sea head.
    Node* curr = head;
    //Si el curr es igual a nullptr, la lista esta vacia
    if (curr == nullptr) {
        return true;
    }
    //Si no se cumple la condicion anterior, la lista tiene elementos. 
    else {
        return false;
    }
}

//Borra toda la informacion de la lista
int DoubleLinkedList::deleteAll() {
    //Crea un nodo que sea head
    Node* curr = head;
    //Recorre la lista hasta que sea nullptr. 
    while (head != nullptr) {
        //El head se recorre al next nodo
        head = head->getNext();
        //Elimina el nodo temporal que es el elemento al que head apuntaba y lo eliminaa
        delete curr;
        //El nodo temporal sera igualado a head
        curr = head;
    }
    //El size se resetea a 0
    int sizeAux = size;
    size = 0;
    //Regresa el tamaño de la lista. 
    cout << "Lista eliminada" << endl;
    return sizeAux;

}