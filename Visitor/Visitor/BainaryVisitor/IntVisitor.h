#ifndef INTVISITOR_H_
#define INTVISITOR_H_

#include "Visitor.h"

class IntVisitor : public Visitor {
public:
	virtual void visit(MsgPackVisitor* pMsgpack) override;
};
#endif // !INTVISITOR_H_
