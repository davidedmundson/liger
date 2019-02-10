include(../../ligerlibrary.pri)

CONFIG -= shared dll qt
INCLUDEPATH += $$PWD/include

CONFIG += exceptions

HEADERS += include/pybind11/detail/class.h
  include/pybind11/detail/common.h
  include/pybind11/detail/descr.h
  include/pybind11/detail/init.h
  include/pybind11/detail/internals.h
  include/pybind11/detail/typeid.h
  include/pybind11/attr.h
  include/pybind11/buffer_info.h
  include/pybind11/cast.h
  include/pybind11/chrono.h
  include/pybind11/common.h
  include/pybind11/complex.h
  include/pybind11/options.h
  include/pybind11/eigen.h
  include/pybind11/embed.h
  include/pybind11/eval.h
  include/pybind11/functional.h
  include/pybind11/numpy.h
  include/pybind11/operators.h
  include/pybind11/pybind11.h
  include/pybind11/pytypes.h
  include/pybind11/stl.h
  include/pybind11/stl_bind.h