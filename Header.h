#ifndef Header_h
#define Header_h
using namespace std;
struct flight {     //List element's data.
    int numb;
    string destination;
    float time;
    int cost;
    int free_spots;
    void get (void) {
        cout<<"Enter Flight Number: "<<endl;
        cin>>numb;
        cout<<"Enter Destination: "<<endl;
        cin>>destination;
        cout<<"Set Arrival Time: "<<endl;
        cin>>time;
        cout<<"Set Cost: "<<endl;
        cin>>cost;
        cout<<"Set available seats: "<<endl;
        cin>>free_spots;
        cout<<"______________________________________________\n"<<endl;
    }
    void printflight (void) {

        cout<<"Flight Number is "<<numb<<endl;
        cout<<"Destination is "<<destination<<endl;
        cout<<"Arrival Time is "<<time<<endl;
        cout<<"Cost is "<<cost<<endl;
        cout<<"There are "<<free_spots<<" Available Seats"<<endl;
        cout<<"______________________________________________\n"<<endl;
    }
};
struct Node     //Element of the list
{
    flight data;
    Node *N,*P;
    Node(flight y)
    {
        data = y;
        N = P = NULL;
    }
};

class List
{
    Node *front;
    Node *back;
public:
    List() {
        front = NULL;
        back = NULL;
        
    }
    ~List() {
        
    }
    void AddElement(flight,int,char*);
    void Sell(int,int);
    void DeleteElement(void);
    void ShowElements_str(void);
    void ShowElements_bck(void);
    void Search(void);
};

void List::AddElement(flight x,int f,char* filename) {
    Node *n = new Node(x);
    if( front == NULL)
    {
        front = n;
        back = n;
    }
    else
    {
        front->P = n;
        n->N = front;
        front = n;
    }

    if (f==1) {     //Check whether new element must be added into file
        ofstream myfile;
        flight data;
        myfile.open(filename,ios::binary | ios::in | ios_base::app);
        if (myfile.is_open())
        {
            myfile<<x.numb<<" ";
            myfile<<x.destination<<" ";;
            myfile<<x.time<<" ";
            myfile<<x.cost<<" ";
            myfile<<x.free_spots<<endl;
        }
    }
    
}
void List::ShowElements_str(void) {
    if (front==NULL && back==NULL) {
        cout<<endl<<"List is empty"<<endl;
        return ;
    }
    Node *temp = front;
    cout << "\nList in forward order:" << endl;
    while(temp != NULL)
    {
        temp->data.printflight();
        temp = temp->N;
    }
}
void List::ShowElements_bck() {
    
}
void List::Sell(int a,int b) {
    
}
void List::DeleteElement() {
    
}
void List::Search() {
    
}

#endif /* Header_h */
