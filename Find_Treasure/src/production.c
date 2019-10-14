/*
 * production.c
 *
 *  Created on: Sep 11, 2019
 *      Author: kushal
 */
#include "production.h"
#include "Layout.h"
#include "Search.h"
#include "tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>



bool production(int argc, char** argv)
{
	
	bool answer = true;
	printf("This is production!\n");
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

	FILE* fp = fopen(filename, "r");	
	
	int numOfRooms;
	fscanf(fp, "%d", &numOfRooms);
	
	int** houseGraph = readFileIntoHouse(numOfRooms,fp);
	printf("This is the house Layout!\n");
	print2DArray(numOfRooms,numOfRooms, houseGraph);
	printf("\n");
	
	int* treasures = readFileIntoTreasure(numOfRooms, fp);
	printf("This is treasure in each rooms!\n");	
	print1DArray(numOfRooms, treasures);
	printf("\n");
	int testTreasure = amtTreasure(7, treasures, numOfRooms);
	printf("Treasure in room is - %d\n\n", testTreasure);

	interaction(numOfRooms, houseGraph, treasures, treasureLimit, maxRoomsToSearch);
	return answer;
}

int** readFileIntoHouse(int numOfRooms, FILE* fp){

	printf("Number of Rooms: %d\n", numOfRooms);
	
	int** houseLayout = (int**)malloc(numOfRooms * sizeof(int*));
	for(int i = 0; i < numOfRooms; i++){
		houseLayout[i] = (int*)malloc(numOfRooms * sizeof(int));
		for(int j = 0; j < numOfRooms;j++){
			fscanf(fp, "%d", &houseLayout[i][j]);	
		}
	}

	return houseLayout;
		
}

int* readFileIntoTreasure(int numOfRooms, FILE* fp){

	int* treasure = (int*)malloc((numOfRooms+1) * sizeof(int));
	for(int i = 0; i < numOfRooms; i++){
		fscanf(fp, "%d", &treasure[i]);
	}

	return treasure;

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
		printf("%3d", arr[i]);
	}	
	printf("\n");
}

int* adjacentRooms(int** arr, int room, int noOfRooms){
	int* adjRooms = (int*)malloc(sizeof(int)*7);
	int j = 0;
	for(int i = 0; i<noOfRooms; i++){
		if( arr[room][i] == 1){
			adjRooms[j] = i+1;  
			j++;				
		} 
		
	}
	return adjRooms;
}

int amtTreasure(int room, int* arr, int noOfRooms){
	int result = 0;
	for(int i = 0;i<noOfRooms; i++){
		if((room-1) == i){
			result = arr[i];		
		}
	}
	return result;
}

void interaction(int noOfRooms, int** houseGraph, int* treasures, int treasureLimit, int maxRooms){
	int inputRoomNo;
	int* adjRoomsTo = (int*)malloc(sizeof(int)*7);
	//int* visitedRooms;
	int* visitedRooms = (int*)malloc(sizeof(int)*10);
	int countVisit = 0;
	int totalTreasure = 0;
	bool firstTime = true;
	printf("Enter the room number to search the room - ");	
	scanf("%d", &inputRoomNo);
	while(countVisit < maxRooms){
		if(((checkAdjRoomPresent(adjRoomsTo, inputRoomNo, noOfRooms)) && !(visited(visitedRooms, inputRoomNo, countVisit))) || firstTime){
			visitedRooms[countVisit] = inputRoomNo;
			countVisit++;		
			firstTime = false;
			adjRoomsTo = adjacentRooms(houseGraph, (inputRoomNo-1), noOfRooms);
			int amtTreasureRoom = amtTreasure(inputRoomNo, treasures, noOfRooms);
			totalTreasure += amtTreasureRoom;
			if(totalTreasure > treasureLimit){
				printf("Total Treasure exceeds limit you provided!\n");
				break;			
			}
			printf("Treasure in this room is - %d\n", amtTreasureRoom);	
			printf("The adjacent rooms are - ");	
			print1DArray(7, adjRoomsTo);
			printf("Total treasure till now is - %d\n", totalTreasure);
			printf("Rooms visited till now - ");
			print1DArray(countVisit, visitedRooms);
			printf("\n");
			printf("What is the next room you would like to search - ");			
			scanf("%d", &inputRoomNo);
		}
			
		else{
			if(visited(visitedRooms, inputRoomNo, countVisit)){
				printf("sorry the room you entered is already visited\n");
				break;		
		
			}
			else{
				printf("sorry the room you entered is not reachable, enter from the adj rooms\n");
				break;
			}	
		}
		
		
	}
	if(countVisit>= maxRooms){
		printf("No of rooms searched exceeds the limit you provided!\n");	
	}
}

bool checkAdjRoomPresent(int* arr, int roomNo, int noOfRooms){
	bool result = false;	
	for(int i = 0;i<noOfRooms;i++){
		if(arr[i]==roomNo){
			result = true;
			break;
		}	
	}
	return result;
}	

bool visited(int* arr, int roomNo, int count){
	bool result = false;
	for(int i = 0;i<count; i++){
		if(arr[i] == roomNo){
			result = true;
			break;
		}
	}
	return result;
}
