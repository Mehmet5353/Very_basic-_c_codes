#include <stdio.h>
#include <stdlib.h>

#define MAX_HW 20

//Reading data form file 
void read_data(FILE *ptr, int d[], int *size) {
	*size=0;
	while(fscanf(ptr, "%d", &d[*size])==1)
		(*size)++;		
}
//Storing data we start from index 0
void store(FILE *ptr,int d[], int size){
	int i;
	for(i=0;i<size;i++)
		fprintf(ptr,"%d\t",d[i]);
}	
//We are stroing the array length
void Store(FILE *ptr,int d[], int size){
	fprintf(ptr,"%d\t",d[0]);
}	

//Taking average
double average(int d[], int size){
	int i;
	float result=0.0;
	for(i=0;i<size;i++)
		result+=d[i];
	return (result/(size));
}
//Taking max
int max(int d[], int size){
	int i;
	int mx=d[0];
	for(i=1;i<size;i++){
		if (d[i]>mx){
			mx=d[i];
		}
	}	
	return mx;
}
//printing data points
void print_data(int d[], int size) {
	int i;
	for(i=0; i<size; i++) {
		printf("%d\t", d[i]);
		if((i+1)%10==0) printf("\n");
	}
}
//Printing array size
void Print_data(int d[], int size) {

	printf("%d\t", size);

	
}
//Main file to write file, You can delete answer-hw3.txt, because after compling it will be recreated. 
int main(){
	FILE *ifp; FILE *ofp;
	int i, sz=MAX_HW;
	int data[MAX_HW]= {100,0};
	ifp=fopen("myhw.txt", "r+");
	ofp=fopen("answer-hw3.txt", "w+");
	read_data(ifp, data, &sz);
	printf("Size of array is ");
	Print_data(data,sz );
	printf("\nMy %d array points are:", sz);
	print_data(data,sz);	
	printf("\nMy array average score is %10f", average(data, sz));
	printf("\nMy array max score is %d",max(data,sz));
	fprintf(ofp,"My array size is ");
	Store(ofp,data,sz);
	fprintf(ofp,"\nMy %d array points are:",sz);
	store(ofp,data,sz);
	fprintf(ofp,"\nMy array average score is %10f", average(data, sz));	
	fprintf(ofp,"\nMy array max score is %d",max(data,sz));
	fclose(ifp);
	fclose(ofp);
	return 0;
	
	
}




