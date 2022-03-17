#ifndef MSGPACKVISITOR_H_
#define MSGPACKVISITOR_H_

#include <string>
#include "Visitor.h"

using namespace std;

class MsgPackVisitor {
public:
	//コンストラクタ
	MsgPackVisitor(string fileName);
	//デストラクタ
	~MsgPackVisitor();
	//ファイル読み込み
	void Load(string fileName);
	//アクセス関数
	void Accept(Visitor* pVisitor);
	FILE* getFile();

private:
	FILE* fp_{ nullptr };
};
#endif // !MSGPACKVISITOR_H_
