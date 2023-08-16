#include <stdio.h>
#include <malloc.h>
 struct node{
    int data;
    struct node * next;
};
struct Graph {
  int vertNum;
  struct node** adjLists;
};

struct node* createNode(int v) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->data = v;
  newNode->next = NULL;
  return newNode;
}

struct Graph* createAGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->vertNum = vertices;
  graph->adjLists = malloc(vertices * sizeof(struct node*));
  int i;
  for (i = 0; i < vertices; i++)
    graph->adjLists[i] = NULL;
  return graph;
}

void addEdge(struct Graph* graph, int s, int d) {
  struct node* newNode = createNode(d);
  newNode->next = graph->adjLists[s];
  graph->adjLists[s] = newNode;
  newNode = createNode(s);
  newNode->next = graph->adjLists[d];
  graph->adjLists[d] = newNode;
}

void printGraph(struct Graph* graph) {
  int v;
  for (v = 0; v < graph->vertNum; v++) {
    struct node* temp = graph->adjLists[v];
    printf("\n Vertex %d\n: ", v);
    while (temp) {
      printf("%d, ", temp->data);
      temp = temp->next;
    }
    printf("\n");
  }
}
struct Graph* creategraph(){
    struct Graph* graph = createAGraph(10);
    addEdge(graph,6,7);
    addEdge(graph,5,6);
    addEdge(graph,1,5);
    addEdge(graph,1,9);
    addEdge(graph,3,8);
    addEdge(graph,2,3);
    addEdge(graph,2,4);
    addEdge(graph,0,7);
    addEdge(graph,0,1);
    addEdge(graph,0,2);

    return graph;
}


struct Qnode {
    int data;
    struct Qnode* next;
};
struct Queue {
    struct Qnode* front;
    struct Qnode* rear;
};
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(struct Queue* queue, int data) {
    struct Qnode* newNode = (struct Qnode*)malloc(sizeof(struct Qnode));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }

    queue->rear->next = newNode;
    queue->rear = newNode;
}

int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        return -1; // Empty queue
    }

    int data = queue->front->data;
    struct Qnode* temp = queue->front;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return data;
}

struct stack{
  struct Qnode* head;
};
struct stack* createstack(){
  struct stack* stack = (struct stack*)malloc(sizeof(struct stack));
    stack->head = NULL;
    return stack;
}
void push (struct stack* stack, int n){
  struct Qnode* newNode = (struct Qnode*)malloc(sizeof(struct Qnode));
  newNode->next =stack->head;
  newNode->data = n;
  stack->head = newNode;
}
int pop (struct stack* stack){
  if (stack->head == NULL) {
        return -1; // Empty
    }
  int data = stack->head->data;
  stack->head = stack->head->next;
  return data;
}

void bfs(struct Graph* graph){
  struct Queue * queue = createQueue();
  int visited[graph->vertNum] ;
  enqueue(queue,0);
  while(queue->front){
    int n = dequeue(queue);
    if (visited[n]!=1){
      printf("%d ",n);
      visited[n]=1;
      struct node * visiting = graph->adjLists[n];
      while (visiting){
        int adj =visiting->data;
        if(visited[adj]!=1){
          enqueue(queue,adj);
        }
        visiting = visiting -> next;
      }
    }
  }
}
void dfs(struct Graph* graph){
  struct stack * stk = createstack();
  int visited[graph->vertNum] ;
  push(stk,0);
  while(stk->head){
    int n = pop(stk);
    if(visited[n]!=1){
      printf("%d ",n);
      visited[n]=1;
      struct node * visiting = graph->adjLists[n];
      while (visiting){
        int adj =visiting->data;
        if(visited[adj]!=1){
          push(stk,adj);
        }
        visiting = visiting -> next;
      }
    }
  }
}
int main() {
    // int n,m,x,y;
    // printf("enter the number of matrices");
    // scanf("%d",&n);
    // printf("enter the number of edges");
    // scanf("%d",&m);
    //
    // struct Graph* graph = createAGraph(n);
    // for (int i = 0; i < m; i++){
    //     printf("enter the the nodes of edges");
    //     scanf("%d",&x);
    //     scanf("%d",&y);
    //     addEdge(graph,x,y);
    // }
    struct Graph* graph = creategraph();
    // printGraph(graph);
    printf("Bfs is : ");
    bfs(graph);
    printf("\n");
    printf("Dfs is : ");
    dfs(graph);
    printf("\n");
    return 0;
}

