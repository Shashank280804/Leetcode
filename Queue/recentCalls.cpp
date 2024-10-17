/*
1. Initialize an empty queue `q` to store the timestamps of pings.
2. Define the constructor `RecentCounter` that initializes `q`.
3. Implement the `ping(int t)` method:
   a. Add the current timestamp `t` to the queue `q`.
   b. Calculate the threshold time: `temp = t - 3000`.
   c. While the front of the queue `q` is less than `temp`, remove the front element (i.e., outdated pings).
   d. Return the size of the queue, which represents the number of pings in the last 3000 milliseconds.

*/

#include <queue> // Include the queue header for using the queue data structure
using namespace std;
class RecentCounter {
public:
    queue<int> q; // Declare a queue to store the timestamps of pings

    // Constructor to initialize the RecentCounter
    RecentCounter() {
        // The queue is automatically initialized as empty
    }
    
    // Method to process a ping at time t
    int ping(int t) {
        // Calculate the threshold time for the last 3000 milliseconds
        int temp = t - 3000;

        // Add the current timestamp t to the queue
        q.push(t);

        // Remove timestamps from the queue that are older than 3000 ms
        while (!q.empty() && q.front() < temp) {
            q.pop(); // Remove the front element if it's older than temp
        }

        // Return the number of pings that are within the last 3000 ms
        return q.size();
    }
};

// Usage
// RecentCounter* obj = new RecentCounter();
// int param_1 = obj->ping(t);


/*
1. **Initialization:**
   - RecentCounter is instantiated: RecentCounter* obj = new RecentCounter();
   - Queue `q` is empty.

2. **First ping (ping(1)):**
   - t = 1
   - Add 1 to `q`: q = [1]
   - Calculate temp: temp = 1 - 3000 = -2999
   - Since 1 >= -2999, no elements are removed.
   - Return q.size() = 1.

3. **Second ping (ping(100)):**
   - t = 100
   - Add 100 to `q`: q = [1, 100]
   - Calculate temp: temp = 100 - 3000 = -2900
   - Since 1 >= -2900, no elements are removed.
   - Return q.size() = 2.

4. **Third ping (ping(3001)):**
   - t = 3001
   - Add 3001 to `q`: q = [1, 100, 3001]
   - Calculate temp: temp = 3001 - 3000 = 1
   - Remove 1 from `q`: q = [100, 3001]
   - Since 100 >= 1, no more elements are removed.
   - Return q.size() = 3.

5. **Fourth ping (ping(3002)):**
   - t = 3002
   - Add 3002 to `q`: q = [100, 3001, 3002]
   - Calculate temp: temp = 3002 - 3000 = 2
   - Remove 100 from `q`: q = [3001, 3002]
   - Since 3001 >= 2, no more elements are removed.
   - Return q.size() = 3.

*/