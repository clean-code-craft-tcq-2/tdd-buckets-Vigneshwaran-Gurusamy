#include <stdio.h>
#include <stdlib.h>
#include "ChargingRangeAndReadings.h"

char* ChargingRangeAndReadings(int* chargingCurrentSamples){
	char *chargingCurrentRangeAndOccurences = (char*)malloc(100);
	int maxValue, minValue;
	size_t numberOfSamples, numberOfOccurences;

	numberOfSamples = FindNumberOfSamples(chargingCurrentSamples);
	minValue = FindMinChargingCurrentRange(chargingCurrentSamples, numberOfSamples);
	maxValue = FindMaxChargingCurrentRange(chargingCurrentSamples, numberOfSamples);
	numberOfOccurences = numberOfSamples; // Since input is conidered as a single range
	sprintf(chargingCurrentRangeAndOccurences, "%d-%d, %lu", minValue, maxValue, numberOfOccurences);
	printf("Range, Readings \n");
	printf("%s\n", chargingCurrentRangeAndOccurences);
	return chargingCurrentRangeAndOccurences;
}

size_t FindNumberOfSamples(int* chargingCurrentSamples) {
	size_t numberOfSamples;
	numberOfSamples = sizeof(chargingCurrentSamples) / sizeof(chargingCurrentSamples[0]);
	return numberOfSamples;
}

int FindMinChargingCurrentRange(int* chargingCurrentSamples, size_t numberOfSamples){
	int minValue;
	minValue = chargingCurrentSamples[numberOfSamples-1]; //Initializing to last element  
	for (size_t i=0; i<numberOfSamples; i++) {
		if(chargingCurrentSamples[i] < minValue){
			minValue = chargingCurrentSamples[i];
		}
	}
	return minValue;
}

int FindMaxChargingCurrentRange(int* chargingCurrentSamples, size_t numberOfSamples){
	int maxValue;
	maxValue = chargingCurrentSamples[0]; // Initializing to first element
	for (size_t i=0; i<numberOfSamples; i++) {
		if(chargingCurrentSamples[i] > maxValue){
			maxValue = chargingCurrentSamples[i];
		}
	}
	return maxValue;
}
