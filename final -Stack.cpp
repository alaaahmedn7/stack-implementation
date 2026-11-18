#include<iostream>
using namespace std;
const int size = 5;

void push(int stack[] , int &top , int data)
{
	top++;
	stack[top]=data;
}

int pop(int stack[],int &top)
{
	int x=stack[top];
	top--;
	return x;
	
}

void print(int stack[] , int top)
{
	while(top!=-1)
	cout<<pop(stack , top);
}

int count(int stack[] , int top)
{
	return top + 1;
}

void rev(int stack[],int top)
{
	int s1[size],top1=-1,s2[size],top2=-1;
	
	while(top != -1)
	push(s1,top1,pop(stack,top));
	
	while(top1 != -1)
	push(s2,top2 ,pop(s1,top1));
	
	while(top2 != -1)
	push(stack,top,pop(s2,top2));
	
	print (stack,top);
	
}

//void delete_value(int stack,int &top,int data)
//{
//	int s1[size],top1=-1,temp;
//	
//	temp = pop(stack,top);
//	if(temp != data)
//	push(s1,top1,temp)
////	ليش كتبنا temp
//	{
//		while (top1!=-1)
//		push(stack,top,pop(s1,top1))
//	}
//	print(stack,top)
//}

void sum_odd_even(int stack[] , int top)
{
	int s1[size], top1=-1,even=0,odd=0,temp;
	
	while(top != -1)
	temp=pop(stack,top);
	if(temp %2 ==0)
	even++;
	odd++;
	
	cout<<"even = " <<even;
	cout<<"odd = " <<odd;
	
}

void delete_odd(int stack[],int &top)
{
	int s1[size], top1=-1, temp;
	
	while(top !=-1){
	temp=pop(stack,top);
	
	if(temp %2 ==0)
	push(s1,top1,temp);
}
    while(top1 !=-1)
    push(stack,top,pop(s1,top1));
}


void delete_neg(int stack[],int &top)
{
	int s1[size],top1=-1,temp;
	
	while(top!=-1){
	temp=pop(stack,top);
	if(temp > 0)
	push(s1,top1,temp);
	}
	while(top1 !=-1)
	push(stack,top,pop(s1,top1));
}

void restore_even_odd(int stack[],int top)
{
	int even[size],tope=-1,odd[size],topd=-1,temp;
	
	while(top!=-1){
		
	temp=pop(stack,top);
	
	if(temp %2 ==0){
	push(even,tope,temp);
	}
	else{
	push(odd,topd,temp);
	}
}
   while(tope!=-1)
   push(stack,top,pop(even,tope));
   while(topd!=-1)
   push(stack,top,pop(odd,topd));
}

int main()
{
	int stack[size], top = -1;
	int data,op;
	
	while(1)
	{
		cout <<"\n 1-puch \n 2-pop \n 3-print \n 4-count\n 5-rev \n";
		cin>>op;
		switch(op)
		{
			case 1 :
				if(top == size-1)
				cout<<"stack fall";
				else 
				{
				cout<<"Enter data : \n ";
				cin>>data;
				push(stack,top,data);
				}
				break;
			
			case 2 :
			if(top == -1)
		    cout<<"stack is empety"<<endl;
		    else 
		    cout<<pop(stack,top);

		    break;
		    
		    case 3 : 
			if(top == -1)
		    cout<<"stack is empety"<<endl;
		    print(stack,top);
		    break;
		    
		    case 4:
		    if(top == -1)
		    cout<<"stack is empety"<<endl;
		    else 
		    cout<<count(stack,top);
		    break;
		    
		    case 5:
		    if(top == -1)
		    cout<<"stack is empety"<<endl;
		    else 
		    rev(stack,top);
		    break;
		    
//		    	case 6:
//				if(top == -1)
//					cout<<"stack empty \n";
//				else{
//					cout<<"enter data : \n";
//						cin>>data;
//				delate_val(stack,top,data);
//				}
//				break;	
			
			case 7:
				if(top == -1)
					cout<<"stack empty \n";
				else{
					sum_odd_even(stack,top);
				}
				break;
					
			case 8:
				if(top == -1)
					cout<<"stack empty \n";
				else{
					restore_even_odd(stack,top);
				}
				break;	
				
			case 9:
				if(top == -1)
					cout<<"stack empty \n";
				else{
					delete_neg(stack,top);
				}
				break;
		}
	}
}


