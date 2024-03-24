#include "LinkStack.h" 
#include <stdlib.h>
//链栈

//初始化栈
Status initLStack(LinkStack *s){
	s->top = (LinkStackPtr*)malloc(sizeof(LinkStack));
	if (!s->top) {
		printf("内存分配失败。\n");
		return ERROR;
	}
	else {
		s->top = NULL;
		s->count = 0;
		return SUCCESS;
	}
}

//判断栈是否为空
Status isEmptyLStack(LinkStack *s){
	if (s->count == 0) return SUCCESS;
	else return ERROR;
}

//得到栈顶元素
Status getTopLStack(LinkStack *s,ElemType *e){
	if (isEmptyLStack==1 || s->top == NULL  ) {
		printf("当前没有栈或栈为空，没有栈顶元素。");
		/*if (isEmptyLStack)printf("!!!");*/
			return ERROR;
	}
	else {
		e = s->top->data;//指向栈顶元素的数据域
		printf("%d", e);
		return SUCCESS;
	}
}

//清空栈
Status clearLStack(LinkStack *s){
	if (isEmptyLStack){
		printf("栈已经为空。");
		return ERROR;
	}
	else {
		while (s->count > 0) {
			LinkStackPtr *del;//存放要删除的指针
			del = s->top->next;
			free(s->top);//从栈顶开始删除结点
			s->top = del;
			s->count--;
			printf("已清空栈。\n");
		}
		printf("%d", s->count);
		return SUCCESS;
	}
}

//销毁栈
Status destroyLStack(LinkStack *s){
	if (!s->top|| s->count == 0) {
		printf("当前没有栈或栈为空，请重新操作。\n");
		return ERROR;
	}
	else {
		clearLStack(&s);//先把栈清空至只剩一个栈顶
		s->top = NULL;
		free(s->top);
		printf("已销毁栈。\n");
		return SUCCESS;
	}
}

//检测栈长度
Status LStackLength(LinkStack *s,int *length){
	if (s->count==0) {/*
		printf("当前没有栈，请先初始化栈。");*/
		return ERROR;
	}
	else {
		length = s->count;
		printf("栈的长度为：%d\n", length);
		return SUCCESS;
	}
}

//入栈
Status pushLStack(LinkStack *s,ElemType data){
	if (!s) {
		printf("当前没有栈，请先初始化栈。");
		return ERROR;
	}
	else {
		StackNode* node = (StackNode*)malloc(sizeof(StackNode));//申请新结点
		if (!node) {
			printf("内存分配失败。\n");
			return ERROR;
		}
		else {
			node->data = data;
			node->next = s->top;//新结点先指向原来的栈顶元素
			s->top = node;//把新结点置为栈顶指针
			s->count++;
			printf("该数据已经压入栈。\n");
			return SUCCESS;
		}
	}
}

//出栈
Status popLStack(LinkStack *s,ElemType *data){
	if (!s->top) {
		printf("当前没有栈，请先初始化栈。");
		return ERROR;
	}
	else {
		LinkStackPtr newtop = s->top->next;//先获得原来的栈顶的下一个元素
		data = s->top->data;//获得栈顶元素
		free(s->top);
		s->top = newtop;//把栈顶结点置为原来的第二个结点
		s->count--;
		printf("已经将栈顶元素弹出栈！\n");
		return SUCCESS;
	}
}