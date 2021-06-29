#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

namespace containers
{

template <typename TData, typename TProxy>

class channel{
public:
    channel(const TProxy& proxy, void(TProxy::*handler)(const TData&) const) : proxy_{proxy}, handler_{handler} {}
    void operator << (const TData& data) const{
        (proxy_.*handler_)(data);
    }
private:
    const TProxy& proxy_;
    void (TProxy::*handler_)(const TData&) const; 
};
}