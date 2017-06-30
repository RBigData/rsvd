# rsvd

* **Version:** 0.1-0
* **License:** [BSD 2-Clause](http://opensource.org/licenses/BSD-2-Clause)
* **Author:** Drew Schmidt (wrathematics .AT. gmail .DOT. com)
* **Project home**: https://github.com/RBigData/rsvd
* **Bug reports**: https://github.com/RBigData/rsvd/issues


A basic implementation of the [randomized svd](https://arxiv.org/pdf/0909.4061) algorithm using the C++ library [armadillo](http://arma.sourceforge.net/).  It is a fairly direct translation of the implementation in the [pbdML](https://github.com/RBigData/pbdML) package.

For ease of distribution, the armadillo sources are distributed with the package under the `include/` directory.  See `include/LICENSE.txt` for armadillo copyright details.



## Installation

Assuming you have CMake, simply run

```
make
```



## Examples

The main codebase is C++, making heavy use of armadillo.  However, there is a C API as well.

See the `examples/` sub tree for examples of each.
