/*****************************************************************//**
 * \file   linkedstack.c
 * \brief  
 * 
 * \author 32353
 * \date   November 2020-11-11
 *********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "linkedstack.h"
#include "SList.h"

void linkedstack_free(SListEntry* linkedStack)
{
	slist_free(linkedStack);
}

SListEntry* linkedstack_push(SListEntry** linkedStack, SListValue data)
{
	return slist_prepend(linkedStack, data);
}

SListValue linkedstack_pop(SListEntry** linkedStack)
{
	SListValue result = slist_nth_data(*linkedStack, 0);
	if (slist_remove_entry(linkedStack, *linkedStack))
		return result;
	return SLIST_NULL;
}
SListValue linkedstack_peek(SListEntry* linkedStack)
{
	return slist_nth_data(linkedStack, 0);
}
int linkedstack_is_empty(SListEntry* linkedStack)
{
	return slist_is_empty(linkedStack);
}