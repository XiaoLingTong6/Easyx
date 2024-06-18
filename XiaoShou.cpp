#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <easyx.h>
#include <graphics.h> 
#include <conio.h>
#define N 5  //员工数
#define M 200 //结构体数组的大小
static char mingzi[N][20] = { "Alice","Blice","Clice","Dlice","Elice" };
long haoma[N] = { 201801,201802,201803,201804,201805 };  //5名员工的工号
typedef struct people {
	long dingdan;   //订单号
	long gonghao;   //工号
	char name[20];  //销售名称
	char goods[30]; //商品名称
	int num;        //数量
	int price;      //单价
	int sum;        //总金额  不读取，计算
	struct date     //日期
	{
		int year;   //年
		int month;  //月
		int day;    //日
	}ymd;
}Peo;
typedef struct  //用来完成任务6
{
	int a;        //总销售额
	double b;     //提成
	char name[20];//销售姓名
	long gonghao; //销售工号
}k;
void chuang()
{
	cleardevice();
	IMAGE img;
	loadimage(&img, "Tu.jpg", 16 * 96, 9 * 96);  //导入图片并刷新界面
	putimage(0, 0, &img);
	BeginBatchDraw();
	setbkmode(TRANSPARENT);
	settextcolor(RED);
	settextstyle(82, 0, "宋体");
	outtextxy(440, 30, "销售绩效管理系统");
}
void menu();//菜单
void one(int);
void two();
void there();
void four();
void five();
void six();
void hua(Peo*, int, int, int, int);  //3个参数，待处理结构体，结构体元素个数，以及这是待处理的第几页结构体
void tongji_1();
void tongji_2();
int  data(Peo);
int com_2(const void* a, const void* b)  //任务2中sort()函数的参数
{  //  按订单号排序
	return (((Peo*)a)->dingdan) - (((Peo*)b)->dingdan);
}
int com_4(const void* a, const void* b)  //任务4中sort()函数的参数
{  //  按总金额排序
	return (((Peo*)b)->sum) - (((Peo*)a)->sum);
}
int com_6(const void* a, const void* b)  //任务6中sort()函数的参数
{  //  按提成排序
	if ((((k*)b)->b) - (((k*)a)->b) > 0)
		return 1;
	else
		return -1;
}
int main()
{
	initgraph(16 * 96, 9 * 96);
	menu();
	closegraph();
	return 0;
}
void menu()
{
	int b = 0;
	char ch[7][30] = { "构建销售记录表" ,"销售明细报表", "销售记录报表" ,
		"销售记录排序" ,"销售业绩统计" , "计算绩效提成","退出系统" };
	chuang();
	ExMessage mouse;
	WM_MOUSEMOVE;  //获取鼠标移动消息
	while (1)
	{
		peekmessage(&mouse, EM_MOUSE);  //获得鼠标的一系列数据
		int x = mouse.x;
		int y = mouse.y;
		int a = 0;
		if (mouse.lbutton == 1)
		{
			if (x >= 1300 && x <= 1470 && y >= 180 && y <= 225)
			{
				putchar('\a');
				settextcolor(RED);
				settextstyle(50, 0, "宋体");
				outtextxy(1200, 450, "有事吗？？？");
			}
			else if (x >= 100 && x <= 405 && y >= 130 && y <= 180)
			{
				FlushMouseMsgBuffer();
				one(10);
				break;
			}
			else if (x >= 100 && x <= 405 && y >= 230 && y <= 280)
			{
				FlushMouseMsgBuffer();
				two();
				break;
			}
			else if (x >= 100 && x <= 405 && y >= 330 && y <= 380)
			{
				FlushMouseMsgBuffer();
				there();
				break;
			}
			else if (x >= 100 && x <= 405 && y >= 430 && y <= 480)
			{
				FlushMouseMsgBuffer();
				four();
				break;
			}
			else if (x >= 100 && x <= 405 && y >= 530 && y <= 580)
			{
				FlushMouseMsgBuffer();
				five();
				break;
			}
			else if (x >= 100 && x <= 405 && y >= 630 && y <= 680)
			{
				FlushMouseMsgBuffer();
				six();
				break;
			}
			else if (x >= 100 && x <= 405 && y >= 730 && y <= 780)
			{
				FlushMouseMsgBuffer();
				putchar('\a');
				closegraph();
			}
		}
		if (x >= 1300 && x <= 1470 && y >= 180 && y <= 225)
		{
			BeginBatchDraw();
			setfillcolor(RED);
			fillrectangle(1300, 180, 1470, 225);
			setbkmode(TRANSPARENT);
			settextcolor(YELLOW);
			settextstyle(41, 0, "宋体");
			outtextxy(1323, 180, "韩蓬勃");
			EndBatchDraw();

		}
		else
		{
			BeginBatchDraw();
			setfillcolor(YELLOW);
			fillrectangle(1300, 180, 1470, 225);
			setbkmode(TRANSPARENT);
			settextcolor(RED);
			settextstyle(41, 0, "宋体");
			outtextxy(1300, 180, "防伪标志");
			EndBatchDraw();
		}
		for (int b = 0; b < 7; b++)
		{
			if (x >= 100 && x <= 400 && y >= 130 + b * 100 && y <= 180 + 100 * b)
			{
				BeginBatchDraw();
				setfillcolor(RED);
				fillrectangle(100, 130 + b * 100, 405, 180 + 100 * b);
				setbkmode(TRANSPARENT);
				settextcolor(YELLOW);
				settextstyle(44, 0, "宋体");
				outtextxy(250 - textwidth(ch[b]) / 2, 135 + b * 100, ch[b]);
				EndBatchDraw();
			}
			else
			{
				BeginBatchDraw();
				setfillcolor(YELLOW);
				fillrectangle(100, 130 + b * 100, 405, 180 + 100 * b);
				setbkmode(TRANSPARENT);
				settextcolor(RED);
				settextstyle(41, 0, "宋体");
				outtextxy(250 - textwidth(ch[b]) / 2, 135 + b * 100, ch[b]);
				EndBatchDraw();
			}
		}
	}
}
int  data(Peo* stu)
{
	FILE* pf = NULL;
	pf = fopen("test.text", "r");
	int a = 0, b = 0;
	char ch = 0;
	for (a = 0, b = 0; !feof(pf); a++, b++)
	{
		fscanf(pf, "%d%c%d%c%s%c", &stu[b].dingdan, &ch, &stu[b].gonghao, &ch, stu[b].name, &ch);
		fgets(stu[b].goods, 30, pf);  //fgets()读取换行符
		fscanf(pf, "%d%c%d%c%d%c%d%c%d%c", &stu[b].num, &ch, &stu[b].price, &ch, 
			&stu[b].ymd.year, &ch, &stu[b].ymd.month, &ch, &stu[b].ymd.day, &ch);
		stu[b].sum = stu[b].num * stu[b].price;
	}
	fclose(pf);
	return a - 1;//在读取函数中最后一次输入自带一个换行符
}
void one(int a)
{

	Peo one = { 0 };
	Peo* arr = (Peo*)malloc(sizeof(Peo) * M);
	int tuichu1 = 0;
	int b = data(arr), num[7] = { 0 };
	char ch[7][31] = { 0 };
	num[0] = InputBox(ch[0], 11, "请输入订单号并点击确定", NULL, NULL, 0, 0, false);
	while (num[0])
	{
		int a = 1;
		one.dingdan = atoi(ch[0]);
		if (one.dingdan < 2018010101 || one.dingdan>2030010101)
		{
			num[0] = InputBox(ch[0], 11, "请输入正确的订单号", NULL, NULL, 0, 0, false);
			a = 0;
		}
		for (int n = 0; n < b; n++)
			if (arr[n].dingdan == one.dingdan)
			{
				num[0] = InputBox(ch[0], 11, "该订单号已存在", NULL, NULL, 0, 0, false);
				a = 0;
				break;
			}
		if (a)
			break;
	}
	if (num[0])
	{
		num[1] = InputBox(ch[1], 7, "请输入工号号并点击确定", NULL, NULL, 0, 0, false);
		while (num[1])
		{
			one.gonghao = atoi(ch[1]);
			int a = 0;
			for (int n = 0; n < N; n++)
				if (haoma[n] == one.gonghao)
				{
					a = 1;
					break;
				}
			if (a)
				break;
			if (!a)
				num[1] = InputBox(ch[1], 7, "该工号不存在，请输入正确工号", NULL, NULL, 0, 0, false);
		}
	}
	if (num[1])
		num[2] = InputBox(ch[2], 21, "请输入销售名称并点击确定", NULL, NULL, 0, 0, false);
	if (num[2])
		num[3] = InputBox(ch[3], 31, "请输入商品名称并点击确定", NULL, NULL, 0, 0, false);
	if (num[3])
		num[4] = InputBox(ch[4], 3, "请输入数量并点击确定", NULL, NULL, 0, 0, false);
	if (num[4])
		num[5] = InputBox(ch[5], 8, "请输入单价并点击确定", NULL, NULL, 0, 0, false);
	if (num[5])
	{
		num[6] = InputBox(ch[6], 20, "请输入日期（形式为2024-01-01）并点击确定", NULL, NULL, 0, 0, false);
		while (num[6])
		{
			int n = 0;
			if (strlen(ch[6]) == 10 && ch[6][0] >= '0' && ch[6][0] <= '9')
				n++;
			if (ch[6][1] >= '0' && ch[6][1] <= '9' && ch[6][2] >= '0' && ch[6][2] <= '9')
				n++;
			if (ch[6][3] >= '0' && ch[6][3] <= '9' && ch[6][4] == '-' && ch[6][5] >= '0' && ch[6][5] <= '9')
				n++;
			if (ch[6][6] >= '0' && ch[6][6] <= '9' && ch[6][7] == '-')
				n++;
			if (ch[6][8] >= '0' && ch[6][8] <= '9' && ch[6][9] >= '0' && ch[6][9] <= '9')
				n++;
			if (n == 5)
				break;
			else
				num[6] = InputBox(ch[6], 20, "请输入正确的日期形式（例：2024-01-01）并点击确定", NULL, NULL, 0, 0, false);
		}
	}
	if (num[6])
	{
		char mm[100] = { 0 };
		sprintf(mm, "%s%s%c%s%s%c%s%s%c%s%s%c%s%s%c%s%s%c%s%s", 
			"订单号：", ch[0],'\n', "工号：", ch[1], '\n', 
			"销售名称：", ch[2],'\n', "商品名称：", ch[3], '\n',
			"数量：", ch[4], '\n',"单价：", ch[5], '\n',"日期：", ch[6]);
		HWND h = GetHWnd();
		int n = MessageBox(h, mm, "以下信息是否正确？", MB_YESNO);
		if (6 == n)
		{
			strcpy(one.name, ch[2]);
			strcpy(one.goods, ch[3]);
			one.num = atoi(ch[4]);
			one.price = atoi(ch[5]);
			char Year[10] = { 0 };
			char Month[10] = { 0 };
			char Day[10] = { 0 };
			for (int a = 0; a < 4; a++)
				Year[a] = ch[6][a];
			Month[0] = ch[6][5];
			Month[1] = ch[6][6];
			Day[0] = ch[6][8];
			Day[1] = ch[6][9];
			one.ymd.year = atoi(Year);
			one.ymd.month = atoi(Month);
			one.ymd.day = atoi(Day);
			FILE* pf = NULL;
			pf = fopen("test.text", "a");
			fprintf(pf, "%d %d %s\n%s\n", one.dingdan, one.gonghao, one.name, one.goods);
			fprintf(pf, "%d %d %d %d %d\n", one.num, one.price, one.ymd.year, one.ymd.month, one.ymd.day);
			fclose(pf);
		}
	}
	menu();
}
void two()
{
	Peo* arr = (Peo*)malloc(sizeof(Peo) * M);//arr为包含M(2000)个people结构体的数组
	int b = data(arr);
	qsort(arr, b, sizeof(Peo), com_2);
	cleardevice();
	chuang();
	hua(arr, b, 0, 0, 0);
}
void there()
{
	Peo* arr = (Peo*)malloc(sizeof(Peo) * M);
	int  a = 0, num = 0, b = 0;
	char mmm[20] = { 0 }, ch = 0;
	int zonghe = 0;
	FILE* pf = NULL;
	pf = fopen("test.text", "r");
	int n = InputBox(mmm, 11, "请输入工号并点击确定", NULL, NULL, 0, 0, false);
	while (n)
	{
		int k = 0;
		num = atoi(mmm);
		for (int a = 0; a < N; a++)
			if (num == haoma[a])
			{
				k = 1;
				break;
			}
		if (k)  //当工号正确时要跳出两层循环
			break;
		else
			n = InputBox(mmm, 11, "请输入正确的工号并点击确定", NULL, NULL, 0, 0, false);
	}
	for (a = 0; !feof(pf); a++)
	{
		Peo stu = { 0 };
		fscanf(pf, "%d%c%d%c%s%c", &stu.dingdan, &ch, &stu.gonghao, &ch, stu.name, &ch);
		fgets(stu.goods, 30, pf);  //fgets()读取换行符
		fscanf(pf, "%d%c%d%c%d%c%d%c%d%c", &stu.num, &ch, &stu.price, &ch, &stu.ymd.year, &ch, &stu.ymd.month, &ch, &stu.ymd.day, &ch);
		stu.sum = stu.num * stu.price;
		if (stu.gonghao == num)
		{
			arr[b] = stu;
			b++;
			zonghe += stu.sum;
		}
	}
	chuang();
	if (n == 0)
		menu();
	else
		hua(arr, b, 0, 1, zonghe);
}
void four()
{
	Peo* arr = (Peo*)malloc(sizeof(Peo) * M);//arr为包含M(2000)个people结构体的数组

	int b = data(arr);
	cleardevice();
	chuang();
	qsort(arr, b, sizeof(Peo), com_4);

	hua(arr, b, 0, 0, 0);
}
void five()
{

	chuang();
	tongji_1();
}
void six()
{
	chuang();
	tongji_2();
}
void hua(Peo* stu, int b, int c, int kk, int o)   //b是总的，c是当前页
{
	int a = 0;
	chuang();
	BeginBatchDraw();
	setlinecolor(YELLOW);
	setlinestyle(PS_SOLID, 3, NULL, 0);
	setbkmode(TRANSPARENT);
	settextcolor(RED);
	settextstyle(41, 0, "宋体");
	for (a = 0; a < 12; a++)
		line(50, a * 50 + 150, 1470, a * 50 + 150);
	int A = 50 + textwidth("8888888888") + 20;
	int B = A + textwidth("201801") + 20;
	int C = B + textwidth("销售名称");
	int D = C + textwidth(" ThinkPad T480 ");
	int E = D + textwidth("数量");
	int F = E + textwidth("000000");
	int G = F + textwidth("8888888");
	line(50, 150, 50, 700);

	char Dingdan[10][20] = { 0 };
	char Gonghao[10][20] = { 0 };
	char Num[10][20] = { 0 };
	char Price[10][20] = { 0 };
	char Sum[10][20] = { 0 };
	char Year[10][20] = { 0 };
	char Month[10][20] = { 0 };
	char Day[10][20] = { 0 };

	for (int a = 0; a < 10; a++)
	{
		sprintf(Dingdan[a], "%ld", stu[c * 10 + a].dingdan);
		sprintf(Gonghao[a], "%ld", stu[c * 10 + a].gonghao);
		sprintf(Num[a], "%d", stu[c * 10 + a].num);
		sprintf(Price[a], "%d", stu[c * 10 + a].price);
		sprintf(Sum[a], "%d", stu[c * 10 + a].sum);
		sprintf(Year[a], "%d", stu[c * 10 + a].ymd.year);
		sprintf(Month[a], "%02d", stu[c * 10 + a].ymd.month);
		sprintf(Day[a], "%02d", stu[c * 10 + a].ymd.day);
	}

	outtextxy(65 + (textwidth("8888888888") - textwidth("订单号")) / 2, 155, "订单号");
	outtextxy(A + 15 + (textwidth("201801") - textwidth("工号")) / 2, 155, "工号");
	outtextxy(B, 155, "销售名称");
	outtextxy(C + (textwidth(" ThinkPad T480 ") - textwidth("商品名称")) / 2, 155, "商品名称");
	outtextxy(D, 155, "数量");
	outtextxy(E + (textwidth("000000") - textwidth("单价")) / 2, 155, "单价");
	outtextxy(F + (textwidth("8888888") - textwidth("金额")) / 2, 155, "金额");
	outtextxy(G + (textwidth("2018-01-01") - textwidth("日期")) / 2, 155, "日期");
	line(A, 150, A, 700);
	line(B, 150, B, 700);
	line(C, 150, C, 700);
	line(D, 150, D, 700);
	line(E, 150, E, 700);
	line(F, 150, F, 700);
	line(G, 150, G, 700);
	line(1470, 150, 1470, 700);

	char mmmm[10] = { 0 };
	sprintf(mmmm, "%d", c + 1);
	outtextxy(50, 100, "第");
	outtextxy(50 + textwidth("第") + (textwidth("20") - textwidth(mmmm)) / 2, 100, mmmm);
	outtextxy(50 + textwidth("第") + textwidth("20"), 100, "页");
	for (a = 0; (a < 10) && c * 10 + a < b; a++)
	{
		char Date[20] = { 0 };
		strcat(Date, Year[a]);
		strcat(Date, "-");
		strcat(Date, Month[a]);
		strcat(Date, "-");
		strcat(Date, Day[a]);
		outtextxy(50 + 12, 205 + a * 50, Dingdan[a]);
		outtextxy(A + 12, 205 + a * 50, Gonghao[a]);
		outtextxy(B + 32, 205 + a * 50, stu[c * 10 + a].name);
		outtextxy(C + (textwidth(" ThinkPad T480 ") - textwidth(stu[c * 10 + a].goods)) / 2, 205 + a * 50, stu[c * 10 + a].goods);
		outtextxy(D + (textwidth("数量") - textwidth(Num[a])) / 2, 205 + a * 50, Num[a]);
		outtextxy(E + (textwidth("000000") - textwidth(Price[a])) / 2, 205 + a * 50, Price[a]);
		outtextxy(F + (textwidth("8888888") - textwidth(Sum[a])) / 2, 205 + a * 50, Sum[a]);
		outtextxy(G, 205 + a * 50, Date);
	}
	char p[20] = { 0 };
	char pp[40] = { "总销售额：" };
	sprintf(p, "%d", o);
	strcat(pp, p);
	if (1 == kk)
		outtextxy(1100, 100, pp);
	EndBatchDraw();
	while (1)
	{
		ExMessage mouse;
		WM_MOUSEMOVE;  //获取鼠标移动消息
		peekmessage(&mouse, EM_MOUSE);  //获得鼠标的一系列数据
		int x = mouse.x;
		int y = mouse.y;
		if (mouse.lbutton == 1)
		{
			if (x >= 1265 && x <= 1470 && y >= 730 && y <= 780)
			{
				memset(stu, 0, sizeof(Peo) * b);  //清空结构体数组
				menu();
				break;
			}
			if (c != 0)
				if (x >= 50 && x <= 170 && y >= 730 && y <= 780)  //上一页
				{
					FlushMouseMsgBuffer();
					c = c - 1;
					hua(stu, b, c, kk, 0);
				}
			if (c != b / 10)
				if (x >= 250 && x <= 370 && y >= 730 && y <= 780)  //下一页
				{
					FlushMouseMsgBuffer();
					c = c + 1;
					hua(stu, b, c, kk, 0);
				}
		}
		setfillcolor(RED);
		setbkmode(TRANSPARENT);
		settextcolor(YELLOW);
		setlinestyle(PS_NULL, 3, NULL, 0);
		settextstyle(41, 0, "宋体");
		BeginBatchDraw();
		if (x >= 1265 && x <= 1470 && y >= 730 && y <= 780)
		{
			fillrectangle(1265, 730, 1470, 780);
			outtextxy(1265, 735, "返回主菜单");
		}
		else if (x >= 50 && x <= 170 && y >= 730 && y <= 780)
		{
			fillrectangle(50, 730, 170, 780);
			outtextxy(50, 735, "上一页");
		}
		else if (x >= 250 && x <= 370 && y >= 730 && y <= 780)
		{
			fillrectangle(250, 730, 370, 780);
			outtextxy(250, 735, "下一页");
		}
		else
		{
			setfillcolor(YELLOW);
			setbkmode(TRANSPARENT);
			settextcolor(RED);
			fillrectangle(1265, 730, 1470, 780);
			outtextxy(1265, 735, "返回主菜单");
			fillrectangle(50, 730, 170, 780);
			outtextxy(50, 735, "上一页");
			fillrectangle(250, 730, 370, 780);
			outtextxy(250, 735, "下一页");
		}
		EndBatchDraw();
	}
	memset(stu, 0, sizeof(Peo) * b);
}
void tongji_1()
{
	Peo* arr = (Peo*)malloc(sizeof(Peo) * M);
	int n = 0;
	n = data(arr);
	char ch = 0;
	int a = 0, zong = 0, num[N] = { 0 }, b = 0;
	for (a = 0; a < n; a++)
	{
		zong += arr[a].sum;
		for (b = 0; b < N; b++)
			if (arr[a].gonghao == haoma[b])
				num[b] += arr[a].sum;
	}
	memset(arr, 0, sizeof(Peo) * n);
	BeginBatchDraw();
	setlinecolor(YELLOW);
	setlinestyle(PS_SOLID, 3, NULL, 0);
	setbkmode(TRANSPARENT);
	settextcolor(RED);
	settextstyle(41, 0, "宋体");
	char Haoma[N][20] = { 0 };
	char Num[N][10] = { 0 };
	char NUm[N][10] = { 0 };
	for (int a = 0; a < 7; a++)
		line(350, 250 + 50 * a, 1180, 250 + 50 * a);
	for (int a = 0; a < N; a++)
	{
		sprintf(Haoma[a], "%ld", haoma[a]);
		sprintf(Num[a], "%ld", num[a]);
		sprintf(NUm[a], "%.2f", num[a] * 1.0 / zong);
	}
	for (int a = 0; a < N; a++)
	{
		outtextxy(350 + (200 - textwidth(mingzi[a])) / 2, 300 + a * 50, mingzi[a]);
		outtextxy(550 + (250 - textwidth(Haoma[a])) / 2, 300 + a * 50, Haoma[a]);
		outtextxy(800 + (240 - textwidth(Num[a])) / 2, 300 + a * 50, Num[a]);
		outtextxy(1040 + (140 - textwidth(NUm[a])) / 2, 300 + a * 50, NUm[a]);
	}
	line(350, 250, 350, 550);
	line(550, 250, 550, 550);
	line(800, 250, 800, 550);
	line(1040, 250, 1040, 550);
	line(1180, 250, 1180, 550);
	outtextxy(350 + (200 - textwidth("销售名称")) / 2, 250, "销售名称");
	outtextxy(550 + (250 - textwidth("工号")) / 2, 250, "工号");
	outtextxy(800 + (240 - textwidth("总销售额")) / 2, 250, "总销售额");
	outtextxy(1040 + (140 - textwidth("占比")) / 2, 250, "占比");
	EndBatchDraw();

	BeginBatchDraw();
	while (1)
	{
		ExMessage mouse;
		WM_MOUSEMOVE;  //获取鼠标移动消息
		peekmessage(&mouse, EM_MOUSE);  //获得鼠标的一系列数据
		int x = mouse.x;
		int y = mouse.y;
		if (mouse.lbutton == 1)
			if (x >= 1265 && x <= 1470 && y >= 730 && y <= 780)
			{
				menu();
				break;
			}
		setfillcolor(RED);
		setbkmode(TRANSPARENT);
		settextcolor(YELLOW);
		setlinestyle(PS_NULL, 3, NULL, 0);
		settextstyle(41, 0, "宋体");
		BeginBatchDraw();
		if (x >= 1265 && x <= 1470 && y >= 730 && y <= 780)
		{
			fillrectangle(1265, 730, 1470, 780);
			outtextxy(1265, 735, "返回主菜单");
		}
		else
		{
			setfillcolor(YELLOW);
			setbkmode(TRANSPARENT);
			settextcolor(RED);
			fillrectangle(1265, 730, 1470, 780);
			outtextxy(1265, 735, "返回主菜单");
		}
		EndBatchDraw();
	}
}
void tongji_2()
{
	Peo* stu = (Peo*)malloc(sizeof(Peo) * M);
	int n = 0;
	n = data(stu);
	char ch = 0;
	int a = 0, b = 0;
	k num[N] = { 0 };
	k mmm = { 0 };
	for (a = 0; a < n; a++)
	{
		for (b = 0; b < N; b++)
			if (stu[a].gonghao == haoma[b])
				num[b].a += stu[a].sum;
	}
	for (a = 0; a < N; a++)
	{
		num[a].gonghao = haoma[a];
		strcpy(num[a].name, mingzi[a]);
		if (num[a].a < 50000)
			num[a].b = num[a].a * 0.05;
		else
			num[a].b = 50000 * 0.05 + (num[a].a - 50000) * 0.08;
	}
	qsort(num, N, sizeof(k), com_6);
	char Gonghao[N][20] = { 0 };
	char A[N][20] = { 0 };
	char B[N][20] = { 0 };
	for (int a = 0; a < N; a++)
	{
		sprintf(Gonghao[a], "%ld", num[a].gonghao);
		sprintf(A[a], "%d", num[a].a);
		sprintf(B[a], "%.2f", num[a].b);
	}
	BeginBatchDraw();
	setlinecolor(YELLOW);
	setlinestyle(PS_SOLID, 3, NULL, 0);
	setbkmode(TRANSPARENT);
	settextcolor(RED);
	settextstyle(41, 0, "宋体");
	for (int a = 0; a < 7; a++)
		line(350, 250 + 50 * a, 1180, 250 + 50 * a);
	line(350, 250, 350, 550);
	line(530, 250, 530, 550);
	line(760, 250, 760, 550);
	line(970, 250, 970, 550);
	line(1180, 250, 1180, 550);
	outtextxy(350 + (180 - textwidth("销售名称")) / 2, 250, "销售名称");
	outtextxy(530 + (230 - textwidth("工号")) / 2, 250, "工号");
	outtextxy(760 + (210 - textwidth("总销售额")) / 2, 250, "总销售额");
	outtextxy(970 + (210 - textwidth("提成")) / 2, 250, "提成");
	for (int a = 0; a < N; a++)
	{
		outtextxy(350 + (180 - textwidth(num[a].name)) / 2, 300 + a * 50, num[a].name);
		outtextxy(530 + (230 - textwidth(Gonghao[a])) / 2, 300 + a * 50, Gonghao[a]);
		outtextxy(760 + (210 - textwidth(A[a])) / 2, 300 + a * 50, A[a]);
		outtextxy(970 + (230 - textwidth(B[a])) / 2, 300 + a * 50, B[a]);
	}
	EndBatchDraw();
	while (1)
	{
		ExMessage mouse;
		WM_MOUSEMOVE;  //获取鼠标移动消息
		peekmessage(&mouse, EM_MOUSE);  //获得鼠标的一系列数据
		int x = mouse.x;
		int y = mouse.y;
		if (mouse.lbutton == 1)
			if (x >= 1265 && x <= 1470 && y >= 730 && y <= 780)
			{
				menu();
				break;
			}
		setfillcolor(RED);
		setbkmode(TRANSPARENT);
		settextcolor(YELLOW);
		setlinestyle(PS_NULL, 3, NULL, 0);
		settextstyle(41, 0, "宋体");
		BeginBatchDraw();
		if (x >= 1265 && x <= 1470 && y >= 730 && y <= 780)
		{
			fillrectangle(1265, 730, 1470, 780);
			outtextxy(1265, 735, "返回主菜单");
		}
		else
		{
			setfillcolor(YELLOW);
			setbkmode(TRANSPARENT);
			settextcolor(RED);
			fillrectangle(1265, 730, 1470, 780);
			outtextxy(1265, 735, "返回主菜单");
		}
		EndBatchDraw();
	}
	memset(stu, 0, sizeof(Peo) * n);
}