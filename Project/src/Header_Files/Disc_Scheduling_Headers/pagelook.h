// Initialising the header files
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


// Main Function
void dopagelook()
{
    // Taking input
    int size;
    cout << "Enter the number of requests: ";
    cin >> size;
    int arr[size];
    cout << "Enter the requests: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int head;
    cout << "Enter the head position: ";
    cin >> head;
    string direction;
    cout << "Enter the direction('left' or 'right'): ";
    cin >> direction;
    int disk_size;
    cout << "Enter the disk size: ";
    cin >> disk_size;


    // Appending values to the array
    int seek_count = 0;
    int distance, cur_track;
    vector<int> left, right;
    vector<int> seek_sequence;

    // appending values which are
    // currently at left and right
    // direction from the head.
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < head)
            left.push_back(arr[i]);
        if (arr[i] > head)
            right.push_back(arr[i]);
    }

    // sorting left and right vectors
    // for servicing tracks in the
    // correct sequence.
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    // run the while loop two times.
    // one by one scanning right
    // and left side of the head
    int run = 2;
    while (run--)
    {
        if (direction == "left")
        {
            for (int i = left.size() - 1; i >= 0; i--)
            {
                cur_track = left[i];

                // appending current track to seek sequence
                seek_sequence.push_back(cur_track);

                // calculate absolute distance
                distance = abs(cur_track - head);

                // increase the total count
                seek_count += distance;

                // accessed track is now the new head
                head = cur_track;
            }
            // reversing the direction
            direction = "right";
        }
        else if (direction == "right")
        {
            for (int i = 0; i < right.size(); i++)
            {
                cur_track = right[i];
                // appending current track to seek sequence
                seek_sequence.push_back(cur_track);

                // calculate absolute distance
                distance = abs(cur_track - head);

                // increase the total count
                seek_count += distance;

                // accessed track is now new head
                head = cur_track;
            }
            // reversing the direction
            direction = "left";
        }
    }

    // Display the total number of seek operations
    cout << "Initial position of head: "<< head << endl;
    cout << "Total number of seek operations = "<< seek_count << endl;
    cout << "Seek Sequence is" << endl;
    for (int i = 0; i < seek_sequence.size(); i++)
    {
        cout << seek_sequence[i] << endl;
    }
}
