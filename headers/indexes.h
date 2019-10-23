#include<iostream>
#include<fstream>
#include<unordered_map>
#include<list>
#include<algorithm>

using namespace std;
std::unordered_map<std::string,std::list<std::string>> data_index_map;
class Store{
public:
    void read_file();
    std::string get_filename();
    void add_index(string);
    void display_index();
    bool is_stop_word(string);
    std::string lower(string);
    Store(string);
private:
    std::string filename;
    std::string file_path;
};

std::string Store::get_filename(){
    std::size_t pos = file_path.find_last_of('\\');
    filename = file_path.substr(pos+1);
    return filename;
}

void Store::add_index(string word){
    if(word!="")
    {
        if(data_index_map.find(word)!=data_index_map.end())
        {
            //std::list<std::string> word_found=data_index_map[word];
            std::list<string>::iterator iter = std::find (data_index_map[word].begin(), data_index_map[word].end(), filename);
            if(iter==data_index_map[word].end())
            {
                data_index_map[word].push_back(filename);
            }
        }
        else
        {
            std::list<string> files1;
            files1.push_back(filename);
            data_index_map.insert(std::make_pair(word,files1));
        }
    }
}

Store::Store(string filePath){
    file_path=filePath;
}


void Store::read_file(){
    ifstream ifile;
    ifile.open(file_path,std::ifstream::in);
    ifile.seekg(0,ifile.end);
    std::streampos length=ifile.tellg();
    ifile.seekg(0,ifile.beg);
    if(ifile.is_open()){
        char * buffer = new char[length];
        while(ifile.getline(buffer,1000,'\n')){
            
            if (!is_stop_word(buffer)){
                add_index(buffer);   
            }
        }
        delete [] buffer;
    }
    else{
        cout<<"couldnt open file"<<endl;
    }
    ifile.close();
    ifile.clear();
}

bool Store::is_stop_word(string word){
    std::list<string> stopWords={"no","of","so","by","use","the","in","and","if","is","he","you","let","be","anywhere","that","this",".","it","in","with","and","from"};
    std::list<string>::iterator liter=std::find(stopWords.begin(),stopWords.end(),lower(word));
    if(liter==stopWords.end()){
        return false;
    }
    else{
        return true;
    }
}

std::string Store::lower(string word){
    int i=0;
    while(i<word.length()){
        if(word[i]>65&&word[i]<92){
            word[i]=word[i]+32;
        }
        i++;
    }
    return word;
}

void display_index(){
    std::unordered_map<std::string,std::list<std::string>>::iterator miter=data_index_map.begin() ;
    std::ofstream ofile("C:\\Users\\whoami\\Documents\\textfiles\\result.json");
    while(miter!=data_index_map.end()){
        ofile<<miter->first<<":[";
        //cout<<miter->first<<": [";
        std::list<string>::iterator viter=miter->second.begin();
        while(viter!=miter->second.end()){
            ofile<<*viter<<",";
            //cout<<*viter<<",";
            viter++;
        }
        ofile<<"]";
        ofile<<endl;
        // cout<<"]";
        // cout<<endl;
        miter++;
    }
}
