// Initialising the header files
#include<iostream>
using namespace std;

// Main Function
int dopagefcfs(){
    int n;
    cout<<"Enter the number of requests: ";
    cin>>n;
    int req[n];
    cout<<"Enter the requests: ";
    for(int i=0;i<n;i++){
        cin>>req[i];
    }
    int head;
    cout<<"Enter the head position: ";
    cin>>head;

    // Calculating the total head movement
    int total_head_movement = 0;
    for(int i=0;i<n;i++){
        total_head_movement += abs(head-req[i]);
        head = req[i];
    }

    // Displaying the total head movement and average head movement
    cout<<"Total head movement: "<<total_head_movement<<endl;
    cout<<"Average head movement: "<<(float)total_head_movement/n<<endl;
}