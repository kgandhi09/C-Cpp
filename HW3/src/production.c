/*
 * production.c
 *
 *  Created on: Sep 11, 2019
 *      Author: kushal
 */
#include "production.h"
#include "Layout.h"
#include "Search.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>



bool production(int argc, char** argv)
{
	
	bool answer = true;
	char* ePtr=(char*)malloc(sizeof(char*));
	
	//char *filename = (char)malloc(sizeof(char)*)
	char filename[100];
	for(int i =0; i<100; i++){
		filename[i] = '\0';
	}
	
	strcpy(filename, argv[1]);

	int maxRoomsToSearch =strtol(argv[2],&ePtr,10); // command line argument 1 - max no of rooms to search in house
	int limTreasure=strtol(argv[3],&ePtr,10); // command line argument 2 - total limit of treasure found
	
	int treasureLimit=(int)limTreasure;
	//nRows=(int)nRooms;
	//nCols=(int)nRooms;

	FILE* fp = fopen(filename, "r");
	
	int* fileArr=readFileIntoArray(43, fp);	
	//print1DArray(43,fileArr);	
	
	int** houseGraph = houseLayout(6,6, fileArr);
	printf("This is the house Layout!\n");
	print2DArray(6,6, houseGraph);
	printf("\n");

	int nRooms = fileArr[0];
	interaction(houseGraph, fileArr);
	/*
	int roomArr[10];
	printf("Enter the room number to search the room - ");	
	scanf("%d", roomArr);
	int* adjRoomsTo1 = adjacentRooms(houseGraph, (roomArr[0]-1));
	int amtTreasureRoom1 = amtTreasure(roomArr[0]-1, fileArr);
	printf("Treasure in this room is - %d\n", amtTreasureRoom1);	
	printf("The adjacent rooms are - ");	
	print1DArray(5, adjRoomsTo1);
	//printf("%d", test);
	*/

	return answer;
}

int* readFileIntoArray(int nElements, FILE* fp){
	int* arr=(int*)malloc(nElements * sizeof(int));
	
	for(int i =0; i<nElements; i++){
			arr[i]=0;
	}
	
	for(int i =0; i<nElements; i++){		
		fscanf(fp,"%d", &arr[i]);
	}
	
	
	return arr;
	
		
}

int** houseLayout(int rows, int cols, int* arr){
	int k=1;

	int** newArr = (int**)malloc(7 * sizeof(int));
	for(int i = 0; i < rows; i++){
		newArr[i] = (int*)malloc(7 * sizeof(int));
		for(int j=0; j<cols;j++){
			newArr[i][j]=arr[k];			
			k++;		
		}
	}
	return newArr;	
}

void print2DArray(int rows, int cols, int** arr){
	for(int i = 0; i < rows; i++){
		for(int j=0; j<cols;j++){
			printf("%2d", arr[i][j]);
		}
		printf("\n");
	} 
}

void print1DArray(int rows, int* arr){
	for(int i = 0; i < rows; i++){
		printf("%2d", arr[i]);
	}	
	printf("\n");
}

int* adjacentRooms(int** arr, int room){
	int* adjRooms = (int*)malloc(sizeof(int)*7);
	int j = 0;
	for(int i = 0; i<6; i++){
		if( arr[room][i] == 1){
			adjRooms[j] = i+1;  
			j++;				
		} 
		
	}
	return adjRooms;
}

int amtTreasure(int room, int* arr){
	int result = 0;
	for(int i = 0;i<5; i++){
		if(room == i){
			result = arr[37+i];		
		}
	}
	return result;
}

void interaction(int** houseGraph, int* fileArr){
	int inputRoomArr[10];
	int inputNextRoomArr[10];
	printf("Enter the room number to search the room - ");	
	
	for(int i = 0;i<10;i++ ){
		scanf("%d", &inputRoomArr[i]);
		int* adjRoomsTo1 = adjacentRooms(houseGraph, (inputRoomArr[i]-1));
		int amtTreasureRoom1 = amtTreasure(inputRoomArr[i]-1, fileArr);	
		printf("Treasure in this room is - %d\n", amtTreasureRoom1);	
		printf("The adjacent rooms are - ");	
		print1DArray(6, adjRoomsTo1);
		printf("\n");
		printf("What is the next room you would like to search - ");
		
	}

}


