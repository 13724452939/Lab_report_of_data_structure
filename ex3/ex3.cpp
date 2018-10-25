#include <iostream>
#include <string>
using namespace std;
const int TOTALLY_CORRECT=0;
const int LEFT_MORE_THAN_RIGHT=-3;
const int RIGHT_MORE_THAN_LEFT=-2;
const int PARTLY_CORRECT=1;
const int NOT_MATCH=-1;
int judge(char *top,char *base,char single_char);//判断是空栈或者是否左右括号不匹配 
char * pop(char *top,char *base);//栈顶出栈
char * push(char *top,char *base,char single_char);//栈顶进栈
int main()
{
	cout << "const int TOTALLY_CORRECT=0;" << endl;
	cout << "const int NOT_MATCH=-1;" << endl;
	cout << "const int RIGHT_MORE_THAN_LEFT=-2;" << endl;
	cout << "const int LEFT_MORE_THAN_RIGHT=-3;" << endl;
	cout << "---------------------------------" << endl;
	cout << "Please input the number of sample:";
	int times;
	cin >> times;
	if (times<=0)
	{
		cout << "Your input is wrong." << endl;
		return 0;
	}
	cin.sync();//去除掉后面的换行符 
	for (int i=0;i<times;++i)
	{
		string str;//输入的测试样本
		cout << "Sample " << (i+1) << " :";
		getline(cin,str);//string类型的读取行操作 
		int length=str.length();//样本长度
		if (length==0)
		{
			cout << TOTALLY_CORRECT << endl;
			continue;
		}
		char *stack=new char [length+1];//创建栈,最多情况是样本全为括号，且栈顶指在最后一个元素的下一个位置所以length+1 
		char *top,*base;
		top=base=stack;//栈头和栈尾指针 
		int judge_number=PARTLY_CORRECT;//const int PARTLY_CORRECT=1;
		for (int j=0;j<length;++j)
		{
			char single_char=char(str[j]);//代表样本中的其中一个字符 
			switch(single_char)
			{
				case '(':
					top=push(top,base,single_char);
					break;
				case '[':
					top=push(top,base,single_char);
					break;
				case '{':
					top=push(top,base,single_char);
					break;
				case ')':
					judge_number=judge(top,base,'(');
					if (judge_number==PARTLY_CORRECT) 
						top=pop(top,base);
					break;
				case ']':
					judge_number=judge(top,base,'[');
					if (judge_number==PARTLY_CORRECT)
						top=pop(top,base);
					break;
				case '}':
					judge_number=judge(top,base,'{');
					if (judge_number==PARTLY_CORRECT)
						top=pop(top,base);
					break;
			}
			if (judge_number!=PARTLY_CORRECT)
			{
				cout << judge_number << endl;
				break;
			}
		}
		if (judge_number==PARTLY_CORRECT && top==base)
			cout << TOTALLY_CORRECT << endl;//const int TOTALLY_CORRECT=0;
		else
			if (judge_number==PARTLY_CORRECT)
				cout << LEFT_MORE_THAN_RIGHT << endl;//const int LEFT_MORE_THAN_RIGHT=-3;
		delete [] stack;
	}
	return 0;
}

char * push(char *top,char *base,char single_char)//栈顶进栈
{
	*top=single_char;
	top=top+1;
	return top;
}

char * pop(char *top,char *base)//栈顶出栈
{
	top=top-1;
	return top;
}

int judge(char *top,char *base,char single_char)//此时的single_char均为样本中单个右括号所对应的左括号 
{
	if (top==base)//栈空 
		return RIGHT_MORE_THAN_LEFT;//const int RIGHT_MORE_THAN_LEFT=-2;
	if (*(top-1)!=single_char)
		return NOT_MATCH;//const int NOT_MATCH=-1;
	return PARTLY_CORRECT;
}

