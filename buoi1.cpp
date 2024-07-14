#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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

void calculateRetirementDate(char* name, int day, int month, int year, char* gender) {
	int current_year = 2021;
	int current_age = current_year - year;
	int retirement_age = 0;
	int retirement_year;

	if ((strcmp(gender, "nam") == 0 && (current_age < 18 || current_age > 62)) ||
		(strcmp(gender, "nu") == 0 && (current_age < 18 || current_age > 60))) {
		printf("Loi: Tuoi khong thuoc trong tuoi lao dong. Ma loi 101\n");
		return;
	}

	if (strcmp(gender, "nam") != 0 && strcmp(gender, "nu") != 0) {
		printf("Loi: Gioi tinh khong hop le. Ma loi errcode\n");
		return;
	}

	if (strcmp(gender, "nam") == 0) {
		retirement_age = 62;
	}
	else if (strcmp(gender, "nu") == 0) {
		retirement_age = 60;
	}

	retirement_year = year + retirement_age;

	printf("%s, gioi tinh %s, sinh ngay %02d/%02d/%04d. Hien tai (nam %d) %s da %d tuoi. Thoi gian %s duoc nghi huu la thang %02d/%04d.\n",
		name, gender, day, month, year, current_year, name, current_age, name, month, retirement_year);
}

int main()
{
	int lc;
	do
	{
		menu();
		printf("\nMoi ban chon bai ");
		scanf_s("%d", &lc);
		switch (lc)
		{
		case 1 :
		{
			int a, b, c;
			printf("Nhap vao so nguyen a : ");
			scanf_s("%d", &a);
			printf("Nhap vao so nguyen b : ");
			scanf_s("%d", &b);
			printf("Nhap vao so nguyen c : ");
			scanf_s("%d", &c);
			if (a - b = 0)
				printf(" %d / (%d -%d) la khong tinh duoc ");
			else
				printf("%d / (%d - %d) la : ", c, a, b,c/(a-b));
		}break;
		case 2 :
		{
			char name[50];
			int day, month, year;
			char gender[10];
	
			printf("Nhap ho ten: ");
			fgets(name, sizeof(name), stdin);
			name[strcspn(name, "\n")] = '\0';  

			printf("Nhap ngay sinh (dd mm yyyy): ");
			scanf("%d %d %d", &day, &month, &year);

			printf("Nhap gioi tinh (nam/nu): ");
			scanf("%s", gender);

			calculateRetirementDate(name, day, month, year, gender);

		}break;



		}
	} while (lc > 10);
	getch();
	return 0;
	
}