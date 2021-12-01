#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <fstream>
#include <chrono>
#include <list>

using namespace std;

int linecount = 0;
int errorcount = 0;
const int columncount = 8; /// file column count
const int size = 100000; /// file entry count
float vectortotaltime=0;

vector <string> lineread;
vector <string> temp;

void fileGenerator() 
{
    ofstream file0(std::to_string(size)+".txt");
    for (int x=1; x<size+1; x++) {
        file0 << ("vardas" + std::to_string(x)) << " " << ("pavarde" + std::to_string(x)) << " ";
        for (int y=0; y<columncount-2; y++) 
        {
            file0 << to_string(rand() % 10 + 1) << " ";
        }
        file0 << "\n";    
    }
    file0.close();
}

void readLine()
{
    string qwer;
    ifstream file;
    try {
        file.open(std::to_string(size)+".txt");
        if (!file.is_open()) {
            throw 403;
            }
        }

    catch (int asd) {
        cout <<"ERROR: missing file"<<endl;
        std::terminate();
    }

    while (getline(file, qwer)) {
        if (qwer=="") {                 /// check for empty lines, skip to next line if empty found
            continue;
        }
        lineread.push_back(qwer);
        linecount ++;
    }
    file.close();
}

void readStr(string a) 
{
    string word;
    stringstream str(a);
    while (str >> word) {
        temp.push_back(word);
    }   
};

class timer {
    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> start;
    public:
        timer() : start{std::chrono::high_resolution_clock::now()} {}
        void reset() {
            start = std::chrono::high_resolution_clock::now();
        }
        double elapsed() const {
            return std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - start).count();
        }
};

class Student 
{
private:

    string vardas_;
    string pavarde_;
    float galutinis_paz_;
    int egz_paz_;
    float galutinis_;
    int wordreadlenght_; 
    vector <int> nd_paz_;
    vector <string> wordread_;
    
public:

void assign() 
{
    if(wordread_.size() == columncount)           
    {   
        for (int x =2; x<wordread_.size()-1; x++) 
        {
            nd_paz_.push_back(std::stoi(wordread_[x]));
            galutinis_ += std::stoi(wordread_[x]);
        }        
        vardas_ = wordread_[0];
        pavarde_ = wordread_[1];
        egz_paz_ = std::stoi(wordread_[wordread_.size()-1]);
        galutinis_paz_= (((galutinis_) / nd_paz_.size())*0.4 + egz_paz_*0.6);   
    }
    else {
        throw 402;
    }
}

Student () 

{
    nd_paz_.reserve(columncount-3);
    wordread_.reserve(columncount);
    galutinis_ =0;
    galutinis_paz_ = 0;
}

    string vardas() const {        return vardas_;    }
    string pavarde() const {        return pavarde_;    }
    float galutinis_paz() const {        return galutinis_paz_;    }
    float galutinis() const {        return galutinis_;    }
    int egz_paz() const {        return egz_paz_;    }
    vector <int> nd_paz() const{        return nd_paz_;    }
    vector <string> wordread() const{        return wordread_;    }
    
    void setwordread(vector <string> v) {        wordread_ = v;    }
   
};

int main() {
    
    lineread.reserve(size);

    timer a;
    fileGenerator();
    cout << std::to_string(size)+".txt generation: "  << a.elapsed() << "s"<< endl;
    vectortotaltime += a.elapsed();
    
    readLine();

    timer c;

    vector <Student> grupedu;
    vector <Student> grupedu_v;

    grupedu.resize(linecount);
        
    for (int x=0; x<linecount; x++)             /// vector handle   
    {
    readStr(lineread[x]);
    grupedu[x].setwordread(temp);
    temp.clear();

    try 
    {
        grupedu[x].assign();
    }
    catch (int qwe) 
    {
        cout << "ERROR: corrupt data on line " << (x+1) << endl;
        errorcount ++;
    }
    catch (char const* zxc) 
    {
        cout << "ERROR: bad int on line " << (x+1) << endl;
        errorcount ++;
    }
    }

    cout << std::to_string(size)+".txt handle: "  << c.elapsed() << "s"<< endl;
    vectortotaltime += c.elapsed();


    std::vector<Student>::iterator lp;
    ofstream file33("vector "+std::to_string(size)+"<5.txt");
    ofstream file44("vector "+std::to_string(size)+">=5.txt");

    timer b;

    lp= grupedu.begin();            /// vector sort + write

    int ii = 0;
    for (lp = grupedu.begin(); lp != grupedu.end();)            
    {
        if (lp -> galutinis_paz() <5) 
        {  
            grupedu_v.push_back(*lp);
            file33 << lineread[ii] << endl;
        }
        else 
        {
            file44 << lineread[ii] << endl;
        }
        lp ++;
        ii ++;
    }
    
    grupedu.erase( remove_if(grupedu.begin(), grupedu.end(), [](const Student & c){return c.galutinis_paz() <5;}),     grupedu.end());

    cout << std::to_string(size)+".txt sort + write: "  << b.elapsed() << "s"<< endl;
    vectortotaltime += b.elapsed();
    cout << std::to_string(size)+".txt total: "  << vectortotaltime << "s"<< endl;
}
