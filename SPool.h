#pragma once
#include "SFormItem.h"
#include <set>

class SFormItem;

/*
 * SFormItem���󣨰����������󣩳أ����д���SFormItem��������������Ļ��Ǳ����������󶨵ģ�
 * ����ĵ�ַ���������д洢�����������н�����Ҫ�ͷ��������SFormItem����
 * �����ǵ�env���ܱ��ظ�ʹ�ã�����env���е�SFormItem����Ӧ�����̱�ɾ����Ϊ�˴ﵽ���Ŀ�ģ�ʹ��releaseExcept��������������
 **/

class SPool
{
private:
	set<SFormItem*> items;
public:
	SPool(void);
	virtual ~SPool(void);
public:
	void add(SFormItem* item);
	void remove(SFormItem* item);
	void releaseExcept(set<SFormItem*> *items);
	void display() const;
};

