#include "LinkStack.h" 
#include <stdlib.h>
//��ջ

//��ʼ��ջ
Status initLStack(LinkStack *s){
	s->top = (LinkStackPtr*)malloc(sizeof(LinkStack));
	if (!s->top) {
		printf("�ڴ����ʧ�ܡ�\n");
		return ERROR;
	}
	else {
		s->top = NULL;
		s->count = 0;
		return SUCCESS;
	}
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack *s){
	if (s->count == 0) return SUCCESS;
	else return ERROR;
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack *s,ElemType *e){
	if (isEmptyLStack==1 || s->top == NULL  ) {
		printf("��ǰû��ջ��ջΪ�գ�û��ջ��Ԫ�ء�");
		/*if (isEmptyLStack)printf("!!!");*/
			return ERROR;
	}
	else {
		e = s->top->data;//ָ��ջ��Ԫ�ص�������
		printf("%d", e);
		return SUCCESS;
	}
}

//���ջ
Status clearLStack(LinkStack *s){
	if (isEmptyLStack){
		printf("ջ�Ѿ�Ϊ�ա�");
		return ERROR;
	}
	else {
		while (s->count > 0) {
			LinkStackPtr *del;//���Ҫɾ����ָ��
			del = s->top->next;
			free(s->top);//��ջ����ʼɾ�����
			s->top = del;
			s->count--;
			printf("�����ջ��\n");
		}
		printf("%d", s->count);
		return SUCCESS;
	}
}

//����ջ
Status destroyLStack(LinkStack *s){
	if (!s->top|| s->count == 0) {
		printf("��ǰû��ջ��ջΪ�գ������²�����\n");
		return ERROR;
	}
	else {
		clearLStack(&s);//�Ȱ�ջ�����ֻʣһ��ջ��
		s->top = NULL;
		free(s->top);
		printf("������ջ��\n");
		return SUCCESS;
	}
}

//���ջ����
Status LStackLength(LinkStack *s,int *length){
	if (s->count==0) {/*
		printf("��ǰû��ջ�����ȳ�ʼ��ջ��");*/
		return ERROR;
	}
	else {
		length = s->count;
		printf("ջ�ĳ���Ϊ��%d\n", length);
		return SUCCESS;
	}
}

//��ջ
Status pushLStack(LinkStack *s,ElemType data){
	if (!s) {
		printf("��ǰû��ջ�����ȳ�ʼ��ջ��");
		return ERROR;
	}
	else {
		StackNode* node = (StackNode*)malloc(sizeof(StackNode));//�����½��
		if (!node) {
			printf("�ڴ����ʧ�ܡ�\n");
			return ERROR;
		}
		else {
			node->data = data;
			node->next = s->top;//�½����ָ��ԭ����ջ��Ԫ��
			s->top = node;//���½����Ϊջ��ָ��
			s->count++;
			printf("�������Ѿ�ѹ��ջ��\n");
			return SUCCESS;
		}
	}
}

//��ջ
Status popLStack(LinkStack *s,ElemType *data){
	if (!s->top) {
		printf("��ǰû��ջ�����ȳ�ʼ��ջ��");
		return ERROR;
	}
	else {
		LinkStackPtr newtop = s->top->next;//�Ȼ��ԭ����ջ������һ��Ԫ��
		data = s->top->data;//���ջ��Ԫ��
		free(s->top);
		s->top = newtop;//��ջ�������Ϊԭ���ĵڶ������
		s->count--;
		printf("�Ѿ���ջ��Ԫ�ص���ջ��\n");
		return SUCCESS;
	}
}