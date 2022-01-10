
#ifndef __DOUBLE_LINK_H__
#define __DOUBLE_LINK_H__


#include "stdint.h"
#include "stddef.h"
/* ���������ض��� */
#define portCHAR char
#define portFLOAT float
#define portDOUBLE double
#define portLONG long
#define portSHORT short
#define portSTACK_TYPE uint32_t
#define portBASE_TYPE long
typedef portSTACK_TYPE StackType_t;
typedef long BaseType_t;
typedef unsigned long UBaseType_t;
#if( configUSE_16_BIT_TICKS == 1 )
typedef uint16_t TickType_t;
#define portMAX_DELAY ( TickType_t ) 0xffff
#else
typedef uint32_t TickType_t;
#define portMAX_DELAY ( TickType_t ) 0xffffffffUL
#endif


struct xLIST_ITEM
{
	TickType_t xItemValue; /* ����ֵ�����ڰ����ڵ���˳������ */
	struct xLIST_ITEM* pxNext; /* ָ��������һ���ڵ� */
	struct xLIST_ITEM* pxPrevious; /* ָ������ǰһ���ڵ� */
	void* pvOwner; /* ָ��ӵ�иýڵ���ں˶���ͨ���� TCB */
	void* pvContainer; /* ָ��ýڵ����ڵ����� */
};
typedef struct xLIST_ITEM ListItem_t; /* �ڵ����������ض��� */



struct xMINI_LIST_ITEM
{
	TickType_t xItemValue; /* ����ֵ�����ڰ����ڵ����������� */
	struct xLIST_ITEM* pxNext; /* ָ��������һ���ڵ� */
	struct xLIST_ITEM* pxPrevious; /* ָ������ǰһ���ڵ� */
};
typedef struct xMINI_LIST_ITEM MiniListItem_t; /* ����ڵ����������ض��� */

typedef struct xLIST
{
	UBaseType_t uxNumberOfItems; /* ����ڵ������ */
	ListItem_t* pxIndex; /* ����ڵ�����ָ�� */
	MiniListItem_t xListEnd; /* �������һ���ڵ� */
} List_t;



#endif
