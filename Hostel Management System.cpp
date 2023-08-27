#include <iostream>
using namespace std;

struct Node{
    int roomNo;
    string studentID;
    string firstName;
    string lastName;
    int phoneNumber;
    char block;

    Node *previous;
    Node *next;
} *head=NULL, *tail=NULL;

struct RoomKey {
    int roomNo;
    char block;
    int floor;

    RoomKey *next;
} *top=NULL;

struct Request {
    string studentID;
    string firstName;
    string lastName;
    string email;
    int phoneNumber;

    Request *next;
} *front=NULL, *rear=NULL, *temp;

struct Room{
    string studentID;
    int roomNo;
    char block;

    Room *next;
    Room *previous;
} *head1=NULL, *tail1=NULL;

void admin_menu();
void student_menu();
void wardenLogin();
void pushRoom(int, int, char);
void displayRooms();
void requestroom();
void displayRequests();
void assignRoom();
void checkAssigment();
void viewAssignedRooms();
void checkIn();
void viewCheckedIn();


int main() {

    cout<<endl << endl;
    cout<<"\t||=================================================================||"<<endl;
    cout<<"\t||                                                                 ||"<<endl;
    cout<<"\t||                                                                 ||"<<endl;
	cout<<"\t||                 JIIT HOSTEL MANAGEMENT SYSTEM                   ||"<<endl;
    cout<<"\t||                                                                 ||"<<endl;
    cout<<"\t||                                                                 ||"<<endl;
	cout<<"\t||=================================================================||"<<endl;
	cout<<endl;
    cout<<"Welcome to JIIT Hostel Management System! "<<endl;


    int role;
    cout<<endl;
    cout<<"Press 1 for Warden 2 for Student"<<endl;
    cin>>role;
    if (role==1) {
        wardenLogin();
    }
    else if(role==2) {
        student_menu();
    }
    else {
        cout<<"Invalid Choice."<<endl;
    }

    return 0;
}


void admin_menu()
{
    int choice, sure, roomNo, flr;
    char block;
    do {
        cout<<endl;
        cout<<endl<<endl<<"\t\t    ------ ADMIN MENU ------"<<endl<<endl<<endl;
    	cout<<"\t\t\t 1. Add to available rooms list."<<endl;
    	cout<<"\t\t\t 2. View all available rooms."<<endl;
    	cout<<"\t\t\t 3. View all assigned rooms"<<endl;
    	cout<<"\t\t\t 4. View all room request."<<endl;
    	cout<<"\t\t\t 5. Assign room to student."<<endl;
    	cout<<"\t\t\t 6. Check In studentd. "<<endl;
        cout<<"\t\t\t 7. View list of students who have checked in."<<endl;
    	cout<<"\t\t\t 8.Exit"<<endl;
    	cout<<"\t\t\t 9.Log Out"<<endl;

    	cin>>choice;
    	switch (choice) {
            case 1:
                cout << "\n\n\t\t    ------ ADD ROOM KEY ------\n\n\n";
                cout<<"Enter Room Number: ";
                cin>>roomNo;
                cout<<"Enter Room Floor: ";
                cin>>flr;
                cout<<"Enter Room Block: ";
                cin>>block;
                pushRoom(roomNo, flr, block);
                break;
            case 2:
                cout<<"\n\n\t\t    ------ VIEW AVAILABLE ROOMS ------\n\n\n";
                displayRooms();
                break;
            case 3:
                 cout << "\n\n\t\t    ------ ASSIGNED ROOMS ------\n\n\n";
                viewAssignedRooms();
                break;
            case 4:
                cout << "\n\n\t\t    -------- ROOM REQUESTS -------\n\n\n";
                displayRequests();
                break;
            case 5:
                cout << "\n\n\t\t   -------- ASSIGN ROOM -------\n\n\n";
                assignRoom();
                break;
            case 6:
                cout << "\n\n\t\t    ------- ADD STUDENT CHECK-IN -------\n\n\n";
                checkIn();
                break;
            case 7:
                cout << "\n\n\t\t    -------- VIEW STUDENTS THAT CHECKED IN -------\n\n\n";
                viewCheckedIn();
                break;
            case 8:
                cout<<"Are you sure you want to exit?\n";
                cout<<"1. Yes \n2. No\n";
                cin>>sure;
                if(sure==1) {
                    cout << "\n\n\t\t    ------  EXIT ------\n\n\n";
                    exit(1);
                }
                else if(sure==2) {
                    admin_menu();
                }
                else {
                    cout<<"Invalid button";
                }
                break;
            case 9:
                 main();
                 break;
            default:
                cout<<"Invalid option."<<endl;
        }
     }while (choice!=8);
}



void student_menu()
{
    int choice;
    int sure;
    do {
        cout<<endl;
        cout <<endl<<endl<<"\t\t    ------ STUDENT MENU ------"<<endl<<endl<<endl;
    	cout << "\t\t\t 1. Request a room." << endl;
    	cout << "\t\t\t 2. Room allotment status." << endl;
    	cout << "\t\t\t 3. Exit" << endl;
    	cout << "\t\t\t 4. Main Menu"<<endl<<endl;

        cin>>choice;
        switch (choice) {
            case 1:
                requestroom();
                break;
            case 2:
                checkAssigment();
                break;
            case 3:
                cout<<"Are you sure you want to exit?\n";
                cout<<"1 Yes \n2 No\n";
                cin>>sure;

                if(sure==1) {
                    cout << "\n\n\t\t    ------  EXIT ------\n\n\n";
                    cout << endl << endl;
                    exit(1);
                }
                else if(sure==2) {
                    main();
                }
                else {
                    cout<<"Invalid option.";
                }
                break;
            case 4:
                main();
                break;
            default:
                cout<<"Invalid option.";
        }
    } while(choice!=3);
}


void wardenLogin(){
    string user;
    string pass;
    cout<<"-------Admin Login-------\n";
    cout<<"Enter your username: \n";
    cin>>user;

    cout<<"Enter your password: \n";
    cin>>pass;

    if(user=="warden" && pass=="pass") {
        cout<<"Welcome ADMIN!\n";
        admin_menu();
    }
    else{
        cout<<"Username or password incorrect.\n";
        main();
    }
}


void pushRoom(int roomNo, int floor, char block){
    RoomKey *newRoomKey= new RoomKey;
    newRoomKey->roomNo= roomNo;
    newRoomKey->floor= floor;
    newRoomKey->block= block;
    newRoomKey->next= top;
    top=newRoomKey;
}


void displayRooms() {
    RoomKey *ptr;
    if(top==NULL) {
        cout<<"There are no rooms available! \n";
    }
    else {
        ptr=top;
        cout<<"The available rooms are: \n";
        cout<<"RoomNo\tFloor\tBlock\n";
        while(ptr!= NULL) {
            cout<< ptr->roomNo<<"\t"<<ptr->floor<< "\t"<<ptr->block<<endl;
            ptr=ptr->next;
        }
    }
    cout<<endl;
}

void requestroom() {
    string fname, lname, gmail, sid;
    int pNo;
    cout<<"----------Request room----------\n";
    cout<<"Please note you should be a student in JIIT to request for a room here, and you are required to bring proofs in order to receive your keys!"<<endl<<endl;
    cout<<"Enter your first name: ";
    cin>>fname;
    cout<<"Enter your last name: ";
    cin>>lname;
    cout<<"Enter your student ID: ";
    cin>>sid;
    cout<<"Enter your email address: ";
    cin>>gmail;
    cout<<"Enter your phone number: ";
    cin>>pNo;
    if(rear==NULL) {
        rear=new Request;
        rear->next=NULL;
        rear->firstName= fname;
        rear->lastName= lname;
        rear->studentID= sid;
        rear->email= gmail;
        rear->phoneNumber=pNo;
        front=rear;
    }
    else {
        temp=new Request;
        rear->next=temp;
        temp->firstName= fname;
        temp->lastName= lname;
        temp->studentID= sid;
        temp->email= gmail;
        temp->phoneNumber=pNo;
        temp->next=NULL;
        rear=temp;
    }
}

void displayRequests() {
    temp= front;
    if((front==NULL) && (rear==NULL)){
        cout<<"There are no current requests\n";
        return;
    }

    cout<<"Requests are: \n";
    cout<<"Name\t\tID\tEmail\t\tPhoneNo\n";
    while(temp!=NULL) {
        cout<<temp->firstName<<" "<<temp->lastName<<"\t"<<temp->studentID<<"\t"<<temp->email<<"\t"<<temp->phoneNumber<< " "<< endl;
        temp=temp->next;
    }
    cout<<endl;

}

void assignRoom(){

    temp=front;
    if(top==NULL){
        cout<<"No available rooms! \n";
        return;
    }

    else {

        if(front==NULL){
        cout<<"There are no current requests\n";
        return;
        }

        else if(temp->next!=NULL) {
            Node *newNode= new Node;
            temp=temp->next;
            cout<<"Student "<<front->studentID<<" has been allocated to room number "<<top->roomNo<< " in block "<<top->block<<"."<<endl;



            newNode->firstName=front->firstName;
            newNode->lastName =front->lastName;
            newNode->studentID= front->studentID;
            newNode->phoneNumber=front->phoneNumber;
            newNode->roomNo=top->roomNo;
            newNode->block=top->block;

            newNode->next=NULL;

            if(head==NULL) {
                newNode->next=NULL;
                head=newNode;
                tail=newNode;
            }
            else {
                newNode->previous=tail;
                tail->next=newNode;
                tail=newNode;
            }

            top=top->next;
            free(front);
            front=temp;
        }

        else {
            cout<<"Student "<<front->studentID<<" has been allocated to room number "<<top->roomNo<< " in block "<<top->block<<"."<<endl;
            Node *newNode= new Node;
            newNode->firstName=front->firstName;
            newNode->lastName =front->lastName;
            newNode->studentID= front->studentID;
            newNode->phoneNumber=front->phoneNumber;
            newNode->roomNo=top->roomNo;
            newNode->block=top->block;

            newNode->next=NULL;

            if(head==NULL) {
                newNode->next=NULL;
                head=newNode;
                tail=newNode;
            }
            else {
                newNode->previous=tail;
                tail->next=newNode;
                tail=newNode;
            }

            top=top->next;
            free(front);
            front=NULL;
            rear=NULL;
        }
    }
}

void viewAssignedRooms() {
    if(head==NULL) {
        cout<<"There are no rooms assigned\n";
    }
    else {
        Node *temp1=head;
        cout<<"RoomNo Block Student ID\tName\t\tPhone No\n";
        while(temp1!=NULL) {
            cout<<temp1->roomNo<<"\t"<<temp1->block<<"\t"<<temp1->studentID<<"\t"<<temp1->firstName<<" "<<temp1->lastName<<"\t"<<temp1->phoneNumber<<"\n";
            temp1=temp1->next;
        }
    }
}

void checkIn() {
    string key;
    int sure;
    cout<<"Ennter the student Id of the student that has checked in: ";
    cin>>key;
    if(head==NULL) {
        cout<<"Room Assignment list is empty";
    }
    else
    {
        Node *temp1=head;
        while(temp1->studentID!=key) {
            if(temp1->next==NULL) {
                cout<<"Record not found\n!";
                break;
            }
            temp1=temp1->next;
        }


        if(temp1->studentID==key) {
            cout<<temp1->roomNo<<"\t"<<temp1->block<<"\t"<<temp1->studentID<<"\t"<<temp1->firstName<<" " <<temp1->lastName<<"\t"<<temp1->phoneNumber<<"\n";
            cout<<"Are you sure this student has checked in? \n1. Yes 2. No\n";
            cin>>sure;
            if(sure==1) {
                if(head->next==NULL) {
                    Room *newRoom= new Room;
                    newRoom->roomNo=temp1->roomNo;
                    newRoom->block=temp1->block;
                    newRoom->studentID=temp1->studentID;
                    newRoom->next=NULL;
                    if(head1==NULL) {
                        newRoom->next=NULL;
                        head1=newRoom;
                        tail1=newRoom;
                    }
                    else {
                        newRoom->previous=tail1;
                        tail1->next=newRoom;
                        tail1=newRoom;
                    }
                    head=NULL;
                    tail=NULL;
                }
                else {
                    if(temp1==head) {
                        Room *newRoom= new Room;
                        newRoom->roomNo=temp1->roomNo;
                        newRoom->block=temp1->block;
                        newRoom->studentID=temp1->studentID;
                        newRoom->next=NULL;
                        if(head1==NULL) {
                            newRoom->next=NULL;
                            head1=newRoom;
                            tail1=newRoom;
                        }
                        else {
                            newRoom->previous=tail1;
                            tail1->next=newRoom;
                            tail1=newRoom;
                        }
                        head=head->next;
                        (temp1->next)->previous=NULL;
                    }
                    else if(temp1==tail) {
                        Room *newRoom= new Room;
                        newRoom->roomNo=temp1->roomNo;
                        newRoom->block=temp1->block;
                        newRoom->studentID=temp1->studentID;
                        newRoom->next=NULL;
                        if(head1==NULL) {
                            newRoom->next=NULL;
                            head1=newRoom;
                            tail1=newRoom;
                        }
                        else {
                            newRoom->previous=tail1;
                            tail1->next=newRoom;
                            tail1=newRoom;
                        }
                        tail=tail->previous;
                        (temp1->previous)->next=NULL;
                    }
                    else {
                        Room *newRoom= new Room;
                        newRoom->roomNo=temp1->roomNo;
                        newRoom->block=temp1->block;
                        newRoom->studentID=temp1->studentID;
                        newRoom->next=NULL;
                        if(head1==NULL) {
                            newRoom->next=NULL;
                            head1=newRoom;
                            tail1=newRoom;
                        }
                        else {
                            newRoom->previous=tail1;
                            tail1->next=newRoom;
                            tail1=newRoom;
                        }
                        (temp1->previous)->next=temp1->next;
                        (temp1->next)->previous=temp1->previous;
                    }
                }
            }
            else {
                cout<<"Entry has not been deleted";
            }
            cout<<" Student: "<<temp1->firstName<<" "<<temp1->lastName<<" [ "<<temp1->studentID<<" ] has received key for Room "<<temp1->roomNo<<" in Block "<<temp1->block<<" .\n";
        }
    }
}

void  viewCheckedIn() {
    if(head1==NULL) {
        cout<<"There are no rooms assigned\n";
    }
    else {
        Room *temp2=head1;
        cout<<"RoomNo\tBlock\tStudent ID\n";
        while(temp2!=NULL) {
            cout<<temp2->roomNo<<"\t"<<temp2->block<<"\t"<<temp2->studentID<<"\n";
            temp2=temp2->next;
        }
    }
}

void checkAssigment(){
    int hasRoom;
    cout<<"Have you requested for a room in JIIT Hostel Management System ? \n";
    cout<< "1. Yes       2. No\n";
    cin>>hasRoom;
    if(hasRoom==1) {
        string key;
        cout<<"Enter your student ID: ";
        cin>>key;
        if(head==NULL) {
            cout<<"You have not been assigned a room yet";
        }
        else {
            Node *temp1=head;
            while(temp1->studentID!=key) {
                if(temp1->next==NULL) {
                    cout<<"You have not been assigned a room yet";
                    break;
                }
                temp1=temp1->next;
            }
            if(temp1->studentID==key) {
                cout<<"Dear Student: "<<temp1->firstName<<" "<<temp1->lastName<<"\n";
                cout<<"You have been allocated to Room number: "<< temp1->roomNo <<"  in Block: "<< temp1->block<<". \n";
                cout<<"Please come to the "<<temp1->block<<" the roomitory office to take your keys, and ID within 2 business days\n";
                cout<<endl<<endl;
                cout<<"Please note that you are required to bring your student ID, national ID, course registration slip, clearance letters(if you've had room rooms before), and letter from your sub-city (if you are an Addis Ababa resident) to receive your room\n"<<endl;
                cout << "\t........................................................................................................" << endl << endl;
                cout << "\t                           Thank you for using JIIT Hostel management system                            " << endl << endl;
                cout << "\t........................................................................................................" << endl << endl;
            }
        }
    }

    else if (hasRoom==2) {
        cout<<"You are supposed to first request for a room in order to check your assignment. Please request and try again later\n";
    }

    else {
        cout<<"Invalid choice.\n";
    }
}
