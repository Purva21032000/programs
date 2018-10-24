#include<iostream>
using namespace std;
class node
{public:
	int no;
	node *next;
	
};
class numbers
{
	public:
	node *head,*head1,*head2,*head3,*headn;
	node *temp;
		numbers()
	{
		head=NULL;              
		head1=NULL;             //positive
		head2=NULL;             //negative
		head3=NULL;             //merge
	}
void display(node *headn)
{
	for(temp=headn;temp!=NULL;temp=temp->next)
	{
		cout<<temp->no<<" ";
	}
}
void add(int a,node *headn)
{
	if(headn==NULL)
	{
		headn=new node;
		headn->no=a;
		headn->next=NULL;
		
	}
	else
	{temp=new node;
	temp->next=headn;
	temp->no=a;
	headn=temp;
	}
}	
void create()
{	int count,x;
	
	cout<<"How many no do you want to insert? ";
	cin>>count;
	cout<<"Enter numbers:"<<endl;
	for(int i=0;i<count;i++)
	{cin>>x;
	add(x,head);
	}
	
	display(head);
	
}
void seperate()
{for(temp=head;temp!=NULL;temp=temp->next)
	{
		if((temp->no)<0)
		{ add(temp->no,head2);
		}
		else if((temp->no)>=0)
		{ add(temp->no,head3);
		}
	}       
}
void sort(node *head_n)
{
	node *temp1;
	node *temp2;
	int num;
	for(temp1=head_n;temp1!=NULL;temp1=temp1->next)
	{
		for(temp2=temp1->next;temp2!=NULL;temp2=temp2->next)
		{
			if((temp1->no) > (temp2->no))
			{
			num=temp1->no;
			temp1->no=temp2->no;
			temp2->no=num;
			}
		}
	}
}
void merge(node *head1,node *head2)
{
	node *temp1;
	node *temp2;
	
	for(temp=head1;temp!=NULL;temp=temp->next)
	{
		add(temp->no,head3);
	}
	for(temp=head2;temp!=NULL;temp=temp->next)
	{
		add(temp->no,head3);
	}
}
void del_neg(node *headn)
{node *temp2,*temp3;
	for(temp=headn;temp!=NULL;temp=temp->next)
	{
		if(temp->no < 0) // if negative number is found
			{
				if(temp==headn) // if the negative number is in the start
				{
					temp=headn;
					headn=headn->next;
					delete temp;
				    temp=headn;
					
				}
				else if(temp->next == NULL) //if the negative number is last in the list
				{
					temp=headn;
							while(temp->next)
							{
								temp2=temp;
								temp=temp->next;
							}
						temp2->next = NULL;
						temp=headn;
						
				}
				else //if the negative number is somewhere in the middle
				{
				  temp2=headn;
				  
				 while(temp2->next == temp)
				 {
					 temp3=temp2;
					 temp2=temp2->next;
				 }
				  temp3->next = temp->next;
				   temp=headn;
					
				}

			}
			else if(temp->no > 0) // if the number is positive
			{
				temp=temp->next;
			}
	}
}

	
};
int main()
{
	numbers n;
	
	int ch;
	int num;

	do
	{
		cout<<"1.Enter number\n2.seperate positive and negative number\n3.Sort negative list\n4.sort positive list\n5.Merge two list into third one\n6.Delete negative numbers\n7.Exit\n";
		cout<<"Enter choice\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
					n.create();
					n.display(n.head);
					break;
			case 2:
					n.seperate();
					cout<<"List of Negative numbers\n";
					n.display(n.head1);
					cout<<"List of positive numbers\n";
					n.display(n.head2);
					break;
			case 3:
					cout<<"Sorted list of negative numbers\n";
					n.sort(n.head1);
					n.display(n.head1);
					break;
			case 4:
					cout<<"Sorted ist of positive numbers\n";
					n.sort(n.head2);
					n.display(n.head2);
					break;
			case 5:cout<<"Merge list\n";
					n.merge(n.head1,n.head2);
					break;
			case 6:n.del_neg(n.head3);
		         	break;
		    case 7:break;
					
					
		}
	}while(ch!=7);
	return 0;
}
