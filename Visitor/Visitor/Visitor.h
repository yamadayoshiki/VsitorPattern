#ifndef VISITOR_H_
#define VISITOR_H_

#include <iostream>
#include <string>
#include <list>

using namespace std;

class Visitor;

/** ノードクラス *****************************/
class Nodo {
public:
	Nodo(int id, string name);
	virtual void add(Nodo* pNodo) = 0;
	virtual void accept(Visitor* pVisitor) = 0;
	int getId();
	string getName();
private:
	int id_;
	string name_;
};
/*********************************************/
/** ファイルクラス ***************************/
class File : public Nodo{
public:
	File(int id, string name);
	virtual ~File();
	virtual void add(Nodo* pNodo) override;
	virtual void accept(Visitor* pVisitor) override;
};
/*********************************************/
/** ディレクトリクラス ***********************/
class Directory : public Nodo {
public:
	Directory(int id, string name);
	virtual ~Directory();
	virtual void add(Nodo* pNodo) override;
	virtual void accept(Visitor* pVisitor) override;

private:
	list<Nodo*> children_;
};
/*********************************************/
/** Visitorインターフェイス ******************/
class Visitor {
public:
	virtual void visit(Directory* pDirectory) = 0;
	virtual void visit(File* pFIle) = 0;
};
/*********************************************/
/** FindVisitor ******************************/
class FindVisitor : public Visitor{
public:
	FindVisitor();
	virtual ~FindVisitor();
	list<Nodo*>* find(Nodo* pNodo, string name);
	virtual void visit(Directory* pDirectory) override;
	virtual void visit(File* pFIle) override;
private:
	string name_;
	list<Nodo*>* pResult_;
};
/*********************************************/
#endif // !VISITOR_H_
