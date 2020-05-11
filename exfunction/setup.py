from setuptools import setup, Extension

setup(
    name="exfunction",
    ext_modules=[
        Extension("exfunction", ["exfunction/module.c"])
    ]
)
