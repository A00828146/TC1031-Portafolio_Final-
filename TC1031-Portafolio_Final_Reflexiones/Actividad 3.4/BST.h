#include "NodeT.h"
class BST {
public:
	BST();
	~BST();
	void add(int key, long long data, string ip);
	void inordenC(int limit);
private:
	NodeT* root;
	void destruye(NodeT* r);
	void inordenCSet(NodeT* r);
	int acum;
	int limitBST;
};

//Complejidad: 0(1)
BST::BST() {
	root = nullptr;
}

//Complejidad: 0(1)
BST::~BST() {
	destruye(root);
}

//Complejidad: 0(n)
void BST::destruye(NodeT* r) {
	if (r != nullptr) {
		destruye(r->getLeft());
		destruye(r->getRight());
		delete r;
	}
}

//Complejidad: 0(n)
//Añade la IP al Arbol de la siguiente manera:
//	Los numeros de acceso mas grande toman prioridad
//	Si el numero de acceso es el mismo, entonces se organiza de IP mas pequeña como prioridad
void BST::add(int key, long long data, string ip) {
	NodeT* curr = root;
	NodeT* father = nullptr;

	while (curr != nullptr) {
		if (curr->getKey() == key) {
			father = curr;
			curr = (curr->getData() > data) ? curr->getRight() : curr->getLeft();
		}
		else {
			father = curr;
			curr = (curr->getKey() > key) ? curr->getLeft() : curr->getRight();
		}
		
	}

	if (father == nullptr) {
		root = new NodeT(key, data, ip);
	}
	else {
		if (father->getKey() > key) {
			father->setLeft(new NodeT(key, data, ip));
		}
		else if (father->getKey() < key) {
			father->setRight(new NodeT(key, data, ip));
		}
		else {
			if (father->getData() < data) {
				father->setLeft(new NodeT(key, data, ip));
			}
			else {
				father->setRight(new NodeT(key, data, ip));
			}
		}
	}	
}

//Complejidad: 0(Altura del arbol)
//Despliega los datos del arbol de mayor acceso y menor IP
void BST::inordenCSet(NodeT *r) {
	
	if (r != nullptr) {
		inordenCSet(r->getRight());	
		//acum que toma el numero de despliegues que lleva en base a lo que pide el limitBST
		if (acum < limitBST) {
			cout << "Numero de accesos: " << r->getKey() << "   " << "IP: " << r->getIp() << endl;
			acum++;
		}
		inordenCSet(r->getLeft ());
	}
}

//Complejidd: 0(Altura del arbol)
void BST::inordenC(int limit) {
	limitBST = limit;
	acum = 0;
	inordenCSet(root);
}