#include "QueueFactory.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

void simulation1() {
    cout << "\n========== SIMULATION 1: TICKET COUNTER ==========" << endl;
    cout << "Using: Array-Based Queue (fixed capacity of 10)" << endl;
    cout << "Scenario: Customers arrive randomly. Line can hold max 10 customers." << endl;
    cout << "If line is full, new customers cannot join." << endl;
    cout << "Generating 100 random numbers between -1 and 1...\n" << endl;

    QueueFactory<int> factory;
    Queue<int>* ticketQueue = factory.GetQueue(10);

    int customersServed = 0;
    int customersTowardaway = 0;
    int customersArrived = 0;

    for (int i = 0; i < 100; i++) {
        int randomNum = (rand() % 3) - 1;

        if (randomNum < 0) {
            if (!ticketQueue->isEmpty()) {
                ticketQueue->dequeue();
                customersServed++;
                cout << "Event " << (i + 1) << ": Customer served. Queue size: " << ticketQueue->getLength() << endl;
            }
        } else {
            try {
                ticketQueue->enqueue(i);
                customersArrived++;
                cout << "Event " << (i + 1) << ": New customer arrives. Queue size: " << ticketQueue->getLength() << endl;
            } catch (string& e) {
                customersTowardaway++;
                cout << "Event " << (i + 1) << ": New customer turned away - " << e << endl;
            }
        }
    }

    cout << "\n--- Simulation 1 Results ---" << endl;
    cout << "Customers Served: " << customersServed << endl;
    cout << "Customers Arrived: " << customersArrived << endl;
    cout << "Custoemrs Turned Away: " << customersTowardaway << endl;
    cout << "Final Queue Size: " << ticketQueue->getLength() << endl;

    delete ticketQueue;
}

void simulation2() {
   cout << "\n========== SIMULATION 2: BANK SERVICE LINE ==========" << endl;
    cout << "Using: Linked-List Based Queue (dynamic capacity)" << endl;
    cout << "Scenario: Customers arrive randomly. Line can grow as needed." << endl;
    cout << "No fixed maximum size for the waiting line." << endl;
    cout << "Generating 100 random numbers between -1 and 2...\n" << endl;

    QueueFactory<int> factory;
    Queue<int>* bankQueue = factory.GetQueue();


    int customersServed = 0;
    int customersArrived = 0;
    int maxQueueLength = 0;

    for (int i = 0; i < 100; i++) {
        int randomNum = (rand() % 4) - 1;

        if (randomNum < 0) {
            if (!bankQueue->isEmpty()) {
                bankQueue->dequeue();
                customersServed++;
                cout << "Event " << (i + 1) << ": Customer departs. Queue size: " << bankQueue->getLength() << endl;
            }
        } else {
            bankQueue->enqueue(i);
            customersArrived++;
            if (bankQueue->getLength() > maxQueueLength) {
                maxQueueLength = bankQueue->getLength();
            }
            cout << "Event " << (i + 1) << ": New customer arrives. Queue size: " << bankQueue->getLength() << endl;
        }
    }
    cout << "\n--- Simulation 2 Results ---" << endl;
    cout << "Customers Served: " << customersServed << endl;
    cout << "Customers Arrived: " << customersArrived << endl;
    cout << "Maximum Queue Length Reached: " << maxQueueLength << endl;
    cout << "Final Queue Size: " << bankQueue->getLength() << endl;

    delete bankQueue;
}

int main() {
    srand(time(0));

    simulation1();
    simulation2();
    cout << "\n========== ALL SIMULATIONS COMPLETE ==========" << endl;
    return 0;
}