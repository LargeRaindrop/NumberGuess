#include<iostream>
#include<cstring>
using namespace std;
string num,numm,guess;
int times,replay,choose,a=0,b=0; //a same place b different place
int main()
{
	a:
	system("title ������С��ϷV1.0 made by С����0727");
	cout<<"������������������������������\n" //�� �� �� �� �� �� �� �� �� �� �� 
	    <<"����ӭ����������С��ϷV1.0����\n"
	    <<"�ǩ���������������������������\n" 
	    <<"��1.��ʼ��Ϸ                ��\n"
	    <<"�ǩ���������������������������\n"
	    <<"��2.�鿴��Ϸ����            ��\n"
	    <<"�ǩ���������������������������\n"
	    <<"��3.�鿴��д��Ա            ��\n"
	    <<"�ǩ���������������������������\n"
	    <<"��4.�����                  ��\n"
	    <<"�ǩ���������������������������\n"
	    <<"���������Ӧ���ֲ��س�      ��\n"
	    <<"������������������������������\n";
	cin>>choose;
	switch (choose)
	{
		case 1:system("cls");
		       break;
		case 2:system("cls");
		       cout<<"���A������һ����λ����Ȼ�����B���в²⡣����һ������λ����ȷ����ô������ʾһ��"  
		           <<"�����һ������λ�ò���ȷ������λ�������������������ʾһ�������������磺\n"
		           <<"1234 1111 ��\n1234 1112 ���\n1100 1034 ���\n1234 0000 X\n�������ﻹ������"
		           <<"�Ļ��������������������\n��Ϸ��죡\n" ;
			   system("pause"); 
		       system("cls");
			   goto a;
	    case 3:system("cls");
		       cout<<"��д��Ա��С����0727\n��Ϸ��죡\n";
	           system("pause");
	           system("cls");
	           goto a;
	    case 4:system("cls");
	           cout<<"��ң���ã�����㷢�������Ϸ��ʲôbug����������ʲô���õ�������벻Ҫ����������������"
	               <<"��һʱ����ϵ��д�飡����ȻĿǰֻ����һ����= =�������֪���ҵ�QQ��ͨ��QQ��ϵ�ң��������֪��"
	               <<"�Ļ�����Ǹ���Ҳ��ܸ������ҵ�QQ= =����ͨ���ٶ�id��С����0727��������guyu_shiwai@126.com"
				   <<"����ϵ�ң�лл��\n��Ϸ��죡\n";
			   system("pause");
			   system("cls"); 
			   goto a;
	}
	cout<<"��ӭ����������С��Ϸ������Ϸ��С����0727��д��\n������Ҫ�µ����֣�";
	cin>>num;
	system("cls");
	for(times=1;;times++)
	{
		cout<<"��"<<times<<"�Σ���������Ҫ�µ����֣�";
		numm=num;
		cin>>guess;
		if (guess==numm) break;
		for(int i=0;i<4;i++)
			if (numm[i]==guess[i])
			{
				cout<<"��";
			    numm[i]='a';
			    guess[i]='a';
			    a++;
			}
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				if (numm[i]==guess[j]&&numm[i]!='a') 
				{
				    cout<<"��";
				    numm[i]='a';
				    guess[j]='a';
				    b++;
		 	    }
		if (a==0&&b==0) cout<<"X";
		cout<<endl;
	}
	cout<<"�����\n��ϲ��¶��ˣ�������"<<times<<"��\n";
	cout<<"�����Ƿ�Ҫ����һ�Σ���������1����������2����";
	cin>>replay;
	switch (replay)
	{
		case 1:system("cls");
			   goto a;
		case 2:system("exit");
	}
	return 0;
}
