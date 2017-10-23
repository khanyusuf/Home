#include<stdio.h>
#include<ctype.h> //for isaplha() function

typedef struct conversion
{
	char a[30];
	int top;
}stack;

void push(stack*,char);

int pop(stack*);

int evaluation(char post[]);

int operation(int n1,int n2,char opr);

int main()
{
	char postfix[30];
	printf("\nENTER POSTFIX EXPRESSION\n");
	scanf("%s",postfix);
	printf("\n\EVALUATION of POSTFIX EXPRESSION\n%d",evaluation(postfix));
	return 0;
}



void push(stack *s,char opr)
{
	s->top++;
	s->a[s->top]=opr;
}

char pop(stack *s)
{
	if (s->top==-1)
	{
		printf("stack is empty\n");
		return 0;
    }
    else
    {
		char data=s->a[s->top--];
		return data;
    }
}

int evaluation(char post[])
{
	int n1,n2,result;
	stack s;
	int i=0;
	s.top=-1;
	
	 while(post[]!='\0')
	 {
		if(isdigit(post[i]))
		 push(&s,post[i]-'0')
		 
		 
		 else 
		 {
			 n1=pop(&s1);
			 n2=pop(&s1);
			 result=operation(n1,n2,post[i]);
			 push(&s,result);
			 
			 
			 }
		 i++
	 } 
		 
		 
		 
	}
	
	
	




int operation(int n1,int n2,char opr)
{
		switch(opr)
	{
		 
	  case '+':return n1+n2;
	  case '-':return n1-n2;
	  case '*':return n1*n2;
	  case '/':return n1/n2;
	
	
	}
}
