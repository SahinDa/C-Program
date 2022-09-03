#include<iostream>
#include<cstring>
using namespace std;
class bin
{
	private :
		string num;
		int length;
	public :
		int get_length()
		{
			return num.size();
		}
	   string get_string(void)
	   {
	   	return num;
	   }
	   void display()
	   {
	   	 cout<<endl<<"Binary string  Is : "<<num<<endl;
	   }
	   int operator==(bin);
       bin operator-(bin);
	   bin operator+(bin);
	   void get_input();
	   int compa(bin b)
	   {
	   	int i;
	   	i=num.compare(b.num);
	   	return i;
		   }	
};
 void bin:: get_input()
{
			int p=1;
			while(p==1){
				p=0;
			cout<<"Enter a binary number : ";
			cin>>num;
			length=num.size();
		for(int i=length-1;i>=0;i--)
		{
			if(num[i]!='0' &&num[i]!='1')
			{
				system("cls");
				cout<<"\n NOt a binary number "<<endl<<"Re";
				p=1;
			}

   		}
   		
   	   }
 }
bin bin::operator-(bin b)
{
	int size_a,size_b,temp=0,p=0,q=0;
	char br='0';
	 bin result;   
		size_a=this->get_length()-1;
		size_b=b.get_length()-1;
	while(size_a>=0){
	 p=0,q=0;
		temp=this->get_string()[size_a]-'0';
		if(size_b>=0){
		p=b.get_string()[size_b]-'0';
		p+=br-'0';
	}
	else p+=br-'0';
      if(p==2)
      {
      	q=p;
      	p/=2;
	  }
		if(temp==0 && p==1)
		{
			result.num='1'+result.num;
			br='1';
		}
		else if(temp==1 && p==0)
		{
			result.num='1'+result.num;
			br='0';
		}
		else if(temp==1 && p==1)
		{
			if(q==2){
				br='1';
				result.num='1'+result.num;
			}
			else{
				br='0';
				result.num='0'+result.num;
			}
		}
		else if(temp==0 && p==0)
		{
			result.num='0'+result.num;
			br='0';
		}
		size_a--;
		size_b--;
	}
	return result;	
}
int bin:: operator==(bin b)
{
  int n,size_a,size_b,r,ainde=0,binde=0;
  size_a=this->get_length();
  size_b=b.get_length();
  if(size_a>size_b)
  {
  	r=size_a-size_b;
   	for( n=0;n<r;n++)
  	if(this->get_string()[n]=='0');
  	else  
	  return 0;
	 for( n=0;n<size_b;n++)
   {
   	 if(this->get_string()[n+r]==b.get_string()[n]);
   	 else return 0;
   }
   if(size_a==n)
   return 1; 
  }
  else if(size_b>size_a)
  {
  	r=size_b-size_a;
  	for( n=0;n<r;n++)
  	if(b.get_string()[n]=='0');
  	else 
  	return 0;
  	for( n=0;n<size_a;n++)
   {
   	 if(this->get_string()[n]==b.get_string()[n+r]);
   	 else return 0;
   }
   if(size_a==n)
   return 1;
   }
   else if(size_a==size_b)
   for( n=0;n<size_b;n++)
   {
   	 if(this->get_string()[n]==b.get_string()[n]);
   	 else return 0;
   }
   if(n==size_b)
   return 1;
}
bin bin :: operator+(bin b)
{
	
       bin result;
	int temp=0;
	int size_a=this->get_length()-1;
	int size_b=b.get_length()-1;
	while(size_a>=0 || size_b>=0 ||temp==1)
	{
		temp+=((size_a>=0)?this->get_string()[size_a]-'0':0);
		temp+=((size_b>=0)?b.get_string()[size_b]-'0':0);
		result.num=char(temp%2+'0')+result.num;
		temp/=2;
		size_a--;
		size_b--;
	}
	return result;
}
int main()
{
	bin a,b,c;
	int choice;
while(1){
	cout<<"\n Enter your choice : \n1.Addition\n2.Subtraction\n3.Compare\n4.Exit\n";
	cin>>choice;
	if(choice<=3){
      a.get_input();
	b.get_input();
}
	int i;
	switch(choice)
	{
	case 1:c=a+b;
	c.display();
	break;
	case 2:
	i=a.compa(b);
	if(i>=0){
		c=a-b;
		c.display();
	}
     else cout<<"\n subtraction not possible<2nd one is greater> \n";
	 break;
	 case 3: 
	       if(a==b)
	       cout<<"\n Both Binary number are same \n";
	       else cout<<"\n Both Binary number are Different\n";
	       break;
	  case 4: exit(0);
	  default : cout<<"\n Invalid choice \n";     
	 }
	}
	return 0;
}
