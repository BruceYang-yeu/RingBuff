#include <stdio.h>
#include <string.h>
#include "ring_que.h"

unsigned int
ringq_init (RINGQ * p_ringq)
{
  p_ringq->size = RINGQ_MAX;

  p_ringq->head = 0;
  p_ringq->tail = 0;

  return p_ringq->size;
}

unsigned int
ringq_free (RINGQ * p_ringq)
{
  return 0;
}

unsigned int
ringq_push (RINGQ * p_ringq, void *data, unsigned int dataLen)
{ 
  unsigned int i = 0;
  
  if (ringq_is_full (p_ringq))
    {
      perror ("ringq is full\n");
      return 0;
    }

  memcpy(p_ringq->space[p_ringq->tail].mData, (unsigned char*)data, dataLen);
  p_ringq->space[p_ringq->tail].mDataLen = dataLen;
   for(i = 0; i < dataLen; i++)
	printf("p_ringq->space[%u].mData[%u]: %x\n", p_ringq->tail, i, p_ringq->space[p_ringq->tail].mData[i]);

  p_ringq->tail = (p_ringq->tail + 1) % p_ringq->size;
  //p_ringq->tail = (p_ringq->tail + 1) & (p_ringq->size - 1);
 
  return p_ringq->tail;
}


unsigned int
ringq_poll (RINGQ * p_ringq, DataNode *data)
{
  unsigned int i = 0, j = 0;;

  if (ringq_is_empty (p_ringq))
    {
      printf ("ringq is empty\n");
      return 0;
    }
  memcpy(data->mData, p_ringq->space[p_ringq->head].mData, p_ringq->space[p_ringq->head].mDataLen);
  for(i = 0; i < (p_ringq->space[p_ringq->head]).mDataLen; i++)
	printf("poll p_ringq->space[%u].mData[%u]: %x\n", p_ringq->head, i, p_ringq->space[p_ringq->head].mData[i]);


  p_ringq->head = (p_ringq->head + 1) % p_ringq->size;
  //p_ringq->head = (p_ringq->head + 1) & (p_ringq->size - 1);

  return p_ringq->head;
}
