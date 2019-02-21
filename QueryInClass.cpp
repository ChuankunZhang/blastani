#include "QueryInClass.h"

QueryInClass::QueryInClass()
{
	//only=
	//{
	//	" ",
	//	" ",
	//	" ",
	//	"blastn",	
	//	"cmd",
	//	1
	//};
	only.Q1 = " ";
	only.Q2 = " ";
	only.d = " ";	
	only.bm = "blastn";
	only.cj = "cmd";
	only.type = 1;
}

QueryInClass::~QueryInClass(void)
{
	
}

void QueryInClass::In(int argc,char* argv[])
{
	int j=0;
	for(int i=1;i<argc;i++)
	{
		if(string(argv[i]) == "-path")
		{	
			if(!access(argv[i+1], F_OK))
			{
				cout<<"PATH_ok"<<endl;
				only.d=string(argv[i+1]);
				//....
			}
			else 
			{
				perror("ERROR");
				cout<<"the Blast+ Path is not true"<<endl;
				exit(0);
			}
			j++;
		}		
		if(string(argv[i]) == "-genome1")
		{	
			if(!access(argv[i+1], F_OK))
			{
				int AGTC=0;
				int all_AGTC=0;
				char s[301] ;
				FILE *fp = fopen(argv[i+1],"r");
				while(fgets(s,300,fp))
				{
					for( int i = 0; s[i] ; i ++ ) 
					{
					
						if( s[i] =='A' | s[i] == 'G' | s[i] == 'T' | s[i] == 'C' )
							AGTC++;
						all_AGTC++;
					}
				
				}
				float m_AGTC = (float)AGTC*100/all_AGTC;
				if(m_AGTC < 90)
				{
					cout<<"the genome1 file is non-existent"<<endl;
					exit(0);
				}
				cout<<"GENOME1_ok"<<endl;
				only.Q1=string(argv[i+1]);
			}
			else 
			{
				perror("ERROR");
				cout<<"the genome1 file is non-existent"<<endl;
				exit(0);
			}
			j++;
		}
		if(string(argv[i])== "-genome2")
		{	
			if(!access(argv[i+1], F_OK))
			{
				int AGTC=0;
				int all_AGTC=0;
				char s[301] ;
				FILE *fp = fopen(argv[i+1],"r");
				while(fgets(s,300,fp))
				{
					for( int i = 0; s[i] ; i ++ ) 
					{
					
						if( s[i] =='A' | s[i] == 'G' | s[i] == 'T' | s[i] == 'C' )
							AGTC++;
						all_AGTC++;
					}
				
				}
				float m_AGTC = (float)AGTC*100/all_AGTC;
				if(m_AGTC < 90)
				{
					cout<<"the genome2 file is non-existent"<<endl;
					exit(0);
				}		
				cout<<"GENOME2_ok"<<endl;
				only.Q2=string(argv[i+1]);
			}
			else 
			{
				perror("ERROR");
				cout<<"the genome2 file is non-existent"<<endl;
				exit(0);
			}
			j++;
		}
		if(string(argv[i])== "-tool_type")
		{	

			cout<<"type_ok"<<endl;
			only.bm = string(argv[i+1]);
			if(only.bm == "blastn")
			{
				
				only.type = 1;
			}
			else if(only.bm == "mummer")
			{
				
				only.type = 2;
			}
			else
			{
				perror("ERROR");
				cout<<"the type is wrong"<<endl;
				exit(0);
			}
			
		}
		if(string(argv[i])== "-out_type")
		{	

			cout<<"type_ok"<<endl;
			only.cj = string(argv[i+1]);
			if(only.cj != "cmd" && only.cj != "json")
			{

				perror("ERROR");
				cout<<"the type is wrong"<<endl;
				exit(0);
			}
			
		}
	}	
	
	if(j < 3)
	{
		
		if (j < 1)
		{
			cout<<endl<<endl;
			cout<<"		*************************"<<endl<<"		*                       *"<<endl<<"		* [ANI CALCULATOR v1.0] *"<<endl<<"		*                       *"<<endl<<"		*************************"<<endl<<endl;
			//ChuanKun Zhang's lab. since 2016
			//Check new software release at http://www.ezbiocloud.net/sw/oat 
		}
		else
		{
			cout<<endl<<endl<<"argument isnt enough:j="<<j<<endl<<endl;
		}
		cout<<"	USAGE"<<endl;
	  	cout<<"		newx [arguments]"<<endl;  
	  	cout<<"		newx -path PATH -method METHOD -genome1 FILE1 -genome2 FILE2 -out_type CMD_or_JSON -tool_type blastn_or_mummer"<<endl<<endl;

		cout<<"		Please enter the BlastPlus Path [\"String\"]"<<endl;
		cout<<"      		recommanded blast path : C:/NCBI/blast+2.2.31+/bin/"<<endl;
		cout<<"      		directory path with gap (like \"Program Files/...\")  "<<endl;
		cout<<"      		can be a problem in window OS."<<endl;
		cout<<"      		So, in case of containing gap in blast program path,"<<endl;
		cout<<"      		you should wrap the path with double quotation mark."<<endl<<endl;;
	
		exit(0);
	}
	//d= "/home/zck/MUMmer3.23";
	//d= "/home/zck/ncbi-blast-2.2.23/bin";				//	/home/zck/MUMmer3.23
	//Q1="../GCA/GCA_000026545.1_ASM2654v1_genomic.fna";	//	/home/zck/Downloads/GCA/GCA_000005845.2_ASM584v2_genomic.fna
	//Q2="../GCA/GCA_000005845.2_ASM584v2_genomic.fna";	//	/home/zck/Downloads/GCA/GCA_000026545.1_ASM2654v1_genomic.fna

	
}
