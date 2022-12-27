using namespace std;
#include "Participants.h"
#include "CircularQueue.h"

int main() {
    // Creating a circular queue with capacity 10
    CircularQueue<Obstacles> obstacle_queue(10);

    // Pushing some obstacles onto the queue
    obstacle_queue.push(Obstacles (3.0, 20.0));
    obstacle_queue.push(Obstacles(2.0, 1.0));
    obstacle_queue.push(Obstacles(30.0, 50.0));

    // Creating some participants
    Man man("John");
    Cat cat("Fluffy");
    Robot robot("Robo");

    // Vector to store the participants that are still in the race
    std::vector<Participant*> participants = { &man, &cat, &robot };

    // Loop until only one participant is left
    while (participants.size() > 1) {
        // Taking turns overcoming obstacles
        for (auto& participant : participants) {
            Obstacles obstacle = obstacle_queue.front();
            if (obstacle.getHeight() == 0.0) {
                participant->run();
            } else {
                participant->jump();
            }
            if (!participant->overcomeObstacle(obstacle)) {
                // Removing participant from the race if they can't overcome the obstacle
                participants.erase(std::remove(participants.begin(), participants.end(), participant), participants.end());
            }
            obstacle_queue.pop();
        }
    }

    // The last participant in the vector is the winner
    std::cout << "The winner is: " << participants[0]->getName() << std::endl;

    return 0;
}
