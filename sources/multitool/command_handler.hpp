#ifndef COMMAND_HANDLER_HPP
#define COMMAND_HANDLER_HPP

//--------------------------------------------------------------------------------

#include "base_module/command_router.hpp"

//--------------------------------------------------------------------------------

namespace mult
{
class CommandHandler
{
public:
    static std::string process(const crow::request& aReq) noexcept;
    static std::string process(const std::string& aCommand,
                               const std::string& aArgument = "") noexcept;
};
} // namespace mult

//--------------------------------------------------------------------------------

#endif // !COMMAND_HANDLER_HPP
