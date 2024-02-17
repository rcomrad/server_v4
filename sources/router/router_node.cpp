#include "router_node.hpp"

#include "router_map.hpp"

route::RouterNode::RouterNode(const std::string& aVolumeName,
                              const std::unordered_set<std::string>& aNodeNames,
                              void* aFunc) noexcept
{
    // for(const auto& name : aNodeNames)
    // {
    //     RouterMap::add(aVolumeName, );
    // }
    // RouterMaster::add(aRouterName, aNodeNames, std::move(aFunc));
}
route::RouterNode::RouterNode(
    const std::string& aVolumeName,
    const std::unordered_map<std::string, void*>& aNodes) noexcept
{
    // RouterMaster::add(aRouterName, aNodeNames, std::move(aFunc));
}
