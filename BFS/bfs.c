#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int vertex;
    struct Edge * next;
};

// Inserts Node to the Linked List by Head Insertion - O(1)
// Returns address of head which is the newly created node.
struct Edge * AddEdge(struct Edge * currentHead, int newVertex)
{
    struct Edge * newHead
                 = (struct Edge *) malloc(sizeof(struct Edge));

    newHead->vertex = newVertex;
    newHead->next = currentHead;

    return newHead;
}

void BreadthFirstSearch(
                        struct Edge * adjacencyList[],
                        int vertices,
                        int parent[],
                        int level[],
                        int startVertex
                       )
{
    struct Edge * traverse;
    int i, par, lev, flag = 1;
    // 'lev' represents the level to be assigned
    // 'par' represents the parent to be assigned
    // 'flag' used to indicate if graph is exhausted

    lev = 0;
    level[startVertex] = lev;
    // We start at startVertex

    while (flag) {
        flag = 0;
        for (i = 1; i <= vertices; ++i) {
            if (level[i] == lev) {
                flag = 1;
                traverse = adjacencyList[i];
                par = i;

                while (traverse != NULL) {
                    if (level[traverse->vertex] != -1) {
                        traverse = traverse->next;
                        continue;
                    }

                    level[traverse->vertex] = lev + 1;
                    parent[traverse->vertex] = par;
                    traverse = traverse->next;
                }
            }
        }

        ++lev;
    }
}

int main()
{
    int vertices, edges, i, v1, v2;

    printf("Enter the Number of Vertices -\n");
    scanf("%d", &vertices);

    printf("\nEnter the Number of Edges -\n");
    scanf("%d", &edges);

    struct Edge * adjacencyList[vertices + 1];
    // Size is made (vertices + 1) to use the
    // array as 1-indexed, for simplicity

    int parent[vertices + 1];
    // Each element holds the Node value of its parent
    int level[vertices + 1];
    // Each element holds the Level value of that node

    // Must initialize your array
    for (i = 0; i <= vertices; ++i) {
        adjacencyList[i] = NULL;
        parent[i] = 0;
        level[i] = -1;
    }

    for (i = 1; i <= edges; ++i) {
        scanf("%d%d", &v1, &v2);

        // Adding edge v1 --> v2
        adjacencyList[v1] = AddEdge(adjacencyList[v1], v2);

        // Adding edge v2 --> v1
        // Remove this if you want a Directed Graph
        adjacencyList[v2] = AddEdge(adjacencyList[v2], v1);
    }

    // Printing Adjacency List
    printf("\nAdjacency List -\n\n");
    for (i = 1; i <= vertices; ++i) {
        printf("adjacencyList[%d] -> ", i);

        struct Edge * traverse = adjacencyList[i];

        while (traverse != NULL) {
            printf("%d -> ", traverse->vertex);
            traverse = traverse->next;
        }

        printf("NULL\n");
    }

    printf("\nEnter a Start Vertex - ");
    scanf("%d", &v1);

    BreadthFirstSearch(adjacencyList, vertices, parent, level, v1);

    // Printing Level and Parent Arrays
    printf("\nLevel and Parent Arrays -\n");
    for (i = 1; i <= vertices; ++i) {
        printf("Level of Vertex %d is %d, Parent is %d\n",
                                  i, level[i], parent[i]);
    }

    return 0;
}
