#include "Control.h"


Control::Control(int argc, char * argv[])
{
    lucid_status_t status = processCommandLineArgs(argc, argv);

    if (status == LUCID_SUCCESS)
    {
        m_validInput = true;
    } else
    {
        m_validInput = false;
    }
}

lucid_status_t Control::processCommandLineArgs(int argc, char * argv[])
{
    if (argv[1] == NULL)
    {
        return LUCID_ERROR;
    } else
    {
        std::string command = argv[1];

        return LUCID_SUCCESS;
    }
}

void Control::usage()
{
    
}

void Control::add()
{

}

void Control::remove()
{

}

void Control::update()
{

}

void Control::search()
{

}

void Control::list()
{

}

int Control::execute()
{
    if (!m_validInput)
    {
        printf("Invalid input");
        usage();
    }

    switch (m_proc)
    {
    case USAGE:
        usage();
        break;
    case ADD:
        add();
        break;
    case REMOVE:
        remove();
        break;
    case UPDATE:
        update();
        break;
    case SEARCH:
        search();
        break;
    case LIST:
        list();
        break;
    default:
        break;
    }

    return 0;
}