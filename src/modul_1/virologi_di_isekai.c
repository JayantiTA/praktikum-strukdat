#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/* Struktur Node */

typedef struct snode_t {
    int data;
    struct snode_t *next;
} SListNode;

/* Struktur ADT SinglyList */

typedef struct slist_t {
    unsigned _size;
    SListNode *_head;
} SinglyList;

/* DAFTAR FUNGSI YANG TERSEDIA */

void slist_init(SinglyList *list);
bool slist_isEmpty(SinglyList *list);
void slist_pushFront(SinglyList *list, int value);
void slist_popFront(SinglyList *list);
void slist_pushBack(SinglyList *list, int value);
void slist_popBack(SinglyList *list);
void slist_insertAt(SinglyList *list, int index, int value);
void slist_removeAt(SinglyList *list, int index);
void slist_remove(SinglyList *list, int value);
int  slist_front(SinglyList *list);
int  slist_back(SinglyList *list);
int  slist_getAt(SinglyList *list, int index);

/* Function definition below */

void slist_init(SinglyList *list) 
{
    list->_head = NULL;
    list->_size = 0;
}

bool slist_isEmpty(SinglyList *list) {
    return (list->_head == NULL);
}

void slist_pushFront(SinglyList *list, int value) 
{
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        list->_size++;
        newNode->data = value;

        if (slist_isEmpty(list)) newNode->next = NULL;
        else newNode->next = list->_head;
        list->_head = newNode;
    }
}

void slist_popFront(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        list->_head = list->_head->next;
        free(temp);
        list->_size--;
    }
}

void slist_pushBack(SinglyList *list, int value)
{
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        list->_size++;
        newNode->data = value;
        newNode->next = NULL;
        
        if (slist_isEmpty(list)) 
            list->_head = newNode;
        else {
            SListNode *temp = list->_head;
            while (temp->next != NULL) 
                temp = temp->next;
            temp->next = newNode;
        }
    }
}

void slist_popBack(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        SListNode *nextNode = list->_head->next;
        SListNode *currNode = list->_head;

        if (currNode->next == NULL) {
            free(currNode);
            list->_head = NULL;
            return;
        }

        while (nextNode->next != NULL) {
            currNode = nextNode;
            nextNode = nextNode->next;
        }
        currNode->next = NULL;
        free(nextNode);
        list->_size--;
    }
}

void slist_insertAt(SinglyList *list, int index, int value)
{
    /* Kasus apabila posisinya melebihi batas */
    if (slist_isEmpty(list) || index >= list->_size) {
        slist_pushBack(list, value);
        return;    
    }
    else if (index == 0 || index < 0) {
        slist_pushFront(list, value);
        return;
    }
    
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        SListNode *temp = list->_head;
        int _i = 0;
        while (temp->next != NULL && _i < index-1) {
            temp = temp->next;
            _i++;
        }
        newNode->data = value;
        newNode->next = temp->next;
        temp->next = newNode;
        list->_size++;
    }
}

void slist_removeAt(SinglyList *list, int index)
{
    if (!slist_isEmpty(list)) {
        
        /* Kasus apabila posisinya melebihi batas */
        if (index >= list->_size) {
            slist_popBack(list);
            return;    
        }
        else if (index == 0 || index < 0) {
            slist_popFront(list);
            return;
        }
        
        SListNode *temp = list->_head;
        int _i = 0;
        while (temp->next != NULL && _i < index-1) {
            temp = temp->next;
            _i++;
        }
        SListNode *nextTo = temp->next->next;
        free(temp->next);
        temp->next = nextTo;
        list->_size--;
    }
}

void slist_remove(SinglyList *list, int value)
{
    if (!slist_isEmpty(list)) {
        SListNode *temp, *prev;
        temp = list->_head;

        if (temp->data == value) {
            slist_popFront(list);
            return;
        }
        while (temp != NULL && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) return;
        prev->next = temp->next;
        free(temp);
        list->_size--;
    }
}

int slist_front(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        return list->_head->data;
    }
    return 0;
}

int slist_back(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        while (temp->next != NULL) 
            temp = temp->next;
        return temp->data;
    }
    return 0;
}

int slist_getAt(SinglyList *list, int index)
{
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        int _i = 0;
        while (temp->next != NULL && _i < index) {
            temp = temp->next;
            _i++;
        }
        return temp->data;
    }
    return 0;
}

int search_min(int time[], int index)
{
    int min = time[0], i;
    for(i = 1; i < index; i++)
    {  
        if(time [i] <= min)
            min = time [i];
    }
    return min;
}

int search_max(int time[], int index)
{
    int max = time[0], i;
    for(i = 1; i < index; i++)
    {  
        if(time [i] >= max)
            max = time[i];
    }
    return max;
}

int main(int argc, char const *argv[])
{
    // Buat objek SinglyList
    SinglyList myList;

    // PENTING! Jangan lupa diinisialisasi
    slist_init(&myList);
    
    int N, M, i, j, len;

    scanf("%d", &N);
    int lab[N];
    for(i = 0; i < N; i++)
        scanf("%d", &lab[i]);

    scanf("%d", &M);
    int basa[M];
    char rna[M][200];
    for(i = 0; i < M; i++)
    {
        scanf("%s", rna[i]);
    }

    for(i = 0; i < M; i++)
    {
        basa[i] = 0;
        len = strlen(rna[i]);
        for(j = 0; j < len; j++)
        {
            if(myList._head == NULL || (rna[i][j] == 'X' && slist_back(&myList) != 'Y')
                                    || (rna[i][j] == 'Y' && slist_back(&myList) != 'X')
                                    || (rna[i][j] == 'A' && slist_back(&myList) != 'B')
                                    || (rna[i][j] == 'B' && slist_back(&myList) != 'A'))
                slist_pushBack(&myList, rna[i][j]);
            else if((rna[i][j] == 'X' && slist_back(&myList) == 'Y') || 
                    (rna[i][j] == 'Y' && slist_back(&myList) == 'X') ||
                    (rna[i][j] == 'A' && slist_back(&myList) == 'B') ||
                    (rna[i][j] == 'B' && slist_back(&myList) == 'A'))
            {
                slist_pushBack(&myList, rna[i][j]);
                slist_popBack(&myList);; slist_popBack(&myList);; 
                basa[i]++;
            }
        }
        while(myList._head != NULL)
            slist_popBack(&myList);;
    }
    
    int k = 0, low = 0, time[N], waktu[N];
    
    for(j = 0; j < N; j++)
        time[j] = 0;
    
    for(i = 0; i < M; i++)
    {
        if(time[k] == 0)
        {
            time[k] += basa[i] * lab[k];
            k++;
        }
        else if(k >= N)
        {
            k = 0;
            for(j = 0; j < N; j++)
            {
                waktu[j] = time[k] + basa[i] * lab[k];
                k++;
            }
            low = search_min(waktu, N);
            time[k] += low;
        }
    }

    printf("%d", search_max(time, N));

    puts("");
    return 0;
}