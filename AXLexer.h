/*
 * Yet Another HSP Compiler
 *
 * AXLexer.h : Header of AX IR Code Lexer
 *
 * Last modified: 2010/02/04
 *
 * Copyright (C) oksoftware. All rights reserved.
 *
 */
#include <istream>
#include <vector>
#include "AXStruct.h"

typedef struct {
	unsigned short *jumpto, bytes;
} JumpToStack;

class AXLexer : public AXFile {
	private:
		std::istream *src;
		std::vector<JumpToStack> jumpToStack;
	public:
		AXLexer(std::istream *src);
		void lex();
	private:
		int getInt();
		short getShort();
		unsigned int getUnsignedInt();
		unsigned short getUnsignedShort();
		char getChar();
		template <class T> std::vector<T> *getList(std::istream *src, T (*func)(), int begin, int length);
		AXHeader *getHeader();
		AXIR *getIR(int *len);
		std::vector<AXIR *> *getIRList();
		unsigned char *getDataSegment();
		std::vector<int> *getObjectTemp();
		std::vector<unsigned char> *getDINFO();
		AXLibDat *getLIBDAT();
		std::vector<AXLibDat *> *getLIBDATList();
		AXStructDat *getSTRUCTDAT();
		std::vector<AXStructDat *> *getSTRUCTDATList();
		AXStructPrm *getSTRUCTPRM();
		std::vector<AXStructPrm *> *getSTRUCTPRMList();
		AXHpiDat *getHPIDAT();
		std::vector<AXHpiDat *> *getHPIDATList();
		
};
