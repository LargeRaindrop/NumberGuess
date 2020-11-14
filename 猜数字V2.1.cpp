//┏ ┳ ┓ ┣ ╋ ┫ ┗ ┻ ┛ ━ ┃
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
void read(int &x,bool single);
bool char_in_string(string x);
int main()
{
	system("title 猜数字小游戏V2.1 made by 小雨点儿");
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
	cout<<"┏━━━━━━━━━━━━━┓\n"
	    <<"┃     猜数字小游戏V2.1     ┃\n"
	    <<"┣━━━━━━━━━━━━━┫\n" 
	    <<"┃1.开始游戏                ┃\n"
		<<"┣━━━━━━━━━━━━━┫\n"
	    <<"┃2.游戏规则                ┃\n"
	    <<"┣━━━━━━━━━━━━━┫\n"
	    <<"┃3.编写人员                ┃\n"
	    <<"┣━━━━━━━━━━━━━┫\n"
	    <<"┃4.致玩家                  ┃\n"
	    <<"┣━━━━━━━━━━━━━┫\n"
	    <<"┃5.版本记录                ┃\n"
	    <<"┣━━━━━━━━━━━━━┫\n"
	    <<"┃请输入对应数字指令并回车  ┃\n"
	    <<"┗━━━━━━━━━━━━━┛\n";
	return;
}
void get_command()
{
	int command;
	while(true)
	{
		read(command,true);
		if (command<=0||command>=6) cout<<"你输入了非法指令，请重新输入\n";
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
	cout<<"请确定是否要系统生成数据？（是请输入“1”，否请输入“0”）\n";
	while(true)
	{
		read(rand_gene,true);
		if (rand_gene!=0&&rand_gene!=1) cout<<"你输入了非法指令，请重新输入\n";
		else break; 
	}
	if (rand_gene==1)
	{
		cout<<"请输入是否允许生成数据中出现重复数字？（是请输入“1”，否请输入“0”）\n";
		while(true)
		{
			read(repeat,true);
			if (repeat!=0&&repeat!=1) cout<<"你输入了非法指令，请重新输入\n";
			else break;
		}
	}
	cout<<"请输入位数：";
	while(true)
	{
		read(bit,false);
		if (bit<=0) cout<<"位数不能为非正数，请重新输入\n";
		else if (bit>=maxbit) cout<<"位数超过上限！位数上限为"<<maxbit-1<<"位，请重新输入\n";
		else if (repeat==0&&bit>=11) cout<<"在禁止出现重复数字的情况下，位数不能大于10，请重新输入\n";
		else break;
	}
	switch (rand_gene)
	{
		case 0:
			cout<<"请输入要猜的数字：";
			while(true)
			{
				getline(cin,std_num);
				if (char_in_string(std_num)) cout<<"输入中存在字符，请重新输入\n";
				else if (std_num.size()!=bit) cout<<"输入位数错误，请重新输入\n";
				else break;
			}
			break;
		case 1:
			std_num=generate_the_number(bit,repeat);
			break;
	}
	system("cls");
	cout<<"输入“answer”即可直接获取答案\n";
	for(times=1;;times++)
	{
		cout<<"第"<<times<<"次：请输入你要猜的数字：";
		while(true)
		{
			getline(cin,gue_num);
			if (gue_num=="answer")
			{
				get_answer=true;
				break;
			}
			else if (char_in_string(gue_num)) cout<<"输入中存在字符，请重新输入\n";
			else if (gue_num.size()!=bit) cout<<"输入位数错误，请重新输入\n";
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
		cout<<"结果：";
		fo(i,1,res_same) cout<<"☆";
		fo(i,1,res_diff) cout<<"△";
		if (res_same==0&&res_diff==0) cout<<"X";
		cout<<endl;
		if (res_same==bit)
		{
			cout<<"恭喜你猜对了数字："<<std_num<<",一共猜了"<<times<<"次\n";
			break;
		}
	}
	if (get_answer) cout<<"答案是："<<std_num<<endl;
	cout<<"请问你是否要再玩一次？（是请输入“1”，否输入“0”）\n";
	while(true)
	{
		read(replay,true);
		if (replay!=0&&replay!=1) cout<<"你输入了非法指令，请重新输入\n";
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
	cout<<"首先由系统生成或是自己输入一个n位数，然后由玩家进行猜测。假如猜测的一个数字位置正确，"
		<<"那么将会显示一个“☆”；如果猜测的一个数字位置不正确，但是在标准数字中存在这个数，那么"
		<<"将会显示一个“△”。以n=4举几个栗子：\n"
		<<"┏━━━━┳━━━━┳━━━━┓\n"
		<<"┃标准数字┃猜测数字┃  结果  ┃\n" 
		<<"┣━━━━╋━━━━╋━━━━┫\n"
		<<"┃  1234  ┃  0000  ┃    X   ┃\n" 
		<<"┣━━━━╋━━━━╋━━━━┫\n"
		<<"┃  1234  ┃  1111  ┃   ☆   ┃\n" 
		<<"┣━━━━╋━━━━╋━━━━┫\n"
		<<"┃  1234  ┃  1112  ┃  ☆△  ┃\n" 
		<<"┣━━━━╋━━━━╋━━━━┫\n"
		<<"┃  1100  ┃  1134  ┃  ☆☆  ┃\n" 
		<<"┣━━━━╋━━━━╋━━━━┫\n"
		<<"┃  1234  ┃  1234  ┃☆☆☆☆┃\n" 
		<<"┣━━━━╋━━━━╋━━━━┫\n"
		<<"┃  1234  ┃  4321  ┃△△△△┃\n" 
		<<"┣━━━━╋━━━━╋━━━━┫\n"
		<<"┃  1116  ┃  1061  ┃ ☆△△ ┃\n" 
		<<"┗━━━━┻━━━━┻━━━━┛\n"
		<<"看到这里还看不懂的话就是你的智商问题啦！\n\n";
	system("pause");
	return;
}
void programmers()
{
	system("cls");
	cout<<"编写人员：小雨点儿\n\n";
	system("pause");
	return; 
}
void to_players()
{
	system("cls");
	cout<<"如果你发现bug请联系我，邮箱guyu_shiwai@126.com。\n\n";
	system("pause");
	return;
}
void version()
{
	system("cls");
	cout<<"V1.0 时间不明\n\n"
		<<"V2.0 2016.12.8\n"
		<<"1.重构了代码\n"
		<<"2.优化了算法\n"
		<<"3.大量功能优化\n\n"
		<<"V2.1 2016.12.21\n"
		<<"1.修复了玩家输入非法字符时会无限死循环的bug\n"
		<<"2.优化了输入提示词\n\n";
	system("pause");
	return;
}
void read(int &x,bool single)
{
	string str_tmp;
	bool flag;
	if (single)
	{
		while(true)
		{
			getline(cin,str_tmp);
			if (str_tmp.size()!=1||!isdigit(str_tmp[0])) cout<<"你输入了非法指令，请重新输入\n";
			else break;
		}
		x=str_tmp[0]-'0';
	}
	else
	{
		while(true)
		{
			getline(cin,str_tmp);
			flag=true;
			fo(i,0,str_tmp.size()-1)
				if (!isdigit(str_tmp[i]))
				{
					flag=false;
					break;
				}
			if (flag) break;
			else cout<<"你输入了非法指令，请重新输入\n";
		}
		x=0;
		fo(i,0,str_tmp.size()-1)
		{
			x*=10;
			x+=str_tmp[i]-'0';
		}
	}
	return;
}
bool char_in_string(string x)
{
	fo(i,0,x.size()-1)
		if (!isdigit(x[i]))
			return true;
	return false;
}	
