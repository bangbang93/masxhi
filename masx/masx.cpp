
#include "stdafx.h"
#include <graphics.h>
#include <ege/fps.h>
#include <time.h>

int main()
{
	char Line[322];
	FILE *fp;
	int loop;
	//初始化
	const int high=960,weight=720;
	initgraph(high, weight);
	setbkcolor(EGERGB(0xFE, 0xFB, 0xF5));
	//打开文件
	if((fp = fopen("AscPic.txt", "r")) == NULL)
	{
		outtextxy(high/2, weight/2, "文件打开失败");
		Sleep(2000);
		exit(EXIT_FAILURE);
	}

	//BGM
	mciSendString(_T("open sound.mp3 alias BGM"), NULL, 0, NULL);
	mciSendString(_T("play BGM"), NULL, 0, NULL);


	//动画演示
	fps f;
	setcolor(EGERGB(0xFF, 0x0, 0x0));
	const int fhigh=6;
	const int fweig=3;
    for ( ; !feof(fp) && is_run(); delay_fps(24))
	{

		for(loop = 0; loop < 121; loop++)
		{
			if(fgets(Line, 322, fp) == NULL)
				break;
			setcolor(EGERGB(0x0, 0x00, 0x0));
			setfont(fhigh,fweig,"宋体");
			outtextxy(0, loop * 6, Line);
		}

	}


	//关闭
	fclose(fp);
	closegraph();

	return 0;
}
