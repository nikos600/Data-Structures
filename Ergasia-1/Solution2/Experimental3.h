      typedef struct Nodetag nodetype;
      
      nodetype *Create();
      int Size(nodetype *);
      int IsEmpty(nodetype *);
      int GetFirst(nodetype *);
      int GetLast(nodetype *);
      nodetype *GetNode(nodetype *,int );
      int GetPrev(nodetype *);
      int GetNext(nodetype *);
      void AddBefore(nodetype *,int );
      void AddAfter(nodetype *,int );
      void AddFirst(nodetype **,int );
      void AddLast(nodetype **,int );
      void Remove(nodetype **l,int );
      void Print(nodetype *);
        
        
      