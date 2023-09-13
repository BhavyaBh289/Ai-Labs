 
#include <stdio.h>
#include <malloc.h>
 struct node{
    int data;
    int cost;
    struct node * next;
};
struct Graph {
  int vertNum;
  struct node** adjLists;
  int * heurestic ;
};

struct node* createNode(int v,int n) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->data = v;
  newNode->cost = n;
  newNode->next = NULL;
  return newNode;
}

struct Graph* createAGraph(int vertices,int heurestic []) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->vertNum = vertices;
    graph->heurestic = malloc(sizeof(int)*vertices);
    graph->adjLists = malloc(vertices * sizeof(struct node*));
    int i;
    for (i = 0; i < vertices; i++){
        graph->adjLists[i] = NULL;
        graph->heurestic[i] = heurestic[i];
    }
  return graph;
}

void addEdge(struct Graph* graph, int s, int d,int n) {
  struct node* newNode = createNode(d,n);
  newNode->next = graph->adjLists[s];
  graph->adjLists[s] = newNode;
  newNode = createNode(s,n);
  newNode->next = graph->adjLists[d];
  graph->adjLists[d] = newNode;
}


struct anode{
    int data;
    int cost;
    struct anode * prev;
};
struct llnode{
    struct anode * element;
    struct llnode * next;
};
struct llnode * head = NULL;
void insert (struct Graph* graph,struct anode * ele){
    struct llnode * new = malloc(sizeof(struct llnode));
    new->element= ele;
    struct llnode * t = head;
    if(!t){
        head=new;
    }else{
        while(((t->element->cost + graph->heurestic[t->element->data]) < (new->element->cost+ graph->heurestic[new->element->data]))&&(t->next!=NULL)){
            t=t->next;
        }
        new->next =t->next;
        t->next = new;
    }
}
void popsmallest(struct Graph* graph){
    struct node* temp = graph->adjLists[head->element->data];
    while (temp) {
        struct anode * new = malloc(sizeof(struct anode));
        new->cost = head->element->cost +temp->cost;
        new->data = temp->data;
        new->prev = head->element;
        insert(graph,new);
        temp = temp->next;
    }
    head = head->next;

}
void astar(struct Graph* graph,int g ){
    struct anode * new = malloc(sizeof(struct anode));
    new->cost = 0;
    new->data = 0;
    new->prev = NULL;
    insert(graph,new);
    while(head->element->data!=g){
        popsmallest(graph);
    }
    // struct anode * final= head->element;

    struct anode *temp = head->element;
    while(temp){
        printf("%d ",temp->data);
        temp = temp->prev;
    }
}

void printGraph(struct Graph* graph) {
  int v;
  for (v = 0; v < graph->vertNum; v++) {
    struct node* temp = graph->adjLists[v];
    printf("\n Vertex %d with heurestic %d\n: ", v,graph->heurestic[v]);
    while (temp) {
      printf("%d with cost %d, ", temp->data,temp->cost);
      temp = temp->next;
    }
    printf("\n");
  }
}
struct Graph* creategraph(){
   /* int t [5] = {1,1,2,1,2};
    struct Graph* graph = createAGraph(5,t);
    addEdge(graph,0,1,3);
    addEdge(graph,0,3,7);
    addEdge(graph,0,4,8);
    addEdge(graph,1,3,4);
    addEdge(graph,1,2,1);
    addEdge(graph,2,3,2);
    addEdge(graph,3,4,3);
   */
    int t [10] ={10,8,5,7,3,6,5,3,1,0};
    struct Graph* graph = createAGraph(10,t);
    addEdge(graph,0,1,6);
    addEdge(graph,0,5,3);
    addEdge(graph,1,2,3);
    addEdge(graph,1,3,2);
    addEdge(graph,2,3,1);
    addEdge(graph,2,4,5);
    addEdge(graph,3,4,8);
    addEdge(graph,4,8,5);
    addEdge(graph,4,8,5);
    addEdge(graph,5,6,1);
    addEdge(graph,5,7,7);
    addEdge(graph,6,8,3);
    addEdge(graph,7,8,2);
    addEdge(graph,8,9,3);
    return graph;
}
struct Graph* makegraph(){
    int n,m,x,y,z;
    printf("enter the number of matrices");
    scanf("%d",&n);
    printf("enter the number of edges");
    scanf("%d",&m);
    struct Graph* graph = creategraph(n);
    for (int i = 0; i < m; i++){
        printf("enter the nodes of edge");
        scanf("%d",&x);
        scanf("%d",&y);
        printf("enter the cost of edge");
        scanf("%d",&z);

        addEdge(graph,x,y,z);

    }
}

int main() {
    struct Graph* graph = creategraph();
    astar(graph,9);
    return 0;
}

