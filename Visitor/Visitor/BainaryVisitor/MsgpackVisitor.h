#ifndef MSGPACKVISITOR_H_
#define MSGPACKVISITOR_H_

#include <string>
#include "Visitor.h"

using namespace std;

class MsgPackVisitor {
public:
	//�R���X�g���N�^
	MsgPackVisitor(string fileName);
	//�f�X�g���N�^
	~MsgPackVisitor();
	//�t�@�C���ǂݍ���
	void Load(string fileName);
	//�A�N�Z�X�֐�
	void Accept(Visitor* pVisitor);
	FILE* getFile();

private:
	FILE* fp_{ nullptr };
};
#endif // !MSGPACKVISITOR_H_
