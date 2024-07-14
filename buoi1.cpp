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
void inputArray(int* arr, int* size) {
	printf("Nhap so luong phan tu: ");
	scanf("%d", size);
	printf("Nhap cac phan tu: ");
	for (int i = 0; i < *size; i++) {
		scanf("%d", arr + i);
	}
}


void outputArray(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", *(arr + i));
	}
	printf("\n");
}


int* findMax(int* arr, int size) {
	int* maxPtr = arr;
	for (int i = 1; i < size; i++) {
		if (*(arr + i) > *maxPtr) {
			maxPtr = arr + i;
		}
	}
	return maxPtr;
}


void findEvenOddMaxMin(int* arr, int size, int** evenMax, int** oddMin) {
	*evenMax = NULL;
	*oddMin = NULL;
	for (int i = 0; i < size; i++) {
		if (*(arr + i) % 2 == 0) {
			if (*evenMax == NULL || *(arr + i) > **evenMax) {
				*evenMax = arr + i;
			}
		}
		else {
			if (*oddMin == NULL || *(arr + i) < **oddMin) {
				*oddMin = arr + i;
			}
		}
	}
}


int removeZeros(int* arr, int size) {
	int newSize = 0;
	for (int i = 0; i < size; i++) {
		if (*(arr + i) != 0) {
			*(arr + newSize++) = *(arr + i);
		}
	}
	return newSize;
}


int addElement(int* arr, int size, int x) {
	for (int i = size; i > 1; i--) {
		*(arr + i) = *(arr + i - 1);
	}
	*(arr + 1) = x;
	return size + 1;
}

bool isPerfectSquare(int num) {
	int root = (int)sqrt(num);
	return root * root == num;
}


int sumPerfectSquares(int* arr, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		if (isPerfectSquare(*(arr + i))) {
			sum += *(arr + i);
		}
	}
	return sum;
}


void findLocalMaxima(int* arr, int size) {
	if (size == 1) {
		printf("%d ", *arr);
		return;
	}

	if (*(arr) > *(arr + 1)) {
		printf("%d ", *(arr));
	}

	for (int i = 1; i < size - 1; i++) {
		if (*(arr + i) > *(arr + i - 1) && *(arr + i) > *(arr + i + 1)) {
			printf("%d ", *(arr + i));
		}
	}

	if (*(arr + size - 1) > *(arr + size - 2)) {
		printf("%d ", *(arr + size - 1));
	}
	printf("\n");
}
struct 
{
	int tu;
	int mau;

}Phan so;

void nhapmangphanso(Phan so* arr, int size)
{
	for (int i = 0; i < size; i++) {
		printf("Nhap tu va mau cho phan so thu %d: ", i + 1);
		scanf("%d %d", &arr[i].tu, &arr[i].mau);
		while (arr[i].mau == 0) {
			printf("Mau so phai khac 0. Nhap lai mau so cho phan so thu %d: ", i + 1);
			scanf("%d", &arr[i].mau);
		}
	}
}
void xuatmangphanso(Phanso* arry, int size)
{
	for (int i = 0; i < size; i++) {
		printf("%d/%d ", arr[i].tu, arr[i].mau);
	}
	printf("\n");
}
int UCLN(int a, int b)
{
	if (b == 0) return a;
	return UCLN(b, a % b);

}

void rutGonPhanSo(PhanSo* ps) {
	int ucln = UCLN(ps->tu, ps->mau);
	ps->tu /= ucln;
	ps->mau /= ucln;
}
void xuatPhanSoMauLonHonTu(PhanSo* arr, int size) {
	for (int i = 0; i < size; i++) {
		if (arr[i].mau > arr[i].tu) {
			printf("%d/%d ", arr[i].tu, arr[i].mau);
		}
	}
	printf("\n");
}


int demPhanSoTuMauChan(PhanSo* arr, int size) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i].tu % 2 == 0 && arr[i].mau % 2 == 0) {
			count++;
		}
	}
	return count;
}


PhanSo tinhTichMangPhanSo(PhanSo* arr, int size) {
	PhanSo tich = { 1, 1 };
	for (int i = 0; i < size; i++) {
		tich.tu *= arr[i].tu;
		tich.mau *= arr[i].mau;
	}
	rutGonPhanSo(&tich);
	return tich;
}


int soSanhPhanSo(PhanSo a, PhanSo b) {
	return a.tu * b.mau - b.tu * a.mau;
}

PhanSo timPhanSoLonNhat(PhanSo* arr, int size) {
	PhanSo max = arr[0];
	for (int i = 1; i < size; i++) {
		if (soSanhPhanSo(arr[i], max) > 0) {
			max = arr[i];
		}
	}
	return max;
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
			if (a - b == 0)
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
		case 3 :
		{
			int arr[100];
			int size, x;

		
			inputArray(arr, &size);

	
			int* maxPtr = findMax(arr, size);
			printf("Phan tu lon nhat la %d tai dia chi %p\n", *maxPtr, (void*)maxPtr);

		
			int* evenMax, * oddMin;
			findEvenOddMaxMin(arr, size, &evenMax, &oddMin);
			if (evenMax != NULL) {
				printf("Phan tu chan lon nhat la %d tai dia chi %p\n", *evenMax, (void*)evenMax);
			}
			else {
				printf("Khong co phan tu chan trong mang.\n");
			}
			if (oddMin != NULL) {
				printf("Phan tu le nho nhat la %d tai dia chi %p\n", *oddMin, (void*)oddMin);
			}
			else {
				printf("Khong co phan tu le trong mang.\n");
			}

		
			size = removeZeros(arr, size);
			printf("Mang sau khi xoa cac phan tu co gia tri 0: ");
			outputArray(arr, size);

			
			printf("Nhap gia tri x de them vao sau phan tu dau tien: ");
			scanf("%d", &x);
			size = addElement(arr, size, x);
			printf("Mang sau khi them x: ");
			outputArray(arr, size);

			
			int sum = sumPerfectSquares(arr, size);
			printf("Tong cac phan tu la so chinh phuong: %d\n", sum);

			
			printf("Cac so cuc dai trong mang: ");
			findLocalMaxima(arr, size);

		}break;
		case 4 :
		{
			int size;
			printf("Nhap so luong phan so: ");
			scanf("%d", &size);

			PhanSo* arr = (PhanSo*)malloc(size * sizeof(PhanSo));

			
			nhapmangPhanSo(arr, size);
			printf("Mang phan so vua nhap: ");
			xuatMangPhanSo(arr, size);

			
			printf("Cac phan so co mau > tu: ");
			xuatPhanSoMauLonHonTu(arr, size);

			
			int count = demPhanSoTuMauChan(arr, size);
			printf("So phan so co tu va mau chan: %d\n", count);

			
			for (int i = 0; i < size; i++) {
				rutGonPhanSo(&arr[i]);
			}
			printf("Mang phan so sau khi rut gon: ");
			xuatmangPhanSo(arr, size);

			
			PhanSo tich = tinhTichMangPhanSo(arr, size);
			printf("Tich cua cac phan so trong mang: %d/%d\n", tich.tu, tich.mau);

			
			PhanSo max = timPhanSoLonNhat(arr, size);
			printf("Phan so lon nhat: %d/%d\n", max.tu, max.mau);

			free(arr);
		}
		case 5 :
		{
			double a, b;
			printf("Nhap so thuc a: ");
			scanf("%lf", &a);
			printf("Nhap so thuc b: ");
			scanf("%lf", &b);

			
			double* pa = &a;
			double* pb = &b;

			
			printf("Gia tri cua pa: %lf, dia chi: %p\n", *pa, (void*)pa);
			printf("Gia tri cua pb: %lf, dia chi: %p\n", *pb, (void*)pb);

			
			double tong = *pa + *pb;
			double hieu = *pa - *pb;
			double tich = *pa * *pb;
			double thuong;
			if (*pb != 0) {
				thuong = *pa / *pb;
			}
			else {
				printf("Khong the chia cho 0.\n");
				return 1; 
			}

			
			printf("Tong: %lf, dia chi: %p\n", tong, (void*)&tong);
			printf("Hieu: %lf, dia chi: %p\n", hieu, (void*)&hieu);
			printf("Tich: %lf, dia chi: %p\n", tich, (void*)&tich);
			printf("Thuong: %lf, dia chi: %p\n", thuong, (void*)&thuong);
		}

		



		}
	} while (lc > 10);
	getch();
	return 0;
	
}