#include<iostream>
#include<cstring>
using namespace std;
string num,numm,guess;
int times,replay,choose,a=0,b=0; //a same place b different place
int main()
{
	a:
	system("title 猜数字小游戏V1.0 made by 小雨点儿0727");
	cout<<"┏━━━━━━━━━━━━━┓\n" //┏ ┳ ┓ ┣ ╋ ┫ ┗ ┻ ┛ ━ ┃ 
	    <<"┃欢迎来到猜数字小游戏V1.0！┃\n"
	    <<"┣━━━━━━━━━━━━━┫\n" 
	    <<"┃1.开始游戏                ┃\n"
	    <<"┣━━━━━━━━━━━━━┫\n"
	    <<"┃2.查看游戏规则            ┃\n"
	    <<"┣━━━━━━━━━━━━━┫\n"
	    <<"┃3.查看编写人员            ┃\n"
	    <<"┣━━━━━━━━━━━━━┫\n"
	    <<"┃4.致玩家                  ┃\n"
	    <<"┣━━━━━━━━━━━━━┫\n"
	    <<"┃请输入对应数字并回车      ┃\n"
	    <<"┗━━━━━━━━━━━━━┛\n";
	cin>>choose;
	switch (choose)
	{
		case 1:system("cls");
		       break;
		case 2:system("cls");
		       cout<<"玩家A先输入一个四位数，然后玩家B进行猜测。假如一个数字位置正确，那么将会显示一个"  
		           <<"“☆”；一个数字位置不正确，但四位数中有这个数，将会显示一个“△”。比如：\n"
		           <<"1234 1111 ☆\n1234 1112 ☆△\n1100 1034 ☆△\n1234 0000 X\n看到这里还看不懂"
		           <<"的话就是你的智商问题啦！\n游戏愉快！\n" ;
			   system("pause"); 
		       system("cls");
			   goto a;
	    case 3:system("cls");
		       cout<<"编写人员：小雨点儿0727\n游戏愉快！\n";
	           system("pause");
	           system("cls");
	           goto a;
	    case 4:system("cls");
	           cout<<"玩家，你好！如果你发现这个游戏有什么bug，或者您有什么更好的意见，请不要吝啬您宝贵的意见，"
	               <<"第一时间联系编写组！（虽然目前只有我一个人= =）如果您知道我的QQ可通过QQ联系我，如果您不知道"
	               <<"的话，抱歉，我不能告诉您我的QQ= =。请通过百度id“小雨点儿0727”或邮箱guyu_shiwai@126.com"
				   <<"来联系我，谢谢！\n游戏愉快！\n";
			   system("pause");
			   system("cls"); 
			   goto a;
	}
	cout<<"欢迎来到猜数字小游戏！此游戏由小雨点儿0727编写。\n请输入要猜的数字：";
	cin>>num;
	system("cls");
	for(times=1;;times++)
	{
		cout<<"第"<<times<<"次：请输入你要猜的数字：";
		numm=num;
		cin>>guess;
		if (guess==numm) break;
		for(int i=0;i<4;i++)
			if (numm[i]==guess[i])
			{
				cout<<"☆";
			    numm[i]='a';
			    guess[i]='a';
			    a++;
			}
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				if (numm[i]==guess[j]&&numm[i]!='a') 
				{
				    cout<<"△";
				    numm[i]='a';
				    guess[j]='a';
				    b++;
		 	    }
		if (a==0&&b==0) cout<<"X";
		cout<<endl;
	}
	cout<<"☆☆☆☆\n恭喜你猜对了！共猜了"<<times<<"次\n";
	cout<<"请问是否要再玩一次？（是输入1，否请输入2）：";
	cin>>replay;
	switch (replay)
	{
		case 1:system("cls");
			   goto a;
		case 2:system("exit");
	}
	return 0;
}
