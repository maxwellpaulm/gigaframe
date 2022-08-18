#!/usr/bin/env python3
from setuptools import setup, Extension

# giga_series C++ module extension
giga_series_extension = Extension(
    "giga_series",
    sources=["cpp/modules/giga_series_module.cpp"],
    language="c++",
)

setup(
    name="gigaframe_util",
    version="0.0-dev",
    description="Gigaframe utilities C++ extension module.",
    ext_modules=[giga_series_extension],
)
