#include "DoubleVisitor.h"
#include "MsgpackVisitor.h"

void DoubleVisitor::visit(MsgPackVisitor* pMsgpack) {
	double num;
	fread(&num, sizeof(num), 1, pMsgpack->getFile());
	printf("%f\n", num);
}