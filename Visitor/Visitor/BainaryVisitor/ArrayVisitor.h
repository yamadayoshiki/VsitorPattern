#ifndef ARRAYVISITOR_H_
#define ARRAYVISITOR_H_

#include "Visitor.h"

class ArrayVisitor : public Visitor {
public:
	virtual void visit(MsgPackVisitor* pMsgpack) override;
};
#endif // !ARRAYVISITOR_H_

