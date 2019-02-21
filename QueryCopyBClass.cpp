#include "QueryCopyBClass.h" 

QueryCopyBClass::QueryCopyBClass()
{
	m_pInQuery = "old1.txt";
	m_pOutQuery = "new1.txt";
	m_count = 0;
	m_hc = 0;
	m_ANI = 0;
	m_PCD = 0;
	m_Count = 0;
}

QueryCopyBClass::~QueryCopyBClass(void)
{

}

void QueryCopyBClass::Copy(int type){   	            
	
	ifstream in(m_pInQuery);
	ofstream out(m_pOutQuery);        
	string line;  
	
	char* l;
	char* l2;

	char p[150];

	float sum = 0;	
	float r3r4 = 0;
	float r3 = 0;
	int r4 = 0;
	int r7 = 0;
	int r8 = 0;
	int r1 = 0;

	int max=0;
	int min=0;
	float ifid = 0;	
	int ifmax=0;
	int ifmin=0;
int v=0;
	char *next1=NULL;
	char *next2=NULL;

	if(type == 1)
	{
		const char* d="\t";
		while (getline(in, line)){
		
			int i=0;
			for(i=0;i<line.length();i++)
				p[i] = line[i];
			p[i] = '\0';

	
		
			next1 = p;
			l = strsep(&next1,d);
			l2= strsep(&l,"@");

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
			//r4>=312;
			//r3 >= ID && (r4*100/CHOP_LEN)>=CVP && r4>=100
			

			//if(r3 >= 90)
			//	r3r4 += r4*r3;

			if(r4 >=100)
			{
				if(m_At.at(r1-1) ==1)
				{
					max = r8;
					min = r7;
				}
				if((r7 > min && r8 <= max)|(r7 >= min && r8 < max))continue;	
				if((max <= r8 && min >= r7)|(r7 < min && r8 <= min)||(r8>max && r7>=max))		
				{
					if(ifmax == r8 && ifmin == r7 && ifid == r3 && m_At.at(r1-1) !=1) continue;
					ifid = r3;
					ifmax = r8;
					ifmin = r7;
						if(r3>30)
							if(r4 >= 714)
							{
								if(r3 >= 90)
								r3r4 += r4*r3;
								m_At.at(r1-1) = 0;
				
								out << line << endl;
				
								sum+=r3;
								m_count++;
								m_hc+=r4;
						
				
			
								m_V1.push_back(m_Icount.at(r1-1));
								m_V3.push_back(r3);
								m_V4.push_back(r4);
								m_V7.push_back(r7);
							}	
				
				}
			}					
		}
	}
	else
	{
		const char* d=" ";
		while (getline(in, line)){
		
			int i=0;
			for(i=0;i<line.length();i++)
				p[i] = line[i];
			p[i] = '\0';

				
			if(line[0] == '>')
			{
				
				next1 = p;
				l = strsep(&next1,d);
				l2= strsep(&l,"@");
			
				r1 = atoi(l);
				
			
				getline(in, line);
				
				int i=0;
				for(i=0;i<line.length();i++)
					p[i] = line[i];
				p[i] = '\0';
	
				next1 = p;
				l = strsep(&next1,d);
				r7=atoi(l);
				next2 = next1;
				l = strsep(&next2,d);
				r8=atoi(l);
				next1 = next2;
				l = strsep(&next1,d);
				next2 = next1;
				l = strsep(&next2,d);
				next1 = next2;
				l = strsep(&next1,d);
				int e = atoi(l);
				r4 = r8-r7+1;
				r3 = (float)(r4-e)*100/r4;
				out<<r1<<" "<<r3<<" "<<r4<<" "<<r7<<" "<<r8<<endl;
				
				sum+=r3;
				m_count++;
				r3r4 += r3*r4;
				

			}					
		}
	}


	m_ANI=sum/m_count;	
	m_PCD=(float)r3r4/m_Count;	
		
	in.close();
	out.close();
}

void QueryCopyBClass::SetInQuery(char* in_query)
{
	m_pInQuery = in_query;
}

void QueryCopyBClass::SetOutQuery(char* out_query)
{
	m_pOutQuery = out_query;
}
	
void QueryCopyBClass::SetCount(int Count)
{
	m_Count = Count;
}

float QueryCopyBClass::GetANI()
{	
	return m_ANI;
}

float QueryCopyBClass::GetPCD()
{	
	return m_PCD;
}

vector <float> QueryCopyBClass::GetVec3()
{
	return m_V3;
}

vector <int> QueryCopyBClass::GetVec1()
{
	return m_V1;
}

vector <int> QueryCopyBClass::GetVec4()
{
	return m_V4;
}

vector <int> QueryCopyBClass::GetVec7()
{
	return m_V7;
}

void QueryCopyBClass::SetVecIcount(vector <int> &vi)
{
	m_Icount = vi;
}

void QueryCopyBClass::SetVecAt(vector <int> &va)
{
	m_At = va;
}
	
int QueryCopyBClass::Getcount(){

	return m_count;
}
