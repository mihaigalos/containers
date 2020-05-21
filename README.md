### Containers [![Build Status](https://travis-ci.org/mihaigalos/containers.svg?branch=master)](https://travis-ci.org/mihaigalos/containers) [![codecov](https://codecov.io/gh/mihaigalos/containers/branch/master/graph/badge.svg)](https://codecov.io/gh/mihaigalos/containers) [![license](https://img.shields.io/badge/license-GPLv3-brightgreen.svg)](LICENSE) [![HitCount](http://hits.dwyl.com/mihaigalos/containers.svg)](http://hits.dwyl.com/mihaigalos/containers)

Simplified manual C++ implementation of STL containers for devices without one, like AVR / Arduino.

This functionality cannot replace the STL. Its purpose is reduced size while still allowing some functionality.

### Build and Test

First, get the sources:
```
git clone https://github.com/mihaigalos/containers.git && cd containers
```

#### Baremetal

Building and testing is managed by `bazel` (transparent to the end-user).

```bash
bazel build //...
bazel test //...
```

#### Using Docker

```bash
docker run -it --rm -v $(pwd):/src -v /tmp:/tmp/bazel remoteapistesting/bazel-build /bin/bash -c "bazel --output_base=/tmp/bazel test //..."
```

Invoking bazel produces a shared object library which the tests use.
To cross compile for i.e. AVR, see `demo/`.
