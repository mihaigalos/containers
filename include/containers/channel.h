#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

namespace containers
{

template <typename TData, typename TSource, typename TDestination, typename TPort, typename TProxy>

class channel{
public:
    channel(const TProxy& proxy, const TSource source, const TDestination destination, TPort port, void(TProxy::*transmit_handler)(TSource, TDestination, TPort, const TData&) const) : proxy_{proxy}, source_{source}, destination_{destination}, port_{port}, transmit_handler_{transmit_handler} {}
    const channel& operator << (const TData& data) const{
        (proxy_.*transmit_handler_)(source_, destination_, port_, data);
        return *this;
    }

    channel() = delete;
    channel(const channel&) = delete;
    channel(const channel&&) = delete;
    channel &operator=(const channel &other) = delete;
    channel &operator=(channel &&other) = delete;

private:
    const TProxy& proxy_;
    const TSource source_{0};
    const TDestination destination_{0};
    const TPort port_{0};
    void (TProxy::*transmit_handler_)(TSource, TDestination, TPort, const TData&) const{nullptr}; 
};
}