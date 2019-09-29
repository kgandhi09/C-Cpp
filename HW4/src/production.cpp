/*
 * production.cpp
 *
 *  Created on: Sep 26, 2019
 *      Author: kushal
 */

#include "production.h"

production::production(int argc, char* argv[]){

}

production::~production(){}

bool production::runProduction(int argc, char* argv[])
{

	bool answer = true;
	printf("This is production!\n");
	char* ePtr=(char*)malloc(sizeof(char*));

	//char *filename = (char)malloc(sizeof(char)*)

	for(int i =0; i<100; i++){
		filename[i] = '\0';
	}

	strcpy(filename, argv[1]);

	maxRoomsToSearch =strtol(argv[2],&ePtr,10); // command line argument 1 - max no of rooms to search in house
	limTreasure=strtol(argv[3],&ePtr,10); // command line argument 2 - total limit of treasure found

	int treasureLimit=(int)limTreasure;

	FILE* fp = fopen(filename, "r");

	fscanf(fp, "%d", &numOfRooms);

	int** houseGraph = readFileIntoHouse(numOfRooms,fp);
	printf("This is the house Layout!\n");
	print2DArray(numOfRooms,numOfRooms, houseGraph);
	printf("\n");

	int* treasures = readFileIntoTreasure(numOfRooms, fp);
	printf("This is treasure in each rooms!\n");
	print1DArray(numOfRooms, treasures);
	printf("\n");

	interaction(numOfRooms, houseGraph, treasures, treasureLimit, maxRoomsToSearch);
	return answer;
}

int** production::readFileIntoHouse(int numOfRooms, FILE* fp){

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

int* production::readFileIntoTreasure(int numOfRooms, FILE* fp){

	int* treasure = (int*)malloc((numOfRooms+1) * sizeof(int));
	for(int i = 0; i < numOfRooms; i++){
		fscanf(fp, "%d", &treasure[i]);
	}

	return treasure;

}


void production::print2DArray(int rows, int cols, int** arr){
	for(int i = 0; i < rows; i++){
		for(int j=0; j<cols;j++){
			printf("%2d", arr[i][j]);
		}
		printf("\n");
	}
}

void production::print1DArray(int rows, int* arr){
	for(int i = 0; i < rows; i++){
		printf("%3d", arr[i]);
	}
	printf("\n");
}

int* production::adjacentRooms(int** arr, int room, int noOfRooms){
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

int production::amtTreasure(int room, int* arr){
	int result = 0;
	for(int i = 0;i<5; i++){
		if((room-1) == i){
			result = arr[i];
		}
	}
	return result;
}

void production::interaction(int noOfRooms, int** houseGraph, int* treasures, int treasureLimit, int maxRooms){
	int inputRoomNo;
	int* adjRoomsTo1 = (int*)malloc(sizeof(int)*7);
	//int* visitedRooms;
	int* visitedRooms = (int*)malloc(sizeof(int)*10);
	int countVisit = 0;
	int totalTreasure = 0;
	bool firstTime = true;
	printf("Enter the room number to search the room - ");
	scanf("%d", &inputRoomNo);
	while(countVisit < maxRooms){
		if(((checkAdjRoomPresent(adjRoomsTo1, inputRoomNo, noOfRooms)) && !(visited(visitedRooms, inputRoomNo, countVisit))) || firstTime){
			visitedRooms[countVisit] = inputRoomNo;
			countVisit++;
			firstTime = false;
			adjRoomsTo1 = adjacentRooms(houseGraph, (inputRoomNo-1), noOfRooms);
			int amtTreasureRoom1 = amtTreasure(inputRoomNo, treasures);
			totalTreasure += amtTreasureRoom1;
			if(totalTreasure > treasureLimit){
				printf("Total Treasure exceeds limit you provided!\n");
				break;
			}
			printf("Treasure in this room is - %d\n", amtTreasureRoom1);
			printf("The adjacent rooms are - ");
			print1DArray(7, adjRoomsTo1);
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

bool production::checkAdjRoomPresent(int* arr, int roomNo, int noOfRooms){
	bool result = false;
	for(int i = 0;i<noOfRooms;i++){
		if(arr[i]==roomNo){
			result = true;
			break;
		}
	}
	return result;
}

bool production::visited(int* arr, int roomNo, int count){
	bool result = false;
	for(int i = 0;i<count; i++){
		if(arr[i] == roomNo){
			result = true;
			break;
		}
	}
	return result;
}



