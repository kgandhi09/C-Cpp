/*
 * controller.cpp
 *
 *  Created on: Oct 1, 2019
 *      Author: kushal
 */

#include "controller.h"

controller::controller(){

}

controller::~controller(){}

int** controller::readFileIntoHouse(int numOfRooms, FILE* fp){

	printf("Number of Rooms: %d\n", numOfRooms);

	int** houseLayout = (int**)malloc(numOfRooms * sizeof(int*));
	for(int i = 0; i < numOfRooms; i++){
		houseLayout[i] = (int*)malloc(numOfRooms * sizeof(int));
		for(int j = 0; j < numOfRooms;j++){
			fscanf(fp, "%d", &houseLayout[i][j]);
			//fp.getline(filename, houseLayout[i][j]);
		}
	}


	return houseLayout;

}


int* controller::readFileIntoTreasure(int numOfRooms, FILE* fp){

	int* treasure = (int*)malloc((numOfRooms+1) * sizeof(int));
	for(int i = 0; i < numOfRooms; i++){
		fscanf(fp, "%d", &treasure[i]);
	}

	return treasure;

}


void controller::print2DArray(int rows, int cols, int** arr){
	for(int i = 0; i < rows; i++){
		for(int j=0; j<cols;j++){
			printf("%2d", arr[i][j]);
		}
		printf("\n");
	}
}

void controller::print1DArray(int rows, int* arr){
	for(int i = 0; i < rows; i++){
		printf("%3d", arr[i]);
	}
	printf("\n");
}

int* controller::adjacentRooms(int** arr, int room, int noOfRooms){
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

int controller::amtTreasure(int room, int* arr, int noOfRooms){
	int result = 0;
	for(int i = 0;i<noOfRooms; i++){
		if((room-1) == i){
			result = arr[i];
		}
	}
	return result;
}

bool controller::checkAdjRoomPresent(int* arr, int roomNo, int noOfRooms){
	bool result = false;
	for(int i = 0;i<noOfRooms;i++){
		if(arr[i]==roomNo){
			result = true;
			break;
		}
	}
	return result;
}

bool controller::visited(int* arr, int roomNo, int count){
	bool result = false;
	for(int i = 0;i<count; i++){
		if(arr[i] == roomNo){
			result = true;
			break;
		}
	}
	return result;
}


