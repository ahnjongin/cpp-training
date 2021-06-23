#include<cstdio>
#define WIDTH 17                     //구현할 그림의 가로 세로 크기 
#define HEIGHT 5
void label(unsigned char img[HEIGHT][WIDTH], int x, int y, int color)  //그림에 대한 재귀함수
{
	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT || img[y][x] != 9)
		return;                                           //검사 종료
	img[y][x] = color;
	label(img, x - 1, y, color);
	label(img, x , y-1, color);
	label(img, x + 1, y, color);
	label(img, x , y+1, color);
}

void blobColoring(unsigned char img[HEIGHT][WIDTH])    //영역 채색 주 함수
{
	int color = 1;
	for(int y=0;y<HEIGHT; y++)
		for (int x = 0; x < WIDTH; x++)
		{
			if (img[y][x] == 9)
				label(img, x, y, color++);     
	}
}
void printImage(unsigned char img[HEIGHT][WIDTH], const char*msg)   //화면에 보기 좋게 출력하는 함수
{
	printf("%s\n", msg);
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (img[y][x] == 0)printf(".");
			else printf("%d", img[y][x]);
		}
		printf("\n");
	}
	printf("\n");
}

void main()
{
	unsigned char image[HEIGHT][WIDTH] = {//입력:C++
		0,0,0,9,0,0,0,0,0,9,0,0,0,9,0,0,0,
		0,0,9,0,9,0,0,0,0,9,9,0,0,9,0,0,0,
		0,0,9,9,9,0,0,0,0,9,0,9,0,9,0,0,0,
		0,9,0,0,0,9,0,0,0,9,0,0,9,9,0,0,0,
		9,0,0,0,0,0,9,0,0,9,0,0,0,9,0,0,0,
	};
	printImage(image, "<Original image>");
	blobColoring(image);
	printImage(image, "<Labelled image>");
}