#include "BlastnClass.h"

BlastnClass::~BlastnClass(void)
{
}


BlastnClass::BlastnClass()
{
	m_pPath = " ";		
	m_pTask = "blastn";
	m_pQuery = "";
	m_pQuery2 = "";
	m_pDB = "as";
	m_pOut = "old.txt";
	m_pNum_align = "150";
	m_pPenalty = "-1";
	m_pReward = "1";
	m_pOutfmt = "6";
	m_pQueryPath = " ";
	m_Queryfna = " ";
}																																																																																																																																																																																																																																																																																																																							

void BlastnClass::BeginBlastn(){

	int fpid=fork();
	int status;
	const char *p=m_pPath.c_str();
	if(fpid==0)
			
		execlp("blastn",p,"-task",m_pTask,"-query",m_pQuery,"-db",m_pDB,"-outfmt",m_pOutfmt,"-evalue","10","-out",m_pOut,"-num_alignments",m_pNum_align,"-penalty",m_pPenalty,"-reward",m_pReward,(char *)0);
		
	else{
		waitpid(fpid,&status,0);				
	}
}

void BlastnClass::BeginMummer(){

	string m_pOut1 = m_pOut;
	string m_pQuery1 = m_pQuery;
	string m_pQuery21 = m_pQuery2;
	string s = "nucmer -p "+m_pOut1+" "+m_pQuery1+" "+m_pQuery21+" 1>1.txt 2>1.txt";
	const char *p=s.c_str();
	system(p);
	remove("1.txt");
}

void BlastnClass::SetCopy(){

	// need Q2 
	
	int a1 = 0;
	string::iterator itstr;
	
	for(itstr=m_pQueryPath.end() ; *itstr != '/' & itstr!=m_pQueryPath.begin( ); --itstr,++a1);
	const int a=a1-1;
	char b[a];

	
	int i=0;
	for(++itstr;itstr!=m_pQueryPath.end( ); ++itstr){
		if(i == a+1)  break;
		
		b[i] = *itstr;	
		++i;
	}
	
	
	m_Queryfna = string(b,a);
	//e.g. c = GCA_000005845.2_ASM584v2_genomic.fna
	

	FILE *pp = popen("pwd","r");
	char tmp[1024];
	fgets(tmp, sizeof(tmp), pp);
	
	pclose(pp);
	string tmp1 = tmp;
	tmp1 = tmp1.substr(0, tmp1.length()-1);
	tmp1 = tmp1+"/"+m_Queryfna;
	
	const char* tmp2 = tmp1.c_str();
	const char* m_pQueryPathc = m_pQueryPath.c_str();
	//e.g. tmp1 = /home/zck/Downloads/try
	//e.g. tmp2 = /home/zck/Downloads/try/GCA_000005845.2_ASM584v2_genomic.fna

	//"../GCA/GCA_000005845.2_ASM584v2_genomic.fna"
	ifstream ifs(m_pQueryPathc, ios_base::binary);
	ofstream ofs(tmp2, ios_base::binary);
	string line;
	 while (getline(ifs, line))ofs << line << endl;
   
	ifs.close();
	ofs.close();
}

void BlastnClass::SetPath(string paths){

	m_pPath = paths;
	const char *p=m_pPath.c_str();
	setenv("PATH",p,1);
	
}

void BlastnClass::SetTask(char* task){

	m_pTask = task;
}

void BlastnClass::SetQuery(char* query){

	m_pQuery = query;
}

void BlastnClass::SetQuery2(char* query){

	m_pQuery2 = query;
}


void BlastnClass::SetDB(const char* db){

	m_pDB = db;
}

void BlastnClass::SetOut(char* out){
	 
	m_pOut = out;
}

void BlastnClass::SetNum_align(int num_align){

	sprintf(m_pNum_align,"%d",num_align);
}

void BlastnClass::SetPenalty(int penalty){

	sprintf(m_pPenalty,"%d",penalty);
}

void BlastnClass::SetReward(int reward){

	sprintf(m_pReward,"%d",reward);
}

void BlastnClass::SetOutfmt(int outfmt){

	sprintf(m_pOutfmt,"%d",outfmt);
}

void BlastnClass::SetQueryPath(string querypaths){
	
	m_pQueryPath = querypaths;
}
