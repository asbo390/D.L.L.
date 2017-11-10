#include <iostream>
#include <string.h>
#include <fstream>
#include "Header.h"
using namespace std;

int menu (void) {   //Console interface
    int r=0;
    cout<<"Functions: "<<endl<<"1.Add element"<<endl<<"2.Delete element"<<endl<<"3.Show elements in streight order"<<endl<<"4.Show elements in backward order"<<endl<<"5.Search by flight number"<<endl<<"6.Sell Tickets"<<endl<<"7.Exit"<<endl;
    cin>>r;
    return (r);
}
int main(int argc, char** argv) {
    char filename[40];
    if(argc >= 2)
        strcat(strcpy(filename, argv[1]), ".dat");
    else

    {
        cout << "Enter File name:" << endl;
        cin >> filename;
        strcat(filename, ".dat");
    }
    List mylist;
    ifstream myfile;
    flight data;
    int filecheck=0;
    myfile.open(filename,ios::binary | ios::out);   // Make list from file.
    if (myfile.is_open())   
    {
        if ( myfile.peek()==ifstream::traits_type::eof() ){ 
            cout<<"File is empty"<<endl;
            filecheck=1;
        }
        if(filecheck==0) {
        while (!myfile.eof()){
            myfile>>data.numb;
            myfile>>data.destination;
            myfile>>data.time;
            myfile>>data.cost;
            myfile>>data.free_spots;
            mylist.AddElement(data,0,filename);
        }
        }
    }
    else {
        cout << "Unable to open file";
        return 0;
    }
    int r;      //Key input 
    do{
        r=menu();
        switch(r)
        {
            case 1:
                data.get();
                mylist.AddElement(data,1,filename);
                break;
            case 2: mylist.DeleteElement(); break;
            case 3: mylist.ShowElements_str(); break;
            case 4: mylist.ShowElements_bck(); break;
            case 5: mylist.Search(); break;
            case 6:
                int a;
                int b;
                cin>>a;
                cin>>b;
                mylist.Sell(a,b);
                break;
        }
    cout<<"______________________________________________\n"<<endl;
    } while (r!=7);
    
    return 0;
}
