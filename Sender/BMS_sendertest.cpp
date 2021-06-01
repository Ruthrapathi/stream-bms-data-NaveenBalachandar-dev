#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "../test/catch.hpp"
#include "BMS_Sender.h"

TEST_CASE("validate that O/P fed to console") {
	
	Alert_Status_s AlertTestStat = {NOT_SENT,FILE_ACCESS_FAILURE};
  
	AlertTestStat = sendDataToConsole(11.5, 0.7);
	
  REQUIRE(AlertTestStat.ConsoleSentStatus   == SENT_TO_CONSOLE);

}

TEST_CASE("validate that file read") 
{
	
	Alert_Status_s AlertTestStat = {NOT_SENT,FILE_ACCESS_FAILURE};
  
	AlertTestStat = readInpDataFile();
	
       REQUIRE(AlertTestStat.FileReadStatus   == FILE_ACCESS_SUCCESS);
       REQUIRE(AlertTestStat.ConsoleSentStatus   == SENT_TO_CONSOLE);

}

