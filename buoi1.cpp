#include<stdio.h>
#include<conio.h>
void menu()
{
	printf("Bai 1");
	printf("\nBai 2");
	printf("\nBai 3");
	printf("\nBai 4");
	printf("\nBai 5");
	printf("\nBai 6");
	printf("\nBai 7");
	printf("\nBai 8");
	printf("\nBai 9");
	printf("\nBai 10");
}

int main()
{
	int lc;
	do
	{
		menu();
		printf("\nMoi ban chon bai ");
		scanf("%d", &lc);
		switch (lc)
		{
		case 1 :
		{
			int a, b, c;
			printf("Nhap vao so nguyen a : ");
			scanf("%d", &a);
			printf("Nhap vao so nguyen b : ");
			scanf("%d", &b);
			printf("Nhap vao so nguyen c : ");
			scanf("%d", &c);
			if (a - b <= 0)
				printf(" %d / (%d -%d) la khong tinh duoc ");
			else
				printf("%d / (%d - %d) la : ", c, a, b,c/(a-b));
		}break;



		}
	} while (lc > 10);
	getch();
	return 0;
	
}