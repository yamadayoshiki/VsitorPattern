#include "DoubleVisitor.h"
#include "MsgpackVisitor.h"
#include <string>
#include <sstream>
#include <bitset>
#include <iostream>
#include <vector>

void DoubleVisitor::visit(MsgPackVisitor* pMsgpack) {
	//fread(&num, sizeof(num), 1, pMsgpack->getFile());
	//printf("%f\n", num);

	double num = -1.0f;
	unsigned char buff;
	size_t readn = 0;
	size_t i;
	int counter = 0;
	std::vector<std::string> data;
	FILE* fp = pMsgpack->getFile();
	fseek(fp, 0, SEEK_SET);

	//1�o�C�g���m�F
	while (readn = fread(&buff, 1, 1, fp))
	{
		std::stringstream ss;
		ss << std::bitset<8>(buff); //2�i���ɕϊ�
		string s = ss.str();
		counter++;

		//�����������ǂ�����bit�Ŕ��f
		if (s == "11001011") {
			break;
		}
	}

	//unsigned char buffs[8];
	//fseek(fp, counter, SEEK_SET);
	//fread(&buffs, sizeof(unsigned char), 8, pMsgpack->getFile());
	//for (auto c : buffs) {
	//	printf("%02X ", c);
	//}
	//printf("\n");
	//�t�@�C���̓ǂݍ��ݐ���w��
	fseek(fp, counter, SEEK_SET);
	fread(&num, sizeof(double), 1, fp);
	printf("%f\n", num);
}