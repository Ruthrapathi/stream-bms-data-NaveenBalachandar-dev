/*--------------------------------------------------------------------------------
---    \file       BMS_Sender.c
---   \author      Naveen Balachandar (RBEI/ECK3) 
---
---     \brief       File to monitor the battery condition based required properties
------------------------------------------------------------------------------------*/
/*------ standard includes -------*/
#include <stdio.h>
#include <stdlib.h>

/*------ Project includes -------*/
#include "BMS_Sender.h"

/*Arrays to store file data*/
static float temp[30];
static float ChargeRate[30];

int readInpDataFile(void)
{
  FILE *fptr;
  int i;
  float TempRead ,ChargerateRead;
  /*Read the input file*/
  fptr=fopen("Inputdata.txt","r");
  if (fptr != NULL) 
  {
     for(i=0;i<30;i++)
     {
      fscanf(fptr,"%f\t%f", &TempRead,&ChargerateRead);
       temp[i] =TempRead;
       ChargeRate[i] =ChargerateRead;
       sendDataToConsole(TempRead,ChargerateRead);
     }
     /*Close the file*/
     fclose(fptr);
  }
  else
  {
   printf("File access error");
  }  
 
  return 0;
 }  


void sendDataToConsole(float temp ,float chargeRate)
{
printf("Temperature:%5.2f;chargeRate:%5.2f",temp,chargeRate);
}


int  main()
{
  readInpDataFile();
  return 0;
}
