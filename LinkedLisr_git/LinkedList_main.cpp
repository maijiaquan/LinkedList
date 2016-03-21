#include <iostream>

using namespace std;

struct node

{
    int data;   //����
    node *next;    //ָ��node�ṹ���ָ��
};


node *Creat()   
{
	node *prev,*last,*head = NULL;   //prevָ����ʱ��㣬lastָ�����һ�����
	
	cout<<"�������������";
	int num;
	cin>>num;
	
	for(int i = 0; i < num ; i++)   //����num��Ԫ�أ�ѭ��num��
	{           
		prev = new node;
		cin>>prev->data;    //�̲��Ͽ�����

		if(head == NULL)   //��һ�β���
		{
			head = last = prev;    
		}
		else   //�ǵ�һ��
		{
            last->next = prev;
            last = prev;    //���������� last = last->next һ�� �� last��ָ�����һ�����
			last->next=NULL;   
		}
	}
    return head;   //����ͷ�ڵ�ĵ�ַ
}


/*������ĵ�i��λ�ò����㣬�����Ԫ�س��ֵ�λ�ã�i��1��ʼ*/
node *Insert(node *head ,int i,int num)     
{
	i--;   

	node *prev,*p;
	p = head;      // //currָͷ,��ͷ��ʼ����

    prev = new node;   //©����һ���ͻ����  5.7 18��23��
    prev->data = num;       //pΪ��ʱ�ڵ�


	if (i == 0)
	{
		prev-> next = head;
		//prev = &head;
		head = prev;     //Ϊʲô���У�����   2016.3.20
		cout<<"�Ѳ���ͷ��"<<endl;
	}
	else
	{
		while(--i != 0)  //ѭ�� i - 1��
		{
			p = p->next;
		}
		prev->next = p->next;
		p->next = prev;
	}
	return head; 
}


/*ɾ��ĳԪ�ػ�ĳλ�õ�Ԫ��
*mode1:ɾ��ĳԪ��
*mode2��ɾ��ĳλ�õ�Ԫ��

*/
node *Delete(node *head, int mode)   //������ظ�Ԫ����ô�죿5.    +    �ڴ沢û��ɾ������
{
	
	/*��һ�����Ҫ��λ�������ֵ�����Ҫ����ָ�룬һǰһ��*/
	if(mode == 1)
	{
		int elem;
		cout<<"����Ҫɾ����Ԫ��ֵ";
		cin>>elem;

		node *curr,*prev;   //currָ��ǰ��㡢prevָ��ǰ������һ��		
		curr=head;            

		if (curr->data == elem)   //ͷ�����Ǵ�ɾ�����
			head=head->next;    

		prev = new node;
		while(curr->data != elem  && curr->next != NULL){  //�������������������ҵ�||��������û�ҵ���
			prev = curr;
			curr = curr->next;        //prev��ǰ��curr�ں�
		}
		if(curr->data == elem)
		{
			prev->next = curr->next;      //ǰ�ڵ��next ������һ�ڵ�curr �ӵ����һ�ڵ�curr->next
		}
		else
		{
			cout<<"��Ԫ�ز��ڱ��У�ɾ��ʧ��"<<endl;   //���ǽ����������
		}
	}

	/*�ڶ����������Ҫ��λ�������ֵ��ֻ��Ҫ��λ��ĳ��λ��loca��ǰ�����*/
	if(mode == 2)
	{
		int loca;
		cin>>loca;

		loca--;

		node *prev;   //��ʾĳ��λ��loaca��ǰ�����
		prev = head;

		if(loca == 0)
		{
			node *temp = head;
			head = head->next;
			delete temp;
		}
		else
		{
			while(--loca != 0)
			{
				prev = prev->next;
			}
			node *temp = prev->next;
			prev->next = prev->next->next;
			delete temp;
		}		
	}

    return head;
}

void Print(node *head) 
{
    if(head != NULL){
        node *curr;
        curr = head;

        cout<<"�����и��ڵ�����Ϊ��";
        while (curr != NULL){
            cout<<" "<<(curr->data);
            curr = curr->next;
        }
        cout<<endl;
    }

    else cout<<"�ձ���������ʾ��"<<endl;
    cout<<"ͷ�������Ϊ"<<head->data;
	cout<<endl;
	cout<<endl;
}


/*��������ģʽ
*mode == 1����λ�ò��ҡ����õ�ֵ
*mode == 2����ֵ���ҡ����õ�λ��

*/
void search(node *head, int mode)
{
	/*ģʽ1����λ�ò���*/
	if(mode == 1)
	{
		cout<<"����Ҫ���ҵ�λ��"<<endl;
		int loca;
		cin>>loca;

		int count = 1;

		node *curr = head;

		while(count != loca)
		{
			curr = curr->next;
			count++;
		}
		cout<<"��λ�ô���ֵΪ"<<curr->data<<endl;
		cout<<endl;
	}

	/*ģʽ2����ֵ���ҡ���ȫ����㶼Ҫ��*/
	else
	{
		cout<<"����Ҫ���ҵ�Ԫ��ֵ"<<endl;
		int elem;
		cin>>elem;

		int loca = 0;

		//int *a = new int[];    //���������峤���в���?����
		//int a_index = -1;

		node *curr = head;
		int amount = 0;    //ͳ����ͬ��ֵ�ĸ���

		while(curr != NULL)
		{
			if(curr->data == elem)
			{
				amount++;
			}
			curr = curr->next;
		}

		if(amount == 0)
		{
			cout<<"��Ԫ�ز����ڣ�����ʧ��";
		}
		else
		{
			int *a = new int[amount];
			int index = 0;


			curr = head;           //�������һ�䣬��Ϊcurr����һ��ȥ�������
			while(curr != NULL)    //ǧ��Ҫ����ѭ��
			{
				loca++;
				if(curr->data == elem)
				{
					a[index]=loca;
					index++;
				}
				curr = curr->next;
			}

			cout<<"ֵΪ"<<elem<<"��Ԫ��λ��Ϊ";
			for(int i = 0; i < amount; i++)
			{
				cout<<a[i]<<" ";
			}
			cout<<endl;
		}

	}

}

int main()
{

    int a;

    while(true)

    {
		cout<<"---------------------------------+";
        cout<<endl<<"1----------------��һ������      |";
        cout<<endl<<"2----------------��ʾȫ��        |";
		cout<<endl<<"3----------------����Ԫ��        |";
        cout<<endl<<"4----------------ɾ��Ԫ��        |";
	    cout<<endl<<"5----------------����Ԫ��        |";
		cout<<endl<<"---------------------------------+";
        cout<<endl<<"��ѡ��:";

        //a=getchar();

        cin>>a;

        switch(a){
            case 1:
                node *head;
                head=Creat();
                Print(head);break;  //Ҳ����˵��ֻҪ�õ�ͷ�������ˣ�ͷ������Creat()�����ķ���ֵ

            case 2:Print(head);break;

            case 3:     //����Ԫ��
				int i,num;
				cin>>i>>num;
				head = Insert(head, i ,num);
				Print(head);break;      //��ӡ����main�����ı�����Insert���ص��Ǵ���������ĵ�ַ��Ҫ�ó�����

            case 4:
				cout<<"��ѡ��ɾ��ģʽ��1Ϊɾ��ĳԪ�أ�2Ϊɾ��ĳλ�õ�Ԫ��"<<endl;
		
				int mode;
				cin>>mode;
				head=Delete(head , mode); //һ��Ҫ��ͷָ�����������Ȼ��һ�е�(head)����֮ǰ��head   5.7 20��30
                Print(head);break;

			case 5:
				cout<<"��ѡ�����ģʽ��1Ϊ��λ�ò���,2Ϊ��ֵ����"<<endl;
				int mode_search;
				cin>>mode_search;
				search(head , mode_search);break;

        }
    }
}