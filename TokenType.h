#pragma once

#include "stdafx.h"

enum TokenType
{
	SPECIAL_SYMBOL,
    NUM,
    ID,
    COMMENT,
    FORM_START,
    FORM_END,
	STRING,
    BOOLEAN,

    // ���²����ʷ������׶�ʹ��
	FORM,
	FORMLIST,
    ORIGINAL_FUNC,
    SS_FUNCTOR,
    NIL,
    LIST,
    // PAIR
};
