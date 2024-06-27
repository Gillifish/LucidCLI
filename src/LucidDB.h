#pragma once

#include <stdio.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include <assert.h>
#include <vector>

typedef enum 
{
    DB_SUCCESS,
    DB_FAILURE
} db_status_t;

/*
* Struct that models the entry data for an account.
*/
struct LucidEntry
{
    int index;
    std::string accountName;
    std::string username;
    std::string password;
};

class LucidDB
{
    private:
        std::vector<LucidEntry> m_data;
        std::string m_filename;

        void loadData();
        void resetIndicies();

    public: 
        LucidDB(const char * filename);
        
        int add(const char * accountName, const char * username, const char * password);
        int remove(int index);
        int update(int index, const char * accountName, const char * username, const char * password);
        LucidEntry search(const char * accountName);
        LucidEntry search(int index);
        int save();

        void printData();
};

