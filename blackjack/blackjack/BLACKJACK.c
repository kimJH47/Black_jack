#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SPADE 0
#define DIA 100
#define HEART 200
#define CLOVER 300
#define KING 13
#define QUEEN 12
#define JACK 11
#define DECK 52
//
void makingCard(int card_deck[]);
void swap(int arr[], int i, int j);
void printArray(int arr[], int n);
void shuffle(int arr[], int n);
int get_playingCard(int arr[]);

int playingCard_number[] = { 1,2,3,4,5,6,7,8,9,10,JACK,QUEEN,KING }; //ī���� ���� �迭 J Q K �� ���� 11 , 12, 13, ���� ��Ÿ��
int playingCard_suite[] = { SPADE , DIA , HEART , CLOVER };
int playerCard[5]; //player�� ������ �������ִ� ī���� �迭
int dealerCard[5]; ////dealer�� ������ �������ִ� ī���� �迭

int main() {

	//Card_deck 52��


	
	int card_deck[52];

	makingCard(card_deck);

	printArray(card_deck, 52);

	shuffle(card_deck,DECK);

	printArray(card_deck, DECK);


	printf("\n\n\n\n\n");
	//ī������ �׽�Ʈ
	playerCard[0]=get_playingCard(card_deck);
	dealerCard[0] = get_playingCard(card_deck);

	printArray(playerCard, 1);
	printArray(dealerCard, 1);
	//


	/*
	srand(time(NULL));


	int temp=0;
	int rn;
	
	for(int j = 0 ; j<20;j++){
		int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
		for (int i = 0; i < 10-1; i++) {

			rn = rand() % (10 - i - 1) + i + 1;

			swap(arr1, i, rn);

		}

	for (int i = 0; i < 10; i++)
		printf("%2d ", arr1[i]);
	printf("\n");
	}
	*/
	/*
	int* car = makingCard();

	shuffle(car);

	for(int i =0 ; i<52;i++)
	printf("%d ", car[i]);
	*/
	
	
	
	
	
	return 0;



}

void printArray(int arr[], int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		printf("%3d ", arr[i]);
		count++;
		if (count % 13 == 0)
			printf("\n");
	}

	printf("\n");


}
 void makingCard(int card_deck[]) {

	int index = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++){
			 card_deck[index] = playingCard_suite[i] + playingCard_number[j];
			index++;
		}
		
	}


}
 

 void swap(int arr[], int i, int j)
 {
	 int temp = arr[i];
	 arr[i] = arr[j];
	 arr[j] = temp;
 }

 void shuffle(int arr[], int n)
{
	
	srand(time(NULL));


	int temp = 0;
	int rn;

	
	for (int i = 0; i < n - 1; i++) {

		rn = rand() % (n - i - 1) + i + 1; //������ ���� :  i + 1 ~  arr[n-1]

		swap(arr, i, rn);
	}
		
}


int get_playingCard(int arr[]){
	static int count = -1;


	if (count > DECK)
		return -1;  //���� ������ ������ ������ ���� -1�� ��ȯ�Ѵ�.

	else {
		count++;
		return arr[count];
	}
	

	
}
