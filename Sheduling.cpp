#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
//THERE MIGHT BE SOME SPELLING MISTAKE IN THE COMMENTS just try to understand the approach to this prob

//This was my solution for this problem just considering that all the strings are actually int i.e. 
//12:30 -> 1230 or 16:50 -> 1650
//This conversion can be done easily by writing a func the can convert "hh:mm" to hhmm
//The only reason for this conversion is just that we will be able to do comparison and basic substraction faster
//This is basically a greedy approach towards the problem which takes approx. O(2n) ~ O(n)

//A[][2] is the array of start and end time of meeting for person A and s_A[] is the array that stores the start and end time
//of meeting throughout the day of person A
//and same for B[][2] and s_B[] for person B
//a_l and b_l is basically to keep track of the current time of person A and person B
//a_i and b_i are the index of the meeting that they ar currently in
//time is the meeting duration between person A and B 
//One thing to notice that {s_A[1],s_A[1]} is append at the end of A[][2] the same thing is done for B[][2]
//notice that this is not invalid as it was already given that they will be in sorted order and then end time of last meeting
//will not exceed s_A[1] and s_B[1] for person A and B respectively
//this is just to make sure that a_l and b_l dosen't exceed s_A[1] and s_B[1] respectively
//in case someone dosen't understand the code just try to do dryrun on some value using this algorithm

int main(){
	int A[][2] = {{730,840},{900,1030},{1400,1600},{1630,1930},{2000,2000}};
	int s_A[] = {700,2000};
	int B[][2] = {{600,700},{800,840},{930,1030},{1600,1700},{2100,2100}};
	int s_B[] = {600,2100};
	int time = 20;
	int a_l = s_A[0], b_l = s_B[0];
	int a_i = 0, b_i = 0;
	vector<pair<int,int>> Times;
	while(a_l <= s_A[1] && b_l <= s_B[1]){
		while(a_l < b_l){
			if(A[a_i][0]<=b_l)a_l = A[a_i][1];
			else break;
			a_i += 1;
		}
		while(b_l < a_l){
			if(B[b_i][0]<=a_l)b_l = B[b_i][1];
			else break;
			b_i += 1;
		}
		//the above two while loops ar used to adjust the value of a_l and b_l
		if(a_l>=s_A[1] || b_l>=s_B[1])break;

		//if statement is used for exception here when the time of a_l or b_l
		// becomes s_A[1] or s_B[1] reaches respectively 

		int start = max(a_l,b_l);

		//the start is used to get the max of current time of A and B, and it works because we know that 
		//both the times a_l and b_l are at the end of some meeting

		int end = min(A[a_i][0],B[b_i][0]);

		//end here is used to keep the record of the min time of start of next meeting of A and B

		if(end-start>=time){

			//checks if the time gap is greater then the time variable
			//if so append it to the Times vector<pair<int,int>>

			Times.push_back({start,end});
		}

		if(A[a_i][1]<A[b_i][1])a_l = A[a_i++][1];
		else b_l = B[b_i++][1];

		//this condition is used to change the value a_l or b_l to the nearest meeting of A or B respectively 

	}
	if(Times.size()==0){
		cout << "No available time";
		return 0;
	}
	for(auto &x: Times){
		cout << "["<< x.first << "," << x.second << "]" << " ";
	}

	//Now just print the solution set if it's empty then there is no available time then Times.size()==0
	return 0;
}