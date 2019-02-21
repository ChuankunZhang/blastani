#include "QueryCutClass.h"

QueryCutClass::QueryCutClass()
{
	//m_pInQuery = "GCA_000005845.2_ASM584v2_genomic.fna";
	m_pOutQuery = "5845.fna";
	m_Count = 0;
	
}

QueryCutClass::~QueryCutClass(void)
{
	vector <int>().swap(m_Icount);
}

void QueryCutClass::Cut()
{
	ifstream in(m_pInQuery);
	ofstream out(m_pOutQuery);        
	string line;
	string line_1;
	string line_2;
	string line_3;
	char one; 
	const char* d="\t";
	string l;
	int NO1=1;
	int NO2=1;
	int flag=2;
	int j=1;
	char *next1=NULL;	
	char p[150]; 
	getline(in, line);
	int i=0;
	for(i=0;i<line.length();i++)
		p[i] = line[i];
	p[i] = '\0';

	next1 = p;
	l = strsep(&next1," ");	
	out << l << "." << NO1 << "." << NO2 <<"@1"<<endl;
	m_At.push_back(1);
	m_Icount.push_back(0);	
	while (getline(in, line)){
		if(line[0]=='\n'|| line[0]=='\t' ||line[0]=='\0')continue;
		if(line[0]=='>'){
					
			j=1;
			NO1++;
			m_Icount.push_back(m_Count);
			NO2=1;





			out << l << "." << NO1 << "." << NO2 <<"@"<< flag <<endl;
			m_At.push_back(1);
			flag++;
			continue;
		}
		
		line_3 +=line;
		if(line_3.size()>80){

			line_1.clear();
			line_1 = line_3.substr(0,80);
			line_2.clear();
			line_2 = line_3.substr(80,line_3.size());
			line_3.clear();
			line_3 = line_2;
		}else{
			line_1.clear();
			line_1 = line_3;
			line_3.clear();
		}
	
		 
		
		if(j==13){
			
			if(line_1.size()>60){

				line_2.clear();
				line_2 = line_1.substr(60,line_1.size())+line_3;
				line_3.clear();
				line_3 = line_2;

				line_2.clear();
				line_2 = line_1.substr(0,60);
				line_1.clear();
				line_1 = line_2;

			}
			
			out <<  line_1 <<endl;
			j++;
			m_Count +=line_1.size(); 
			continue;

		}
		if(j==14){			
			
			NO2++;
			out << l << "." << NO1 << "." << NO2 <<"@"<< flag << endl << line_1 << endl;
			m_At.push_back(1);
			flag++;	
			j=2;
			m_Icount.push_back(m_Count);
			m_Count +=line_1.size(); 
			continue;

		}
			
		m_Count +=line_1.size(); 
			

		out << line_1 <<endl;
		j++;
		
	}
	
	
	while(line_3.size()>80){
		
			line_1.clear();
			line_1 = line_3.substr(0,80);
			line_2.clear();
			line_2 = line_3.substr(80,line_3.size());
			line_3.clear();
			line_3 = line_2;
		
		if(j==13){
			
			if(line_1.size()>60){

				line_2.clear();
				line_2 = line_1.substr(60,line_1.size())+line_3;
				line_3.clear();
				line_3 = line_2;

				line_2.clear();
				line_2 = line_1.substr(0,60);
				line_1.clear();
				line_1 = line_2;

			}
			
			out <<  line_1 <<endl;
			j++;
			m_Count +=line_1.size(); 
			continue;

		}
		if(j==14){			
			
			NO2++;
			out << l << "." << NO1 << "." << NO2 <<"@"<< flag << endl << line_1 << endl;
			m_At.push_back(1);
			flag++;	
			j=2;
			m_Icount.push_back(m_Count);
			m_Count +=line_1.size(); 
			continue;

		}
			
		m_Count +=line_1.size(); 
			

		out << line_1 <<endl;
		j++;


	}
	if(line_3.size()>60 && j==13){

			line_1.clear();
			line_1 = line_3.substr(0,60);
			line_2.clear();
			line_2 = line_3.substr(60,line_3.size());
			out <<  line_1 <<endl;
			m_Count +=line_1.size();
			out << l << "." << NO1 << "." << NO2 <<"@"<< flag << endl << line_2 << endl;
			m_At.push_back(1);
			m_Icount.push_back(m_Count);
			m_Count +=line_2.size();
			m_Icount.push_back(m_Count);
		}else{
			out <<  line_3 <<endl;
			m_Count +=line_3.size();
			m_Icount.push_back(m_Count);
		}
	in.close();
	out.close();
	
}

void QueryCutClass::Kiri()
{
	ifstream in(m_pInQuery);
	ofstream out(m_pOutQuery);        
	string line;
	char one; 
	const char* d="\t";
	string l;
	int NO1=1;
	int NO2=1;
	int flag=2;
	int j=1;
	char *next1=NULL;	
	char p[150]; 
	getline(in, line);
	int i=0;
	for(i=0;i<line.length();i++)
		p[i] = line[i];
	p[i] = '\0';

	next1 = p;
	l = strsep(&next1," ");	
	out << l << "." << NO1 << "." << NO2 <<"@1"<<endl;
	m_At.push_back(1);
	m_Icount.push_back(0);	
	while (getline(in, line)){
		if(line[0]=='\n'|| line[0]=='\t' ||line[0]=='\0')continue;
		if(line[0]=='>'){
					
			j=1;
			NO1++;
			m_Icount.push_back(m_Count);
			NO2=1;


			out << l << "." << NO1 << "." << NO2 <<"@"<< flag <<endl;
			m_At.push_back(1);
			flag++;
			continue;
		}
			
		m_Count +=line.size(); 
			

		out << line <<endl;
		j++;
		
	}
	in.close();
	out.close();
	
}

void QueryCutClass::SetInQuery(string in_query)
{
	const char *p=in_query.c_str();
	m_pInQuery = p;

}

void QueryCutClass::SetOutQuery(char* out_query)
{
	
	m_pOutQuery = out_query;

}

int QueryCutClass::GetCount()
{

	return m_Count;

}

vector<int> QueryCutClass::GetIcount()
{

	return m_Icount;
	 
}

vector<int> QueryCutClass::GetAt()
{

	return m_At;
	 
}
