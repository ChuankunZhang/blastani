#pragma once
#include <time.h>
#include <unistd.h>
#include <sstream>
#include <fstream>  
#include <string.h>  
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstdlib>
#include <cstdio>
#include <vector> 
using namespace std;
class DataInputClass
{
	
private:
	string m_Path;
	string m_Query1;
	string m_Query2;

public:

	void DataInput();
	void GetPath(){return m_Path;}
	void GetQuery1(){return m_Query1;}
	void GetQuery2(){return m_Query2;}

public:
	
	DataInputClass();  
	virtual ~DataInputClass(void);  

};


