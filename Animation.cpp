/************************************************************************************************************
Filename: animation.cpp
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
Purpose: All the logic for adding, editing, deleting and reporting the list of frames is contained in this file.
As well as all logic manipulating the Animation data members.
***********************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include "Animation.h"
#include <iostream>
#include <string>
using namespace std;
/************************************************************************************************************
Function name: Animation
Purpose: Initialize Animation and prompt user for Animation Name
		Allocated memory for Animation name
In parameters: None
Out parameters: None
Version: 2.0
Author: Jason Waid
*************************************************************************************************************/
Animation::Animation() {
	char buffer[64];
	int size;

	frames = nullptr;

	cout << "Enter Animation name: ";
	cin >> buffer;

	size = strlen(buffer) + 1;

	this->animationName = new char[size];

	strcpy(this->animationName, buffer);
}
/************************************************************************************************************
Function name: ~Animation
Purpose: Deletes Animation freeing up memory allocated for Animation
In parameters: None
Out parameters: None
Version: 2.0
Author: Jason Waid
*************************************************************************************************************/
Animation::~Animation() {
	delete[] animationName;
	delete frames;

	animationName = nullptr;
	frames = nullptr;

}
/************************************************************************************************************
Function name: InsertFrame
Purpose: Prompts user for the name of the new frame
Inserts a new frame object (allocates memory) to the begining of the linked list
In parameters: None
Out parameters: None
Version: 2.0
Author: Jason Waid
*************************************************************************************************************/
void Animation::InsertFrame() {
	Frame* head_frame = frames;
	Frame* new_frame = new Frame;
	char buffer[64];
	int size;

	cout << "Insert a Frame in the Animation" << endl;

	cout << "Please Enter Frame frameName: ";
	cin >> buffer;

	size = strlen(buffer) + 1;

	new_frame->GetFrameName() = new char[size];
	strcpy(new_frame->GetFrameName(), buffer);

	new_frame->GetpNext() = head_frame;

	frames = new_frame;

}
/************************************************************************************************************
Function name: EditFrame
Purpose: Prompts the user for an index to edit the frame
replaces the existing frame name with the new one entered
In parameters: None
Out parameters: None
Version: 2.0
Author: Jason Waid
*************************************************************************************************************/
void Animation::EditFrame() {
	Frame* frame = frames;

	int num_frames = 0;
	int frame_index;
	int size;
	char new_frame_name[64];

	/*while loop used to count the frames in the list*/
	while (frame != nullptr) {

		frame = frame->GetpNext();
		num_frames++;
	}

	/*reset pointer value to begining of list*/
	frame = frames;

	cout << "Edit a Frame in the Animation" << endl;
	cout << "There are " << num_frames << " Frames(s) in the list. Please specify the index (<=" << num_frames - 1 << ") to edit at: " << endl;
	cin >> frame_index;

	if ((frame_index <= num_frames - 1) && (frame_index >= 0)) {
		/*navigate the list up till the desired index*/
		for (int i = 0; i != frame_index; i++) {
			frame = frame->GetpNext();
		}
		cout << "The name of this Frame is " << frame->GetFrameName() << ". What do you wish to replace it with?" << endl;
		cin >> new_frame_name;

		/*Calculate size of entered string plus null terminating byte*/
		size = strlen(new_frame_name) + 1;

		/*Reallocate FrameName mem*/
		frame->GetFrameName() = new char[size];

		/*Copy the new name into memory*/
		strcpy(frame->GetFrameName(), new_frame_name);
	}
}
/************************************************************************************************************
Function name: DeleteFrame
Purpose: Deletes the last frame at the end of the list
In parameters: None
Out parameters: None
Version: 2.0
Author: Jason Waid
*************************************************************************************************************/
void Animation::DeleteFrame() {
	Frame* frame = frames;
	Frame* previous_frame = frames;

	if (frames != nullptr) {

		/*deletes last frame only*/
		while (frame->GetpNext() != nullptr) {
			previous_frame = frame;

			frame = frame->GetpNext();
		}

		/*If deleted frame is first frame, resolve dangling pointers*/
		if (frames == frame) {
			frames = nullptr;
		}
		else
		{
			previous_frame->GetpNext() = nullptr;
		}
		delete frame;
	}
}
/************************************************************************************************************
Function name: ReportAnimation
Purpose: Prints out the Frame linked list
In parameters: None
Out parameters: None
Version: 2.0
Author: Jason Waid
*************************************************************************************************************/
void Animation::ReportAnimation() {
	int frame_num = 0;
	Frame* frame = frames;

	cout << "The Animation name is " << animationName << endl;
	cout << "Report the Animation" << endl;

	/*for loop that prints all frames till end of list*/
	while (frame != nullptr) {

		cout << "Frame #" << frame_num << " file name = " << frame->GetFrameName() << endl;

		frame = frame->GetpNext();
		frame_num++;

	}
}