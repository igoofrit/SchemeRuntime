#pragma once
#include "StrStream.h"
#include "SEnv.h"
#include "SPool.h"
#define FORM_START_CHAR '('
#define FORM_END_CHAR ')'
#define COMMENT_START_CHAR ';'
#define COMMENT_END_CHAR '\n'
#define STRING_WRAPPER '"'
#define isFormChar(c) ((c) == FORM_START_CHAR || (c) == FORM_END_CHAR)
#define isWhiteSpace(c) ((c) == ' ' || (c) == '\t' || (c) == '\n' || (c) == ',')
#define isDigit(c) ((c) >= '0' && (c) <= '9')
#define isSpecialChar(c) (isFormChar(c) || (c) == COMMENT_START_CHAR)
#define isLetter(c) ((c) >= 'A' && (c) <= 'z')

class SFormList;
class SFormItem;
class SForm;
class SEnv;
class SPool;

class SchemeRuntime
{
private:
	StrStream *stream;
	SFormList *list;
	SEnv *env;
	void resetStream();
	void resetFormList();
public:
	SPool *itemsPool;
	SEnv *getEnv() const;
public:
	void initEnv();
	SFormItem *findInEnv(string name);
	void pushToCurEnv(string name, SFormItem *value);
	SFormItem *evalInNewEnv(SFormItem *item);
	SFormItem *evalInCurEnv(SFormItem *item);
	bool downEnv(); // �ڻ���������ײ��´���һ���µĻ�����Ϊ��ǰ����
	bool upEnv(); // ȡ���������ĵ�ǰ�������ĳɵ�ǰ��������һ�㻷�������������⣩
public:
	SchemeRuntime(void);
	virtual ~SchemeRuntime(void);
public:
	void loadStr(string str);
	void loadProgram(string filepath);
	SFormList* lexAnalise();
	bool run();
};

