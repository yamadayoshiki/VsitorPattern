#include "IntVisitor.h"
#include "MsgpackVisitor.h"

void IntVisitor::visit(MsgPackVisitor* pMsgpack) {
	int num;
	fread(&num, sizeof(num), 1, pMsgpack->getFile());
	printf("%d\n", num);
}