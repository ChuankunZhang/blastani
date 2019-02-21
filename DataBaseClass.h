

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
class DataBaseClass
{
	
private:
	string m_pPath;

public:

	void FormatDB();
	void SetPath(string path = NULL);

public:
	
	DataBaseClass();  
	virtual ~DataBaseClass(void);  

};



