/*  
Program to find the hourly avegrage of AWS data.
*/

#include<iostream>
#include<fstream>
using namespace std;
int main(){
  char filename[42];
  float time,temp,rh,ws,wd,p;
  float avgwsarr[24]={0}, avgwdarr[24]={0}, avgrharr[24]={0},avgtemparr[24]={0}, avgparr[24]={0};
  ofstream outfile("/home/manu/Documents/jeni/op/op2015.dat");
  ifstream readfile("/home/manu/Documents/jeni/op/hourly2015filelist.txt");
  int ii=15; float tt;
  while(true){
     readfile>>filename;
     if(readfile.eof()) break;
     ifstream infile(filename);
     cout<<filename<<endl;
     float sumwsarr[24]={0}, sumwdarr[24]={0},sumrharr[24]={0},sumtemparr[24]={0},sumparr[24]={0};
     int n=0;
     int narr[24]={0};
     bool changemode=false;
     int i=0;
     while(true){
       infile>>time>>temp>>rh>>ws>>wd>>p; 
       if(infile.eof()) break; 
       if(time>=i & time<i+1){
        sumwsarr[i] += ws;
        sumwdarr[i] += wd;
        sumrharr[i] += rh;
        sumtemparr[i] += temp;
        sumparr[i] += p;
        narr[i]++;
        changemode=false;
     }
     else {
        changemode=true;
        i=i+1;
     }
    }
    
    for(int jj=0; jj<24; jj++){
       avgwsarr[jj] = sumwsarr[jj]/narr[jj];
       avgwdarr[jj] = sumwdarr[jj]/narr[jj];
       avgtemparr[jj] = sumtemparr[jj]/narr[jj];
       avgrharr[jj] = sumrharr[jj]/narr[jj];
       avgparr[jj] = sumparr[jj]/narr[jj];
       tt=ii+(jj/24.0); 
       //cout << jj << "\t" << narr[jj] << "\t" << "\t" << avgwsarr[jj] << "\t"<<avgwdarr[jj]
       //     <<"\t"<< avgtemparr[jj]<<"\t"<<avgrharr[jj]<<"\t"<<avgparr[jj]<<endl;
       outfile<<tt<<"\t"<<jj<< "\t" << "\t" << avgwsarr[jj] << "\t"<<avgwdarr[jj]
              <<"\t"<< avgtemparr[jj]<<"\t"<<avgrharr[jj]<<"\t"<<avgparr[jj]<<endl;

    }
    ii++;
    infile.close();
  }
  readfile.close();
  outfile.close();
  return 0;
}
