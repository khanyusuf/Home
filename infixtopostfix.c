#include<stdio.h>
#include<ctype.h> //for isaplha() function

typedef struct conversion
{
	char a[30];
	int top;
}stack;

void push(stack*,char);

char pop(stack*);

void checkbalenced(char exp[]);

int ismatchingpair(char left,char right);

int main()
{ 

	char exp[30];
	printf("\nENTER EXPRESSION CONTAINING PARENT\n");
	scanf("%s",exp);
	
	checkbalenced(exp);
	return 0;
	}
	
int ismatchingpair(char left,char right)

	{
	switch(left)
	{
		case'(':
		if(right==')')
		return 1;
		else
		return 0;
		
		case'[':
		if(right==']')
		return 1;
		else
		return 0;
		
		case'{':
		if(right=='}')
		return 1;
		else
		return 0;
		
		default:
		 return 0;
		}	
}
		
void checkbalenced(char exp[])
{
	int i;
	char c;
	stack s;
	s.top=-1;
	for(i=0;exp[i]!='\0';i++)
	{
			 if(exp[i]=='('||exp[i]=='['||exp[i]=='{')
			push(&s,exp[i]);
		 else
		 {
			 if(s.top!=-1)
				c=pop(&s);
			 else{
				printf("invalid expression");
				return;
			}
			if(ismatchingpair(c,exp[i]))
			continue;
			else
			{
			printf("invalid expression");
			return;
			}
		}
	}
		if(s.top==-1)
		printf("expression is valid");
		else
		printf("expression is invalid");
}	

void push(stack *s,char opr)
{
	s->top++;
	s->a[s->top]=opr;
}

char pop(stack *s)
{
	if(s->top==-1)
	{
		printf("stack is empty");
	return 0;
	}
	else
	{
		char data=s->a[s->top--];
		return data;
	
	}
}
		
	

