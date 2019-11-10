#include<stdio.h> 
struct stack 
{ 
	int a[20]; 
	int top; 
	int capacity; 
}s; 
void initstack(int size) 
{ 
	s.top=-1; 
	s.capacity=size; 
} 
int isfull() 
{ 
	if(s.top==s.capacity-1) 
		return 1; 
	else 
		return 0; 
} 
void push(int n) 
{ 
	if(isfull())	 
		printf("Fatal Error:Stack is full!!"); 
	else 
	{ 
		s.top++; 
		s.a[s.top]=n; 
	} 
} 
int isempty() 
{ 
	if(s.top==-1) 
		return 1; 
	else 
		return 0; 
} 
int pop() 
{ 
	if(isempty()) 
		printf("Fatal Error:Stack is empty!!"); 
	else 
	  //printf("Item Popped: %d",s.a[s.top--]);
	return s.a[s.top--];
} 
void peek() 
{ 
	printf("Top element : %d",s.a[s.top]); 
}	 
void peekandpop() 
{ 
	peek(); 
	printf("\n"); 
	pop(); 
} 
void display() 
{ 
	int n; 
	n=s.top; 
	if(s.top==-1) 
  		printf("Fatal Error:Stack is empty!!"); 
	else 
	{ 
		printf("Contents of the stack:-\n"); 
	 	while(n!=-1) 
		printf("%d\t",s.a[n--]); 
	} 
} 
void makeempty() 
{    
	s.top=-1; 
} 

int count() 
{ 
	return s.top+1; 
} 
void create() 
{ 
	int x,op; 
	do 
	{ 
		printf("\nEnter the element to be added to the stack"); 
		scanf("%d",&x); 
		push(x); 
printf("\nDo you want to add another element to the stack?(1.yes/2.no)"); 
		scanf("%d",&op); 
	}while(op==1); 
}
/*
int main() 
{ 
	int size,n,ch; 
	printf("Enter the capacity of the stack :"); 
	scanf("%d",&size); 
          initstack(size); 
	while(1) 
	{ 
printf("\nMENU :\n\t1)Create\n\t2)Push\n\t3)Pop\n\t4)Peek\n\t5)Peek and Pop\n\t6)Display\n\t7)Make Empty\n\t8)Count\n\t9)Exit\nChoice: "); 
scanf("%d",&ch); 
                    if(ch==9) 
        		break; 
		switch(ch) 
		{ 
			case 1: 
				create(); 
				break; 
			case 2: 
	                		printf("Enter the element to be pushed :"); 
			   	scanf("%d",&n); 
			  	push(n); 
			  	break; 
			case 3: 
				pop(); 
				break; 
			case 4: 
				peek(); 
				break; 
			case 5:	 
				peekandpop(); 
				break; 
			case 6:	 
				display(); 
				break; 
			case 7:	 
				makeempty(); 
				printf("Stack made empty!!!"); 
				break; 
			case 8: 
				printf("Count: %d",count()); 
				break;		 
			default:	 
				printf("Enter correct menu option!!"); 
		} 
	} 
	return 0; 
}
*/
