//�� �� �� �� �� �� �� �� �� �� ��
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cstring> 
#define fo(i,j,k) for(int i=j;i<=k;i++)
#define random(m,n) rand()%(n-m+1)+m
using namespace std;
const int maxbit=10001;
void guess_the_number();
void main_interface();
void get_command();
void start_game();
string generate_the_number(int bit,int repeat);
void game_rules();
void programmers();
void to_players();
void version();
int main()
{
	system("title ������С��ϷV2.0 made by С����");
	guess_the_number();
	return 0;
}
void guess_the_number()
{
	while(true)
	{
		main_interface();
		get_command();
	}
	return;
}
void main_interface()
{
	system("cls");
	cout<<"������������������������������\n"
	    <<"��     ������С��ϷV2.0     ��\n"
	    <<"�ǩ���������������������������\n" 
	    <<"��1.��ʼ��Ϸ                ��\n"
		<<"�ǩ���������������������������\n"
	    <<"��2.��Ϸ����                ��\n"
	    <<"�ǩ���������������������������\n"
	    <<"��3.��д��Ա                ��\n"
	    <<"�ǩ���������������������������\n"
	    <<"��4.�����                  ��\n"
	    <<"�ǩ���������������������������\n"
	    <<"��5.�汾��¼                ��\n"
	    <<"�ǩ���������������������������\n"
	    <<"���������Ӧ����ָ��س�  ��\n"
	    <<"������������������������������\n";
	return;
}
void get_command()
{
	int command;
	while(true)
	{
		cin>>command;
		if (command<=0||command>=6) cout<<"�������˷Ƿ�ָ�����������\n";
		else break;
	}
	switch (command)
	{
		case 1:
			start_game();
			break;
		case 2:
			game_rules();
			break;
		case 3:
			programmers();
			break;
		case 4:
			to_players();
			break;
		case 5:
			version();
			break;
	}
	return;
}
void start_game()
{
	int rand_gene,times,bit,res_same,res_diff,replay,repeat;
	int num_exist[10];
	bool get_answer=false;
	bool same[maxbit];
	string std_num,gue_num;
	system("cls");
	cout<<"��ȷ���Ƿ�Ҫϵͳ�������ݣ����������롰1�����������롰0����\n";
	while(true)
	{
		cin>>rand_gene;
		if (rand_gene!=0&&rand_gene!=1) cout<<"�������˷Ƿ�ָ�����������\n";
		else break; 
	}
	if (rand_gene==1)
	{
		cout<<"�������Ƿ��������������г����ظ����֣����������롰1�����������롰0����\n";
		while(true)
		{
			cin>>repeat;
			if (repeat!=0&&repeat!=1) cout<<"�������˷Ƿ�ָ�����������\n";
			else break;
		}
	}
	cout<<"������λ����";
	while(true)
	{
		cin>>bit;
		if (bit<=0) cout<<"λ������Ϊ������������������\n";
		else if (repeat==0&&bit>=11) cout<<"�ڽ�ֹ�����ظ����ֵ�����£�λ�����ܴ���10������������\n";
		else break;
	}
	switch (rand_gene)
	{
		case 0:
			cout<<"������Ҫ�µ����֣�";
			while(true)
			{
				cin>>std_num;
				if (std_num.size()!=bit) cout<<"����λ����������������\n";
				else break;
			}
			break;
		case 1:
			std_num=generate_the_number(bit,repeat);
			break;
	}
	system("cls");
	cout<<"���롰answer������ֱ�ӻ�ȡ��\n";
	for(times=1;;times++)
	{
		cout<<"��"<<times<<"�Σ���������Ҫ�µ����֣�";
		while(true)
		{
			cin>>gue_num;
			if (gue_num=="answer")
			{
				get_answer=true;
				break;
			}
			else if (gue_num.size()!=bit) cout<<"����λ����������������\n";
			else break;
		}
		if (get_answer) break;
		res_same=0;
		res_diff=0;
		memset(num_exist,0,sizeof(num_exist));
		memset(same,0,sizeof(same));
		fo(i,0,bit-1)
		{
			if (std_num[i]==gue_num[i])
			{
				res_same++;
				same[i]=true;
			}
			else num_exist[std_num[i]-'0']++;
		}
		fo(i,0,bit-1)
		{
			if (!same[i]&&num_exist[gue_num[i]-'0']!=0)
			{
				res_diff++;
				num_exist[gue_num[i]-'0']--;
			}
		}
		cout<<"�����";
		fo(i,1,res_same) cout<<"��";
		fo(i,1,res_diff) cout<<"��";
		if (res_same==0&&res_diff==0) cout<<"X";
		cout<<endl;
		if (res_same==bit)
		{
			cout<<"��ϲ��¶������֣�"<<std_num<<",һ������"<<times<<"��\n";
			break;
		}
	}
	if (get_answer) cout<<"���ǣ�"<<std_num<<endl;
	cout<<"�������Ƿ�Ҫ����һ�Σ����������롰1���������롰0����\n";
	while(true)
	{
		cin>>replay;
		if (replay!=0&&replay!=1) cout<<"�������˷Ƿ�ָ�����������\n";
		else break;
	}
	if (replay==1) start_game();
	return;
}
string generate_the_number(int bit,int repeat)
{
	string ret;
	bool used[10]={0};
	int tmp;
	srand(time(0));
	if (repeat==1)
	{
		fo(i,0,bit-1) ret+=random(0,9)+'0';
	}
	else
	{
		fo(i,0,bit-1)
		{
			tmp=random(0,9);
			while(used[tmp]) tmp=random(0,9);
			used[tmp]=true;
			ret+=tmp+'0';
		}
	}
	return ret;
}
void game_rules()
{
	system("cls");	
	cout<<"������ϵͳ���ɻ����Լ�����һ��nλ����Ȼ������ҽ��в²⡣����²��һ������λ����ȷ��"
		<<"��ô������ʾһ�����������²��һ������λ�ò���ȷ�������ڱ�׼�����д������������ô"
		<<"������ʾһ������������n=4�ټ������ӣ�\n"
		<<"�����������ש��������ש���������\n"
		<<"����׼���֩��²����֩�  ���  ��\n" 
		<<"�ǩ��������贈�������贈��������\n"
		<<"��  1234  ��  0000  ��    X   ��\n" 
		<<"�ǩ��������贈�������贈��������\n"
		<<"��  1234  ��  1111  ��   ��   ��\n" 
		<<"�ǩ��������贈�������贈��������\n"
		<<"��  1234  ��  1112  ��  ���  ��\n" 
		<<"�ǩ��������贈�������贈��������\n"
		<<"��  1100  ��  1134  ��  ���  ��\n" 
		<<"�ǩ��������贈�������贈��������\n"
		<<"��  1234  ��  1234  ������\n" 
		<<"�ǩ��������贈�������贈��������\n"
		<<"��  1234  ��  4321  ������������\n" 
		<<"�ǩ��������贈�������贈��������\n"
		<<"��  1116  ��  1061  �� ����� ��\n" 
		<<"�����������ߩ��������ߩ���������\n"
		<<"�������ﻹ�������Ļ��������������������\n\n";
	system("pause");
	return;
}
void programmers()
{
	system("cls");
	cout<<"��д��Ա��С����\n\n";
	system("pause");
	return; 
}
void to_players()
{
	system("cls");
	cout<<"����㷢��bug����ϵ�ң�����guyu_shiwai@126.com��\n\n";
	system("pause");
	return;
}
void version()
{
	system("cls");
	cout<<"V1.0 ʱ�䲻��\n"
		<<"V2.0 2016.12.8\n"
		<<"1.�ع��˴���\n"
		<<"2.�Ż����㷨\n"
		<<"3.���������Ż�\n\n";
	system("pause");
	return;
}
