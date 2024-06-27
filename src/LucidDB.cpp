#include "LucidDB.h"

LucidDB::LucidDB(const char * filename) :
m_filename(filename)
{
    loadData();
}

void LucidDB::loadData()
{
    std::ifstream fileHandle(m_filename);
    std::string line;

    assert(fileHandle.is_open());

    while (getline(fileHandle, line))
    {
        std::stringstream ss(line);
        std::string token;

        LucidEntry entry = LucidEntry();

        ss >> token;
        entry.index = atoi(token.c_str());
        ss >> token;
        entry.accountName = token;
        ss >> token;
        entry.username = token;
        ss >> token;
        entry.password = token;

        m_data.push_back(entry);
    }

    fileHandle.close();
}

void LucidDB::resetIndicies()
{
    int index = 0;

    for (LucidEntry &e : m_data)
    {
        e.index = index;
        index++;
    }
}

int LucidDB::add(const char * accountName, const char * username, const char * password)
{
    if (accountName == NULL || username == NULL || password == NULL)
    {
        return DB_FAILURE;
    }

    LucidEntry entry;
    entry.index = m_data.size();
    entry.accountName = accountName;
    entry.username = username;
    entry.password = password;

    m_data.push_back(entry);

    return DB_SUCCESS;
}

int LucidDB::remove(int index)
{
    if (index < 0 || index >= m_data.size())
    {
        return DB_FAILURE;
    }

    m_data.erase(m_data.begin() + index);
    resetIndicies();

    return DB_SUCCESS;
}

int LucidDB::update(int index, const char * accountName, const char * username, const char * password)
{
    if (index < 0 || 
        index >= m_data.size() || 
        accountName == NULL || 
        username == NULL || 
        password == NULL)
    {
        return DB_FAILURE;
    }

    m_data[index].accountName = accountName;
    m_data[index].username = username;
    m_data[index].password = password;

    return DB_SUCCESS;
}

LucidEntry LucidDB::search(const char * accountName)
{
    LucidEntry entry;

    for (LucidEntry e : m_data)
    {
        if (strcmp(e.accountName.c_str(), accountName) == 0)
        {
            entry = e;
            break;
        }
    }

    return entry;
}

LucidEntry LucidDB::search(int index)
{
    if (index < 0 || index >= m_data.size())
    {
        LucidEntry entry;
        return entry;
    }

    return m_data[index];
}

int LucidDB::save()
{
    std::ofstream fileHandle(m_filename);

    assert(fileHandle.is_open());

    for (LucidEntry e : m_data)
    {
        fileHandle << e.index 
                   << " " 
                   << e.accountName 
                   << " " 
                   << e.username
                   << " "
                   << e.password
                   << "\n";
    }

    fileHandle.close();

    return DB_SUCCESS;
}

void LucidDB::printData()
{
    for (LucidEntry &e : m_data)
    {
        printf("%d\n%s\n%s\n%s\n", 
            e.index, 
            e.accountName.c_str(), 
            e.username.c_str(), 
            e.password.c_str());
    }
}
