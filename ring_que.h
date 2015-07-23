#ifndef __RINGQ_H__
#define __RINGQ_H__

#ifdef __cplusplus
extern "C"
{
#endif

#define RINGQ_MAX 4
#define DATALEN_MAX  5

typedef struct DataNode
{
    unsigned int   mDataLen;
    unsigned char  mData[DATALEN_MAX];
}DataNode;		
  
typedef struct RingQueue
{
      unsigned int head;	/*Head of the queue direction */
      unsigned int tail;	/*Tail, into the queue direction */
      unsigned int size;	/*The total size of the queue */
      DataNode space[RINGQ_MAX];	/* Queue space */
} RINGQ;

  /*
   *   Queue is empty: head == tail .
   *   Queue full: (tail+1)%MAX == head  
   *   init: head = tail = 0;   
   **/

  extern unsigned int ringq_init (RINGQ * p_ringq);

  extern unsigned int ringq_free (RINGQ * p_ringq);

  extern unsigned int ringq_push (RINGQ * p_ringq, void *data, unsigned int dataLen);
  extern unsigned int ringq_poll (RINGQ * p_ringq, DataNode *data);

#define ringq_is_empty(q) (q->head == q->tail)

#define ringq_is_full(q) (((q->tail+1)%q->size) == q->head )

#ifdef __cplusplus
}
#endif

#endif				/* __QUEUE_H__ */
