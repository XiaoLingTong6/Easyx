#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <easyx.h>
#include <graphics.h> 
#include <conio.h>
#define N 5  //Ա����
#define M 200 //�ṹ������Ĵ�С
static char mingzi[N][20] = { "Alice","Blice","Clice","Dlice","Elice" };
long haoma[N] = { 201801,201802,201803,201804,201805 };  //5��Ա���Ĺ���
typedef struct people {
	long dingdan;   //������
	long gonghao;   //����
	char name[20];  //��������
	char goods[30]; //��Ʒ����
	int num;        //����
	int price;      //����
	int sum;        //�ܽ��  ����ȡ������
	struct date     //����
	{
		int year;   //��
		int month;  //��
		int day;    //��
	}ymd;
}Peo;
typedef struct  //�����������6
{
	int a;        //�����۶�
	double b;     //���
	char name[20];//��������
	long gonghao; //���۹���
}k;
void chuang()
{
	cleardevice();
	IMAGE img;
	loadimage(&img, "Tu.jpg", 16 * 96, 9 * 96);  //����ͼƬ��ˢ�½���
	putimage(0, 0, &img);
	BeginBatchDraw();
	setbkmode(TRANSPARENT);
	settextcolor(RED);
	settextstyle(82, 0, "����");
	outtextxy(440, 30, "���ۼ�Ч����ϵͳ");
}
void menu();//�˵�
void one(int);
void two();
void there();
void four();
void five();
void six();
void hua(Peo*, int, int, int, int);  //3��������������ṹ�壬�ṹ��Ԫ�ظ������Լ����Ǵ�����ĵڼ�ҳ�ṹ��
void tongji_1();
void tongji_2();
int  data(Peo);
int com_2(const void* a, const void* b)  //����2��sort()�����Ĳ���
{  //  ������������
	return (((Peo*)a)->dingdan) - (((Peo*)b)->dingdan);
}
int com_4(const void* a, const void* b)  //����4��sort()�����Ĳ���
{  //  ���ܽ������
	return (((Peo*)b)->sum) - (((Peo*)a)->sum);
}
int com_6(const void* a, const void* b)  //����6��sort()�����Ĳ���
{  //  ���������
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
	char ch[7][30] = { "�������ۼ�¼��" ,"������ϸ����", "���ۼ�¼����" ,
		"���ۼ�¼����" ,"����ҵ��ͳ��" , "���㼨Ч���","�˳�ϵͳ" };
	chuang();
	ExMessage mouse;
	WM_MOUSEMOVE;  //��ȡ����ƶ���Ϣ
	while (1)
	{
		peekmessage(&mouse, EM_MOUSE);  //�������һϵ������
		int x = mouse.x;
		int y = mouse.y;
		int a = 0;
		if (mouse.lbutton == 1)
		{
			if (x >= 1300 && x <= 1470 && y >= 180 && y <= 225)
			{
				putchar('\a');
				settextcolor(RED);
				settextstyle(50, 0, "����");
				outtextxy(1200, 450, "�����𣿣���");
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
			settextstyle(41, 0, "����");
			outtextxy(1323, 180, "���");
			EndBatchDraw();

		}
		else
		{
			BeginBatchDraw();
			setfillcolor(YELLOW);
			fillrectangle(1300, 180, 1470, 225);
			setbkmode(TRANSPARENT);
			settextcolor(RED);
			settextstyle(41, 0, "����");
			outtextxy(1300, 180, "��α��־");
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
				settextstyle(44, 0, "����");
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
				settextstyle(41, 0, "����");
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
		fgets(stu[b].goods, 30, pf);  //fgets()��ȡ���з�
		fscanf(pf, "%d%c%d%c%d%c%d%c%d%c", &stu[b].num, &ch, &stu[b].price, &ch, 
			&stu[b].ymd.year, &ch, &stu[b].ymd.month, &ch, &stu[b].ymd.day, &ch);
		stu[b].sum = stu[b].num * stu[b].price;
	}
	fclose(pf);
	return a - 1;//�ڶ�ȡ���������һ�������Դ�һ�����з�
}
void one(int a)
{

	Peo one = { 0 };
	Peo* arr = (Peo*)malloc(sizeof(Peo) * M);
	int tuichu1 = 0;
	int b = data(arr), num[7] = { 0 };
	char ch[7][31] = { 0 };
	num[0] = InputBox(ch[0], 11, "�����붩���Ų����ȷ��", NULL, NULL, 0, 0, false);
	while (num[0])
	{
		int a = 1;
		one.dingdan = atoi(ch[0]);
		if (one.dingdan < 2018010101 || one.dingdan>2030010101)
		{
			num[0] = InputBox(ch[0], 11, "��������ȷ�Ķ�����", NULL, NULL, 0, 0, false);
			a = 0;
		}
		for (int n = 0; n < b; n++)
			if (arr[n].dingdan == one.dingdan)
			{
				num[0] = InputBox(ch[0], 11, "�ö������Ѵ���", NULL, NULL, 0, 0, false);
				a = 0;
				break;
			}
		if (a)
			break;
	}
	if (num[0])
	{
		num[1] = InputBox(ch[1], 7, "�����빤�źŲ����ȷ��", NULL, NULL, 0, 0, false);
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
				num[1] = InputBox(ch[1], 7, "�ù��Ų����ڣ���������ȷ����", NULL, NULL, 0, 0, false);
		}
	}
	if (num[1])
		num[2] = InputBox(ch[2], 21, "�������������Ʋ����ȷ��", NULL, NULL, 0, 0, false);
	if (num[2])
		num[3] = InputBox(ch[3], 31, "��������Ʒ���Ʋ����ȷ��", NULL, NULL, 0, 0, false);
	if (num[3])
		num[4] = InputBox(ch[4], 3, "���������������ȷ��", NULL, NULL, 0, 0, false);
	if (num[4])
		num[5] = InputBox(ch[5], 8, "�����뵥�۲����ȷ��", NULL, NULL, 0, 0, false);
	if (num[5])
	{
		num[6] = InputBox(ch[6], 20, "���������ڣ���ʽΪ2024-01-01�������ȷ��", NULL, NULL, 0, 0, false);
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
				num[6] = InputBox(ch[6], 20, "��������ȷ��������ʽ������2024-01-01�������ȷ��", NULL, NULL, 0, 0, false);
		}
	}
	if (num[6])
	{
		char mm[100] = { 0 };
		sprintf(mm, "%s%s%c%s%s%c%s%s%c%s%s%c%s%s%c%s%s%c%s%s", 
			"�����ţ�", ch[0],'\n', "���ţ�", ch[1], '\n', 
			"�������ƣ�", ch[2],'\n', "��Ʒ���ƣ�", ch[3], '\n',
			"������", ch[4], '\n',"���ۣ�", ch[5], '\n',"���ڣ�", ch[6]);
		HWND h = GetHWnd();
		int n = MessageBox(h, mm, "������Ϣ�Ƿ���ȷ��", MB_YESNO);
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
	Peo* arr = (Peo*)malloc(sizeof(Peo) * M);//arrΪ����M(2000)��people�ṹ�������
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
	int n = InputBox(mmm, 11, "�����빤�Ų����ȷ��", NULL, NULL, 0, 0, false);
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
		if (k)  //��������ȷʱҪ��������ѭ��
			break;
		else
			n = InputBox(mmm, 11, "��������ȷ�Ĺ��Ų����ȷ��", NULL, NULL, 0, 0, false);
	}
	for (a = 0; !feof(pf); a++)
	{
		Peo stu = { 0 };
		fscanf(pf, "%d%c%d%c%s%c", &stu.dingdan, &ch, &stu.gonghao, &ch, stu.name, &ch);
		fgets(stu.goods, 30, pf);  //fgets()��ȡ���з�
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
	Peo* arr = (Peo*)malloc(sizeof(Peo) * M);//arrΪ����M(2000)��people�ṹ�������

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
void hua(Peo* stu, int b, int c, int kk, int o)   //b���ܵģ�c�ǵ�ǰҳ
{
	int a = 0;
	chuang();
	BeginBatchDraw();
	setlinecolor(YELLOW);
	setlinestyle(PS_SOLID, 3, NULL, 0);
	setbkmode(TRANSPARENT);
	settextcolor(RED);
	settextstyle(41, 0, "����");
	for (a = 0; a < 12; a++)
		line(50, a * 50 + 150, 1470, a * 50 + 150);
	int A = 50 + textwidth("8888888888") + 20;
	int B = A + textwidth("201801") + 20;
	int C = B + textwidth("��������");
	int D = C + textwidth(" ThinkPad T480 ");
	int E = D + textwidth("����");
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

	outtextxy(65 + (textwidth("8888888888") - textwidth("������")) / 2, 155, "������");
	outtextxy(A + 15 + (textwidth("201801") - textwidth("����")) / 2, 155, "����");
	outtextxy(B, 155, "��������");
	outtextxy(C + (textwidth(" ThinkPad T480 ") - textwidth("��Ʒ����")) / 2, 155, "��Ʒ����");
	outtextxy(D, 155, "����");
	outtextxy(E + (textwidth("000000") - textwidth("����")) / 2, 155, "����");
	outtextxy(F + (textwidth("8888888") - textwidth("���")) / 2, 155, "���");
	outtextxy(G + (textwidth("2018-01-01") - textwidth("����")) / 2, 155, "����");
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
	outtextxy(50, 100, "��");
	outtextxy(50 + textwidth("��") + (textwidth("20") - textwidth(mmmm)) / 2, 100, mmmm);
	outtextxy(50 + textwidth("��") + textwidth("20"), 100, "ҳ");
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
		outtextxy(D + (textwidth("����") - textwidth(Num[a])) / 2, 205 + a * 50, Num[a]);
		outtextxy(E + (textwidth("000000") - textwidth(Price[a])) / 2, 205 + a * 50, Price[a]);
		outtextxy(F + (textwidth("8888888") - textwidth(Sum[a])) / 2, 205 + a * 50, Sum[a]);
		outtextxy(G, 205 + a * 50, Date);
	}
	char p[20] = { 0 };
	char pp[40] = { "�����۶" };
	sprintf(p, "%d", o);
	strcat(pp, p);
	if (1 == kk)
		outtextxy(1100, 100, pp);
	EndBatchDraw();
	while (1)
	{
		ExMessage mouse;
		WM_MOUSEMOVE;  //��ȡ����ƶ���Ϣ
		peekmessage(&mouse, EM_MOUSE);  //�������һϵ������
		int x = mouse.x;
		int y = mouse.y;
		if (mouse.lbutton == 1)
		{
			if (x >= 1265 && x <= 1470 && y >= 730 && y <= 780)
			{
				memset(stu, 0, sizeof(Peo) * b);  //��սṹ������
				menu();
				break;
			}
			if (c != 0)
				if (x >= 50 && x <= 170 && y >= 730 && y <= 780)  //��һҳ
				{
					FlushMouseMsgBuffer();
					c = c - 1;
					hua(stu, b, c, kk, 0);
				}
			if (c != b / 10)
				if (x >= 250 && x <= 370 && y >= 730 && y <= 780)  //��һҳ
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
		settextstyle(41, 0, "����");
		BeginBatchDraw();
		if (x >= 1265 && x <= 1470 && y >= 730 && y <= 780)
		{
			fillrectangle(1265, 730, 1470, 780);
			outtextxy(1265, 735, "�������˵�");
		}
		else if (x >= 50 && x <= 170 && y >= 730 && y <= 780)
		{
			fillrectangle(50, 730, 170, 780);
			outtextxy(50, 735, "��һҳ");
		}
		else if (x >= 250 && x <= 370 && y >= 730 && y <= 780)
		{
			fillrectangle(250, 730, 370, 780);
			outtextxy(250, 735, "��һҳ");
		}
		else
		{
			setfillcolor(YELLOW);
			setbkmode(TRANSPARENT);
			settextcolor(RED);
			fillrectangle(1265, 730, 1470, 780);
			outtextxy(1265, 735, "�������˵�");
			fillrectangle(50, 730, 170, 780);
			outtextxy(50, 735, "��һҳ");
			fillrectangle(250, 730, 370, 780);
			outtextxy(250, 735, "��һҳ");
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
	settextstyle(41, 0, "����");
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
	outtextxy(350 + (200 - textwidth("��������")) / 2, 250, "��������");
	outtextxy(550 + (250 - textwidth("����")) / 2, 250, "����");
	outtextxy(800 + (240 - textwidth("�����۶�")) / 2, 250, "�����۶�");
	outtextxy(1040 + (140 - textwidth("ռ��")) / 2, 250, "ռ��");
	EndBatchDraw();

	BeginBatchDraw();
	while (1)
	{
		ExMessage mouse;
		WM_MOUSEMOVE;  //��ȡ����ƶ���Ϣ
		peekmessage(&mouse, EM_MOUSE);  //�������һϵ������
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
		settextstyle(41, 0, "����");
		BeginBatchDraw();
		if (x >= 1265 && x <= 1470 && y >= 730 && y <= 780)
		{
			fillrectangle(1265, 730, 1470, 780);
			outtextxy(1265, 735, "�������˵�");
		}
		else
		{
			setfillcolor(YELLOW);
			setbkmode(TRANSPARENT);
			settextcolor(RED);
			fillrectangle(1265, 730, 1470, 780);
			outtextxy(1265, 735, "�������˵�");
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
	settextstyle(41, 0, "����");
	for (int a = 0; a < 7; a++)
		line(350, 250 + 50 * a, 1180, 250 + 50 * a);
	line(350, 250, 350, 550);
	line(530, 250, 530, 550);
	line(760, 250, 760, 550);
	line(970, 250, 970, 550);
	line(1180, 250, 1180, 550);
	outtextxy(350 + (180 - textwidth("��������")) / 2, 250, "��������");
	outtextxy(530 + (230 - textwidth("����")) / 2, 250, "����");
	outtextxy(760 + (210 - textwidth("�����۶�")) / 2, 250, "�����۶�");
	outtextxy(970 + (210 - textwidth("���")) / 2, 250, "���");
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
		WM_MOUSEMOVE;  //��ȡ����ƶ���Ϣ
		peekmessage(&mouse, EM_MOUSE);  //�������һϵ������
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
		settextstyle(41, 0, "����");
		BeginBatchDraw();
		if (x >= 1265 && x <= 1470 && y >= 730 && y <= 780)
		{
			fillrectangle(1265, 730, 1470, 780);
			outtextxy(1265, 735, "�������˵�");
		}
		else
		{
			setfillcolor(YELLOW);
			setbkmode(TRANSPARENT);
			settextcolor(RED);
			fillrectangle(1265, 730, 1470, 780);
			outtextxy(1265, 735, "�������˵�");
		}
		EndBatchDraw();
	}
	memset(stu, 0, sizeof(Peo) * n);
}