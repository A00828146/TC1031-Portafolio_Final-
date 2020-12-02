class NodeT {
public:
	NodeT(int key, long long data, string ip);
	NodeT(int key, long long data, string ip, NodeT* left, NodeT* right);
	long long getData();
	void setData(long long data);
	void setKey(int key);
	void setIp(string ip);
	string getIp();
	int getKey();
	NodeT* getLeft();
	void setLeft(NodeT* left);
	NodeT* getRight();
	void setRight(NodeT* right);

private:
	int data;
	long long key;
	string ip;
	NodeT* left;
	NodeT* right;

};

NodeT::NodeT(int key, long long data, string ip) {
	this->data = data;
	this->key = key;
	this->ip = ip;
	this->left = nullptr;
	this->right = nullptr;
}

NodeT::NodeT(int key, long long data, string ip, NodeT* left, NodeT* right) {
	this->data = data;
	this->key = key;
	this->ip = ip;
	this->left = left;
	this->right = right;
}



long long NodeT::getData() {
	return data;
}

void NodeT::setData(long long data) {
	this->data = data;
}

NodeT* NodeT::getLeft() {
	return left;
}

void NodeT::setLeft(NodeT* left) {
	this->left = left;
}

NodeT* NodeT::getRight() {
	return right;
}

void NodeT::setRight(NodeT* right) {
	this->right = right;
}

void NodeT::setKey(int key) {
	this->key = key;
}

int NodeT::getKey() {
	return key;
}

void NodeT::setIp(string Ip) {
	this->ip = ip;
}

string NodeT::getIp() {
	return ip;
}