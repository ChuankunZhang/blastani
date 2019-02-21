#include "DataBaseClass.h"

DataBaseClass::~DataBaseClass(void)
{
}


DataBaseClass::DataBaseClass()
{
    m_pPath = "GCA_000026545.1_ASM2654v1_genomic.fna";

}

void DataBaseClass::FormatDB(){

	//int fpid=fork();
	//int status;
	//const char *p1=m_pPath.c_str();
		m_pPath = "makeblastdb -in "+m_pPath+" -dbtype nucl -title "+m_pPath+" -parse_seqids -out "+m_pPath+">1.txt";
		const char *p=m_pPath.c_str();
		system(p);
		remove("1.txt");
	//FILE *pp = fopen(p1,"w");
	
		//FILE *pp = popen(p,"r");
		//pclose(pp);

	//int b = fileno(pp);
	
	//dup2(b,0);
	
	//if(fpid==0)
	//{	
	//	execlp("makeblastdb","makeblastdb","-in",p,"-dbtype","nucl","-title",p,"-parse_seqids","-out",p,(char *)0);
	//}
	//else
	//{
	//	waitpid(fpid,&status,0);						
	//}
	
	//system("makeblastdb -in GCA_000005845.2_ASM584v2_genomic.fna -dbtype nucl -title GCA_000005845.2_ASM584v2_genomic.fna -parse_seqids -out GCA_000005845.2_ASM584v2_genomic.fna");
	
	
	
	//int a = fclose(pp);
	//cout<<"@@@"<<a<<"@@@"<<endl;
	
}

void DataBaseClass::SetPath(string path){

	m_pPath = path;

}
