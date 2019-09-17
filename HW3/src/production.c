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
	print2DArray(6,6, houseGraph);
	printf("\n");

	int nRooms = fileArr[0];
	printf("%d\n\n", nRooms);

	int amtTreasureRoom1 = fileArr[37];
	int amtTreasureRoom2 = fileArr[38];
	int amtTreasureRoom3 = fileArr[39];
	int amtTreasureRoom4 = fileArr[40];
	int amtTreasureRoom5 = fileArr[41];
	int amtTreasureRoom6 = fileArr[42];

	printf("%d%3d%3d%2d%2d%2d", amtTreasureRoom1, amtTreasureRoom2, amtTreasureRoom3, amtTreasureRoom4, amtTreasureRoom5, amtTreasureRoom6);
	printf("\n");
	int* adjRoomsTo1 = adjacentRooms(houseGraph, 5);	

	//printf("%d", test);

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
	int* adjRooms = (int*)malloc(sizeof(int)*6);
	int j = 0;
	for(int i = 0; i<6; i++){
		if( arr[room][i] == 1){
			adjRooms[j] = i+1;  
			j++;				
		} 
		
	}
	return adjRooms;
}


