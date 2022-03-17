#ifndef STRINGVISITOR_H_
#define STRINGVISITOR_H_

#include "Visitor.h"

class StringVisitor : public Visitor {
public:
	virtual void visit(MsgPackVisitor* pMsgpack) override;
};
#endif // !STRINGVISITOR_H_