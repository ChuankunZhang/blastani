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

using namespace std;
class QueryCutClass
{
	
private:
	const char* m_pInQuery;
	char* m_pOutQuery;
	int m_Count;
	vector<int> m_Icount;
	vector<int> m_At;

public:
	
	void Kiri();
	void Cut();
	void SetInQuery(string in_query = NULL);
	void SetOutQuery(char* out_query = NULL);
	int GetCount();
	vector<int> GetIcount();
	vector<int> GetAt();
public:
	
	QueryCutClass();  
	virtual ~QueryCutClass(void);  

};
