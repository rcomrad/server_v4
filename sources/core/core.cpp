#include "core.hpp"

#include <fstream>

#include "domain/error_message.hpp"

#include "post/journal_handler.hpp"
#include "post/plan_handler.hpp"
#include "post/user_handler.hpp"
#include "tester/tester.hpp"

#include "generate_code.hpp"
#include "program_state.hpp"
#include "server.hpp"

//--------------------------------------------------------------------------------

// data::DBSettings core::Core::mDBS;

core::Core::Core() noexcept
{
    generateDatabaseStructuresFiles();
    mApps["server"] = std::move(std::thread(&Core::serverThread, this));
}

void
core::Core::remakeDatabase()
{
    deleteEnvironment();
    createEnvironment();
    createDatabaseFromFile("database.psql_db");
    populateDatabaseFromFile("database.populate");
}

void
core::Core::populate()
{
    populateDatabaseFromFile("../tests/example.populate");

    post::UserHandler::dataFileUpload("../tests/user.data");

    post::PlanHandler::PlanData data;
    data.subjectID = 1;

    data.name = "Тест";
    data.url  = "../tests/plan_test.csv";
    post::PlanHandler::csvFileUpload(data);

    data.name = "C++";
    data.url  = "../tests/plan_cpp.csv";
    post::PlanHandler::csvFileUpload(data);

    post::JournalHandler::dataFileUpload("../tests/journal.data");
}

void
core::Core::run(const std::vector<std::string>& argv) noexcept
{
    // mCommand.process(argv);

    // std::map<Command::Type, std::function<void()>> methodMap{
    //     {Command::Type::GET_USERS,           [&]() { printUsers(); }       },
    //     {Command::Type::GET_ACTIVE_USERS,    [&]() { printUsers(); }       },
    //     {Command::Type::GET_DELETED_USERS,   [&]() { printUsers(); }       },
    //     {Command::Type::RENAME_USERS,        [&]() { renameUsers(); }      },
    //     {Command::Type::GENERATE_NAMES,      [&]() { generateNames(); }    },
    //     {Command::Type::GENERATE_ROBO_NAMES, [&]() { generateRoboNames(); }},
    //     {Command::Type::EVALUATE,            [&]() { getResults(); }       }
    // };

    // for (auto& i : methodMap)
    // {
    //     if (mCommand.getCommand() == i.first) i.second;
    // }

    auto& state = ProgramState::getInstance();

    bool flag = true;
    while (true)
    {
        // std::string s;
        // std::cin >> s;

        // if (s == "create") createDatabaseFromFile("database.data");
        // else if (s == "populate")
        //     populateDatabaseFromFile("populate_database.data");
        // else if (s == "set_up") createEnvironment();
        // else if (s == "remake")
        // {
        //     createDatabaseFromFile("database");
        //     populateDatabaseFromFile("populate_database");
        // }

        if (state.needRestart())
        {
            state.startRestart();
            if (state.needRemakeDB()) remakeDatabase();
            if (state.needPopulateDB()) populate();
            state.endRestart();
        }

        if (state.hasSubmition())
        {
            test::Tester tester(10);
            // data::Table<data::Submission> temp = ;
            tester.run(state.getSubmition());
        }

        // std::cin >> n;
        // std::cout << n * n << "\n";
        // if (flag)
        // {
        //     mApps["server"] = std::move(std::thread(&Core::serverThread,
        //     this));
        // }

        // flag = false;
    }
}

void
core::Core::serverThread() noexcept
{
    Server app;
    while (true)
        ;
}

void
core::Core::createDatabaseFromFile(std::string aFileName) noexcept
{
    data::DatabaseQuery dbq(data::DatabaseQuery::UserType::USER);

    std::vector<data::ColumnSetting> colums;
    std::ifstream ios(aFileName);
    if (!ios.is_open())
    {
        std::cout << "NO_SUCH_FILE!\n";
        return;
    }
    else
    {
        std::cout << "Extracting_file\n";
    }
    std::string s1, s2;
    std::string name;
    while (ios >> s1)
    {
        std::getline(ios, s2, ' ');
        std::getline(ios, s2);
        if (s1 == "TABLE")
        {
            if (name.size()) dbq.createTable(name, colums);
            colums.clear();
            name = s2;
        }
        else
        {
            // colums.emplace_back(data::ColumSetting(s1, s2, ""));
            colums.emplace_back(s1, s2);
        }
    }
}

#include <sstream>

void
core::Core::populateDatabaseFromFile(std::string aFileName) noexcept
{
    data::DatabaseQuery dbq(data::DatabaseQuery::UserType::USER);

    std::vector<data::ColumnSetting> colums;
    std::ifstream ios(aFileName);
    if (!ios.is_open())
    {
        std::cout << "NO_SUCH_FILE!\n";
        return;
    }
    else
    {
        std::cout << "Extracting_file\n";
    }
    std::string s1, s2;
    std::string name;
    while (ios >> s1)
    {
        std::getline(ios, s2);
        std::getline(ios, s2);
        std::stringstream ss;

        while (s2 != "END")
        {
            std::stringstream ss;
            ss << s2;

            std::vector<std::string> data;
            while (std::getline(ss, s2, ';'))
            {
                if (s2.back() == ';') s2.back() = ' ';
                data.emplace_back(s2);
            }
            // TODO:
            dbq.insert(s1, data);
            std::getline(ios, s2);
        }
    }
}

void
core::Core::createEnvironment() noexcept
{
    data::DatabaseQuery dbq(data::DatabaseQuery::UserType::ADMIN);
    dbq.createEnvironment(data::DatabaseQuery::UserType::USER);
}

void
core::Core::deleteEnvironment() noexcept
{
    data::DatabaseQuery dbq(data::DatabaseQuery::UserType::ADMIN);
    dbq.dropDatabase(data::DatabaseQuery::UserType::USER);
}
