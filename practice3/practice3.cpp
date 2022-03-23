#include <iostream>

const int QUEUE_SIZE{ 10 };

enum Command
{
    ENQUEUE = 1,
    DEQUEUE = 2,
    EXIT = 3
};

struct Queue
{
    int container[QUEUE_SIZE]{};
    int head{};
    int tail{};
};

void PrintInfo()
{
    std::cout << "<QUEUE>" << std::endl;
    std::cout << "[1] enqueue" << std::endl;
    std::cout << "[2] dequeue" << std::endl;
    std::cout << "[3] exit" << std::endl;
    std::cout << "-------------------" << std::endl;
}

void printQueue(Queue& Queue)
{
    std::cout << "---- Queue ----" << std::endl;
    if (Queue.head == Queue.tail)
    {
        std::cout << "비어있음!!" << std::endl;
    }

    int i = Queue.head;
    while (i != Queue.tail)
    {
        i = (i + 1) % QUEUE_SIZE;
        std::cout << Queue.container[i] << " ";
    }
    std::cout << std::endl << "-------" << std::endl;
}

void Enqueue(Queue& Queue, int value)
{
    if ((Queue.tail + 1) % QUEUE_SIZE == Queue.head)
    {
        std::cout << "Queue is FULL" << std::endl;
        return;
    }
    Queue.tail = (Queue.tail + 1) % QUEUE_SIZE;
    Queue.container[Queue.tail] = value;
}

void Dequeue(Queue& queue)
{
    if ( queue.head == queue.tail)
    {
        std::cout << "Queue is EMPTY" << std::endl;
    }
    queue.head = (queue.head + 1) % QUEUE_SIZE;
    std::cout << queue.container[queue.head]<< " is dequeued!!" << std::endl;
}

void ProcessUserInput(Queue& queue)
{
    int command{ -1 };
    bool isExit{ false };
    while (true)
    {
        printQueue(queue);

        std::cout << std::endl << "> ";
        std::cin >> command;
        switch (command)
        {
        case ENQUEUE:
        {
            int value;
            std::cout << " value >>";
            std::cin >> value;
            Enqueue(queue, value);
            break;
        }
        case DEQUEUE:
            Dequeue(queue);
            break;
        case EXIT:
            isExit = true;
            break;
        default:
            std::cout << "Innalid command!!" << std::endl;
            break;
        }
    }
}

int main()
{
    Queue myQueue;
    PrintInfo();
    ProcessUserInput(myQueue);

}