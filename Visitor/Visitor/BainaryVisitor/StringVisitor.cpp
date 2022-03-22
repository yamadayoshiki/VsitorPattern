#include "StringVisitor.h"
#include "MsgpackVisitor.h"
#include <string>
#include <string>
#include <sstream>
#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

void StringVisitor::visit(MsgPackVisitor* pMsgpack) {


	unsigned char buff;
	size_t readn = 0;
	size_t i;
	int counter = 0;
	FILE* fp = pMsgpack->getFile();
	fseek(fp, 0, SEEK_SET);

	//1バイトずつ確認
	while (readn = fread(&buff, 1, 1, fp))
	{
		stringstream ss;
		ss << bitset<8>(buff); //2進数に変換
		string s = ss.str();
		counter++;
		//先頭3bitを取得
		string substr = s.substr(0, 3);
		//配列かどうかをbitで判断
		if (substr == "101") {
			break;
		}
	}

	fseek(fp, counter, SEEK_SET);
	char str[256] = "";
	fread(&str, sizeof(str[0]), sizeof(str), pMsgpack->getFile());
	printf("%s\n", str);
}