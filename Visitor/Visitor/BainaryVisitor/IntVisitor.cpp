#include "IntVisitor.h"
#include "MsgpackVisitor.h"
#include <string>
#include <sstream>
#include <bitset>
#include <iostream>

void IntVisitor::visit(MsgPackVisitor* pMsgpack) {
	//int num;
	//fread(&num, sizeof(num), 1, pMsgpack->getFile());
	//printf("%d\n", num);

	unsigned char buff;
	size_t readn = 0;
	size_t i;

	while (readn = fread(&buff, 1, 1, pMsgpack->getFile()))
	{
		std::stringstream ss;
		ss << std::bitset<8>(buff); //2�i���ɕϊ�
		string s = ss.str();
		//�擪4bit���擾
		string substr = s.substr(0, 4);
		//�������ǂ�����擪��bit�Ŕ��f
		if (substr <= "0111") {
			printf("%d\n", buff);
			break;
		}
	}
}