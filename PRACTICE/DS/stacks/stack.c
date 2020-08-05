#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 5
int stack[CAPACITY], top = -1;
int isfull(){
	if (top == CAPACITY - 1) 
		return 1;
	return 0;
}
int isempty(){
	if (top == - 1) 
		return 1;
	return 0;
}
void push(int element){
	if (isfull()) 
		printf("\nSTACK OVERFLOW\n\n");
	else
		stack[++top] = element;
}
int pop() {
	if (isempty()) 
		printf("\nSTACK UNDERFLOW\n\n");
	else
		return stack[top--];
}
int peek(){
	if (isempty())
		printf("\nSTACK UNDERFLOW\n\n");
	else
		return stack[top];
}
int main(){
	int element, ch;
	while (1) {
		printf("\n1.push\n2.pop\n3.peek\n4.exit\n");
		scanf("%d", &ch);
		switch (ch) {
		case 1:
			scanf("%d", &element);
			push(element);
			break;
		case 2: 
			element = pop();
			printf("%d popped\n", element );
			break;
		case 3: 
			element = peek();
			printf("%d peeked\n", element );
			break;
		case 4: 
			exit(0);
		default: 
			printf("\nWrong choice\n");
		}
	}
}