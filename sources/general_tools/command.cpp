// #include "command.hpp"

// #include "string_data/parser.hpp"

// base::Command::Command(const std::string& aValue,
//                        const std::string& aArguments) noexcept
//     : value(aValue)
// {
//     auto args = strd::Parser::slice(aArguments, "; \n\t");
//     for (auto& i : args)
//     {
//         auto temp = strd::Parser::slice(i, "=");
//         if (temp.size() == 1)
//         {
//             arguments.insert(std::move(temp[0]));
//         }
//         else
//         {
//             variables[temp[0]] = temp[1];
//         }
//     }
// }
