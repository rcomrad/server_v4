#ifndef ROUTER_NODE_HPP
#define ROUTER_NODE_HPP

//--------------------------------------------------------------------------------

#include <functional>
#include <string>
#include <unordered_set>

//--------------------------------------------------------------------------------

namespace route
{
class RouterNode
{
public:
    RouterNode(const std::string& aVolumeName,
               const std::string& aNodeName,
               void* aFunc) noexcept;

    RouterNode(const std::string& aVolumeName,
               const std::unordered_set<std::string>& aNodeNames,
               void* aFunc) noexcept;

    RouterNode(const std::string& aVolumeName,
               const std::unordered_map<std::string, void*>& aNodes) noexcept;
};
} // namespace route

//--------------------------------------------------------------------------------

#endif // !ROUTER_NODE_HPP
