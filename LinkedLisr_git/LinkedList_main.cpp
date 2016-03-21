#include <iostream>

using namespace std;

struct node

{
    int data;   //数据
    node *next;    //指向node结构体的指针
};


node *Creat()   
{
	node *prev,*last,*head = NULL;   //prev指向临时结点，last指向最后一个结点
	
	cout<<"输入链表结点个数";
	int num;
	cin>>num;
	
	for(int i = 0; i < num ; i++)   //插入num个元素，循环num次
	{           
		prev = new node;
		cin>>prev->data;    //教材上看到的

		if(head == NULL)   //第一次插入
		{
			head = last = prev;    
		}
		else   //非第一次
		{
            last->next = prev;
            last = prev;    //本质上这句和 last = last->next 一样 ， last都指向最后一个结点
			last->next=NULL;   
		}
	}
    return head;   //返回头节点的地址
}


/*在链表的第i个位置插入结点，插入后，元素出现的位置，i从1开始*/
node *Insert(node *head ,int i,int num)     
{
	i--;   

	node *prev,*p;
	p = head;      // //curr指头,从头开始遍历

    prev = new node;   //漏了这一步就会出错  5.7 18：23；
    prev->data = num;       //p为临时节点


	if (i == 0)
	{
		prev-> next = head;
		//prev = &head;
		head = prev;     //为什么不行？？？   2016.3.20
		cout<<"已插入头部"<<endl;
	}
	else
	{
		while(--i != 0)  //循环 i - 1次
		{
			p = p->next;
		}
		prev->next = p->next;
		p->next = prev;
	}
	return head; 
}


/*删除某元素或某位置的元素
*mode1:删除某元素
*mode2：删除某位置的元素

*/
node *Delete(node *head, int mode)   //如果有重复元素怎么办？5.    +    内存并没有删除啊！
{
	
	/*第一种情况要定位到具体的值，因此要两个指针，一前一后*/
	if(mode == 1)
	{
		int elem;
		cout<<"输入要删除的元素值";
		cin>>elem;

		node *curr,*prev;   //curr指向当前结点、prev指向当前结点的上一个		
		curr=head;            

		if (curr->data == elem)   //头结点就是待删除结点
			head=head->next;    

		prev = new node;
		while(curr->data != elem  && curr->next != NULL){  //结束条件：在链表中找到||在链表中没找到，
			prev = curr;
			curr = curr->next;        //prev在前，curr在后
		}
		if(curr->data == elem)
		{
			prev->next = curr->next;      //前节点的next 跳过后一节点curr 接到后后一节点curr->next
		}
		else
		{
			cout<<"该元素不在表中，删除失败"<<endl;   //还是解决不了问题
		}
	}

	/*第二种情况不需要定位到具体的值，只需要定位到某个位置loca的前驱结点*/
	if(mode == 2)
	{
		int loca;
		cin>>loca;

		loca--;

		node *prev;   //表示某个位置loaca的前驱结点
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

        cout<<"链表中各节点数据为：";
        while (curr != NULL){
            cout<<" "<<(curr->data);
            curr = curr->next;
        }
        cout<<endl;
    }

    else cout<<"空表无数据显示！"<<endl;
    cout<<"头结点数据为"<<head->data;
	cout<<endl;
	cout<<endl;
}


/*查找两种模式
*mode == 1：按位置查找——得到值
*mode == 2：按值查找——得到位置

*/
void search(node *head, int mode)
{
	/*模式1：按位置查找*/
	if(mode == 1)
	{
		cout<<"输入要查找的位置"<<endl;
		int loca;
		cin>>loca;

		int count = 1;

		node *curr = head;

		while(count != loca)
		{
			curr = curr->next;
			count++;
		}
		cout<<"该位置处的值为"<<curr->data<<endl;
		cout<<endl;
	}

	/*模式2：按值查找——全部结点都要找*/
	else
	{
		cout<<"输入要查找的元素值"<<endl;
		int elem;
		cin>>elem;

		int loca = 0;

		//int *a = new int[];    //看看不定义长度行不行?不行
		//int a_index = -1;

		node *curr = head;
		int amount = 0;    //统计相同的值的个数

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
			cout<<"该元素不存在，查找失败";
		}
		else
		{
			int *a = new int[amount];
			int index = 0;


			curr = head;           //必须加这一句，因为curr在上一步去到了最后
			while(curr != NULL)    //千万要看清循环
			{
				loca++;
				if(curr->data == elem)
				{
					a[index]=loca;
					index++;
				}
				curr = curr->next;
			}

			cout<<"值为"<<elem<<"的元素位置为";
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
        cout<<endl<<"1----------------建一个链表      |";
        cout<<endl<<"2----------------显示全表        |";
		cout<<endl<<"3----------------插入元素        |";
        cout<<endl<<"4----------------删除元素        |";
	    cout<<endl<<"5----------------查找元素        |";
		cout<<endl<<"---------------------------------+";
        cout<<endl<<"请选择:";

        //a=getchar();

        cin>>a;

        switch(a){
            case 1:
                node *head;
                head=Creat();
                Print(head);break;  //也就是说我只要拿到头结点就行了，头结点就是Creat()函数的返回值

            case 2:Print(head);break;

            case 3:     //插入元素
				int i,num;
				cin>>i>>num;
				head = Insert(head, i ,num);
				Print(head);break;      //打印的是main函数的变量，Insert返回的是传进来后处理的地址，要拿出来。

            case 4:
				cout<<"请选择删除模式：1为删除某元素，2为删除某位置的元素"<<endl;
		
				int mode;
				cin>>mode;
				head=Delete(head , mode); //一定要把头指针带回来，不然下一行的(head)就是之前的head   5.7 20：30
                Print(head);break;

			case 5:
				cout<<"请选择查找模式：1为按位置查找,2为按值查找"<<endl;
				int mode_search;
				cin>>mode_search;
				search(head , mode_search);break;

        }
    }
}