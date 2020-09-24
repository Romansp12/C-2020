#include <bits/stdc++.h>

using namespace std;
vector<vector<string> > data;


int read(char* file){
    ifstream in(file);
    string s;
    if (in.is_open()){
    while(getline(in,s)){
        string delimiter = "\t";
        size_t pos = 0;
        string token;
        vector<string> cur;
        while ((pos = s.find(delimiter)) != std::string::npos) {
            token = s.substr(0, pos);
            cur.push_back(token);
            s.erase(0, pos + delimiter.length());
        }
        cur.push_back(s);
        data.push_back(cur);
    }
    }else{
        return 0;
    }

    return 1;
}


void stringlow(string& s){
    for(auto& u: s) u=tolower(u);
}

void stringup(string& s){
    for(auto& u: s) u=toupper(u);
}

int main(int argc,char* argv[]){


    if (argc<2){
        cout<<"ERROR"<<endl;
        return 1;
    }
    if (read(argv[1])==0){
        cout<<"ERROR FILE"<<endl;
        return 1;

    }

    for(int i=2;i<argc;i++){
        string token(argv[i]);
        int po=token.find(":");
        string tmp=token.substr(0,po);
        int in=atoi(tmp.c_str());
        token.erase(0,po+1);


        if (token[0]=='u'){
            for(int i=0;i<data.size();i++){
               if (data[i].size()<=in) continue;
               stringlow(data[i][in]);
            }
        }

        if (token[0]=='U'){
            for(int i=0;i<data.size();i++){
               if (data[i].size()<=in) continue;
               stringup(data[i][in]);
            }
        }

        if (token[0]=='R'){
            char A=token[1];
            char B=token[2];
            for(int i=0;i<data.size();i++){
                if (data[i].size()<=in) continue;
                for(int j=0;j<data[i][in].size();j++) data[i][in][j]=(data[i][in][j]==A?B:data[i][in][j]);
            }
        }



    }

    for(int i=0;i<data.size();i++){
        for(int j=0;j<data[i].size();j++) cout<<data[i][j]<<" ";
        cout<<endl;
    }


}
