#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

struct student {
	int no;
	int sub1;
	int sub2;
	int sub3;
	int sum;
	double ave;
	int rank;
};

void inputdata(struct student s[], int tot);
void printdata(struct student s[], int tot);
void processranking(struct student s[], int tot, int process);
void sortingno(struct student s[], int tot);
void sortingrank(struct student s[], int tot);

int main()
{
	struct student s[30];
	int i, tot, menu, process, process2;
	tot = 25 + rand() % 6; // 정보 입력 수
	
	process = 0; // 입력을 한 번만 하기 위해 만든 변수
	process2 = 0; // 성적 처리 한 번만 하기 위해 만든 변수
	srand((unsigned)time(NULL));
	while (1)
	{
		printf("1. 자료입력 \n");
		printf("2. 자료처리 \n");
		printf("3. 번호순 \n");
		printf("4. 성적순 출력\n");
		printf("0. 종료 \n");
		printf(" 원하는 번호는? ");
		scanf_s("%d", &menu);
		switch (menu) {
		case 1:
			if (process == 0) {
				printf("새로운 자료 입력\n");
				process+=1;
				inputdata(s, tot); break;
			}
			else
				printf("이미 자료가 있습니다"); break;
		case 2: 
			if (process2 == 0)
			{
				printf("자료를 처리합니다.\n\n");
				processranking(s, tot, process);
				process2 += 1; break;
			}
			else {
				printf("이미 자료처리를 했습니다~\n\n"); break;
			}

		case 3: 
			if (process == 0 ) {
				printf("자료부터 입력하시오~~\n"); break;
			}
			else {
				printf("번호순으로 출력합니다.\n");
				sortingno(s, tot);
				printdata(s, tot); break;
			}
			
		case 4:
			if (process == 0) {
				printf("자료부터 입력하시오~~\n"); break;
			}
			else {
				printf("순위순으로 출력합니다.\n");
				sortingrank(s, tot);
				printdata(s, tot); break;
			}

		case 0: return 0;

		}
		menu = _getch();
		system("cls");
	}

	return 0;
}

//성적 입력 함수
void inputdata(struct student s[], int tot)
{
	int i;

	for (i = 0; i < tot; i++) {
		s[i].no = i + 1;
		s[i].sub1 = rand() % 101;
		s[i].sub2 = rand() % 101;
		s[i].sub3 = rand() % 101;
		s[i].sum = s[i].sub1 + s[i].sub2 + s[i].sub3;
		s[i].ave = s[i].sum / 3.0;
		s[i].rank = 1;
	}
	printf("자료 입력 완성\n");
}

//프린트 함수
void printdata(struct student s[], int tot) {
	int i;
	printf("번호 성적1 성적2 성적3 합계 평균   순위\n");
	for (i = 0; i < tot; i++)
		printf("%3d  %3d  %4d %5d %5d %6.2f %4d\n", s[i].no, s[i].sub1, s[i].sub2, s[i].sub3, s[i].sum, s[i].ave, s[i].rank);

}

//성적 처리 함수
void processranking(struct student s[], int tot, int process) {
		for (int i = 0; i < tot; i++) {
			for (int j = 0; j < tot; j++) {
				if (s[i].sum < s[j].sum)
					s[i].rank += 1;
			}
		}
	
}

//삽입정렬 이용하여 번호 순대로 정렬하기
void sortingno(struct student s[],int tot) {
	struct student temp[1];
	for (int i = 1; i < tot; i++) {
		temp[0] = s[i];
		for (int j = i - 1; j >= 0; j--)
		{
			if (s[j].no > temp[0].no)
			{
				while (j < i) {
					s[i] = s[i - 1];
					i--;
				}
				s[j] = temp[0];
			}
		}

	}
}

//삽입정렬 이용하여 성적 순대로 정렬하기
void sortingrank(struct student s[], int tot) {
	struct student temp[1];
	for (int i = 1; i < tot; i++) {
		temp[0] = s[i];
		for (int j = i - 1; j >= 0; j--)
		{
			if (s[j].rank > temp[0].rank)
			{
				while (j < i) {
					s[i] = s[i - 1];
					i--;
				}
				s[j] = temp[0];
			}
		}
	}
}