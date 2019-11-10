#ifndef queue_impl
# define queue_impl
typedef struct Queue *queue;
struct Queue* createQueue(int capacity);
int isEmpty(struct Queue *queue);
int isFull(queue);
void enqueue(struct Queue *queue,int item);
int dequeue(struct Queue *queue);
int front(struct Queue *queue);
int rear(struct Queue *queue);
void display(struct Queue *queue);
#endif
