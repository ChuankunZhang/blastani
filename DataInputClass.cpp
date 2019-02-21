#include "DataInputClass.h"

DataInputClass::DataInputClass(){

	m_Path = " ";
	m_Query1 = " ";
	m_Query2 = " ";

}

DataInputClass::~DataInputClass(void){

}

DataInputClass::DataInput(){

	cout<<"*********************"<<endl<<"[ANI CALCULATOR v1.0]"<<endl<<"*********************"<<endl<<endl;
	cout<<"Please enter the BlastPlus Path [\"String\"] the genome1 file[\"String\"] the genome2 file[\"String\"]"<<endl;
	cout<<"      recommanded blast path : C:/NCBI/blast+2.2.31+/bin/"<<endl;
	cout<<"      directory path with gap (like \"Program Files/...\")  "<<endl;
	cout<<"      can be a problem in window OS."<<endl;
	cout<<"      So, in case of containing gap in blast program path,"<<endl;
	cout<<"      you should wrap the path with double quotation mark."<<endl;
	cout<<"e.g. -path /home/zck/ncbi-blast-2.2.23/bin -genome1 ../GCA/GCA_000026545.1_ASM2654v1_genomic.fna -genome2 ../GCA/GCA_000005845.2_ASM584v2_genomic.fna"<<endl;
	
	string query;
	
	char *next1=NULL;
	char *next2=NULL;

	char *l;
	char *l2;

	while(1)
	{
		getline(cin,query);
		next1=query.c_str();
		
		l = strsep(&next1," ");
		

		r1 = atoi(l);

		next2 = next1;
		l = strsep(&next2,d);
		next1 = next2;
		l = strsep(&next1,d);	
		r3=atof(l);

		
		next2 = next1;
		l = strsep(&next2,d);
		r4=atoi(l);	
		next1 = next2;
		l = strsep(&next1,d);
		next2 = next1;
		l = strsep(&next2,d);
		next1 = next2;
		l = strsep(&next1,d);
		r7=atoi(l);
		next2 = next1;
		l = strsep(&next2,d);
		r8=atoi(l);




	}

	cout<<"Please enter the genome1 file[\"String\"]"<<endl;	
	while(1)
	{
		getline(cin,m_Query1);
		const char *genome1=m_Query1.c_str();
		if(!access(genome1, F_OK))
		{
			cout<<"ok"<<endl;
			break;
		}
		else 
		{
			perror("ERROR");
			cout<<"Please enter the genome1 file again[\"String\"]"<<endl;
		}
	}

	cout<<"Please enter the genome2 file[\"String\"]"<<endl;
	while(1)
	{
		getline(cin,m_Query2);
		const char *genome2=m_Query2.c_str();
		if(!access(genome2, F_OK))
		{
			cout<<"ok"<<endl;
			break;
		}
		else 
		{
			perror("ERROR");
			cout<<"Please enter the genome2 file again[\"String\"]"<<endl;
		}
	}
}

