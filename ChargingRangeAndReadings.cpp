#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test-framework/catch.hpp"
#include "ChargingRangeAndReadings.h"

TEST_CASE("Checks the charging current range and its readings") {
	int chargingCurrentSamples[] = {4,5};
	const char* expectedRangeAndOccurences = "4-5, 2";
	char* rangeAndOccurences;
	rangeAndOccurences = ChargingRangeAndReadings(chargingCurrentSamples);
	REQUIRE(strcmp(rangeAndOccurences, expectedRangeAndOccurences) == 0);
}

TEST_CASE("Check the size of given charging current samples") {
	int chargingCurrentSamples[] = {4,5};
	size_t expectedSize = 2;
	size_t numberOfSamples = FindNumberOfSamples(chargingCurrentSamples);
	REQUIRE(numberOfSamples == expectedSize);
}

TEST_CASE("Checks the minimum value in a given charging current range") {
	int chargingCurrentSamples[] = {4,5};
	int expectedMinValue = 4;
	size_t numberOfSamples = FindNumberOfSamples(chargingCurrentSamples);
	int minValueForChargingCurrentRange = FindMinChargingCurrentRange(chargingCurrentSamples, numberOfSamples);
	REQUIRE(minValueForChargingCurrentRange == expectedMinValue);
}

TEST_CASE("Checks the maximum value in a given charging current range") {
	int chargingCurrentSamples[] = {4,5};
	int expectedMaxValue = 5;
	size_t numberOfSamples = FindNumberOfSamples(chargingCurrentSamples);
	int maxValueForChargingCurrentRange = FindMaxChargingCurrentRange(chargingCurrentSamples, numberOfSamples);
	REQUIRE(maxValueForChargingCurrentRange == expectedMaxValue);
}
