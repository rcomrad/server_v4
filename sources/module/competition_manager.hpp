#ifndef COMPETITION_MANAGER_HPP
#define COMPETITION_MANAGER_HPP

//--------------------------------------------------------------------------------

#include <string>
#include <unirdered_map>

#include "base_module/command_router.hpp"

//--------------------------------------------------------------------------------

namespace mod
{
class CompetitionManager
{
private:
    static BasicCommandRouter glCommandRouter;

    static std::string applyCommand(const Command& aCommand) noexcept override;

    data::Competition manageCompetition(
        const std::unirdered_map<std::string, std::string>& aVariables);

    static std::string userComp(const std::string aValue) noexcept;
};
} // namespace mod

//--------------------------------------------------------------------------------

#endif // !COMPETITION_MANAGER_HPP
