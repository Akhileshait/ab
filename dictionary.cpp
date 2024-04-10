#include<bits/stdc++.h>
using namespace std;

struct node{
    string word;
    string meaning;
    node *nxt;
    node(){
        nxt=NULL;
    }
};

class hashing{
    
    public:
    node *table[10];
        hashing(){
            for(int i=0; i<10; ++i){
                table[i]->word="null";
            }                    
        }
        
        void insertword(string word, string meaning){
            int h=0;
            for(int i=0; i<word.size(); ++i){
                h+=word[i]*pow(10, word.size()-i-1);
            }
            h=h%10;
            if(table[h]->word=="null"){   
                table[h]->word=word;
                table[h]->meaning=meaning;
            }else{
                node *head=table[h];
                while(head!=NULL){
                    head=head->nxt;
                }
                head->word=word;
                head->meaning=meaning;
            }
        }

        void searchword(string word){
            int h=0;
            for(int i=0; i<word.size(); ++i){
                h+=word[i]*pow(10, word.size()-i-1);
            }
            h=h%10;
            if(table[h]->word=="null"){   
                cout<<"NOT Found"<<"\n";
            }else{
                node *head=table[h];
                while(head->word!=word && head!=NULL){
                    head=head->nxt;
                }
                if(head!=NULL){
                    cout<<head->meaning<<"\n";
                }else{
                    cout<<"NOT Found"<<"\n";
                }
            }
        }

        void display(){
            for(int i=0; i<10; ++i){
                if(table[i]->word!="null"){
                    node *head=table[i];
                    while(head!=NULL){
                        cout<<i<<" "<<head->word<<" "<<head->meaning<<"\n";
                        head=head->nxt; 
                    }
                }else{
                    cout<<"null"<<"\n";
                }
            }
            
        }
};

int main(){
    hashing h;

    h.insertword("Hello", "Greeting");
    h.insertword("AIT", "College");
    h.insertword("computer", "device");
    h.insertword("hiking", "on mountain");

    h.display();
}