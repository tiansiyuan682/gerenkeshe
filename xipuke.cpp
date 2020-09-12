//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef struct card{
    int Order;        // ˳��
    char Suit;        // ��ɫ
    char Number;    // ��С
}Card;
 
// card arr
Card OneCard[108] = {};
 
// ��ӡ����
void showCard(){
	int i;
	
	for(i=0; i<108; i++){
		//printf("  %02d,%c,%c", OneCard[i].Order, OneCard[i].Suit, OneCard[i].Number);
		if(OneCard[i].Number=='@'){
			cout<<"  "<<OneCard[i].Suit<<","<<setw(3)<<10;
		}
		else
			cout<<"  "<<OneCard[i].Suit<<","<<setw(3)<<OneCard[i].Number;
		if(12 == i%13){
			printf("\n");
		}
	}	
	printf("\n");
}
 
// �������
void shuffle(){
	int i;
 
	Card tmpCard;
 
	srand(time(NULL));
	for(i=0; i<108; i++){
		int tmp = rand()%108;
		tmpCard = OneCard[tmp];
		OneCard[tmp] = OneCard[i];
		OneCard[i] = tmpCard;
	}
 
	showCard();
	return;
}
 
// ��ʼ����˳��
void initCard(){
	int i;
	
	for(i=0; i<108; i++){
		OneCard[i].Order = i;
 
		if(i>=105){
			if(i==105||i==106){
				OneCard[i].Suit = 'g';
				OneCard[i].Number = 'g';
			}else{
				OneCard[i].Suit = 'G';
				OneCard[i].Number = 'G';
			}
		}else{
			if(i<=25){
				OneCard[i].Suit = 'H';	// heart���� 
			}else if(i<=51){
				OneCard[i].Suit = 'S';	// spade���� 
			}else if(i<=77){
				OneCard[i].Suit = 'D';	// diamond���� 
			}else{ 
				OneCard[i].Suit = 'C';	// club÷�� 
			}
 
			switch(i%13){
				case 0:
					OneCard[i].Number = 'A';
					break;
				case 9:
					OneCard[i].Number = '@';
					break;
				case 10:
					OneCard[i].Number = 'J';
					break;			
				case 11:
					OneCard[i].Number = 'Q';
					break;
				case 12:
					OneCard[i].Number = 'K';
					break;			
				default:
					OneCard[i].Number = (i%13)+'1';
			}
		}		
	}
 
	showCard();
	return;
}
void paixu(Card X[]){
	Card tmp;
	for(int i=0;i<27;i++){
		for(int j=i;j<27;j++){
			if(X[i].Number==X[j].Number){
				if(X[i].Suit>X[j].Suit){	//C<D<H<S
				tmp.Order=X[i].Order;
				tmp.Suit=X[i].Suit;
				tmp.Number=X[i].Number;
				X[i].Order=X[j].Order;
				X[i].Suit=X[j].Suit;
				X[i].Number=X[j].Number;
				X[j].Order=tmp.Order;
				X[j].Suit=tmp.Suit;
				X[j].Number=tmp.Number;
				} 
			} 
			if(X[i].Number>X[j].Number){
				tmp.Order=X[i].Order;
				tmp.Suit=X[i].Suit;
				tmp.Number=X[i].Number;
				X[i].Order=X[j].Order;
				X[i].Suit=X[j].Suit;
				X[i].Number=X[j].Number;
				X[j].Order=tmp.Order;
				X[j].Suit=tmp.Suit;
				X[j].Number=tmp.Number;
		}
		}
	}
}
void printyifu(Card a[]){
	for(int i=0; i<27; i++){
		if(a[i].Number=='@'){
			cout<<"  "<<a[i].Suit<<","<<setw(3)<<10;
		}
		else
			cout<<"  "<<a[i].Suit<<","<<setw(3)<<a[i].Number;
		if(12 == i%13){
			printf("\n");
		}
	}
	cout<<endl;
}
int main(void){
	
	printf("init card:\n");
	initCard();
 
	printf("\nafter shuffle1 cards: \n");
	shuffle();
	
	Card A[27]={};
	Card B[27]={};
	Card C[27]={};
	Card D[27]={};
	for(int i=0;i<27;i++){
		A[i].Order=OneCard[i].Order;
		A[i].Suit=OneCard[i].Suit;
		A[i].Number=OneCard[i].Number;
	}
	for(int i=27;i<54;i++){
		B[i-27].Order=OneCard[i].Order;
		B[i-27].Suit=OneCard[i].Suit;
		B[i-27].Number=OneCard[i].Number;
	}
	for(int i=54;i<81;i++){
		C[i-54].Order=OneCard[i].Order;
		C[i-54].Suit=OneCard[i].Suit;
		C[i-54].Number=OneCard[i].Number;
	}
	for(int i=81;i<108;i++){
		D[i-81].Order=OneCard[i].Order;
		D[i-81].Suit=OneCard[i].Suit;
		D[i-81].Number=OneCard[i].Number;
	}
	cout<<"A:"<<endl;
	printyifu(A);
	cout<<"A�����:"<<endl;
	paixu(A);
	printyifu(A);
	cout<<"B�����:"<<endl;
	paixu(B);
	printyifu(B);
	cout<<"C�����:"<<endl;
	paixu(C);
	printyifu(C);
	cout<<"D�����:"<<endl;
	paixu(D);
	printyifu(D);
	//��A��ʼ
	Card shuru[27]={};
	cout<<"��������������(�ÿո����):"<<endl;
	int count=0;
	while(cin>>shuru[count].Suit){
		string tmp;
		cin>>tmp;
		if(tmp[0]>='0'&&tmp[0]<='9'){
		if(tmp[1]=='0'&&tmp[0]=='1')
		shuru[count].Number='@';
		else shuru[count].Number=tmp[0];	
		}
		if(tmp[0]>='A'&&tmp[0]<='Z'){
		shuru[count].Number=tmp[0];
		}
		shuru[count].Order=count;
		cout<<shuru[count].Suit<<","<<shuru[count].Number<<endl;
		cout<<"count:"<<count<<endl;
		++count;
		
	}
	
	
	
	
	
	
	return 0;
}

