#pragma once

#include "LucidDB.h"

enum LucidProcess {
    NONE = -1,
    ADD,
    REMOVE,
    UPDATE,
    SEARCH,
    LIST
};

class Control 
{
    private:
        LucidProcess proc;
        void processCommandLineArgs();
        void add();
        void remove();
        void update();
        void search();
        void list();
    public:
        Control(int argc, char * argv[]);
        int execute();
};
