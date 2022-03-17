#include "Visitor.h"

/*** ノードクラス ******************************/
Node::Node(int id, string name) {
	id_ = id;
	name_ = name;
}

int Node::getId() {
	return id_;
}

string Node::getName() {
	return name_;
}
/*********************************************/
/** ファイルクラス ***************************/
File::File(int id, string name)
	:Node(id, name) {
}

File::~File() {
}

void File::add(Node* pNodo) {
}

void File::accept(Visitor* pVisitor) {
	pVisitor->visit(this);
}
/*********************************************/
/** ディレクトリクラス ***********************/
Directory::Directory(int id, string name)
	:Node(id, name) {
}

Directory::~Directory() {
}

void Directory::add(Node* pNodo) {
	children_.push_back(pNodo);
}

void Directory::accept(Visitor* pVisitor) {
	pVisitor->visit(this);
	list<Node*>::iterator it = children_.begin();
	while (it != children_.end()) {
		(*it)->accept(pVisitor);
		it++;
	}
}
/*********************************************/

/** FindVisitor ******************************/
FindVisitor::FindVisitor() {
	pResult_ = new list<Node*>;
}

FindVisitor::~FindVisitor() {
	delete pResult_;
}

list<Node*>* FindVisitor::find(Node* pNodo, string name) {
	name_ = name;
	pNodo->accept(this);
	return pResult_;
}

void FindVisitor::visit(Directory* pDirectory) {
	if (pDirectory->getName().compare(name_) == 0)
		pResult_->push_back(pDirectory);
}

void FindVisitor::visit(File* pFIle) {
	if (pFIle->getName().compare(name_) == 0)
		pResult_->push_back(pFIle);
}
/*********************************************/