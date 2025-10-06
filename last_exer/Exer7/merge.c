link merge(link list1, link list2) {
    int i, lvl;
    int unflipped = true;
    link update[maxLevel];

    // Δημιουργία νέας λίστας εξόδου
    link list3 = NEW(NULL, maxLevel);
    int level3 = (list1->sz > list2->sz) ? list1->sz : list2->sz;
    for (i = 1; i <= level3; i++) update[i] = list3;

    while (list1->next[1] != z && list2->next[1] != z) {
        Item key1 = list1->next[1]->item;
        Item key2 = list2->next[1]->item;

        if (less(key2, key1)) {
            // Αν key1 > key2: ανταλλαγή h1 <-> h2
            link temp = list1; 
            list1 = list2; 
            list2 = temp;
            Item flag = key1; 
            key1 = key2; 
            key2 = flag;
            unflipped = !unflipped;
        }

        // Αντιγραφή από h1 όλων των κόμβων με key ≤ key2
        lvl = 1;
        do {
             update[lvl]->next[lvl] = list1->next[lvl];
             lvl++;
        } while (lvl <= level3 && !less(key2, list1->next[lvl]->item));
         
          
        lvl--;

        // Εύρεση τελευταίου κόμβου που πέρασε στο επίπεδο lvl
        link x = list1->next[lvl];
        for (i = lvl; i >= 1; i--) {
            while (x->next[i] != z && !less(key2, x->next[i]->item))
                x = x->next[i];
            update[i] = x;
            list1->next[i] = x->next[i];
        }

        // Αν key2 == τελευταίο inserted key, κρατάμε value από h2 (αν ζητείται)
        if (eq(key2, x->item)) {
            if (unflipped)
                x->item = list2->next[1]->item;

            // Διαγραφή duplicate από h2
            link y = list2->next[1];
            for (i = 1; i <= y->sz; i++)
                list2->next[i] = y->next[i];
            free(y);
        }
    }

    // Επισυνάπτουμε τα υπόλοιπα
    link leftOver = (list2->next[1] == z) ? list1 : list2;
    for (i = 1; i <= leftOver->sz; i++)
        update[i]->next[i] = leftOver->next[i];
    for (i = leftOver->sz + 1; i <= level3; i++)
        update[i]->next[i] = z;

    // Μείωση επιπέδων αν χρειάζεται
    while (level3 > 1 && h->next[level3] == z)
        list3->sz = liste3->sz - 1;
    list3->sz = level3;

    // Προαιρετικά free τις δύο εισόδους
    free(list1);
    free(list2);

    return list3;
}