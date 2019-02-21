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
#include <dirent.h>

#include <sys/stat.h>
#include <errno.h>

#include "DataBaseClass.h"
#include "BlastnClass.h"
#include "CoverageClass.h"
#include "QueryCutClass.h"
#include "QueryCopyBClass.h"
#include "QueryOutClass.h"
#include "QueryInClass.h"
#include "BlastnVersionClass.h"
#include "PearsonClass.h"
#include "jsoncpp/json/json.h" 

#ifndef XX
#define XX
#pragma once 
#include "QueryStruct.h"
#endif

using namespace std;  

int c=0;

	
//K-12 MG1655	CFT073		96.76	88.37
//K-12 MG1655	E2348/69	97.05	84.41
//K-12 MG1655	53G		98.63	85.97
//
//CFT073	K-12 MG1655	96.58	78.41	
//E2348/69	K-12 MG1655	97.06	77.02
//53G		K-12 MG1655	98.64	80.41

//HI2424	G4		87.55	31.26?
//G4		HI2424		87.97	28.73?

//OS155		CN-32		83.89	17.60?
//CN-32		OS155		83.31	71.12?

//CFT073	GCA_000007445.1_ASM744v1_genomic.fna
//K-12 MG1655	GCA_000005845.2_ASM584v2_genomic.fna
//E2348/69	GCA_000026545.1_ASM2654v1_genomic.fna
//53G		GCA_000283715.1_ASM28371v1_genomic.fna

//HI2424	GCA_000203955.1_ASM20395v1_genomic.fna
//G4		GCA_000016205.1_ASM1620v1_genomic.fna

//PAO1		GCA_000006765.1_ASM676v1_genomic.fna
//Pf-5		GCA_000012265.1_ASM1226v1_genomic.fna
//SBW25		GCA_000009225.1_ASM922v1_genomic.fna
//B728a		GCA_000012245.1_ASM1224v1_genomic.fna
//DC3000	GCA_000007805.1_ASM780v1_genomic.fna

//OS155		GCA_000015845.1_ASM1584v1_genomic.fna
//CN-32		GCA_000016585.1_ASM1658v1_genomic.fna


// /home/zck/ncbi-blast-2.2.23/bin
//K-12 MG1655	GCA_000005845.2_ASM584v2_genomic.fna
//E2348/69	GCA_000026545.1_ASM2654v1_genomic.fna

char* Query1;
char* Query2;

string Q1;
string Q2;
string bm = "blastn";
string cj = "cmd";
int type = 1;
string d;

string Q_1;
string Q_2;

string o = "???";

float ixy1=0;
float iyx2=0;
int X=0;
int Y=0;

vector <int> icount1;
vector <int> icount2;
vector <int> at1;
vector <int> at2;

vector <int> r1v1;
vector <float> r3v1;
vector <int> r4v1;
vector <int> r7v1;

vector <int> r1v2;
vector <float> r3v2;
vector <int> r4v2;
vector <int> r7v2;

float ANI1=0;
float PCD1=0;
float ANI2=0;
float PCD2=0;

int Count1 = 0;
int Count2 = 0;
float Sum = 0;
int count1=0;
int count2=0;
int hc1 = 0;
int hc2 = 0;

DataBaseClass*	g_pDataBase = NULL;
BlastnClass*	g_pBlastn = NULL;
CoverageClass*	g_pCoverage = NULL;
CoverageClass*	g_pCoverage1 = NULL;
QueryCutClass*  g_pQueryCut1 = NULL;
QueryCutClass*  g_pQueryCut2 = NULL;
QueryCopyBClass* g_pQueryCopy = NULL;
QueryCopyBClass* g_pQueryCopy1 = NULL;
QueryOutClass*  g_pQueryOut = NULL;
QueryInClass*  g_pQueryIn = NULL;
BlastnVersionClass* g_pBlastnVersion = NULL;
PearsonClass* g_pPearson = NULL;	

incmdline onlyin;

void Blastn_cut();
void Blastn_blastdb();
void Blastn_copy();
void Blastn_coverage();
void Blastn_kiri();
void Blastn_blastdbinit();
void Out();
void In(int argc,char* argv[]);

