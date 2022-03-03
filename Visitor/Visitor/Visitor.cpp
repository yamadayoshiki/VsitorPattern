#include "Visitor.h"

/********************************************/
Nodo::Nodo(int id, string name) {
	id_ = id;
	name_ = name;
}

int Nodo::getId() {
	return id_;
}

string Nodo::getName() {
	return name_;
}
/*********************************************/
/** ファイルクラス ***************************/
File::File(int id, string name)
	:Nodo(id, name) {
}

File::~File() {
}

void File::add(Nodo* pNodo) {
}

void File::accept(Visitor* pVisitor) {
	pVisitor->visit(this);
}
/*********************************************/
/** ディレクトリクラス ***********************/
Directory::Directory(int id, string name)
	:Nodo(id, name) {
}

Directory::~Directory() {
}

void Directory::add(Nodo* pNodo) {
	children_.push_back(pNodo);
}

void Directory::accept(Visitor* pVisitor) {
	pVisitor->visit(this);
	list<Nodo*>::iterator it = children_.begin();
	while (it != children_.end()) {
		(*it)->accept(pVisitor);
		it++;
	}
}
/*********************************************/

/** FindVisitor ******************************/
FindVisitor::FindVisitor() {
	pResult_ = new list<Nodo*>;
}

FindVisitor::~FindVisitor() {
	delete pResult_;
}

list<Nodo*>* FindVisitor::find(Nodo* pNodo, string name) {
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