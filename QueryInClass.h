#pragma once

#include <time.h>
#include <unistd.h>
#include <sstream>
#include <fstream>  
#include <string>
#include <cstring>  
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstdlib>
#include <cstdio>
#include <vector> 

#ifndef XX
#define XX
#pragma once 
#include "QueryStruct.h"
#endif



using namespace std;
class QueryInClass
{
	
private:/*
	struct incmdline
	{
		string m_Q1;
		string m_Q2;
		string m_d;	
		string m_bm;
		string m_cj;
		int m_type;
	}only;*/
	incmdline only;
public:
	
	void In(int argc,char* argv[]);
	int Gettype(){return only.type;}
	string Getbm(){return only.bm;}
	string Getcj(){return only.cj;}
	string Getd(){return only.d;}
	string GetQ1(){return only.Q1;}
	string GetQ2(){return only.Q2;}
	incmdline Getcmd(){return only;}
public:
	
	QueryInClass();  
	virtual ~QueryInClass(void);  

};
