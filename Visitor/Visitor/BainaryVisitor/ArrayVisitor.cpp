#include "ArrayVisitor.h"
#include "MsgpackVisitor.h"
#include <string>
#include <string>
#include <sstream>
#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

void ArrayVisitor::visit(MsgPackVisitor* pMsgpack) {
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
		string substr = s.substr(0, 4);
		//配列かどうかをbitで判断
		if (substr == "1001") {
			break;
		}
	}

	//unsigned char str[16] = "";
	readn = 0;
	std::vector<unsigned char> result;
	fseek(fp, 0, SEEK_SET);

	int num;
	fread(&num, sizeof(int), 1, fp);
	printf("%d\n", num);

	double d;
	fread(&d, sizeof(double), 1, fp);
	printf("%lf\n", d);

	char str[16];
	fread(&str, sizeof(unsigned char), sizeof(str), fp);
	printf("%s\n", str);

	//while (readn = fread(&str, sizeof(str[0]), sizeof(str), fp)) {
	//	for (i = 0; i < readn; i++) {
	//		result.push_back(str[i]);
	//	}
	//}
	//for (auto s : result) {
	//	printf("%d ", s);
	//}

}