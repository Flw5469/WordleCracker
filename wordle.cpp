#include <iostream>
#include <string>
#include <fstream>
#include <set>
using namespace std;
//0 is leave, 1 is correct pos, 2 is incorrect pos, 3 is not exist, 4 is read/write statement in apple-12121 format
//word position is 0 indexed
set<string> select(set<string> words,char c,int condition,int position){
    set<string> newWord;
    for (auto itr=words.begin();itr!=words.end();itr++){
        int DNE=0;
        for (int i=0;i<5;i++){
            if (condition==1){
                if (i==position){
                    if ((*itr).at(i)==c){
                        newWord.insert(*itr);
                    }
                }                
            }
            if (condition==2){
                if ((i!=position)&&((*itr).at(i)==c)&&(*itr).at(position)!=c){
                    newWord.insert(*itr);
                }
            }
            if (condition==3){
                if ((*itr).at(i)!=c){
                    DNE++;
                }
                if (DNE>=5){
                    newWord.insert(*itr);
                }
            }
        }
    }
    return newWord;
}
//only print first 1k
void printAll(set<string> words){
    cout<<"Words are: "<<endl;
    int count=0;
    for (auto itr=words.begin();itr!=words.end();itr++){
        if ((count++)>=5000) break;
        cout<<*itr<<endl;
    }
}
int main(){
    ifstream f("words.txt",ios::in);
    string word;
    set<string> words;
    while (getline(f,word)){
        words.insert(word);
    }
    int condition;
    do {
        cout<<"condition: ";
        cin>>condition;
        if (condition==4){
            string input;
            cout<<"input: ";
            cin>>input;
            string result;
            cout<<"result: ";
            cin>>result;

            for (int i=0;i<5;i++){
                words=select(words,input.at(i),result.at(i)-'0',i);
            }
        }
        else if (condition!=0){
                char c;
                int position=0;
                cout<<"character: ";
                cin>>c;
                if (condition!=3){
                    cout<<"position: ";
                    cin>>position;
                }
                words=select(words,c,condition,position);
        }
        printAll(words);
    } while (condition!=0);
    
    return 0;
}