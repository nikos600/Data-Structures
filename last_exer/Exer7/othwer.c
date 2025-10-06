int randX() {
    int level = 1;
    while ((rand() & 1) && level < max_level)
        level++;
    return level;
}
