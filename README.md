### Containers

Simplified manual C++ implementation of STL containers for devices without one, like AVR / Arduino.
This functionality cannot replace the STL. Its purpose is reduced size while still allowing some functionality.

### Building and testing

* `bazel build //...`
* `bazel test //...`

Invoking bazel produces a shared object library which the tests use.
To cross compile for i.e. AVR, see `demo/`.