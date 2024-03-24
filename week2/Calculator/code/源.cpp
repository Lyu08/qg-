#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_LEN 100

/*由于之前写过类似的程序，就沿用了之前的思路，没有用规范的栈的操作来写Orz......*/

double calc(char* exp);//计算函数
int priority(char op);//优先级
double operate(double n1, char op, double n2);//运算，包括加减乘除和次方
int isNumber(char c);
int isOperator(char c);
char expression[MAX_LEN];

int main() {
    while (1) {
        printf("键入井号#退出系统\n请输入表达式>>>");
        gets_s(expression);
        if (expression[0] == '#')break;
        printf("结果为%.5lf\n", calc(expression));
        system("pause");
        system("cls");
    }
    return 0;
}


double calc(char* exp) {
    double num_stack[MAX_LEN];
    char op_stack[MAX_LEN];
    int num_top = -1, op_top = -1, i = 0, flag = 1;//数字和符号栈顶的状态
    while (exp[i] != '\0') {
        if (exp[i] == ' ') {//空格不处理
            i++;
            continue;
        }
        else if (isNumber(exp[i]))//如果是数字
        {
            char num_exp[MAX_LEN];
            int k = 0;
            while (isNumber(exp[i]))
            {
                num_exp[k++] = exp[i++];//存入数字的栈
            }
            num_exp[k] = '\0';
            double num = atof(num_exp);
            if (exp[i] == '.') {//如果遇到小数点
                i++;
                char point[MAX_LEN] = "0.";//构建小数部分
                int j = 2;
                while (isNumber(exp[i]))
                {
                    point[j++] = exp[i++];//把小数部分存进去
                }
                num = atof(point) + num;// 把字符串转换成浮点数，构成小数数字
            }
            if (flag == 1 && exp[0] == '-')//处理第一个出现负数情况
            {
                num = num * (-1);
                op_top = -1;
                flag = 0;
            }
            num_stack[++num_top] = num;
        }
        else if (isOperator(exp[i])) {//如果是符号
                                //比较符号栈顶和遇到的符号优先级大小
            while (op_top && (priority(op_stack[op_top]) >= priority(exp[i])))
            {
                //弹出数字栈顶元素和符号栈顶赋给n1，n2，op进行运算
                double n2 = num_stack[num_top--];
                double n1 = num_stack[num_top--];
                char op = op_stack[op_top--];
                num_stack[++num_top] = operate(n1, op, n2);
            }
            op_stack[++op_top] = exp[i++];
        }
        else if (exp[i] == '(') {//遇到括号
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
            else if (exp[i] == ' ') i++;//空格不处理
            else {
                printf("请重试，错误：%c\n", exp[i]);
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

//判断运算符
int isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
        return 1;
    }
    else return 0;
}