#include"satck.h"
void StackInit(Stack* ps)
{
	assert(ps);
	ps->arry=NULL;
	ps->_capacity=0;
	ps->_top=0;
}
void StackDestory(Stack* ps)
{
	assert(ps);
	if(ps->_top!=NULL)
	{
		free(ps->arry);
		ps->_capacity=0;
		ps->_top;
	}
}
void StackPush(Stack* ps,StackDataType x)
{
    assert(ps);
	if(ps->_top==ps->_capacity)
	{
		size_t newcapacity=ps->_capacity==0 ? 2 : ps->_capacity*2;
		ps->arry=(StackDataType*)realloc(ps->arry,newcapacity*sizeof(StackDataType*));
		ps->_capacity=newcapacity;
	}
	ps->arry[ps->_top]=x;
	ps->_top++;

}
void StackPop(Stack* ps)
{
	assert(ps&&ps->_top>0);
	--ps->_top;

}
StackDataType StackTop(Stack* ps)
{
	assert(ps&&ps->_top>0);
	return ps->arry[ps->_top-1];
}

size_t StackSize(Stack*ps)
{
    assert(ps);
	return ps->_top;
}

//bool StackEmpty(Stack*ps)
//{
//	assert(ps);
//	return ps->_top;
//}