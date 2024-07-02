#pragma once

#include "LucidDB.h"
#include <string>

typedef enum
{
    NONE = -1,
    USAGE,
    ADD,
    REMOVE,
    UPDATE,
    SEARCH,
    LIST
} lucid_process_t;

typedef enum
{
    LUCID_SUCCESS,
    LUCID_ERROR,
} lucid_status_t;

class Control 
{
    private:
        bool m_validInput;
        lucid_process_t m_proc;

        lucid_status_t processCommandLineArgs(int argc, char * argv[]);
        void usage();
        void add();
        void remove();
        void update();
        void search();
        void list();
    public:
        Control(int argc, char * argv[]);
        int execute();
};
