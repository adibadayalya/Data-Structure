#include <stdio.h>
#include <time.h>
#include <limits.h>
#define N 5

typedef struct CIRQUEUE
{
  int traffTime[N];
  int head,tail;
  int size;
} CQ;

void enQueue(CQ *ptrQ, int val)
{
  if(ptrQ->size == N)
  printf("Queue is full!!\n");
  else
  {
    if(ptrQ->head == -1)
    ptrQ->head = 0;
    ptrQ->tail = (ptrQ->tail + 1) % N;
    ptrQ->traffTime[ptrQ->tail] = val;
    ptrQ->size++;
  }
}

int traffic(CQ *ptrQ)
{
  for(int i = 0; i < ptrQ->size; i++)
    if(ptrQ->traffTime[i] != 0)
      return 1;
  return 0;
}

int getMax(CQ *ptrQ)
{
  int max = -1;
  for(int i = 0; i < ptrQ->size; i++)
    max = (ptrQ->traffTime[i] > max)? ptrQ->traffTime[i] : max;
  return max;
}

int getMin(CQ *ptrQ)
{
  int min = INT_MAX;
  for(int i = 0; i < ptrQ->size; i++)
    min = (ptrQ->traffTime[i] < min)? ptrQ->traffTime[i] : min;
  return min;
}

void displayQueue(CQ *ptrQ)
{
  for(int i = 0; i < ptrQ->size; i++)
    printf("| R%d Traffic Time = %d seconds |\n", i+1, ptrQ->traffTime[i]);
}

void delay(int seconds)
{
  int milliSeconds=1000*seconds;
  clock_t startTime = clock();
  while (clock()<startTime+milliSeconds);
}

void main()
{
  CQ Q = {.head = -1, .tail = -1, .size = 0};
  int maxPrioIndex, minPrioIndex, maxTraffic, minTraffic;
  srand(time(0));
  for(int i = 0; i < 5; i++)
  enQueue(&Q,rand()%10+10);
  int maxTraffIndex = 0;
  while(traffic(&Q))
  {
    displayQueue(&Q);
    maxTraffic = getMax(&Q);
    minTraffic = getMin(&Q);
    if(maxTraffic == minTraffic)
    minTraffic = 0;
    while(Q.traffTime[maxTraffIndex]!=maxTraffic)
    maxTraffIndex = (maxTraffIndex + 1) % N;
    printf("\n| ROAD %d SIGNAL: GREEN |\n", maxTraffIndex+1);
    printf("| %d secs left |\n", maxTraffic-minTraffic);
    delay(maxTraffic-minTraffic);
    printf("---------------------------------------------------------------\n");
    Q.traffTime[maxTraffIndex] = minTraffic;
    maxTraffIndex = (maxTraffIndex + 1) % N;
  }
  printf("| !!TRAFFIC CLEARED!! |");
}
