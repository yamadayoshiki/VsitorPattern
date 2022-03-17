#include "StringVisitor.h"
#include "MsgpackVisitor.h"
#include <string>
using namespace std;

void StringVisitor::visit(MsgPackVisitor* pMsgpack) {
	char str[20] = "";
	fread(&str, sizeof(str[0]), sizeof(str), pMsgpack->getFile());
	printf("%s\n",str);
}