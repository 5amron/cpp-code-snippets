//author : samanSadeghyan
//purpose : graph and pathes (D.S.)

#include <iostream>
#include <fstream>
#include <vector>  
#include <algorithm>
#include <queue>
using namespace std;

vector<vector<int> >graph(100); 

int myFunction(int i,int m[10],int nodeMoredeNazar,int p[10],int f){
	for (int s=0;s<=p[f];s++){
		if (nodeMoredeNazar==m[s]){              
		return 1;                                
		break;                                   
		}else{
		continue;
				}
			}
	}

bool vectorFunction(int gereh, vector<int>path){
	int x;
	x = path.size();
	for(int i=0;i<x;++i){
		if(path[i]==gereh)
		return false;
	}
	return true;
}

int bigFunction(int aghaz,int target,int U,int V){

	vector<int>path;
	path.push_back(aghaz);
	queue<vector<int> >q;
	q.push(path);
	int i = 0;
	int length[10];
	int c = 0;
	int a[100][100];								
											
	while (!q.empty()){
		path = q.front();
		q.pop();
		int lastNode = path[path.size()- 1];

		if (lastNode==target){
			copy(path.begin(),path.end(),a[i]);
			i++;
			length[c] = path.size();                 
			c++;					
		}
		int o = graph[lastNode].size();
		for (int i = 0;i<o;++i){
			if (vectorFunction(graph[lastNode][i], path)){
				vector<int>npath(path.begin(),path.end());
				npath.push_back(graph[lastNode][i]);
				q.push(npath);
			}
		}
	}

	int myTarget;
	int help = 0;
	int p = length[i-1];
	int n[10] ;
	for (int va1=0;va1<p;va1++){					
		myTarget = a[i-1][va1];						
										            
	    for (int va2=0;va2<=i-1;va2++){				
			for (int va3=0;va3<length[va2];va3++)	
				n[va3] = a[va2][va3];  				
										            
			help = myFunction(i-1,n,myTarget,length,va2);
			if (help==1){
				continue;
			}
			else{
				break;
				}
			}
		if (help==1){
			cout<<myTarget;                                             
			help = 0;
		}
	}
	cout << endl;
	return 1;
}

int main(){

	int U;
	int V;
	int u;
	int v;
	int aghaz =1;

		ifstream infile;
		infile.open("afile.dat");

		infile >>U>>V;                    	

		for (int i=1;i<=10;i++){      //$$$$ tavajoh $$$$ baraye dadane graph haye mokhtalef bayad 10 ra dar in for taghir dad
			infile >>u>>v;
			graph[u].push_back(v);       	 
		}
		for(int j=2;j<=U;j++){
            bigFunction(aghaz,j,U,V);   		
		}

		infile.close();

	cout<<"Hello!!!"<<endl;
	return 0;
}


//------------afile.dat---------//
/*8
10
1 2
2 3
2 4
2 5
2 6
3 6
4 6
5 7
6 7
7 8
*/





