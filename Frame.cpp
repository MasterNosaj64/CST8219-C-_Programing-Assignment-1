/************************************************************************************************************
Filename: frame.cpp
Version: 1.0
Author: Jason Waid
Student Number: 040912687
Course Name: C++
Course Code: CST8219
Lab Section: 303
Assignment Number: 1
Assignment Name: Animation Project in C
Due Date: 2019/12/10
Submission Date: 2019/12/10
Professor's Name: Mohamed Abouseif
List of source files: Animation.cpp, Frame.cpp
Purpose: All the logic for initializing and deallocting memory exists in this file
************************************************************************************************************/
#include "Frame.h"
using namespace std;
/************************************************************************************************************
Function name: Frame
Purpose: Initializes a frame object
In parameters: None
Out parameters: None
Version: 2.0
Author: Jason Waid
*************************************************************************************************************/
Frame::Frame() {

frameName = nullptr;
pNext = nullptr;

}
/************************************************************************************************************
Function name: ~Frame
Purpose: Deletes all memory allocated for the frame
In parameters: None
Out parameters: None
Version: 2.0
Author: Jason Waid
*************************************************************************************************************/
Frame::~Frame() {

	/*Free memory for data members*/
	delete[] frameName;
	delete pNext;

	/*Avoids dangling pointers*/
	frameName = nullptr;
	pNext = nullptr;

}



