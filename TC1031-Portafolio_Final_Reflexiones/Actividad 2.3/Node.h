struct Info { 
    long long key;
    string fechaHora; 
    string ip;
    string motivo;
};



class Node {
public:
    Node(Info data);
    Node(Info data, Node* next, Node* prev);
    Info getData();
    Node* getNext();
    Node* getPrev();
    void setData(Info data);
    void setNext(Node* next);

    void setPrev(Node* prev);

private:
    Info data;
    Node* next;
    Node* prev;
};

Node::Node(Info data) {
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
}

Node::Node(Info data, Node*prev,  Node* next) {
    this->data = data;
    this->prev = prev;
    this->next = next;
}

Info Node::getData() {
    return data;
}
Node* Node::getNext() {
    return next;
}

Node* Node::getPrev() {
    return prev;
}

void Node::setData(Info data) {
    this->data = data;
}
void Node::setNext(Node* next) {
    this->next = next;
}

void Node::setPrev(Node* prev) {
    this->prev = prev;
}
