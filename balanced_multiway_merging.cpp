#include<iostream>
#include<vector>
#include<array>
#include<fstream>
using namespace std;

void COPY(vector<int>&a,vector<int>&b){
    while(!a.empty()){
        b.push_back(a[0]);
        a.erase(a.begin());
    }
}

int counting_char_in_vector(vector<int>a){
    int s=0;
    for(int i=0;i<a.size();i++){
        int k=a[i];
        if(k<0){
            s++;
            k=-k;
        }
        while(k/10) {
            s++;
            k=k/10;
        }
        s++;
    }
    return s;
}

int count_the_number(int a){
    int s=0;
    if(a<0){
        s++;
        a=-a;
    }
    while(a/10){
        s++;
        a/=10;
    }
    s++;
    return s;
}

void reading_file(string file_name,vector<int>&a){
    fstream b(file_name);
    string str;
    getline(b,str);
    if(str.empty())
        return;
    for(int i=0;i<str.size();i++){
        int k=int(str[i]-48);
        if(k==-3){
            k=int(str[i+1])-48;
            i++;
            if(int(str[i+1])-48==-16)
                a.push_back(-k);
            else if(0 <=int(str[i+1]-48) && int(str[i+1]-48) <= 9){
                while(0<=int(str[i+1])-48 && int(str[i])-48<=9) {
                    int p=int(str[i+1])-48;
                    k = k * 10 + p;
                    i++;
                }
                a.push_back(-k);
            }
        }
        else if(k==-16)
            continue;
        else if(0 <=int(str[i+1]-48) && int(str[i+1]-48) <= 9) {
            while(0<=int(str[i+1])-48 && int(str[i])-48<=9) {
                int p=int(str[i+1])-48;
                k = k * 10 + p;
                i++;
            }
            a.push_back(k);
        }
        else
         a.push_back(k);
    }
}

int Exponentiation(int c){
    int t=1;
    for(int i=1;i<c;i++)
        t*=10;
    return t;
}

void clear_file(string file_name){
    fstream f;
    f.open(file_name,ios::trunc);
    f.close();
}

void writting_file(string file_name,vector<int>&a){
    int t= counting_char_in_vector(a);
    char s[t*2];
    int j=0;
    for(int i=0;i<a.size();i++){
        int c= count_the_number(a[i]);
        if(c==1) {
            s[j] = a[i]+48;
            j++;
        }
        else if(c>1) {
            int e = a[i];
            if(e<0){
                s[j]='-';
                e=-e;
                j++;
                c--;
            }
            while (e / 10) {
                int l = Exponentiation(c);
                int k = e / l;
                e = e % Exponentiation(c);
                s[j] = k + 48;
                j++;
                c--;
            }
            s[j] = e + 48;
            j++;
        }
        if(i==a.size()-1) {
            s[j] = '\0';
            break;
        }
        else
            s[j]=' ';
        j++;
    }
    a.clear();
    clear_file(file_name);
    fstream f(file_name,ios::out);
    f<<s;
    f.close();
}

void reading(vector<vector<int>>&File,char chr){
    vector<int>E;
    if(int(chr)==102) {
        reading_file("f1.txt", E);
        File.push_back(E);
        E.clear();
        reading_file("f2.txt", E);
        File.push_back(E);
        E.clear();
        reading_file("f3.txt", E);
        File.push_back(E);
        E.clear();
    }
    else{
        reading_file("g1.txt", E);
        if(!E.empty()) {
            File.push_back(E);
            E.clear();
        }
        reading_file("g2.txt", E);
        if(!E.empty()) {
            File.push_back(E);
            E.clear();
        }
        reading_file("g3.txt",E);
        if(!File.empty()) {
            File.push_back(E);
            E.clear();
        }
    }
}

void writting(vector<vector<int>>&File,char chr){
    if(int(chr)==102) {
        if (!File[0].empty()) {
            writting_file("f1.txt", File[0]);
            File[0].clear();
        }
        if (!File[1].empty()) {
            writting_file("f2.txt", File[1]);
            File[1].clear();
        }
        if (!File[2].empty()) {
            writting_file("f3.txt", File[2]);
            File[2].clear();
        }
    }
    else{
        if (!File[0].empty()) {
            writting_file("g1.txt", File[0]);
            File[0].clear();
        }
        if (File.size()>=2 && !File[1].empty()) {
            writting_file("g2.txt", File[1]);
            File[1].clear();
        }
        if (File.size()>=3 && !File[2].empty()) {
            writting_file("g3.txt", File[2]);
            File[1].clear();
        }
    }
}

int checknull(vector<vector<int>>A){
    int k=0;
    for(vector<vector<int>>::iterator it=A.begin();it!=A.end();++it)
        if(it->empty())
            k++;
    if(k==A.size())
        return 0;
    return 1;
}


void sort(vector<vector<int>>&A,int& run_size,char chr) {
    vector<vector<int>> E;
    vector<vector<int>> G;
    reading(E, chr);
    vector<int> Q;
    for(int i=0;i<3;i++)
        A.push_back(Q);
    int e=0;
    while (checknull(E)) {
        for (int i = 0; !E[i].empty(); i++) {
            int k = A[i][0];
            A[i].erase(A[i].begin());
            for (int t = 0; t < k; t++) {
                if (E[i].empty())
                    continue;
                Q.push_back(E[i][0]);
                E[i].erase(E[i].begin());
            }
        }
        sort(Q.begin(), Q.end());
        G.push_back(Q);
        A[e+3].push_back(Q.size());
        e++;
        if(e == 3)
            e=0;
        Q.clear();
    }
    while(A[0].empty())
        A.erase(A.begin());
    if(int(chr)==102) {
        writting(G, 'g');
        while(!G.empty() && G[0].empty())
            G.erase(G.begin());
    }
    else {
        writting(G, 'f');
        while(!G.empty() && G[0].empty())
            G.erase(G.begin());
    }
}

void nature_run_distribute(vector<vector<int>> &File) {
    vector<int> f;
    reading_file("f0.txt", f);
    vector<int> a;
    for(int i=0;i<6;i++)
        File.push_back(a);
    int k = 0;
    for (; !f.empty();) {
        if (a.empty()) {
            a.push_back(f[0]);
            f.erase(f.begin());
        }
        while (!f.empty() && a.back() < f[0]) {
            a.push_back(f[0]);
            f.erase(f.begin());
        }
        if (k == 0) {
            File[k + 3].push_back(a.size());
            COPY(a, File[k]);
            k = 1;
        } else if (k == 1) {
            File[k + 3].push_back(a.size());
            COPY(a, File[k]);
            k = 2;
        } else {
            File[k + 3].push_back(a.size());
            COPY(a, File[k]);
            k = 0;
        }
    }
    writting(File, 'f');
    while(File[0].empty())
        File.erase(File.begin());
    f.clear();
}

void balance_multiway_sorting(vector<vector<int>> &File, int run_size) {
    vector<int> A;
    reading_file("f0.txt", A);
    nature_run_distribute(File);
    int chr=102;
    while(File[0][0]!=A.size()) {
        sort(File, run_size,char(chr));
        if(chr==102)
            chr=103;
        else
            chr=102;
    }
    A.clear();
    if(chr==102){
        reading_file("f1.txt",A);
        writting_file("f0.txt",A);
    }
    else{
        reading_file("g1.txt",A);
        writting_file("f0.txt",A);
    }
}

void print_file_f0() {
    vector<int>f;
    reading_file("f0.txt",f);
    cout<<"File 'f0.txt' sau khi tron co du lieu la: ";
    for(int i=0;i<f.size();i++)
        cout<<f[i]<<' ';
}
int main() {
    //reading_file
    fstream f("f0.txt");
    cout << "Nhap mot mang ki tu vào file f0 tai day: ";
    char a[100];
    cin.get(a, 100);
    f << a;
    f.close();
    //----------------------------------------------------------------------------------------------------------------

    //thuc hien doc file xem co loi khong
    cout << "Sau khi nhap file nguon co du lieu la: ";
    string s;
    fstream fs("f0.txt");
    getline(fs, s);
    cout << s << endl;
    //----------------------------------------------------------------------------------------------------------------
    vector<vector<int>> File;
    vector<int> b;
    int run_size = 1;
    balance_multiway_sorting(File, run_size);
    print_file_f0();
}