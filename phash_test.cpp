#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "pHash.h"

#include <iostream>

using namespace cv;
using namespace std;

/*	
	Author: Ben Caine
	Date: 8/22/2013

	These are some basic, ugly, purely functional tests for my pHash library to
	check that these functions work in the naive case. 

	Someday proper unit tests will be added...
*/
int main()
{
	Mat hawaii = imread("C://Development//testimages//hawaii.jpg");
	Mat senior = imread("C://Development//testimages/senior_pic.jpg");
	Mat hawaii_2 = imread("C://Development//testimages//hawaii.jpg");

	// Init a pHash of size 50 to take Ints as their datatype
	pHash<int> hash(50);
	
	//Put two test images in the hash
	hash[hawaii] = 10;
	hash[senior] = 10;

	hash.at(senior) = 25;

	//Output the strings we saved
	cout<<hash.at(hawaii)<<endl;
	cout<<hash.at(senior)<<endl;
	
	// Test that with a different image object of the same image, 
	// it still pulls up the correct data
	cout<<hash[hawaii_2]<<endl;

	hash[hawaii_2] = 15;
	
	cout<<hash[hawaii_2]<<endl;

	cout<<"Size and Max Size"<<endl;
	cout<<hash.size()<<endl;
	cout<<hash.max_size()<<endl;

	cout<<"Erasing Hawaii, size should be 1"<<endl;
	hash.erase(hawaii_2);

	cout<<hash.size()<<endl;

	cout<<"Clearing"<<endl;
	hash.clear();

	cout<<hash[hawaii_2]<<endl;

	cin.get();
	cin.ignore();
	return 0;
}