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
#include "jsoncpp/json/json.h" 

using namespace std;
class QueryOutClass
{
	
private:
	string m_bm;
	string m_ver;
	string m_Q_1;
	string m_Q_2;
	float m_ANI1;
	float m_ANI2;
	float m_PCD1;
	float m_PCD2;	

public:
	
	void SetJson(string Q_1,string Q_2,string bm,string ver);	
	void SetArg(float ANI1,float ANI2,float PCD1,float PCD2);
	void OutCmd();
	void OutJson();

public:
	
	QueryOutClass();  
	virtual ~QueryOutClass(void);  

};
