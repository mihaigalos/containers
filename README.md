### Containers

Manual C++ implementation of STL containers for devices without one, like AVR.

### Building and testing

* `bazel build //...`
* `bazel test //...`

Invoking bazel produces a shared object library which the tests use.
To cross compile for i.e. AVR, see `demo/`.