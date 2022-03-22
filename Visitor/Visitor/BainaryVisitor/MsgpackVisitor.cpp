#include "MsgpackVisitor.h"

MsgPackVisitor::MsgPackVisitor(string fileName) {
	fp_ = nullptr;
	Load(fileName);
}

MsgPackVisitor::~MsgPackVisitor() {
	fclose(fp_);
	delete fp_;
}

void MsgPackVisitor::Load(string fileName) {
	fopen_s(&fp_, fileName.c_str(), "rb");
}

void MsgPackVisitor::Accept(Visitor* pVisitor) {
	pVisitor->visit(this);
}

FILE* MsgPackVisitor::getFile() {
	return fp_;
}