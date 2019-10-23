#include"headers\indexes.h"

int main(){
    /*
    const char * muliti_line_string = "hated minions of the law who were silent spectators of this delirium of"
"popular joy"
"what to do now"
"man this is";
int i=0;
int length = std::strlen(muliti_line_string);
while(i<length){
    cout<<muliti_line_string[i];
    i++;
}*/
    string file_path;
    //Store s("C:\\Users\\whoami\\Documents\\textfiles\\mspagesource.txt");
    Store s("C:\\Users\\whoami\\Documents\\textfiles\\memories_of_lincoln.txt");
    s.get_filename();
    s.read_file();
    /*Store s1("C:\\Users\\whoami\\Documents\\textfiles\\Rabbits_Have_Long_Ears.txt");
    s1.get_filename();
    s1.read_file();
    Store s2("C:\\Users\\whoami\\Documents\\textfiles\\The_last_President.txt");
    s2.get_filename();
    s2.read_file();*/
    display_index();
    return 0;
}