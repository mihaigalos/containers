#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

namespace containers
{

template <typename TData, typename TAddress, typename TPort, typename TLength, typename TProxy>

class channel{
public:
    channel() = delete;
    channel(const TProxy& proxy, const TAddress source, const TAddress destination, TPort port, void(TProxy::*handler)(TAddress, TAddress, TPort, const TData&) const) : proxy_{proxy}, source_{source}, destination_{destination}, port_{port}, handler_{handler} {}
    const channel& operator << (const TData& data) const{
        (proxy_.*handler_)(source_, destination_, port_, data);
        return *this;
    }

    channel(const channel&) = delete;
    channel(const channel&&) = delete;
    channel &operator=(const channel &other) = delete;
    channel &operator=(channel &&other) = delete;

private:
    const TProxy& proxy_;
    const TAddress source_{0};
    const TAddress destination_{0};
    const TAddress port_{0};
    void (TProxy::*handler_)(TAddress, TAddress, TPort, const TData&) const{nullptr}; 
};
}