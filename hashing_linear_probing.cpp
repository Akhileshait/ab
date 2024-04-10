#include<iostream>
using namespace std;


struct rec{
    int rolln;
    string name;
};

class Hashing{
    
    public:

    rec hashtable[10];
    int ct=0;

    Hashing(){
        for(int i=0; i<10; ++i){
        hashtable[i].rolln=-1;
        }
    }
    
    void insert(int r, string s){
        int pos=r%10;

        if(hashtable[pos].rolln==-1){
            hashtable[pos].rolln=r;
            hashtable[pos].name=s;
            ct++;
        }else{
            if(ct==10){
                cout<<"Completely filled"<<"\n";
                return;
            }
            while(true){
                pos++;
                pos=pos%10;
                if(hashtable[pos].rolln==-1){
                    hashtable[pos].rolln=r;
                    hashtable[pos].name=s;
                    ct++;
                    return;
                }
            }
        }
    }

    int search(int r){
        for(int i=0; i<10; ++i){
            if(hashtable[i].rolln==r){
                return i;
            }
        }
        return -1;
    }

    void display(){
        for(int i=0; i<10; ++i){
            cout<<hashtable[i].rolln<<" "<<hashtable[i].name<<"\n";
        }
    }

    void erase(int r){
        int pos=r%10;
        for(int i=0; i<10; ++i){
            if(hashtable[pos].rolln==r){
                hashtable[pos].rolln=-2;
                hashtable[pos].name="";
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
            string s;
            cout<<"Enter the roll no.";
            cin>>r;
            cout<<"Enter the Name: ";
            cin>>s;
            h.insert(r, s);

        }else if(ch==2){
            int r;
            cout<<"Enter the roll num: ";
            cin>>r;
            h.search(r);
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