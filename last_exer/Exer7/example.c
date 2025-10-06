   for (i = 1;i < level3;i++) {
                x = list1 ->next[i];
                x1 = list2->next[i];


                while (x != z && x1 != z) {
                  if (less(key(x1->item),key(x1->item))) {
                    list3->next[i] = x;
                    list3 = x;
                    x = x->next[i];
                  }
                  else if (less(key(x1->item),key(x->item))) {
                    list3->next[i] = x;
                    list3 = x;
                    x = x->next[i];
                  }
                  else {
                    update->next[i] = x1;
                    update = x1;
                    x = x->next[i];
                    x1 = x1->next[i];
                  }
                  
              }
              while (x != z) {
                list3->next[i] = x;
                list3 = x;
                x = x->next[i];
              }

                while (x1 != z) {
                list3->next[i] = x1;
                list3 = x1;
                x1 = x1->next[i];
              }
              list3->next[i] = z;
        }

        free(list1);
        free(list2);

        }

