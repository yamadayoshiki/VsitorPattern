#ifndef DOUBLEVISITOR_H_
#define DOUBLEVISITOR_H_

#include "Visitor.h"

class DoubleVisitor : public Visitor {
public:
	virtual void visit(MsgPackVisitor* pMsgpack) override;
};
#endif // !DOUBLEVISITOR_H_