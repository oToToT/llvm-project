// RUN: %clang_cc1 -fsyntax-only -verify %s
// RUN: %clang_cc1 -fsyntax-only -verify -std=c++98 %s
// RUN: %clang_cc1 -fsyntax-only -verify -std=c++11 %s

// expected-no-diagnostics

namespace GH37979 {

struct Restrict {
  float * __restrict Ptrs[2];
};

struct RestrictAlt {
  float * __restrict__ Ptrs[2];
};

void copyAssign() {
  Restrict A, B;
  A = B;

  RestrictAlt C, D;
  C = D;
}

#if __cplusplus >= 201103L
void moveAssign() {
  Restrict A;
  A = Restrict();

  RestrictAlt B;
  B = RestrictAlt();
}
#endif

} // namespace GH37979
