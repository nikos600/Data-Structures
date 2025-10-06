    typedef struct queue *qpointnode;
    typedef struct headtail *queueht;  
    typedef int Pqitem;

    queueht Queueinit();
    qpointnode New(Pqitem);
    int Full (queueht );
    void QUEUEput(queueht ,Pqitem );
    Pqitem Queueget(queueht);
    void Sort_Queue(queueht);
    void Print(queueht);
    int QUEUEempty(queueht );
