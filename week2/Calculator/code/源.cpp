#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_LEN 100

/*����֮ǰд�����Ƶĳ��򣬾�������֮ǰ��˼·��û���ù淶��ջ�Ĳ�����дOrz......*/

double calc(char* exp);//���㺯��
int priority(char op);//���ȼ�
double operate(double n1, char op, double n2);//���㣬�����Ӽ��˳��ʹη�
int isNumber(char c);
int isOperator(char c);
char expression[MAX_LEN];

int main() {
    while (1) {
        printf("���뾮��#�˳�ϵͳ\n��������ʽ>>>");
        gets_s(expression);
        if (expression[0] == '#')break;
        printf("���Ϊ%.5lf\n", calc(expression));
        system("pause");
        system("cls");
    }
    return 0;
}


double calc(char* exp) {
    double num_stack[MAX_LEN];
    char op_stack[MAX_LEN];
    int num_top = -1, op_top = -1, i = 0, flag = 1;//���ֺͷ���ջ����״̬
    while (exp[i] != '\0') {
        if (exp[i] == ' ') {//�ո񲻴���
            i++;
            continue;
        }
        else if (isNumber(exp[i]))//���������
        {
            char num_exp[MAX_LEN];
            int k = 0;
            while (isNumber(exp[i]))
            {
                num_exp[k++] = exp[i++];//�������ֵ�ջ
            }
            num_exp[k] = '\0';
            double num = atof(num_exp);
            if (exp[i] == '.') {//�������С����
                i++;
                char point[MAX_LEN] = "0.";//����С������
                int j = 2;
                while (isNumber(exp[i]))
                {
                    point[j++] = exp[i++];//��С�����ִ��ȥ
                }
                num = atof(point) + num;// ���ַ���ת���ɸ�����������С������
            }
            if (flag == 1 && exp[0] == '-')//�����һ�����ָ������
            {
                num = num * (-1);
                op_top = -1;
                flag = 0;
            }
            num_stack[++num_top] = num;
        }
        else if (isOperator(exp[i])) {//����Ƿ���
                                //�ȽϷ���ջ���������ķ������ȼ���С
            while (op_top && (priority(op_stack[op_top]) >= priority(exp[i])))
            {
                //��������ջ��Ԫ�غͷ���ջ������n1��n2��op��������
                double n2 = num_stack[num_top--];
                double n1 = num_stack[num_top--];
                char op = op_stack[op_top--];
                num_stack[++num_top] = operate(n1, op, n2);
            }
            op_stack[++op_top] = exp[i++];
        }
        else if (exp[i] == '(') {//��������
            char bracket[MAX_LEN];
            int count = 1, bracket_len = 0;
            i++;
            while (count) {
                if (exp[i] == '(') count++;
                if (exp[i] == ')') count--;
                if (count != 0) bracket[bracket_len++] = exp[i];
                i++;
            }

            bracket[bracket_len++] = '\0';
/*          printf("%s", bracket);*/
            double num = calc(bracket);
            num_stack[++num_top] = num;
        }
        else if (exp[i] == ')'){
            i++;
            while (op_stack[op_top] != '(') {
                double n2 = num_stack[num_top--];
                double n1 = num_stack[num_top--];
                char op = op_stack[op_top--];
                num_stack[++num_top] = operate(n1, op, n2);
            }
            op_top--;
        }
        else {
            if (exp[i] == '(')
            {
                char bracket[MAX_LEN];
                int count = 1, bracket_len = 0;
                i++;
                while (count)
                {
                    if (exp[i] == '(') count++;
                    if (exp[i] == ')') count--;
                    if (count != 0) bracket[bracket_len++] = exp[i];
                    i++;
                }
                bracket[bracket_len++] = '\0';
                double num = calc(bracket);
                num_stack[++num_top] = sqrt(num);
            }
            else if (exp[i] == ' ') i++;//�ո񲻴���
            else {
                printf("�����ԣ�����%c\n", exp[i]);
                break;
            }
        }
    }
   
    
    while (op_top >= 0) {
        double n2 = num_stack[num_top--];
        double n1 = num_stack[num_top--];
        char op = op_stack[op_top--];
        num_stack[++num_top] = operate(n1, op, n2);
    }
    return num_stack[0];
}

int priority(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/' ) return 2;
    if (c == '^' ) return 3;
    return 0;
}

double operate(double n1, char op, double n2) {
    switch (op) {
    case '+': return n1 + n2;
    case '-': return n1 - n2;
    case '*': return n1 * n2;
    case '/': return n1 / n2;
    case'^': return pow(n1, n2);
    default:  return 0;
    }
}

int isNumber(char c){
    if (c >= '0' && c <= '9') return 1;
    else return 0;
}

//�ж������
int isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
        return 1;
    }
    else return 0;
}