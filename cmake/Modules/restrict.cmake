# Taken from https://cmake.org/pipermail/cmake/2013-January/053113.html
# with only very minor modifications


INCLUDE (CheckCXXSourceCompiles)

# Builds the macro A_C_RESTRICT form automake
foreach(ac_kw __restrict __restrict__ _Restrict restrict)
  check_cxx_source_compiles(
  "
  typedef int * int_ptr;
  int foo (int_ptr ${ac_kw} ip) {
    return ip[0];
  }
  int main(){
    int s[1];
    int * ${ac_kw} t = s;
    t[0] = 0;
    return foo(t);
  }
  "
  RESTRICT)
  if(RESTRICT)
    set(ac_cv_c_restrict ${ac_kw})
    break()
  endif()
endforeach()
if(RESTRICT)
  MESSAGE(STATUS "restrict keyword - ${ac_cv_c_restrict}")
  add_definitions("-Drestrict=${ac_cv_c_restrict}")
else()
  MESSAGE(STATUS "restrict keyword - not found")
  add_definitions("-Drestrict=")
endif()
