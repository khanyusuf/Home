#include<stdio.h>
#include<ctype.h> 

typedef struct conversion
{
	char a[30];
	int top;
}stack;

void push(stack*,char);

char pop(stack*);

int isMatch(char left,char right);

 void check(char exp[]);
 
 




int main()
{
	char exp[30];
	printf("\nENTER PARA EXPRESSION\n");
	scanf("%s",exp);
	check(exp);
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

int isMatch(char left,char right)

{
	switch(left)
	{
	case '(':
	    if(right==')')	
		return 1;
		else 
		return 0;
		
		case '{':
	    if(right=='}')	
		return 1;
		else 
		return 0;
		
		case '[':
	    if(right==']')	
		return 1;
		else 
		return 0;
		
		default:
		return 0;
	}
}


 void check(char exp[])


{
	int i;
	stack s;
	char c;
	s.top=-1;
	for(i=0;exp[i]!='\0';i++)
	{
	if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
	  {
		push(&s,exp[i]);
	  }	
	 else
	   {
		   if(s.top==-1)
		   {
		   printf("invalid expression");
		   return;
	   }
		   else
		   {
			c=pop(&s); 
			if(isMatch(c,exp[i]))
			{
				continue;
			}
			else
			{
				printf("invalid Expression");
				return;
			}
		}
	}
}
	       if(s.top==-1)
	       printf("BALANCED");
	       else
	       printf("Invalid Expression");
	
	}
