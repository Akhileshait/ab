#include<iostream>
using namespace std;

//hashing using linear probing with chaining without replacement
struct rec{
    int rolln;
    int chain;
};

class Hashing{
    
    public:

    rec hashtable[10];
    int ct=0;

    Hashing(){
        for(int i=0; i<10; ++i){
        hashtable[i].rolln=-1;
        hashtable[i].chain=-1;
        }
    }
    
    void insert(int r){
        int pos=r%10;
        int p=r%10;
        if(hashtable[pos].rolln==-1){
            hashtable[pos].rolln=r;
            ct++;
        }else{
            if(ct==10){
                cout<<"Completely filled"<<"\n";
                return;
            }

                    while(true){
                        pos++;
                        pos=pos%10;
                        if(hashtable[pos].rolln%10==r%10){
                            p=pos;
                        }
                        if(hashtable[pos].rolln==-1){
                        hashtable[pos].rolln=r;
                        if((hashtable[p].rolln%10)==(hashtable[pos].rolln%10)){
                            hashtable[p].chain=pos;  
                        }
                        ct++;
                        return;
                    }
                    }
                
            
        }
    }

    int search(int r){
        int pos=r%10;
        while(true){
            if(hashtable[pos].rolln==r){
                return pos;
            }else if(hashtable[pos].rolln==-1){
                return -1;

            }
            else{
                if(hashtable[pos].chain==-1){
                    return -1;
                }else{
                    pos=hashtable[pos].chain;
                }
            }        
        }
        return -1;
    }

    void display(){
        for(int i=0; i<10; ++i){
            cout<<hashtable[i].rolln<<" "<<hashtable[i].chain<<"\n";
        }
    }

    void erase(int r){
        int pos=r%10;
        for(int i=0; i<10; ++i){
            if(hashtable[pos].rolln==r){
                hashtable[pos].rolln=-2;
                hashtable[pos].chain=-2;
                return;
            }
            pos++;
            pos=pos%10;
        }
        cout<<"No such Elemenet found "<<"\n";
        return;

    }
}h;

int main(){
    int ch;
    cout<<"Enter the operation: "<<"\n";
        cout<<"1. Insert"<<"\n";
        cout<<"2. search"<<"\n";
        cout<<"3. Display"<<"\n";
        cout<<"4. Erase"<<"\n";
        cout<<"0 for Exit"<<"\n";
    while(ch){
        cin>>ch;

        if(ch==0){
            break;
        }else if(ch==1){
            int r;
            cout<<"Enter the roll no.";
            cin>>r;
            h.insert(r);

        }else if(ch==2){
            int r;
            cout<<"Enter the roll num: ";
            cin>>r;
            cout<<h.search(r);
        }else if(ch==3){
            h.display();
        }else if(ch==4){
            int r;
            cout<<"Enter the roll no.";
            cin>>r;
            h.erase(r);
        }
    }
}